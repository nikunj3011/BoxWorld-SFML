
#include "World.h"
#include "Player.h"
#include "Category.h"
#include "InteractablePlaceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include "Frogger.h"
#include <SFML\System\Sleep.hpp>
#include <string>


World::World(sf::RenderTarget& outputTarget, const FontHolder_t& fonts)
	: target(outputTarget)
	, sceneTexture()
	, worldView(outputTarget.getDefaultView())
	, textures()
	, fonts(fonts)
	, sceneGraph()
	, sceneLayers()
	, commandQueue()
	, worldBounds(0.f, 0.f, worldView.getSize().x, worldView.getSize().y)
	, spawnPosition(15.f, 120.f)
	, playerFrogger(nullptr)
{
	sceneTexture.create(target.getSize().x, target.getSize().y);

	loadTextures();
	buildScene();
	
	npcSpawnTable = initializeNPCSpawnData2();

	worldView.setCenter(worldView.getSize().x / 2.f, worldBounds.height - worldView.getSize().y / 2.f);
}

CommandQueue& World::getCommands()
{
	return commandQueue;
}

bool World::hasAlivePlayer() const
{
	return playerFrogger->getLivesLeft() > 0;
}

bool World::hasPlayerReachedEnd() const
{
	return playerFrogger->hasFroggerFilledSlots();
}

void World::update(sf::Time dt) {

	destroyEntitiesOutsideView();

	sceneGraph.removeWrecks();

	handleCollisions();

	while (!commandQueue.isEmpty()) {
		sceneGraph.onCommand(commandQueue.pop(), dt);
	}

	adaptPlayerVelocity();

	addEnemies();

	updateNPCSpawnTable(dt);

	sceneGraph.update(dt, getCommands());

	updateText();

	updateLivesIndicator(playerFrogger->getLivesLeft()-1);

	adaptPlayerPosition();
}

void World::updateText()
{
	score->setString("Score: " + std::to_string(playerFrogger->getScore()));
	score->setPosition(370.f, 30.f);
}

void World::draw() {

	target.setView(worldView);
	target.draw(sceneGraph);
}

void World::loadTextures() {
	textures.load(TextureID::Background, "Media/Textures/backgroundtut.png");
	textures.load(TextureID::Background2, "Media/Textures/background3.png");
	textures.load(TextureID::BoxWorld, "Media/Textures/boxworld.png");
	textures.load(TextureID::BoxWorld2, "Media/Textures/level2.png");
	textures.load(TextureID::Live, "Media/Textures/lives.png");
}

void World::buildScene() {

	for (std::size_t i = 0; i < LayerCount; ++i) {
		Category::Type category;
		switch (i) {
		case PlayingLayer:
			category = Category::Type::BackgroundLayer;
			break;
		case River:
			category = Category::Type::GroundFire;
			break;
		default:
			category = Category::Type::None;
			break;
		}

		SceneNode::Ptr layer(new SceneNode(category));

		sceneLayers[i] = layer.get();

		sceneGraph.attachChild(std::move(layer));
	}

	auto positions = getWinningSpotPositions();

	for (int i = 0; i < positions.size(); ++i) {
		SceneNode::Ptr winningSpot(new InteractablePlaceHolder(Category::Type::WinningSpot, positions[i]));
		winningSpotsFilled.push_back(false);

		sceneLayers[River]->attachChild(std::move(winningSpot));
	}

	sf::Texture& texture = textures.get(TextureID::Background);
	texture.setRepeated(true);

	float viewHeight = worldView.getSize().y;
	sf::IntRect textureRect(worldBounds);
	textureRect.height += static_cast<int>(viewHeight);

	// background spriteNode
	std::unique_ptr<SpriteNode> background(new SpriteNode(texture, textureRect));
	background->setPosition(worldBounds.left, worldBounds.top - viewHeight);
	sceneLayers[Background]->attachChild(std::move(background));

	std::unique_ptr<TextNode> scoreField(new TextNode(fonts, ""));
	score = scoreField.get();
	sceneLayers[Background]->attachChild(std::move(scoreField));

	std::unique_ptr<Frogger> frog(new Frogger(textures, fonts));
	frog.get()->setPosition(spawnPosition);
	frog.get()->setVelocity(0.f, 0.f);

	playerFrogger = frog.get();

	sceneLayers[PlayingLayer]->attachChild(std::move(frog));

	buildLivesIndicator(playerFrogger->getLivesLeft()-1);
}

void World::addEnemies()
{
	for (int i = 0; i < npcSpawnTable.size(); ++i) {
		if (npcSpawnTable[i].elapsedTime >= npcSpawnTable[i].interval) {
			npcSpawnTable[i].elapsedTime -= npcSpawnTable[i].interval;

			std::unique_ptr<Actor> enemy(new Actor(npcSpawnTable[i].type, textures, fonts));
			enemy->setPosition(npcSpawnTable[i].position);
			enemy->setVelocity(npcSpawnTable[i].speed, 0.f);
			enemy->setDirection(npcSpawnTable[i].direction);

			if (enemy.get()->getCategory() & Category::Type::Enemies) {
				sceneLayers[River]->attachChild(std::move(enemy));
			}
			else {
				sceneLayers[PlayingLayer]->attachChild(std::move(enemy));
			}
		}
		if (npcSpawnTable[11].elapsedTime >= npcSpawnTable[11].interval) {
			npcSpawnTable[11].elapsedTime -= npcSpawnTable[11].interval;

			std::unique_ptr<Actor> enemy(new Actor(npcSpawnTable[11].type, textures, fonts));
			enemy->setPosition(npcSpawnTable[11].position);
			enemy->setVelocity(0.f, npcSpawnTable[11].speed);
			enemy->setDirection(npcSpawnTable[11].direction);

			if (enemy.get()->getCategory() & Category::Type::Enemies) {
				sceneLayers[River]->attachChild(std::move(enemy));
			}
			else {
				sceneLayers[PlayingLayer]->attachChild(std::move(enemy));
			}
		}
	}


}

void World::handleCollisions()
{
	// get all colliding pairs
	std::set<SceneNode::Pair> collisionPairs;
	sceneGraph.checkSceneCollision(sceneGraph, collisionPairs);

	playerFrogger->setBoxVelocity(0.f, 0.f);
	playerFrogger->resetPositionFlags();

	for (auto pair : collisionPairs) {
		if (matchesCategories(pair, Category::BoxMan, Category::Platform)) {
			playerFrogger->setBoxVelocity(0.f, -50.f);
			//playerFrogger->jump(50.f, 50.f);
			return;
		}
		if (matchesCategories(pair, Category::BoxMan, Category::Enemies)) {
			playerFrogger->setIsStruckByCar(true);
			return;
		}

		/*if (matchesCategories(pair, Category::BoxMan, Category::River)) {
			playerFrogger->setIsInRiver(false);
		}
		if (matchesCategories(pair, Category::BoxMan, Category::SwimmingNPC)) {
			playerFrogger->setIsOnSwimmingNPC(false);

			sf::Vector2f velocity = (static_cast<Actor&>(*pair.second)).getVelocity();

			playerFrogger->setVelocity(velocity);
		//}*/
		//if (matchesCategories(pair, Category::BoxMan, Category::WinningSpot)) {
		//	Command command;
		//	command.category = Category::BackgroundLayer;
		//	command.action = derivedAction<Frogger>([this, pair](Frogger& f, sf::Time t) {

		//			std::unique_ptr<Actor> winningFrogPicture(new Actor(Actor::Type::BoxWinner, textures, fonts));
		//			sf::FloatRect posRect = (static_cast<InteractablePlaceHolder&>(*pair.second)).getPosition();
		//			sf::Vector2f posVector (posRect.left + posRect.width / 2, posRect.top + posRect.height / 2);

		//			int spotIndex = getWinningSpotIndexByPosition(posRect);
		//			
		//			if (winningSpotsFilled[spotIndex]) {
		//					playerFrogger->setPosition(posVector);
		//					playerFrogger->setIsWinningSpotTaken();
		//			}
		//			else {
		//				winningSpotsFilled[spotIndex] = true;
		//				winningSpotsFilled[getWinningSpotIndexByPosition(posRect)] = true;

		//				winningFrogPicture.get()->setPosition(posVector);
		//				winningFrogPicture.get()->setVelocity(0.f, 0.f);
		//				sceneLayers[Background]->attachChild(std::move(winningFrogPicture));

		//				playerFrogger->addScore(30);

		//				//  here show winning title
		//				if (isAllWinningSpotsFilled())
		//					playerFrogger->setHasFroggerFilledSlots();

		//				playerFrogger->respawnFrogger();
		//			}
		//			
		//		});
		//	commandQueue.push(command);
		//}
	}

}

bool World::matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
	unsigned int category1 = colliders.first->getCategory();
	unsigned int category2 = colliders.second->getCategory();

	if (type1 & category1 && type2 & category2) {
		return true;
	}
	else if (type2 & category1 && type1 & category2) {
		std::swap(colliders.first, colliders.second);
		return true;
	}
	else {
		return false;
	}
}

void World::adaptPlayerVelocity()
{
	sf::Vector2f velocity = playerFrogger->getVelocity();

	// If moving diagonally, normalize the velocity
	if (velocity.x != 0.f && velocity.y != 0.f)
		playerFrogger->setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	//playerActor->accelerate(0.f, scrollSpeed);
}

void World::destroyEntitiesOutsideView()
{
	Command command;
	command.category = Category::NPC;
	command.action = derivedAction<Actor>([this](Actor& a, sf::Time t) {
		if (!getBattlefieldBounds().intersects(a.getBoundingRect())) {
			a.setMarkedForRemoval(true);
		}
		});
	commandQueue.push(command);
}

void World::updateLivesIndicator(int frogLives)
{
	if (playerFrogger->getState() == Actor::State::Death) {
		int interval = 25;
		int curPosition = 5;
		int positionY = 570;
		int livesIndexInSceneLayers = 1;

		sceneGraph.detachChild(*sceneLayers[Lives]);

		SceneNode::Ptr lives(new SceneNode(Category::None));

		for (int i = 0; i < frogLives - 1; ++i) {
			std::unique_ptr<SpriteNode> live(new SpriteNode(textures.get(TextureID::Live)));
			live->setPosition(curPosition, positionY);
			curPosition += interval;
			lives->attachChild(std::move(live));
		}
		sceneLayers[livesIndexInSceneLayers] = lives.get();

		sceneGraph.attachChild(std::move(lives));
	}
}

void World::buildLivesIndicator(int frogLives)
{
	int interval = 25;
	int curPosition = 5;
	int positionY = 20;

	for (int i = 0; i < frogLives; ++i) {
		std::unique_ptr<SpriteNode> live(new SpriteNode(textures.get(TextureID::Live)));
		live->setPosition(curPosition, positionY);
		curPosition += interval;
		sceneLayers[Lives]->attachChild(std::move(live));
	}
}

void World::updateNPCSpawnTable(sf::Time dt)
{
	for (int i = 0; i < npcSpawnTable.size(); ++i) {
		npcSpawnTable[i].elapsedTime += dt;
	}
}

sf::FloatRect World::getViewBounds() const
{
	return sf::FloatRect(worldView.getCenter() - worldView.getSize() / 2.f, worldView.getSize());
}

sf::FloatRect World::getBattlefieldBounds() const
{
	auto bounds = getViewBounds();

	bounds.left -= 50.f;
	bounds.width += 100.f;

	return bounds;
}

int World::getWinningSpotIndexByPosition(sf::FloatRect pos)
{
	auto v = getWinningSpotPositions();

	for (int i = 0; i < winningSpotsFilled.size(); ++i) {
		if (abs(pos.left - v[i].left) < 0.1) {
			return i;
		}
	}	
	return -1;
}

bool World::isAllWinningSpotsFilled()
{
	for (int i = 0; i < winningSpotsFilled.size(); ++i) {
		if (!winningSpotsFilled[i])
			return false;
	}
	return true;
}


void World::adaptPlayerPosition()
{
	sf::Vector2f position = playerFrogger->getPosition();
	float left = worldView.getCenter().x - worldView.getSize().x / 2.f;
	float right = worldView.getCenter().x + worldView.getSize().x / 2.f;
	float top = worldView.getCenter().y - worldView.getSize().y / 2.f;
	float bottom = worldView.getCenter().y + worldView.getSize().y / 2.f;

	const float borderDistance = 20.f;

	if (position.x < left + borderDistance) {
		playerFrogger->setPosition(left + borderDistance, position.y);
	}
	else if (position.x > right - borderDistance) {
		playerFrogger->setPosition(right - borderDistance, position.y);
	}
	else if (position.y > bottom - borderDistance) {
		playerFrogger->setPosition(position.x, bottom - borderDistance);
	}
	else if (position.y < top + borderDistance) {
		playerFrogger->setPosition(position.x, top + borderDistance);
	}
}

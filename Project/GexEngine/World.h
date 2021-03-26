
#pragma once

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "CommandQueue.h"
#include "Command.h"
#include "Actor.h"
#include "DataTables.h"
#include "TextNode.h"
#include "SoundPlayer.h"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <array>

namespace sf {
	class RenderTarget;
}

class World : private sf::NonCopyable {

public:
	explicit				World(sf::RenderTarget& window, FontHolder_t& fonts, SoundPlayer& sounds);
	void					update(sf::Time dt);
	void					draw();

	CommandQueue&			getCommands();

	bool					hasAlivePlayer() const;
	bool					hasPlayerReachedEnd() const;

private:
	void					loadTextures();
	void					buildScene();

	void					addEnemies();
	void					handleCollisions();
	bool					matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);
	void					adaptPlayerVelocity();
	void					destroyEntitiesOutsideView();
	void								updateSounds();

	void					updateLivesIndicator(int amount);
	void					buildLivesIndicator(int frogLives);

	void					updateText();

	void					updateNPCSpawnTable(sf::Time dt);

	sf::FloatRect			getViewBounds() const;
	sf::FloatRect			getBattlefieldBounds() const;

	int						getWinningSpotIndexByPosition(sf::FloatRect pos);
	bool					isAllWinningSpotsFilled();

	void adaptPlayerPosition();

private:
	enum Layer
	{
		Background,
		Lives,
		River,
		PlayingLayer,
		LayerCount
	};


private:
	sf::RenderTarget&					target;
	sf::RenderTexture					sceneTexture;
	sf::View							worldView;
	TextureHolder_t						textures;
	const FontHolder_t&					fonts;
	TextNode*							score;
	SoundPlayer&						sounds;

	SceneNode							sceneGraph;
	std::array<SceneNode*, LayerCount>	sceneLayers;
	CommandQueue						commandQueue;

	sf::FloatRect						worldBounds;
	sf::Vector2f						spawnPosition;
	float								scrollSpeed;
	Frogger*							playerFrogger;

	std::vector<NPCSpawnData>			npcSpawnTable;
	std::vector<bool>					winningSpotsFilled;
	std::vector<std::unique_ptr<SpriteNode>>			livesToShow;

};


#include "Actor.h"
#include "Player.h"
#include <algorithm>
#include "CommandQueue.h"
#include "Frogger.h"

Player::Player()
	: currentMissionStatus(MissionStatus::Running)
{
	initializeKeyBindings();
	initializeActions();

	for (auto& pair : actionBindings) {
		pair.second.category = Category::BoxMan;
	}
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		auto found = keyBindings.find(event.key.code);
		if (found != keyBindings.end() && !isRealtimeAction(found->second))
			commands.push(actionBindings[found->second]);
	}
}

void Player::handleRealTimeInput(CommandQueue& commands)
{
	for (auto pair : keyBindings) {

		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(actionBindings[pair.second]);
	}
}

void Player::setMissionStatus(MissionStatus status)
{
	currentMissionStatus = status;
}

Player::MissionStatus Player::getMissionStatus() const
{
	return currentMissionStatus;
}

void Player::initializeKeyBindings() {
	keyBindings[sf::Keyboard::Left] = Action::MoveLeft;
	keyBindings[sf::Keyboard::Right] = Action::MoveRight;
	keyBindings[sf::Keyboard::Up] = Action::MoveUp;
	keyBindings[sf::Keyboard::Down] = Action::MoveDown;
	keyBindings[sf::Keyboard::M] = Action::Jump;

	keyBindings[sf::Keyboard::A] = Action::MoveLeft;
	keyBindings[sf::Keyboard::D] = Action::MoveRight;
	keyBindings[sf::Keyboard::W] = Action::MoveUp;
	keyBindings[sf::Keyboard::S] = Action::MoveDown;
}


void Player::initializeActions()
{	
	const float playerSpeed = 150.f;
	actionBindings[Action::MoveLeft].action = derivedAction<Frogger>(
		[playerSpeed](Frogger& a, sf::Time dt) {
			a.accelerate(sf::Vector2f(-playerSpeed, 0.f));
		});

	actionBindings[Action::Jump].action = derivedAction<Frogger>(
		[playerSpeed](Frogger& a, sf::Time dt) {
			a.jump(0.f,-50.f);
		});

	actionBindings[Action::MoveRight].action = derivedAction<Frogger>(
		[playerSpeed](Frogger& a, sf::Time dt) {
			a.accelerate(sf::Vector2f(playerSpeed, 0.f));
		});

	actionBindings[Action::MoveUp].action = derivedAction<Frogger>(
		[playerSpeed](Frogger& a, sf::Time dt) {
			a.accelerate(sf::Vector2f(0.f, -playerSpeed));
		});

	actionBindings[Action::MoveDown].action = derivedAction<Frogger>(
		[playerSpeed](Frogger& a, sf::Time dt) {
			a.accelerate(sf::Vector2f(0.f, playerSpeed));
		});
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case Action::MoveLeft:
	case Action::MoveRight:
	case Action::MoveDown:
	case Action::MoveUp:
	case Action::Jump:
		return true;
	default:
		return false;
	}
}

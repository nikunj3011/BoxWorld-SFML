#pragma once
#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>

class GameOverState : public State
{
public:

	GameOverState(StateStack& stack, Context context);

	virtual void			draw() override;
	virtual bool			update(sf::Time dt) override;
	virtual bool			handleEvent(const sf::Event& event) override;

private:
	sf::Text				gameOverText;
	sf::Time				elapsedTime;
};


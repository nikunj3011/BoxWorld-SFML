/*
Alena Selezneva
*/

#include "State.h"
#include "World.h"
#include "Player.h"

#include <SFML/Graphics.hpp>


#pragma once
class GameState : public State
{
public:
						GameState(StateStack& stack, Context context);

	virtual void		draw() override;
	virtual bool		update(sf::Time dt) override;
	virtual bool		handleEvent(const sf::Event& event) override;

private:
	World				world;
	Player&				player;

};


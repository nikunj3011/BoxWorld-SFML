#pragma once
#include "SceneNode.h"
#include "SFML/Graphics/Rect.hpp"

class InteractablePlaceHolder : public SceneNode
{
public:
						InteractablePlaceHolder(Category::Type category);
						InteractablePlaceHolder(Category::Type category, sf::FloatRect pos);

	sf::FloatRect		getPosition() const;
	void				setPosition(sf::FloatRect pos);

	sf::FloatRect		getBoundingRect() const;

private:
	sf::FloatRect			position;
};


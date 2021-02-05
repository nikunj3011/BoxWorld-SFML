#include "InteractablePlaceHolder.h"

InteractablePlaceHolder::InteractablePlaceHolder(Category::Type category)
	:SceneNode(category)
{}

InteractablePlaceHolder::InteractablePlaceHolder(Category::Type category, sf::FloatRect pos)
	:SceneNode(category)
	, position(pos)
{
}

sf::FloatRect InteractablePlaceHolder::getPosition() const
{
	return position;
}

void InteractablePlaceHolder::setPosition(sf::FloatRect pos)
{
	position = pos;
}

sf::FloatRect InteractablePlaceHolder::getBoundingRect() const
{
	return position;
}

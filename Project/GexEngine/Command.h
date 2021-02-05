
#include <SFML/System/Time.hpp>
#include <functional>
#include <cassert>
#include "Category.h"

class SceneNode;

#pragma once
struct Command
{
	Command();
	std::function <void (SceneNode&, sf::Time)> action;
	unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
	return [=](SceneNode& node, sf::Time dt)
	{
		fn(static_cast<GameObject&>(node), dt);
	};
}
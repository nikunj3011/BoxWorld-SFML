
#include "Actor.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "JsonFrameParser.h"
#include "Utility.h"
#include "DataTables.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace
{
	const std::map<Actor::Type, ActorData> TABLE = initializeActorData2();
}

Actor::Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts)
	: Entity(100)
	, type_(type)
	, state_(State::Idle)
	, sprite_(textures.get(TABLE.at(type).texture))
	, direction_(Direction::Up)
{
	for (auto a : TABLE.at(type).animations)
	{
		animations_[a.first] = a.second;
	}

	sprite_.setTextureRect(animations_[Actor::State::Idle].getCurrentFrame());
	centerOrigin(sprite_);

}

Actor::Actor(const TextureHolder_t& textures, const FontHolder_t& fonts)
	: Entity(100)
	, type_(Type::Boxman)
{}

unsigned int Actor::getCategory() const
{
	switch (type_)
	{
	case Type::Boxman:
		return Category::BoxMan;
		break;
	case Type::Platform1:
	case Type::Platform2: 
	case Type::Platform3:
		return Category::Platform;
		break;
	case Type::MovingPlatform:
		return Category::MovingPlatform;
		break;
	case Type::Enemy:
	case Type::Fire:
	case Type::Spike:
	case Type::GroundFire:
	case Type::SpikeUp:
		return Category::Enemies;
		break;
	default:
		return Category::None;
	}

	return Category::NPC;
}

sf::FloatRect Actor::getBoundingRect() const
{
	auto box = getWorldTransform().transformRect(sprite_.getGlobalBounds());
	box.width -= 10; // tighten up bounding box for more realistic collisions
	box.left += 5;
	box.top += 5;
	box.height -= 10;
	return box;
}

float Actor::getMaxSpeed() const
{
	//return TABLE.at(type_).speed;
	return 0.f;
}

bool Actor::isMarkedForRemoval() const
{
	return isMarkedForRemoval_; // (state_ == State::Dead && animations_.at(state_).isFinished());
}

void Actor::setMarkedForRemoval(bool b)
{
	isMarkedForRemoval_ = b;
}

void Actor::setState(State state)
{
	state_ = state;
	animations_[state_].restart();
}

Actor::State Actor::getState() const
{
	return state_;
}

void Actor::setDirection(Actor::Direction d)
{
	direction_ = d;
}

Actor::Direction Actor::getDirection() const
{
	return direction_;
}

void Actor::updateStates()
{
	const sf::Time timeToJump = sf::milliseconds(100);
}

void Actor::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	updateStates();

	auto rec = animations_.at(state_).getCurrentFrame();
	if (!(type_ == Type::MovingPlatform || type_ == Type::Platform1))
		rec = animations_.at(state_).update(dt);

	move(velocity * dt.asSeconds());

	sprite_.setTextureRect(rec);
	centerOrigin(sprite_);
}

void Actor::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);
}

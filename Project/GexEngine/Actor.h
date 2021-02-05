
#pragma once

#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Animation.h"
#include "CommandQueue.h"

#include <SFML/Graphics/Sprite.hpp>

class Actor : public Entity
{
public:
    enum class Type {
        Frogger, Car1, Car2, Car3, Truck1, Truck2, Alligator, Turtle2, Turtle3, Log1, Log2, 
        FroggerWinner,
    };

    enum class State {
        IdleLeft,
        IdleRight,
        IdleUp,
        IdleDown,
        JumpLeft,
        JumpRight,
        JumpUp,
        JumpDown,
        Idle,
        Death,
        Respawn,
        count,
        GameOver
    };

    enum class Direction
    {
        Left, Right, Up, Down
    };


public:
    Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts);
    Actor(const TextureHolder_t& textures, const FontHolder_t& fonts);
    ~Actor() = default;

    unsigned int    getCategory() const override;
    sf::FloatRect   getBoundingRect() const override;
    float           getMaxSpeed() const;

    bool            isMarkedForRemoval() const override;
    void            setMarkedForRemoval(bool b);

    void            setState(State state);
    Actor::State    getState() const;

    void            setDirection(Actor::Direction d);
    Actor::Direction getDirection() const;

private:
    void            updateStates();
    void            updateCurrent(sf::Time dt, CommandQueue& commands) override;
    void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
    Type                                type_;
    State                               state_;
    mutable sf::Sprite                  sprite_;
    std::map<Actor::State, Animation>   animations_;
    Direction                           direction_;

    bool                                isMarkedForRemoval_;
};
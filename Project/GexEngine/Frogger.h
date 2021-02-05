#pragma once
#include "Actor.h"

class Frogger : public Actor
{
public:

    enum class Direction
    {
        Left, Right, Up, Down
    };


public:
    Frogger(const TextureHolder_t& textures, const FontHolder_t& fonts);
    ~Frogger() = default;

    unsigned int    getCategory() const override;
    sf::FloatRect   getBoundingRect() const override;
    float           getMaxSpeed() const;

    bool            isMarkedForRemoval() const override;

    void            setHasFroggerFilledSlots();
    bool            hasFroggerFilledSlots() const;

    void            setIsWinningSpotTaken();

    void            setState(State state);
    Frogger::State  getState() const;

    bool            isStruckByCar() const;
    void            setIsStruckByCar(bool b);
    bool            isInRiver() const;
    void            setIsInRiver(bool b);
    bool            isOnSwimmingNPC() const;
    void            setIsOnSwimmingNPC(bool b);

    void            resetPositionFlags();

    void            setStateCountdownToZero();
    sf::Time        getStateCountdown();

    int             getScore();
    void            addScore(int score);

    int             getLivesLeft();
    void            deductLife();

    void            hop(Actor::Direction direction);

    void            respawnFrogger();   

private:
    void            updateStates();
    void            updateCurrent(sf::Time dt, CommandQueue & commands) override;
    void            drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
    Actor::State                        state_;
    mutable sf::Sprite                  sprite_;
    std::map<Actor::State, Animation>   animations_;
    Direction                           direction_;

    std::size_t                         directionIndex_;
    sf::Time                            stateCountdown_;

    sf::Vector2f                        respawnPosition_;
    bool                                isStruckByCar_;
    bool                                isInRiver_;
    bool                                isOnSwimmingNPC_;

    int                                 score_;
    int                                 livesLeft_;
    bool                                isMarkedForRemoval_;
    bool                                hasFroggerFilledSlots_;
    bool                                isWinningSpotTaken_;
};


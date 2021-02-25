
#include "SceneNode.h"

#pragma once
class Entity : public SceneNode
{
public:
	Entity(int hitPoints);
	void			setVelocity(sf::Vector2f v);
	void			setVelocity(float xv, float yv);

	void setBoxVelocity(float xv, float yv);

	void			accelerate(sf::Vector2f v);
	void			accelerate(float xv, float yv);

	void jump(float xv, float yv);

	sf::Vector2f	getVelocity() const;

	int				getHitpoints() const;
	void			repair(int points);
	void			damage(int points);
	void			destroy();
	virtual bool	isDestroyed() const;
	float			gravity = 50;

protected:
	virtual void	updateCurrent(sf::Time dt, CommandQueue& commands) override;

protected:
	sf::Vector2f	velocity;
	int				hitPoints;

};


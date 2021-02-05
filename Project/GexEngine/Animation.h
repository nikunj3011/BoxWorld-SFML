#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

using Frame = sf::IntRect;

class Animation
{
public:
	explicit 				Animation(bool repeat = true);

	void					addFrame(Frame frame);
	void					addFrameSet(std::vector<Frame> frames);
	void 					setDuration(sf::Time duration);
	sf::Time 				getDuration() const;

	void 					setRepeating(bool flag);
	bool 					isRepeating() const;

	void 					restart();
	bool 					isFinished() const;

	Frame					getCurrentFrame() const;

	Frame 					update(sf::Time dt);

private:
	std::vector<Frame>		frames_;
	std::size_t 			currentFrame_;
	sf::Time 				duration_;
	sf::Time 				elapsedTime_;
	bool 					repeat_;
};


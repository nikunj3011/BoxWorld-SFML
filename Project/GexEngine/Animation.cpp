
#include "Animation.h"

Animation::Animation(bool repeat)
	: currentFrame_(0)
	, duration_(sf::Time::Zero)
	, elapsedTime_(sf::Time::Zero)
	, repeat_(repeat)
{}

void Animation::addFrame(Frame frame)
{
	frames_.emplace_back(frame);
}

void Animation::addFrameSet(std::vector<Frame> frames)
{
	frames_ = frames;
}

void Animation::setDuration(sf::Time duration)
{
	duration_ = duration;
}

sf::Time Animation::getDuration() const
{
	return duration_;
}

void Animation::setRepeating(bool flag)
{
	repeat_ = flag;
}

bool Animation::isRepeating() const
{
	return repeat_;
}

void Animation::restart()
{
	currentFrame_ = 0;
}

bool Animation::isFinished() const
{
	return (!repeat_ && currentFrame_ >= frames_.size());
}

Frame Animation::getCurrentFrame() const
{
	return frames_[currentFrame_ >= frames_.size() ? frames_.size() - 1 : currentFrame_];
}

Frame Animation::update(sf::Time dt)
{
	sf::Time timePerFrame = duration_ / static_cast<float>(frames_.size());
	elapsedTime_ += dt;

	// While we have a frame to process
	while (elapsedTime_ >= timePerFrame && (currentFrame_ < frames_.size() || repeat_))
	{
		// And progress to next frame
		elapsedTime_ -= timePerFrame;
		currentFrame_++;
		if (repeat_)
		{
			currentFrame_ %= frames_.size();
		}
	}
	return getCurrentFrame();
}

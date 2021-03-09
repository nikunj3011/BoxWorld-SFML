#pragma once

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>
#include <map>
#include <string>

class MusicPlayer : private sf::NonCopyable
{
public:
					MusicPlayer();
	void			play(MusicID theme);
	void			stop();
	
	void			setPaused(bool paused);
	void			setVolume(float v);

private:
	sf::Music		music;
	std::map<MusicID, std::string>		filenames;
	float			volume;
};


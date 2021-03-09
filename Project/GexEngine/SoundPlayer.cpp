#include "SoundPlayer.h"
#include<SFML/Audio/Listener.hpp>
#include<cmath>

namespace
{
	// Sound coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)
	const float ListenerZ = 300.f;
	const float Attenuation = 8.f;
	const float MinDistance2D = 200.f;
	const float MinDistance3D = std::sqrt(MinDistance2D * MinDistance2D + ListenerZ * ListenerZ);
}

SoundPlayer::SoundPlayer()
	: soundBuffers()
	, sounds()
{
	soundBuffers.load(EffectID::AlliedGunfire, "Media/Sound/AlliedGunfire.wav");
	soundBuffers.load(EffectID::EnemyGunfire, "Media/Sound/EnemyGunfire.wav");
	soundBuffers.load(EffectID::Explosion1, "Media/Sound/Explosion1.wav");
	soundBuffers.load(EffectID::Explosion2, "Media/Sound/Explosion2.wav");
	soundBuffers.load(EffectID::LaunchMissile, "Media/Sound/LaunchMissile.wav");
	soundBuffers.load(EffectID::CollectPickup, "Media/Sound/CollectPickup.wav");
	soundBuffers.load(EffectID::Button, "Media/Sound/Button.wav");
	// Listener points towards the screen (default in SFML)
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}

void SoundPlayer::play(EffectID effect)
{
	play(effect, getLinearPosition());
}

void SoundPlayer::play(EffectID effect, sf::Vector2f position)
{
	sounds.push_back(sf::Sound());
	sf::Sound& sound = sounds.back();
	sound.setBuffer(soundBuffers.get(effect));
	sound.setPosition(position.x, -position.y, 0.f);
	sound.setAttenuation(Attenuation);
	sound.setMinDistance(MinDistance3D);
	sound.play();
}

void SoundPlayer::removeStoppedSounds()
{
	sounds.remove_if([](const sf::Sound& s)
		{
			return s.getStatus() == sf::Sound::Stopped;
		}
	);
}

void SoundPlayer::setListenerPosition(sf::Vector2f p)
{
	sf::Listener::setPosition(p.x, -p.y, ListenerZ);
}

sf::Vector2f SoundPlayer::getLinearPosition() const
{
	auto pos = sf::Listener::getPosition();
	return sf::Vector2f(pos.x, -pos.y);
}

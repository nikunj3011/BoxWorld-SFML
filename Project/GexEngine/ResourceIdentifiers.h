
#pragma once

namespace sf
{
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

enum class EffectID
{
	AlliedGunfire,
	EnemyGunfire,
	Explosion1,
	Explosion2,
	LaunchMissile,
	CollectPickup,
	Button,
};

enum class MusicID
{
	MenuTheme,
	MissionTheme,
};

enum class TextureID
{
	TitleScreen,
	Background,
	BoxWorld,
	Live,

};

enum class FontID {
	Main
};

enum class ShaderID {
	BrightnessPass,
	DownSamplePass,
	GaussianBlurPass,
	AddPass,
};

template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder_t = ResourceHolder<sf::Texture, TextureID>;
using FontHolder_t = ResourceHolder<sf::Font, FontID>;
using ShaderHolder_t = ResourceHolder<sf::Shader, ShaderID>;
using SoundBufferHolder_t = ResourceHolder<sf::SoundBuffer, EffectID>;
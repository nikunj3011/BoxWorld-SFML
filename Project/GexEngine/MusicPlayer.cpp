#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
	: music()
	, filenames()
	, volume(100.f)
{
	filenames[MusicID::MenuTheme] = "Media/Music/MainTheme.ogg";
	filenames[MusicID::MissionTheme] = "Media/Music/MissionTheme.ogg";
}

void MusicPlayer::play(MusicID theme)
{
	auto filename = filenames[theme];

	if (!music.openFromFile(filename))
		throw std::runtime_error("Music " + filename + "could not be found");
	music.setVolume(volume);
	music.setLoop(true);
	music.play();
}

void MusicPlayer::stop()
{
	music.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		music.pause();
	else
		music.pause();
}

void MusicPlayer::setVolume(float v)
{
	volume = v;
}

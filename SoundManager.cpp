#include "SoundManager.h"



SoundManager::SoundManager()
{
	if (music.openFromFile("song1.flac")) std::cout << "Song 1 loaded!" << std::endl;
	music.setVolume(10);
	music.setLoop(true);
	music.play();
	if (buildSoundbuffer[0].loadFromFile("constructionsound1.flac")) std::cout << "Build sound 1 loaded!" << std::endl;
	if (buildSoundbuffer[1].loadFromFile("constructionsound2.flac")) std::cout << "Build sound 2 loaded!" << std::endl;
	if (buildSoundbuffer[2].loadFromFile("constructionsound3.flac")) std::cout << "Build sound 3 loaded!" << std::endl;
	buildSound.setVolume(20);
	buildSound.setRelativeToListener(false);
	buildSound.setMinDistance(100);
	buildSound.setAttenuation(0.01f);
	if(coinSoundbuffer.loadFromFile("coin.wav")) std::cout << "Coin sound loaded!" << std::endl;
	coinSound.setVolume(3);
	coinSound.setRelativeToListener(true);
	coinSound.setBuffer(coinSoundbuffer);
}

SoundManager::SoundManager(const SoundManager &)
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::PlayBuildSound(sf::Vector3f pos)
{
	buildSound.setBuffer(buildSoundbuffer[rand()%3]);
	buildSound.setPosition(pos);
	buildSound.play();
}

void SoundManager::PlayCoinSound()
{
	coinSound.play();
}
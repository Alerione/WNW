#ifndef __WNW_SoundManagerClass_
#define __WNW_SoundManagerClass_

#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
protected:
	sf::Music music;
	sf::Sound buildSound;
	sf::SoundBuffer buildSoundbuffer[3];
	sf::Sound coinSound;
	sf::SoundBuffer coinSoundbuffer;
public:
	SoundManager();
	SoundManager(const SoundManager&);
	~SoundManager();
	void PlayBuildSound(sf::Vector3f);
	void PlayCoinSound();

};

#endif
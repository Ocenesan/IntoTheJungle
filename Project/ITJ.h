#ifndef ITJ_H
#define ITJ_H

#include "Game.h"
#include "Sound.h"
#include "Music.h"
#include "Setting.h"
#include "ITJMainMenu.h"
#include "ITJGameScreen.h"
#include "ITJGameOver.h"

namespace Engine {
	class ITJ :public Engine::Game
	{
	public:
		ITJ(Setting* setting);
		~ITJ();
		virtual void Init();
		virtual void Update();
		virtual void Render();
		Music* music = NULL;
		Sound* sound = NULL;
	private:

	};
}

#endif
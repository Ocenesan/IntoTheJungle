#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include "Screen.h"
#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Button.h"
#include "Text.h"
#include <vector>
#include "ScreenManager.h"
#include "ITJ.h"

namespace Engine {
	class ITJ;
	class VictoryScreen :
		public Engine::Screen
	{
	public:
		VictoryScreen(ITJ* itjInstance);
		void Init();
		void Update();
		void Draw();
	private:
		vector<Button*> buttons;
		Text* victoryText = NULL;
		Sprite* victorySprite = NULL;
		int currentButtonIndex = 0;
		ITJ* itj;
	};
}

#endif

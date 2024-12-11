#ifndef ITJMAINMENU_H
#define ITJMAINMENU_H

#include "Screen.h"
#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Button.h"
#include "Text.h"
#include <vector>
#include "ScreenManager.h"

namespace Engine {
	class ITJMainMenu :
		public Engine::Screen
	{
	public:
		ITJMainMenu();
		~ITJMainMenu();
		void Init();
		void Update();
		void Draw();
	private:
		vector<Button*> buttons;
		Text* text;
		Sprite* backgroundSprite = NULL;
		int currentButtonIndex = 0;
	};
}

#endif
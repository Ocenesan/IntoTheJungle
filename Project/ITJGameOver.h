#ifndef ITJGAMEOVER_H
#define ITJGAMEOVER_H

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
	class ITJGameOver :
		public Engine::Screen
	{
	public:
		ITJGameOver(ITJ* itjInstance);
		void Init();
		void Update();
		void Draw();
	private:
		vector<Button*> buttons;
		Text* gameOverText = NULL;
		int currentButtonIndex = 0;
		ITJ* itj;
	};
}

#endif

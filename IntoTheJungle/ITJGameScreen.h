#ifndef ITJGAMESCREEN_H
#define ITJGAMESCREEN_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include <vector>
#include "Screen.h"
#include "ScreenManager.h"
#include "ITJ.h"

namespace Engine {
	class ITJ;
	class ITJGameScreen : public Screen
	{
	public:
		ITJGameScreen(ITJ* itjInstance);
		//~ITJGameScreen();
		void Init();
		void Update();
		void Draw();
	private:
		ITJ* itj;
		vector<Sprite*> platforms;
		vector<Sprite*> obstacles; // Rintangan pohon
		vector<Sprite*> treasureChests; // Peti harta
		vector<Sprite*> coins;     // Koin
		Sprite* npcSprite = NULL;  // NPC untuk menjual kunci
		Sprite* bjornSprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* treeSprite = NULL;
		Sprite* coin = NULL;
		Sprite* chestSprite = NULL;
		Sprite* coinSprite = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		bool hasKey = false; // Status apakah pemain punya kunci
		int playerHealth = 3;      // Nyawa Bjorn
		int coinCount = 0;         // Jumlah koin terkumpul
		bool isImmune = false; // Status kebal
		float immunityDuration = 2000.0f; // Durasi kebal dalam milidetik
		float immunityTimer = 0.0f; // Timer untuk menghitung sisa waktu kebal
	};
}
#endif
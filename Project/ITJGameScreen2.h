#ifndef ITJGAMESCREEN2_H
#define ITJGAMESCREEN2_H

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
#include <sstream>

namespace Engine {
	class ITJ;
	class ITJGameScreen2 : public Screen
	{
	public:
		ITJGameScreen2(ITJ* itjInstance);
		//~ITJGameScreen2();
		void GenerateTileMap(); // Generate Map
		void ShowTextForDuration(float duration); // Set duration for text
		void SetTeleportDelay(float delay); // Set delay for teleportation
		void UpdateCoinText(); // Coin counter

		void Init();
		void Update();
		void Draw();
	private:
		ITJ* itj;
		vector<Sprite*> platforms;
		vector<Sprite*> walls;
		vector<Sprite*> obstacles; // Rintangan pohon
		vector<Sprite*> treasureChests; // Peti harta
		vector<Sprite*> coins;     // Koin
		vector<Sprite*> hearts;
		Sprite* npcSprite = NULL;  // NPC untuk menjual kunci
		Sprite* bjornSprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* treeSprite = NULL;
		Sprite* coin = NULL;
		Sprite* keySprite = NULL;
		Sprite* heart = NULL;
		Sprite* icon = NULL;
		Music* music = NULL;;
		Sound* sound = NULL; // Jump SFX
		Sound* coinSound = NULL; // Coin SFX
		Sound* keySound = NULL; // Key SFX
		Sound* hurtSound = NULL; // Hurt SFX
		Text* text = NULL;
		Text* coinText = NULL;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		bool hasKey = false; // Status apakah pemain punya kunci
		int playerHealth = 3; // Nyawa Bjorn
		int coinCount = 0; // Jumlah koin terkumpul
		bool isImmune = false; // Status kebal
		float immunityDuration = 2000.0f; // Durasi kebal dalam milidetik
		float immunityTimer = 0.0f; // Timer untuk menghitung sisa waktu kebal
		std::vector<std::vector<int>> tileMap; // 2D array map layout
		const int TILE_SIZE = 32; // Adjust based on sprites
		float textVisibleTime = 0.0f; // Timer text visible
		bool isTextVisible = false;  // Status visibilitas teks
		float teleportDelay; // Delay in teleporting
		float teleportTimer; // Timer to teleport
		bool isTeleporting = false; // Cek teleport
	};
}
#endif
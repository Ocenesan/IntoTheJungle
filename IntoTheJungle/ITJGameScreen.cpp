#include "ITJGameScreen.h"

Engine::ITJGameScreen::ITJGameScreen(ITJ* itjInstance) :itj(itjInstance)
{
	
}

void Engine::ITJGameScreen::GenerateTileMap() {

	// 0 = Empty, 1 = Platform, 2 = Obstacle, 3 = Coin, 4 = Treasure Chest5 = walls

	// 23 Baris & 40 Kolom ini buat Tile Size = 32
	tileMap = {
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 5},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	// Load textures
	Texture* platformTexture = new Texture("Tile_02.png");
	Texture* wallTexture = new Texture("Tile_55.png");
	Texture* treeTexture = new Texture("treeObstacle.png");
	Texture* coinTexture = new Texture("coin.png");
	Texture* chestTexture = new Texture("chest.png");

	// Iterate through the tile map to create sprites
	for (int row = tileMap.size() - 1; row >= 0; --row) { // Start from the bottom row
		for (int col = 0; col < tileMap[row].size(); ++col) {
			int tileType = tileMap[row][col];
			vec2 position(col * 32, (tileMap.size() - row - 1) * 32);

			switch (tileType) {
			case 1: // Platform
			{
				Sprite* platform = new Sprite(platformTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				platform->SetSize(32, 32)->SetPosition(position.x, position.y)->SetBoundingBoxSize(platform->GetScaleWidth() - (50 * platform->GetScale()), platform->GetScaleHeight());
				platforms.push_back(platform);
			}
			break;
			case 2: // Obstacle
			{
				Sprite* obstacle = new Sprite(treeTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				obstacle->SetSize(40, 28)->SetPosition(position.x, position.y)->SetBoundingBoxSize(obstacle->GetScaleWidth() - (50 * obstacle->GetScale()), obstacle->GetScaleHeight());
				obstacles.push_back(obstacle);
			}
			break;
			case 3: // Coin
			{
				Sprite* coin = new Sprite(coinTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				coin->SetSize(40, 10)->SetPosition(position.x, position.y)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(50)->SetScale(3.0f)->AddAnimation("idle", 0, 3);
				coins.push_back(coin);
			}
			break;
			case 4: // Treasure Chest
			{
				Sprite* chest = new Sprite(chestTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				chest->SetSize(128, 32)->SetPosition(position.x, position.y)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(50)->SetScale(3.0f)->AddAnimation("open", 1, 3)
					->AddAnimation("idle", 0, 0);
				treasureChests.push_back(chest);
				chest->PlayAnim("Idle");
			}
			break;
			case 5: //tembok
			{
				Sprite* wall = new Sprite(wallTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				wall->SetSize(32, 32)->SetPosition(position.x, position.y)->SetBoundingBoxSize(wall->GetScaleWidth() - (50 * wall->GetScale()), wall->GetScaleHeight());
				walls.push_back(wall);
			}
			break;
			default:
				// Do nothing for empty tiles
				break;
			}
		}
	}
}

void Engine::ITJGameScreen::ShowTextForDuration(float duration) {
	isTextVisible = true;
	textVisibleTime = duration;
}

//Next Stage
void Engine::ITJGameScreen::SetTeleportDelay(float delay)
{
	teleportDelay = delay;
	teleportTimer = teleportDelay; // Initialize the timer
	isTeleporting = true; // Start the teleportation process
}

//Coin Counter
void Engine::ITJGameScreen::UpdateCoinText()
{
	// Convert coinCount to string
	std::string coinString = std::to_string(coinCount);

	// Set the coin count text
	coinText->SetText("X " + coinString);
}

void Engine::ITJGameScreen::Init() {
	// Generate the tile-based map
	GenerateTileMap();
	
	//Create background
	Texture* bgTexture = new Texture("JungleBg.png");
	backgroundSprite = (new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);

	// character spritesheet has 11 cols and 2 rows (total frames = 11x2 = 22 frames)
	/*Texture* bjornTexture = new Texture("bjornSprite.png");
	bjornSprite = new Sprite(bjornTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	bjornSprite->SetSize(858, 116)->SetPosition(0, 33)->SetNumXFrames(11)->SetNumYFrames(2)->SetAnimationDuration(30)->SetScale(2.0f)->AddAnimation("jump", 9, 10)->AddAnimation("idle", 11, 21)->AddAnimation("run", 0, 7);
	bjornSprite->SetBoundingBoxSize(bjornSprite->GetScaleWidth() - (16 * bjornSprite->GetScale()),
		bjornSprite->GetScaleHeight() - (4 * bjornSprite->GetScale()));*/

	Texture* bjornTexture = new Texture("monster.png");
	bjornSprite = new Sprite(bjornTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	bjornSprite->SetPosition(33, 33)->SetNumXFrames(6)->SetNumYFrames(3)->SetAnimationDuration(70)->SetScale(1.8f)->AddAnimation("attack", 13, 14)->AddAnimation("idle", 0, 3)->AddAnimation("run", 6, 11);
	bjornSprite->SetBoundingBoxSize(bjornSprite->GetScaleWidth() - (16 * bjornSprite->GetScale()),
		bjornSprite->GetScaleHeight() - (4 * bjornSprite->GetScale()));
	
	// NPC kunci
	Texture* npcTexture = new Texture("npc.png");
	npcSprite = new Sprite(npcTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	npcSprite->SetPosition(350, 32)->SetSize(456, 28)->SetNumXFrames(12)->SetNumYFrames(1)->SetAnimationDuration(40)->SetScale(2.0f)->AddAnimation("idle", 0, 11);
	
	//Kunci
	Texture* keyTexture = new Texture("key.png");
	keySprite = new Sprite(keyTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	keySprite->SetPosition(350, 50)->SetSize(48, 8)->SetScale(4.0f)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(10)->SetScale(2.0f)->AddAnimation("pop", 0, 3);

	//Health
	Texture* heartTexture = new Texture("hearts.png");
	for (int i = 0; i < playerHealth; ++i) {
		Sprite* heart = new Sprite(heartTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
		heart->SetPosition(1 + (i * 38), 675)->SetSize(180, 14)->SetScale(2.0f)->SetNumXFrames(10)->SetNumYFrames(1)->SetAnimationDuration(100)->AddAnimation("idle", 0, 5)->AddAnimation("hit", 6, 9);
		hearts.push_back(heart); // Add to the hearts vector
	}

	// Icon Coin
	Texture* iconCoin = new Texture("coin.png");
	icon = new Sprite(iconCoin, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	icon->SetPosition(game->GetSettings()->screenWidth * 0.90, game->GetSettings()->screenHeight * 0.961)->SetSize(40, 10)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(10)->SetScale(3.0f)->AddAnimation("idle", 0, 3);

	// Add input mapping 
	game->GetInputManager()->AddInputMapping("Run Right", SDLK_d)->AddInputMapping("Run Left", SDLK_a)->AddInputMapping("Jump", SDLK_w)->AddInputMapping("Attack", SDLK_f)->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT)->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT)->AddInputMapping("Jump", SDL_CONTROLLER_BUTTON_A)->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X)->AddInputMapping("Quit", SDLK_ESCAPE)->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y);

	// Playing music
	music = (new Music("2021-08-16_-_8_Bit_Adventure_-_www.FesliyanStudios.com.ogg"))->SetVolume(20)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(50);
	coinSound = (new Sound("coin.wav"))->SetVolume(50);
	keySound = (new Sound("power_up.wav"))->SetVolume(50);
	hurtSound = (new Sound("hurt.wav"))->SetVolume(50);

	text = new Text("lucon.ttf", 24, game->GetDefaultTextShader());
	text->SetScale(1.0f)->SetColor(255, 255, 255);

	coinText = new Text("lucon.ttf", 24, game->GetDefaultTextShader());
	coinText->SetText("X 0")->SetScale(1.0f)->SetColor(255, 255, 255);

	// Set debug
	debug = false;
}

void Engine::ITJGameScreen::Update() {
	// If user press "Quit" key then exit
	if (game->GetInputManager()->IsKeyReleased("Quit")) {
		ScreenManager::GetInstance(game)->SetCurrentScreen("itjgameover");
		return;
	}

	//text->SetText("Right-Left-Up to Move and Jump");

	bjornSprite->PlayAnim("idle");
	npcSprite->PlayAnim("idle");
	for (auto& heart : hearts) {
		heart->PlayAnim("idle");
	}

	// Move monster sprite using keyboard
	vec2 oldBjornPos = bjornSprite->GetPosition();
	float x = oldBjornPos.x, y = oldBjornPos.y;
	if (game->GetInputManager()->IsKeyPressed("Run Right")) {
		x += 0.2f * (game->GetGameTime());
		bjornSprite->PlayAnim("run")->SetFlipHorizontal(false);
	}

	if (game->GetInputManager()->IsKeyPressed("Run Left")) {
		x -= 0.2f * (game->GetGameTime());
		bjornSprite->PlayAnim("run")->SetFlipHorizontal(true);
	}

	bjornSprite->SetPosition(x, y);

	for (Sprite* wall : walls) {
		if (wall->GetBoundingBox()->CollideWith(bjornSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldBjornPos.x;
			bjornSprite->SetPosition(x, y);
			break;
		}
	}
	// Obstacle Collision
	for (Sprite* obstacle : obstacles) {
		if (bjornSprite->GetBoundingBox()->CollideWith(obstacle->GetBoundingBox())) {
			//revert x position if collided
			x = oldBjornPos.x;
			bjornSprite->SetPosition(x, y);
			//bjornSprite->PlayAnim("attack");
			if (!isImmune) {
				// Trigger immunity
				playerHealth--;
				hurtSound->Play(false);
				isImmune = true;
				immunityTimer = immunityDuration;
				if (playerHealth > 0) {
					hearts[playerHealth]->PlayAnim("hit"); // Correct index
					hearts.erase(hearts.begin() + playerHealth);
				}
			}

			if (playerHealth <= 0) {
				ScreenManager::GetInstance(game)->SetCurrentScreen("itjgameover");
				return;
			}
		}
	}

	// Immunity Handling
	if (isImmune) {
		immunityTimer -= (game->GetGameTime());

		if (immunityTimer <= 0) {
			isImmune = false; // Reset immunity
		}
	}

	if (game->GetInputManager()->IsKeyPressed("Jump") && !jump) {
		//Set gravity and yVelocity
		float ratio = ((game->GetGameTime()) / 16.7f);
		gravity = 0.16f * ratio;
		yVelocity = 1.8f;
		jump = true;
		sound->Play(false);
	}

	if (y > 0) {
		yVelocity -= gravity;
	}
	else if (y < 0) {
		jump = false;
		yVelocity = 0;
		y = 0;
	}

	y += yVelocity * (game->GetGameTime());
	bjornSprite->SetPosition(x, y);

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(bjornSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldBjornPos.y;
			bjornSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	if (game->GetInputManager()->IsKeyPressed("Attack")) {
		bjornSprite->PlayAnim("attack");
	}

	// Update sprite animation
	bjornSprite->Update(game->GetGameTime());
	npcSprite->Update(game->GetGameTime());

	// Deteksi interaksi dengan NPC untuk membeli kunci
	if (bjornSprite->GetBoundingBox()->CollideWith(npcSprite->GetBoundingBox()) && game->GetInputManager()->IsKeyPressed("Attack")) {
		if (coinCount >= 5) {
			hasKey = true;		// Membeli kunci
			keySprite->SetPosition(-100, -100);
			coinCount -= 5;		// Kurangi jumlah koin
			UpdateCoinText();	// Coin Counter
			keySound->Play(false);	// Suara konfirmasi pembelian
		}
		else if (coinCount < 5 && !hasKey) {
			text->SetText("Koin tidak cukup untuk membeli kunci");
			ShowTextForDuration(2000.0f);
		}
		else if (hasKey) {
			text->SetText("Berhasil mendapatkan kunci!");
			ShowTextForDuration(2000.0f);
		}
	}

	// Deteksi pembukaan peti
	for (Sprite* chest : treasureChests) {
		if (hasKey && game->GetInputManager()->IsKeyReleased("Attack") && bjornSprite->GetBoundingBox()->CollideWith(chest->GetBoundingBox())) {
			// Logika membuka peti
			chest->Update(game->GetGameTime());
			chest->PlayAnim("open");
			// Start teleportation timer
			SetTeleportDelay(20.0f); // Set teleport delay

			// Handle teleportation timer if it's active
			if (isTeleporting)
			{
				teleportTimer -= (game->GetGameTime()); // Decrease the timer by the time passed

				if (teleportTimer <= 0.0f)
				{
					// Teleport the player after the delay
					ScreenManager::GetInstance(game)->SetCurrentScreen("itjgamescreen2");
					isTeleporting = false; // Reset teleporting flag
				}
			}
		}
		if (!hasKey && game->GetInputManager()->IsKeyReleased("Attack") && bjornSprite->GetBoundingBox()->CollideWith(chest->GetBoundingBox())) {
			// Tambahkan logika jika ingin menampilkan notifikasi atau efek
			text->SetText("Belum ada Kunci");
			ShowTextForDuration(2000.0f);
		}
		else {

		}
	}

	// Koleksi koin
	for (size_t i = 0; i < coins.size(); ++i) {
		if (bjornSprite->GetBoundingBox()->CollideWith(coins[i]->GetBoundingBox())) {
			coins.erase(coins.begin() + i); // Hapus koin yang dikumpulkan
			coinCount++;					// Tambah koin terkumpul
			coinSound->Play(false);				// Suara koin
			UpdateCoinText();				// Coin Counter
		}
	}

	if (isTextVisible) {
		textVisibleTime -= (game->GetGameTime());
		if (textVisibleTime <= 0.0f) {
			isTextVisible = false;
		}
	}
}

void Engine::ITJGameScreen::Draw() {
	backgroundSprite->Draw();
	if (isTextVisible) {
		text->SetPosition(game->GetSettings()->screenWidth / 3 - (text->GetFontSize() * text->GetScale()), game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()));
		text->Draw();
	}
	for (Sprite* s : platforms) {
		s->Draw();
	}
	for (Sprite* wall : walls) {
		wall->Draw();
	}
	bjornSprite->Draw();
	
	// Gambar rintangan dan NPC
	for (Sprite* obstacle : obstacles) {
		obstacle->Draw();
	}
	npcSprite->Draw();
	keySprite->Draw();
	icon->Draw();

	coinText->Draw();
	coinText->SetPosition(game->GetSettings()->screenWidth * 0.95 - (text->GetFontSize() * text->GetScale()), game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()));
	//Gambar hati
	for (Sprite* heart : hearts) {
		heart->Update(game->GetGameTime());
		heart->Draw();
	}
	// Gambar peti harta
	for (Sprite* chest : treasureChests) {
		chest->Draw();
	}
	// Gambar koin
	for (Sprite* coin : coins) {
		coin->Draw();
	}

}

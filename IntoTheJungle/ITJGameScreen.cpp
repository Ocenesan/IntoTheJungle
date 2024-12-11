#include "ITJGameScreen.h"

Engine::ITJGameScreen::ITJGameScreen(ITJ* itjInstance) :itj(itjInstance)
{
	
}

//Engine::ITJGameScreen::~ITJGameScreen()
//{
//	delete bjornSprite;
//	delete music;
//	delete text;
//	delete treeSprite;
//	delete coin;
//	delete chestSprite;
//	delete npcSprite;
//	delete coinSprite;
//}

void Engine::ITJGameScreen::Init() {
	// Generate Platforms
	Texture* platformTexture = new Texture("Tile_02.png");
	vec2 start = vec2(200, 90);
	for (int i = 0; i < 8; i++) {
		Sprite* platformSprite = new Sprite(platformTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
		platformSprite->SetSize(100, 32)->SetPosition(start.x + i * 210, start.y + i * 60);
		platformSprite->SetBoundingBoxSize(platformSprite->GetScaleWidth() - (50 * platformSprite->GetScale()), platformSprite->GetScaleHeight());
		platforms.push_back(platformSprite);
	}
	
	//Create background
	Texture* bgTexture = new Texture("JungleBg.png");
	backgroundSprite = (new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);

	// character spritesheet has 11 cols and 2 rows (total frames = 11x2 = 22 frames)
	Texture* bjornTexture = new Texture("bjornSprite.png");
	bjornSprite = new Sprite(bjornTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	bjornSprite->SetSize(858, 116)->SetPosition(0, 0)->SetNumXFrames(11)->SetNumYFrames(2)->SetAnimationDuration(30)->SetScale(2.0f)->AddAnimation("jump", 9, 10)->AddAnimation("idle", 11, 21)->AddAnimation("run", 0, 7);
	bjornSprite->SetBoundingBoxSize(bjornSprite->GetScaleWidth() - (16 * bjornSprite->GetScale()),
		bjornSprite->GetScaleHeight() - (4 * bjornSprite->GetScale()));
	
	// Rintangan pohon
	Texture* treeTexture = new Texture("treeObstacle.png");
	for (int i = 0; i < 5; i++) {
		Sprite* treeSprite = new Sprite(treeTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
		treeSprite->SetSize(40, 28)->SetPosition(start.x + i * 225, start.y + i * 85);
		obstacles.push_back(treeSprite);
	}

	// NPC kunci
	Texture* npcTexture = new Texture("npc.png");
	npcSprite = new Sprite(npcTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	npcSprite->SetPosition(350, 25)->SetSize(456, 28)->SetNumXFrames(12)->SetNumYFrames(1)->SetAnimationDuration(40)->SetScale(2.0f)->AddAnimation("idle", 0, 11);
	
	// Chest
	Texture* chestTexture = new Texture("chest.png");
	for (int i = 0; i < 3; i++) {
		Sprite* chestSprite = new Sprite(chestTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
		chestSprite->SetPosition(200, 25)->SetSize(128, 32)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(10)->SetScale(3.0f)->AddAnimation("idle", 0, 3);
		treasureChests.push_back(chestSprite);
	}

	// Coins
	Texture* coinTexture = new Texture("coin.png");
	for (int i = 0; i < 10; i++) {
		Sprite* coinSprite = new Sprite(coinTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
		coinSprite->SetSize(40, 10)->SetPosition(rand() % game->GetSettings()->screenWidth, rand() % game->GetSettings()->screenHeight / 2)->SetNumXFrames(4)->SetNumYFrames(1)->SetAnimationDuration(10)->SetScale(3.0f)->AddAnimation("idle", 0, 3);
		coins.push_back(coinSprite);
	}

	// Add input mapping 
	game->GetInputManager()->AddInputMapping("Run Right", SDLK_RIGHT)->AddInputMapping("Run Left", SDLK_LEFT)->AddInputMapping("Jump", SDLK_UP)->AddInputMapping("Attack", SDLK_x)->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT)->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT)->AddInputMapping("Jump", SDL_CONTROLLER_BUTTON_A)->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X)->AddInputMapping("Quit", SDLK_ESCAPE)->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y);

	// Playing music
	music = (new Music("2021-08-16_-_8_Bit_Adventure_-_www.FesliyanStudios.com.ogg"))->SetVolume(20)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(50);

	text = new Text("lucon.ttf", 24, game->GetDefaultTextShader());
	text->SetScale(1.0f)->SetColor(255, 255, 255)->SetPosition(0, game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()));

	// Set debug
	debug = false;
}

void Engine::ITJGameScreen::Update() {
	// If user press "Quit" key then exit
	if (game->GetInputManager()->IsKeyReleased("Quit")) {
		dynamic_cast<ITJ*>(game)->SetState(Engine::State::EXIT);
		ScreenManager::GetInstance(game)->SetCurrentScreen("itjgameover");
		return;
	}

	text->SetText("Right-Left-Up to Move and Jump");

	bjornSprite->PlayAnim("idle");
	npcSprite->PlayAnim("idle");

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

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(bjornSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldBjornPos.x;
			bjornSprite->SetPosition(x, y);
			break;
		}
	}
	// Obstacle Collision
	for (Sprite* obstacle : obstacles) {
		if (bjornSprite->GetBoundingBox()->CollideWith(obstacle->GetBoundingBox())) {
			if (!isImmune) {
				// Trigger immunity
				playerHealth--;
				isImmune = true;
				immunityTimer = immunityDuration;
			}

			if (playerHealth <= 0) {
				dynamic_cast<ITJ*>(game)->SetState(Engine::State::EXIT);
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
	if (bjornSprite->GetBoundingBox()->CollideWith(npcSprite->GetBoundingBox()) && game->GetInputManager()->IsKeyReleased("Attack")) {
		if (coinCount >= 5) {
			hasKey = true;       // Membeli kunci
			coinCount -= 5;      // Kurangi jumlah koin
			sound->Play(false);  // Suara konfirmasi pembelian
		}
		else {
			// Tambahkan logika jika ingin menampilkan notifikasi atau efek
			text->SetText("Koin tidak cukup untuk membeli kunci!");
		}
	}

	// Deteksi pembukaan peti
	for (Sprite* chest : treasureChests) {
		if (hasKey && bjornSprite->GetBoundingBox()->CollideWith(chest->GetBoundingBox())) {
			// Logika membuka peti
			chest->SetPosition(-100, -100); // Hilangkan peti dari layar
		}
	}

	// Koleksi koin
	for (size_t i = 0; i < coins.size(); ++i) {
		if (bjornSprite->GetBoundingBox()->CollideWith(coins[i]->GetBoundingBox())) {
			coins.erase(coins.begin() + i); // Hapus koin yang dikumpulkan
			coinCount++;                   // Tambah koin terkumpul
			sound->Play(false);            // Suara koin
		}
	}
}

void Engine::ITJGameScreen::Draw() {
	backgroundSprite->Draw();
	text->Draw();
	for (Sprite* s : platforms) {
		s->Draw();
	}
	bjornSprite->Draw();

	// Gambar rintangan dan NPC
	for (Sprite* obstacle : obstacles) {
		obstacle->Draw();
	}
	npcSprite->Draw();

	// Gambar peti harta
	for (Sprite* chest : treasureChests) {
		chest->Draw();
	}
	// Gambar koin
	for (Sprite* coin : coins) {
		coin->Draw();
	}

}
#include "ITJGameOver.h"

Engine::ITJGameOver::ITJGameOver(ITJ* itjInstance) : itj(itjInstance)
{

}

void Engine::ITJGameOver::Init()
{
	// Create a Texture
	Texture* texture = new Texture("play.png");
	Texture* exitTexture = new Texture("close.png");
	Texture* retryTexture = new Texture("restart.png");

	// Create Sprites
	Sprite* retrySprite = (new Sprite(retryTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	Sprite* mainMenuSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	Sprite* exitSprite = (new Sprite(exitTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	//Create Buttons
	Button* retryButton = new Button(retrySprite, "retry");
	retryButton->SetPosition((game->GetSettings()->screenWidth / 2) - (retrySprite->GetScaleWidth() / 2),
		400);
	buttons.push_back(retryButton);

	Button* mainMenuButton = new Button(mainMenuSprite, "mainmenu");
	mainMenuButton->SetPosition((game->GetSettings()->screenWidth / 2) - (mainMenuSprite->GetScaleWidth() / 2),
		300);
	buttons.push_back(mainMenuButton);

	Button* exitButton = new Button(exitSprite, "exit");
	exitButton->SetPosition((game->GetSettings()->screenWidth / 2) - (exitSprite->GetScaleWidth() / 2),
		200);
	buttons.push_back(exitButton);

	// Set play button into active button
	currentButtonIndex = 0;
	buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);

	// Create Game Over Text
	gameOverText = (new Text("8-bit Arcade In.ttf", 100, game->GetDefaultTextShader()))
		->SetText("Game Over")->SetPosition(game->GetSettings()->screenWidth * 0.5f - 500, game->GetSettings()->screenHeight - 100.0f)->SetColor(235, 229, 52);

	// Add input mappings
	game->GetInputManager()->AddInputMapping("next", SDLK_DOWN)
		->AddInputMapping("prev", SDLK_UP)
		->AddInputMapping("press", SDLK_RETURN);

}


void Engine::ITJGameOver::Update()
{
	// Set background
	game->SetBackgroundColor(52, 155, 235);

	if (game->GetInputManager()->IsKeyReleased("next")) {
		// Set previous button to normal state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
		// Next Button
		currentButtonIndex = (currentButtonIndex < (int)buttons.size() - 1) ? currentButtonIndex + 1 : currentButtonIndex;
		// Set current button to hover state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
	}

	if (game->GetInputManager()->IsKeyReleased("prev")) {
		// Set previous button to normal state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
		// Prev Button
		currentButtonIndex = currentButtonIndex > 0 ? currentButtonIndex - 1 : currentButtonIndex;
		// Set current button to hover state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
	}

	if (game->GetInputManager()->IsKeyReleased("press")) {
		// Set current button to press state
		Button* b = buttons[currentButtonIndex];
		b->SetButtonState(Engine::ButtonState::PRESS);
		// If play button then go to InGame, exit button then exit
		if ("retry" == b->GetButtonName()) {
			ScreenManager::GetInstance(game)->SetCurrentScreen("itj");
		}
		else if ("mainmenu" == b->GetButtonName()) {
			ScreenManager::GetInstance(game)->SetCurrentScreen("mainmenu");
		}
		else if ("exit" == b->GetButtonName()) {
			game->SetState(Engine::State::EXIT);
		}
	}

	// Update All buttons
	for (Button* b : buttons) {
		b->Update(game->GetGameTime());
	}

}

void Engine::ITJGameOver::Draw()
{
	// Render all buttons
	for (Button* b : buttons) {
		b->Draw();
	}
	// Render title 
	gameOverText->Draw();
}
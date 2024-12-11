#include "ITJGameOver.h"

Engine::ITJGameOver::ITJGameOver(ITJ* itjInstance) : itj(itjInstance)
{

}

void Engine::ITJGameOver::Init()
{
	// Create Background
	Texture* bgTexture = new Texture("JungleBg.png"); // Your background image
	backgroundSprite = new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	backgroundSprite->SetSize(game->GetSettings()->screenWidth, game->GetSettings()->screenHeight);
	
	// Create a Texture
	Texture* exitTexture = new Texture("close.png");
	Texture* retryTexture = new Texture("restart.png");

	// Create Sprites
	Sprite* retrySprite = (new Sprite(retryTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	Sprite* exitSprite = (new Sprite(exitTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	//Create Buttons
	Button* retryButton = new Button(retrySprite, "retry");
	retryButton->SetPosition((game->GetSettings()->screenWidth / 2) - (retrySprite->GetScaleWidth() / 2),
		350);
	buttons.push_back(retryButton);

	Button* exitButton = new Button(exitSprite, "exit");
	exitButton->SetPosition((game->GetSettings()->screenWidth / 2) - (retrySprite->GetScaleWidth() / 2),
		100);
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
			ScreenManager::GetInstance(game)->SetCurrentScreen("itjgamescreen");
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
	if (backgroundSprite) {
		backgroundSprite->Draw();
	}

	// Render all buttons
	for (Button* b : buttons) {
		b->Draw();
	}
	// Render title 
	gameOverText->Draw();
}
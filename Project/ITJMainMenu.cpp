#include "ITJMainMenu.h"

Engine::ITJMainMenu::ITJMainMenu()
{
	text = NULL;
	backgroundSprite = NULL;
}

Engine::ITJMainMenu::~ITJMainMenu()
{
	delete backgroundSprite; // Delete the background sprite in the destructor
}

void Engine::ITJMainMenu::Init()
{
	// Create Background
	Texture* bgTexture = new Texture("JungleBg.png"); // Your background image
	backgroundSprite = new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	backgroundSprite->SetSize(game->GetSettings()->screenWidth, game->GetSettings()->screenHeight);
	
	// Create a Texture
	Texture* texture = new Texture("play.png");

	// Create Sprites
	Sprite* playSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()));

	//Create Buttons
	Button* playButton = new Button(playSprite, "play");
	playButton->SetPosition((game->GetSettings()->screenWidth / 2) - (playSprite->GetScaleWidth() / 2), 200);
	buttons.push_back(playButton);

	// Set play button into active button
	currentButtonIndex = 0;
	buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);

	// Create Text
	text = (new Text("8-bit Arcade In.ttf", 100, game->GetDefaultTextShader()))
		->SetText("Into The Jungle")->SetPosition(game->GetSettings()->screenWidth * 0.5f - 500, game->GetSettings()->screenHeight - 100.0f)->SetColor(235, 229, 52);

	// Add input mappings
	game->GetInputManager()->AddInputMapping("next", SDLK_DOWN)
		->AddInputMapping("prev", SDLK_UP)
		->AddInputMapping("press", SDLK_SPACE);

}


void Engine::ITJMainMenu::Update()
{
	cout << currentButtonIndex << endl;
	if (backgroundSprite) {
		backgroundSprite->Update(game->GetGameTime());
	}
	
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
		if ("play" == b->GetButtonName()) {
			//cout << "tes" << endl;
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

void Engine::ITJMainMenu::Draw()
{
	if (backgroundSprite) {
		backgroundSprite->Draw();
	}
	
	// Render all buttons
	for (Button* b : buttons) {
		b->Draw();
	}
	// Render title 
	text->Draw();
}
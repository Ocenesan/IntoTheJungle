#include "ITJ.h"

Engine::ITJ::ITJ(Setting* setting) :Engine::Game(setting)
{
	setting->windowTitle = "Into the Jungle";
}

Engine::ITJ::~ITJ()
{
}

void Engine::ITJ::Init()
{
	Engine::ScreenManager::GetInstance(this)->AddScreen("itjgamescreen", new ITJGameScreen(this))->AddScreen("itjgamescreen2", new ITJGameScreen2(this))
		->AddScreen("itjgamescreen3", new ITJGameScreen3(this))->AddScreen("victoryscreen", new VictoryScreen(this))->AddScreen("itjmainmenu", new ITJMainMenu())->AddScreen("itjgameover", new ITJGameOver(this))->SetCurrentScreen("itjmainmenu");

	music = (new Music("2021-08-16_-_8_Bit_Adventure_-_www.FesliyanStudios.com.ogg"))->SetVolume(40)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(100);
}

void Engine::ITJ::Update()
{
	Engine::ScreenManager::GetInstance(this)->Update();
}

void Engine::ITJ::Render()
{
	Engine::ScreenManager::GetInstance(this)->Draw();
}

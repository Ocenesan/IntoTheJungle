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
	Engine::ScreenManager::GetInstance(this)->AddScreen("itjgamescreen", new ITJGameScreen(this))
		->AddScreen("itjmainmenu", new ITJMainMenu())->AddScreen("itjgameover", new ITJGameOver(this))->SetCurrentScreen("itjmainmenu");
		//->AddScreen("itjpause", new DinoPauseScreen());

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
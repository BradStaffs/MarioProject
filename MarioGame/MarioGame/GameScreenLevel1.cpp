#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenLevel1::~GameScreenLevel1()
{
	m_background_texture = nullptr;
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

void GameScreenLevel1::Render()
{
	//Draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

bool GameScreenLevel1::SetUpLevel()
{
	//Load texture
	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}

}
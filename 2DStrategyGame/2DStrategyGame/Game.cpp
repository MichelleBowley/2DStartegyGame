#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	if (Background)
		{
			delete Background;
			Background = 0;
		}

	if (dx)
	{
		delete dx;
		dx = 0;
	}
}

bool
Game::Initialise(HWND hWindow)
{
	dx = new DirectX; //Creates a new directx pointer

	if (!dx->InitDx(hWindow, screenWidth, screenHeight, m_fullscreen)) //Initialises directx and height and width and weather its fullscreen
	{
		return false;
	}

	Background = new GameObject(0, 0, 0, 0, 0, 0);//This creates a new object for the tile, i think i need to dulicate this every loop
	if (!Background->Initialize(dx->d3d9_Device, "Sprites\\Grass.png", sWidth, sHeight)) //This one just loads up the sprite from file using direct x
	{
		return false; //returns false if load failed
	}

	gameTime = new Timer;
	if (!gameTime->Initialise())
	{
		return false;
	}
	m_running = true;
	return true;
}

void
Game::Run()
{
	gameTime->Update();

	Update(gameTime->elapsedTime);
	Draw(gameTime->elapsedTime);
}

void
Game::Draw(float gameTime)
{
	dx->Clear(D3DCOLOR_XRGB(0, 100, 100));
	dx->Begin();

	Background->Draw(gameTime);

	dx->End();
	dx->PresentBB();
}

void
Game::Update(float gameTime)
{
	Background->Update(gameTime);
}
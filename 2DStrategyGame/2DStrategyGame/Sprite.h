#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <d3dx9.h>
#pragma comment (lib,"d3dx9.lib")
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	//Sprite(float x, float y); //Constructor with x and y co-ords
	~Sprite();

	bool InitSprite(LPDIRECT3DDEVICE9 d3d9_Device, string filename, int width, int height); //Initialise the sprite. 

																							//virtual void Update(float gameTime); //Virtual void to be overridden in game update method
	virtual void Draw(float gameTime, D3DXVECTOR3 position); //virtual void to be overridden in game Draw method


															 //D3DXVECTOR3 vector;


private:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	//D3DXVECTOR3 position;
	D3DCOLOR colour;
	bool Initialised;

};

#endif //!_SPRITE_H_
#pragma once
#pragma once

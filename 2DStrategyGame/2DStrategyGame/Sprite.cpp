#include "Sprite.h"

Sprite::Sprite()
{
	//when colour is set to white is exactly what the image looks like
	colour = D3DCOLOR_ARGB(255, 255, 255, 255); //white and visable
	Initialised = false;
}

Sprite::~Sprite()
{
}

bool
Sprite::InitSprite(LPDIRECT3DDEVICE9 d3d9_Device, string filename, int width, int height) //The direct device, name of the file where the sprite is, width and height of the sprite added manually
{
#define COLOR_ARGB DWORD
	const COLOR_ARGB transcolour = D3DCOLOR_ARGB(255, 255, 0, 255);

	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(d3d9_Device, filename.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, transcolour, NULL, NULL, &texture)))
	{
		MessageBox(NULL, "There was a problem with your texture", NULL, NULL);
		return false;
	}

	if (!SUCCEEDED(D3DXCreateSprite(d3d9_Device, &sprite)))
	{
		MessageBox(NULL, "There was a problem with the sprite", NULL, NULL);
		return false;
	}

	Initialised = true;
	return true;
}

void
Sprite::Draw(float gameTime, D3DXVECTOR3 position)
{
	if (sprite && texture)
	{
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		sprite->Draw(texture, NULL, NULL, &position, colour);
		sprite->End();
	}
}
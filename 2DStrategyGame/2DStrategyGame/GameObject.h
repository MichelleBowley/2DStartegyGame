#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "Sprite.h"
#include <string>

enum class ObjectStatus { Active, Dying, Dead };

class GameObject
{
public:
	GameObject(float x, float y, float rotation, float velocityY, float velocityX, float maxSpeed);
	~GameObject();

	virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height);
	virtual void Update(float gameTime);
	virtual void Draw(float gameTime);

	ObjectStatus GetStatus() const;

	void SetSpeed(float speed);


protected:
	std::string Name;
	std::string Description;

	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
	float rotation;
	float speed;


private:
	ObjectStatus status;
	Sprite *sprite;
	float maxSpeed;

	int screenWidth = GetSystemMetrics(SM_CXSCREEN); //Gets the width of the current monitor being used
	int screenHeight = GetSystemMetrics(SM_CYSCREEN); //Gets the height of the current monitor being used
	int sWidth = screenWidth - 150;
	int sHeight = screenHeight - 150;
};


#endif //¬!_GAMEOBJECT_H#pragma once#pragma once

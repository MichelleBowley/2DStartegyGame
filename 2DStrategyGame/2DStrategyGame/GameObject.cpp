#include "GameObject.h"

GameObject::GameObject(float x, float y, float rotation, float velocityY, float velocityX, float maxSpeed)
{
	float twopi = (float)(M_PI * 2);
	position.x = x;
	position.y = y;
	position.z = 0;

	if (rotation > twopi) rotation = twopi;
	if (rotation < 0) rotation = 0;

	if (speed > maxSpeed) speed = maxSpeed;
	if (speed < 0) speed = 0;

	this->rotation = rotation;
	this->speed = speed;

	velocity.x = cos(rotation) * velocityX;
	velocity.y = sin(rotation) * velocityY;
	velocity.z = 0;

	this->maxSpeed = maxSpeed;
}

GameObject::~GameObject()
{
	if (sprite)
	{
		delete sprite;
		sprite = 0;
	}
}

bool
GameObject::Initialize(LPDIRECT3DDEVICE9 device, std::string file, int width, int height)
{
	status = ObjectStatus::Active;

	if (!sprite)
	{
		sprite = new Sprite();
		if (!sprite->InitSprite(device, file, width, height))
		{
			return false;
		}
	}
	return true;
}

void
GameObject::Update(float gameTime)
{
	if (status == ObjectStatus::Active)
	{
		position.x += velocity.x;// *gameTime;
		position.y += velocity.y;// *gameTime;
		position.z = 0;

		if (position.x < 0 || position.x > sWidth - 45) //Sprites origin is in the top left hand corner. Maybe move to the middle
		{
			velocity.x = -velocity.x;
		}

		if (position.y < 0 || position.y > sHeight - 70)
		{
			velocity.y = -velocity.y;
		}
	}
}

void
GameObject::Draw(float gameTime)
{
	if (sprite) sprite->Draw(gameTime, position);
}

ObjectStatus
GameObject::GetStatus() const
{
	return status;
}

void
GameObject::SetSpeed(float speed)
{
	if (speed >= 0 && speed <= maxSpeed)
	{
		this->speed = speed;
		velocity.x = cos(rotation) * speed;
		velocity.y = sin(rotation) * speed;
		velocity.x = 0;
	}
}
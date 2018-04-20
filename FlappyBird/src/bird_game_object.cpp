#include "bird_game_object.h"
#include <glm/glm.hpp>
#include "globals.h"

BirdGameObject::BirdGameObject(glm::vec2 position,
	float rotInDegrees,
	glm::vec2 velocity,
	float acceleration,
	Animation* animation) : mAcceleration(acceleration), GameObject(position, rotInDegrees, velocity, animation) {}

BirdGameObject::~BirdGameObject() {}

void BirdGameObject::UpdatePosition(float dt)
{
	mVelocity.y += mAcceleration * dt;
	mPosition.x += mVelocity.x * dt;
	mPosition.y += mVelocity.y * dt;

	if (mJumpPressed)
	{
		mVelocity.y += 300.0f * SCREEN_SCALING;
		mJumpPressed = false;
	}

	mVelocity.y = glm::clamp(mVelocity.y, -166.0f * SCREEN_SCALING, 133.0f * SCREEN_SCALING);
	mRotInDegrees = mVelocity.y * 90.0f / (166.0f * SCREEN_SCALING);
	mRotInDegrees = glm::clamp(mRotInDegrees, -90.0f, 30.0f);

}
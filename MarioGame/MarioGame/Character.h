#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "constants.h"
#include "Texture2D.h"
#include "LevelMap.h"

using namespace std;

class Texture2D;

class Character
{

protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_moving_right;
	bool m_moving_left;
	float m_movementspeed;

	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;

	virtual void MoveLeft(float deltaTime, float speed);
	virtual void MoveRight(float deltaTime, float speed);
	virtual void AddGravity(float deltaTime);
	virtual void Jump();

	float m_collision_radius;

	bool m_alive;

public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	~Character();

	virtual void Render(SDL_Rect camera_rect);
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();

	float GetCollisionRadius();
	inline Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }

	inline bool IsJumping() { return m_jumping; }
	inline void CancelJump() { m_jumping = false; }

	void SetAlive(bool IsAlive);
	inline bool GetAlive() { return m_alive; }

private:
	FACING m_facing_direction;

	LevelMap* m_current_level_map;
};

#endif
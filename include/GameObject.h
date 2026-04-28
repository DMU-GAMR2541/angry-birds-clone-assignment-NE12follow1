#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <string>

class GameObject {
protected:
	float f_xPos = 0.0f;
	float f_yPos = 0.0f;
	b2Vec2 v_Pos = b2Vec2(f_xPos, f_yPos);
	std::string str_spriteLocation;

public:

	virtual void loadSprite() = 0;

	virtual void render() = 0;


};
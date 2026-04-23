#pragma once
#include <box2d/box2d.h>

class GameObject {
protected:
	float f_xPos;
	float f_yPos;
	b2Vec2 v_Pos;

public:

	virtual void render() = 0;


};
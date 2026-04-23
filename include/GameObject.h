#pragma once
#include <box2d/box2d.h>

class GameObject {
protected:
	float f_xPos = 0.0f;
	float f_yPos = 0.0f;
	b2Vec2 v_Pos = b2Vec2(f_xPos, f_yPos);

public:

	virtual void render() = 0;


};
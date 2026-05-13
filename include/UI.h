#pragma once
#include "StaticObject.h"
#include "DynamicObject.h"

class UI : public StaticObject, public DynamicObject {
private:
    b2CircleShape b2_dynamicCircle;
public:
	UI() = default;
	~UI() {}

    void setupB2d(b2World& b2_world) override {
        b2_bodyDef.type = b2_dynamicBody;
        b2_bodyDef.position = b2_pos;

        b2_body = b2_world.CreateBody(&b2_bodyDef);

        b2_fixtureDef.shape = &b2_dynamicCircle;
        b2_fixtureDef.density = 1.0f;
        b2_fixtureDef.friction = 0.3f;
        b2_fixtureDef.restitution = 0.5f;

        b2_body->CreateFixture(&b2_fixtureDef);
    }
};
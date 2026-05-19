#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
private:
	float f_speed;
	float f_mass;
	std::string str_type;
	b2CircleShape b2_dynamicCircle;

public:
	Bird() = default;
	Bird(std::string str_type, float f_posX, float f_posY) {
		this->str_type = str_type;
		this->f_xPos = f_posX;
		this->f_yPos = f_posY;
		this->b2_pos = b2Vec2(f_posX, f_posY);

		if (str_type == "red") {
			str_spriteLocation = "../assets/Ang_Birds/Red.png";
			rect_spriteRect = sf::IntRect(0, 0, 951, 876);
			this->f_spriteScale = 0.05;
			this->f_speed = 10;
			this->f_mass = 10;
			this->vec_texSize = b2Vec2(951, 876);
			this->b2_dynamicCircle.m_radius = 438 * f_spriteScale / 30;
		}
		else if (str_type == "yellow") {
			str_spriteLocation = "../assets/Ang_Birds/Yellow.png";
			rect_spriteRect = sf::IntRect(0, 0, 1045, 955);
			this->f_spriteScale = 0.05;
			this->f_speed = 30;
			this->f_mass = 7;
			this->vec_texSize = b2Vec2(1045, 955);
			this->b2_dynamicCircle.m_radius = 477 * f_spriteScale / 30;
		}
		else if (str_type == "blue") {
			str_spriteLocation = "../assets/Ang_Birds/Blue.png";
			rect_spriteRect = sf::IntRect(0, 0, 1024, 1024);
			this->f_spriteScale = 0.035;
			this->f_speed = 10;
			this->f_mass = 5;
			this->vec_texSize = b2Vec2(1024, 1024);
			this->b2_dynamicCircle.m_radius = 512 * f_spriteScale / 30;
		}
	}

	~Bird() {}

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

	b2Body* GetBody() {
		return b2_body;
	}

	float GetSpeed() {
		return f_speed;
	}

	void SetSpeed(float speed) {
		f_speed = speed;
	}

	float GetMass() {
		return f_mass;
	}

	void SetMass(float mass) {
		f_mass = mass;
	}

	std::string GetType() {
		return str_type;
	}

	void SetType(std::string type) {
		str_type = type;
	}
};
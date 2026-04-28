#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
private:
	float f_speed;
	float f_mass;
	std::string str_type;

public:
	Bird() = default;
	Bird(std::string str_type, std::string str_spriteLocation, float f_speed, float f_mass) {
		this->str_type = str_type;
		this->str_spriteLocation = str_spriteLocation;
		this->f_speed = f_speed;
		this->f_mass = f_mass;
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
#pragma once
#include "DynamicObject.h"

class Bird : public DynamicObject {
private:
	float f_speed;
	float f_mass;
	std::string s_type;

public:
	Bird() = default;
	Bird(std::string s_type, float f_speed, float f_mass) {
		this->s_type = s_type;
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
		return s_type;
	}

	void SetType(std::string type) {
		s_type = type;
	}
};
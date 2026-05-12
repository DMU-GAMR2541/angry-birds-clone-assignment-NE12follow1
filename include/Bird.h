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
	Bird(std::string str_type, float f_speed, float f_mass) {
		this->str_type = str_type;
		this->f_speed = f_speed;
		this->f_mass = f_mass;

		if (str_type == "red") {
			str_spriteLocation = "../assets/Ang_Birds/Red.png";
			rect_spriteRect = sf::IntRect(0, 0, 951, 876);
			this->f_spriteScaleX = 0.075;
			this->f_spriteScaleY = 0.075;
		}
		else if (str_type == "yellow") {
			str_spriteLocation = "../assets/Ang_Birds/Yellow.png";
			rect_spriteRect = sf::IntRect(0, 0, 1045, 955);
			this->f_spriteScaleX = 0.075;
			this->f_spriteScaleY = 0.075;
		}
		else if (str_type == "blue") {
			str_spriteLocation = "../assets/Ang_Birds/Blue.png";
			rect_spriteRect = sf::IntRect(0, 0, 1024, 1024);
			this->f_spriteScaleX = 0.05;
			this->f_spriteScaleY = 0.05;
		}
	}

	~Bird() {}

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
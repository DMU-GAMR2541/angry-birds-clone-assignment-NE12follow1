#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject {
protected:
	sf::Sprite sp_rendered;
	sf::Texture sf_tex;
	sf::IntRect rect_spriteRect;
	b2BodyDef b2_bodyDef;
	b2FixtureDef b2_fixtureDef;
	b2Body* b2_body;

public:
	void loadSprite() override {
		if (!sf_tex.loadFromFile(str_spriteLocation)) {
			std::cout << "Failed to load texture: " << str_spriteLocation << std::endl;
		}

		sp_rendered = sf::Sprite(sf_tex, rect_spriteRect);

		sp_rendered.setOrigin(sf_tex.getSize().x / 2.0f, sf_tex.getSize().y / 2.0f);
	}

	void render(sf::RenderWindow& sf_window) override {
		sf_window.draw(sp_rendered);
	}
};
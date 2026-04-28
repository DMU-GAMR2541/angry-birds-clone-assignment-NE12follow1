#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject {
protected:
	sf::Sprite sp_rendered;
	sf::Texture sf_tex;
	sf::RenderWindow sf_window;

public:
	void loadSprite() override {
		if (!sf_tex.loadFromFile(str_spriteLocation)) {
			std::cout << "Failed to load texture: " << str_spriteLocation << std::endl;
		}

		sp_rendered.setTexture(sf_tex);

		sp_rendered.setOrigin(sf_tex.getSize().x / 2.0f, sf_tex.getSize().y / 2.0f);
	}

	void render() override {
		sf_window.draw(sp_rendered);
	}
};
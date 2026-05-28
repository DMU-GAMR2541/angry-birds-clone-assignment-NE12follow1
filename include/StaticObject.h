#pragma once
#include "GameObject.h"

class StaticObject : public virtual GameObject {
protected:
	
public:
	virtual bool loadSprite() override {
		if (!sf_tex.loadFromFile(str_spriteLocation)) {
			std::cout << "Failed to load texture: " << str_spriteLocation << std::endl;
			return false;
		}
		else {
			return true;
		}


		sp_rendered = sf::Sprite(sf_tex, rect_spriteRect);
		sp_rendered.scale(f_spriteScale, f_spriteScale);
		std::cout << sf_tex.getSize().x << " " << sf_tex.getSize().y << std::endl;

		sp_rendered.setOrigin(sf_tex.getSize().x / 2.0f, sf_tex.getSize().y / 2.0f);
		sp_rendered.move(sf_tex.getSize().x * f_spriteScale / 2.0f, sf_tex.getSize().y * f_spriteScale / 2.0f);
	}

	virtual void render(sf::RenderWindow& sf_window) override {
		sf_window.draw(sp_rendered);
	}

	virtual void updateVisual(float SCALE, float PI) override {
		sp_rendered.setPosition(b2_body->GetPosition().x * SCALE, b2_body->GetPosition().y * SCALE);
		sp_rendered.move(sf_tex.getSize().x * f_spriteScale / 2.0f, sf_tex.getSize().y * f_spriteScale / 2.0f);
		sp_rendered.setRotation(b2_body->GetAngle() * (180.0f / PI));
	}
};
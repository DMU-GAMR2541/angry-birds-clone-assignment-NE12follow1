#pragma once
#include "GameObject.h"

class DynamicObject : public virtual GameObject {
protected:
	b2Vec2 vec_texSize;
public:
	virtual void loadSprite() override {
		if (!sf_tex.loadFromFile(str_spriteLocation)) {
			std::cout << "Failed to load texture: " << str_spriteLocation << std::endl;
		}

		sp_rendered = sf::Sprite(sf_tex, rect_spriteRect);
		sp_rendered.setOrigin(vec_texSize.x * f_spriteScaleX / 2.0f, vec_texSize.y * f_spriteScaleY / 2.0f);
		sp_rendered.scale(f_spriteScaleX, f_spriteScaleY);
	}

	virtual void render(sf::RenderWindow& sf_window) override {
		sf_window.draw(sp_rendered);
	}

	virtual void updateVisual(float SCALE, float PI) override {
		sp_rendered.setPosition(b2_body->GetPosition().x * SCALE, b2_body->GetPosition().y * SCALE);
		sp_rendered.setRotation(b2_body->GetAngle() * (180.0f / PI));
	}

	virtual void setupB2d(b2World &b2_world) = 0;
};
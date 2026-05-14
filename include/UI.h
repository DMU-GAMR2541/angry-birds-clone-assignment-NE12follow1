#pragma once
#include "StaticObject.h"
#include "DynamicObject.h"

class UI : public virtual StaticObject, public virtual DynamicObject {
private:
    b2CircleShape b2_dynamicCircle;
public:
	UI() = default;
	~UI() {}

    void loadSprite() override {
        if (!sf_tex.loadFromFile(str_spriteLocation)) {
            std::cout << "Failed to load texture: " << str_spriteLocation << std::endl;
        }

        sp_rendered = sf::Sprite(sf_tex, rect_spriteRect);
        sp_rendered.scale(f_spriteScaleX, f_spriteScaleY);
        std::cout << sf_tex.getSize().x << " " << sf_tex.getSize().y << std::endl;

        sp_rendered.setOrigin(sf_tex.getSize().x / 2.0f, sf_tex.getSize().y / 2.0f);
        sp_rendered.move(sf_tex.getSize().x * f_spriteScaleX / 2.0f, sf_tex.getSize().y * f_spriteScaleY / 2.0f);
    }

    void render(sf::RenderWindow& sf_window) override {
        sf_window.draw(sp_rendered);
    }

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

    virtual void updateVisual(float SCALE, float PI) override {
        sp_rendered.setPosition(b2_body->GetPosition().x * SCALE, b2_body->GetPosition().y * SCALE);
        sp_rendered.move(sf_tex.getSize().x * f_spriteScaleX / 2.0f, sf_tex.getSize().y * f_spriteScaleY / 2.0f);
        sp_rendered.setRotation(b2_body->GetAngle() * (180.0f / PI));
    }
};
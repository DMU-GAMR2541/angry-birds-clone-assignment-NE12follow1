#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <string>

class GameObject {
protected:
	float f_xPos = 0.0f;
	float f_yPos = 0.0f;
	b2Vec2 b2_pos = b2Vec2(f_xPos, f_yPos);
	std::string str_spriteLocation;
	sf::RenderWindow sf_window;
	sf::Sprite sp_rendered;
	sf::Texture sf_tex;
	sf::IntRect rect_spriteRect;
	float f_spriteScaleX;
	float f_spriteScaleY;

public:

	virtual void loadSprite() = 0;

	virtual void render(sf::RenderWindow& sf_window) = 0;


};
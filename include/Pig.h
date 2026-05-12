#pragma once
#include <iostream>
#include "DynamicObject.h"

class Pig : public DynamicObject {
/// <summary>
/// Varaibles that define an enemy.
/// </summary>
private:
    int i_maxHealth;
    int i_health;
    bool b_isDestroyed;
    std::string str_enemyType = "pig";
    int i_healthThreashold;
    b2CircleShape b2_dynamicCircle;

public:
    //Default constructor for an enemy. 
    Pig() = default;
    Pig(std::string str_enemyType, int i_initialHealth, float f_posX, float f_posY) {
        this->str_enemyType = str_enemyType;
        this->i_maxHealth = i_initialHealth;
        this->i_health = i_maxHealth;
        this->i_healthThreashold = 1;
        this->b_isDestroyed = false;
        this->f_xPos = f_posX;
        this->f_yPos = f_posY;
        this->v_Pos = b2Vec2(f_posX, f_posY);

        if (str_enemyType == "pig") {
            str_spriteLocation = "../assets/Ang_Birds/Pig.png";
            rect_spriteRect = sf::IntRect(0, 0, 433, 427);
            this->f_spriteScaleX = 0.25;
            this->f_spriteScaleY = 0.25;
        }
        else if (str_enemyType == "armoured") {
            str_spriteLocation = "../assets/Ang_Birds/sprite_3.png";
            rect_spriteRect = sf::IntRect(0, 0, 105, 91);
        }
        else if (str_enemyType == "baron") {
            str_spriteLocation = "../assets/Ang_Birds/sprite_5.png";
            rect_spriteRect = sf::IntRect(0, 0, 120, 109);
        }
    }

    ~Pig() {}

    //Class functions to be tested.
    void takeDamage(int damage) {
        if (damage < 0) return;
            i_health -= damage;
        if (i_health <= 0) {
            i_health = 0;
            b_isDestroyed = true;
        }
        /*else if ((i_health / i_maxHealth) >= 0.5) {
            i_healthThreashold = 2;
        }
        else {
            i_healthThreashold = 3;
        }*/
    }

    int getHealth() const { 
        return i_health; 
    }

    void setHealth(int health) {
        i_health = health;
    }

    std::string getType() {
        return str_enemyType;
    }

    void setType(std::string type) {
        str_enemyType = type;
    }

    bool checkIfPopped() const {
        return b_isDestroyed;
    }

    b2Vec2 getPos() {
        std::cout << "X: " << f_xPos << " Y: " << f_yPos;
        return v_Pos;
    }

    void setPos(b2Vec2 newPos) {
        v_Pos = newPos;
    }

    float getXPos() {
        return f_xPos;
    }

    void setXPos(float xPos) {
        f_xPos = xPos;
    }

    float getYPos() {
        return f_yPos;
    }

    void setYPos(float yPos) {
        f_yPos = yPos;
    }

};
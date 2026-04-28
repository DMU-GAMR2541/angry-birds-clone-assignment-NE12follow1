#pragma once
#include <iostream>
#include "DynamicObject.h"

class Enemy : public DynamicObject {
/// <summary>
/// Varaibles that define an enemy.
/// </summary>
private:
    int i_health;
    bool b_isDestroyed;
    std::string str_enemyType = "swine";
    int i_enemySubtype;

public:
    //Default constructor for an enemy. 
    Enemy() = default;
    Enemy(std::string str_enemyType, int i_enemySubtype, int i_initialHealth, float x, float y) {
        this->str_enemyType = str_enemyType;
        this->i_enemySubtype = i_enemySubtype;
        this->i_health = i_initialHealth;
        this->b_isDestroyed = false;
        this->f_xPos = x;
        this->f_yPos = y;
        this->v_Pos = b2Vec2(x, y);

        if (str_enemyType == "swine") {
            str_spriteLocation = "assets/Ang_Birds/sprite_2.png";
        }
        else if (str_enemyType == "armoured") {
            str_spriteLocation = "assets/Ang_Birds/sprite_3.png";
        }
    }

    //Class functions to be tested.
    void takeDamage(int damage) {
        if (damage < 0) return;
            i_health -= damage;
        if (i_health <= 0) {
            i_health = 0;
            b_isDestroyed = true;
        }
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
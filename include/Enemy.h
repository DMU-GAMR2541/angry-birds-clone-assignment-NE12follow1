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
    float f_xPos = 0;
    float f_yPos = 0;
    std::string s_enemyType = "swine";

public:
    //Default constructor for an enemy. 
    Enemy() = default;
    Enemy(int i_initialHealth, float x, float y) : i_health(i_initialHealth), b_isDestroyed(false), f_xPos(x), f_yPos(y) {}

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

    void getPos() {
        std::cout << "X: " << f_xPos << " Y: " << f_yPos;
    }

    float getXPos() {
        return f_xPos;
    }

    float getYPos() {
        return f_yPos;
    }

    std::string getType() {
        return s_enemyType;
    }

    bool checkIfPopped() const { 
        return b_isDestroyed; 
    }

    void setHealth(int health) {
        i_health = health;
    }

    void setType(std::string type) {
        s_enemyType = type;
    }
};
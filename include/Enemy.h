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
    std::string s_enemyType = "swine";

public:
    //Default constructor for an enemy. 
    Enemy() = default;
    Enemy(int i_initialHealth, float x, float y) {
        this->i_health = i_initialHealth;
        this->b_isDestroyed = false;
        this->f_xPos = x;
        this->f_yPos = y;
        this->v_Pos = b2Vec2(x, y);
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

    b2Vec2 getPos() {
        std::cout << "X: " << f_xPos << " Y: " << f_yPos;
        return v_Pos;
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
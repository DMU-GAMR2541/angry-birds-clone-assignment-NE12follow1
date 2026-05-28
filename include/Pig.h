#pragma once
#include "DynamicObject.h"

class Pig : public DynamicObject {
/// <summary>
/// Varaibles that define an enemy.
/// </summary>
private:
    int i_maxHealth;
    int i_health;
    bool b_isDestroyed;
    //int i_healthThreashold;
    b2CircleShape b2_dynamicCircle;
    std::string str_type;
public:
    enum Type {
        PIG,
        ARMOURED,
        BARON
    };
    //Default constructor for an enemy. 
    Pig() = default;
    Pig(std::string str_enemyType, float f_posX, float f_posY) {
        this->str_type = str_enemyType;
        //this->i_healthThreashold = 1;
        this->b_isDestroyed = false;
        this->f_xPos = f_posX;
        this->f_yPos = f_posY;
        this->b2_pos = b2Vec2(f_posX, f_posY);

        if (str_enemyType == "pig") {
            str_spriteLocation = "../assets/Ang_Birds/Pig.png";
            rect_spriteRect = sf::IntRect(0, 0, 433, 427);
            this->f_spriteScale = 0.125;
            this->i_maxHealth = 100;
            this->vec_texSize = b2Vec2(433, 427);
            b2_dynamicCircle.m_radius = 208 * f_spriteScale / 30;
        }
        else if (str_enemyType == "armoured") {
            str_spriteLocation = "../assets/Ang_Birds/Armoured.png";
            rect_spriteRect = sf::IntRect(0, 0, 93, 85);
            this->f_spriteScale = 1;
            this->i_maxHealth = 150;
            this->vec_texSize = b2Vec2(93, 85);
            b2_dynamicCircle.m_radius = 42 * f_spriteScale / 30;
        }
        else if (str_enemyType == "baron") {
            str_spriteLocation = "../assets/Ang_Birds/Baron.png";
            rect_spriteRect = sf::IntRect(0, 0, 112, 99);
            this->f_spriteScale = 1;
            this->i_maxHealth = 180;
            this->vec_texSize = b2Vec2(112, 99);
            b2_dynamicCircle.m_radius = 49 * f_spriteScale / 30;
        }

        this->i_health = i_maxHealth;
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

    void setupB2d(b2World &b2_world) override {
        b2_bodyDef.type = b2_dynamicBody;
        b2_bodyDef.position.Set(b2_pos.x, b2_pos.y);

        b2_body = b2_world.CreateBody(&b2_bodyDef);

        b2_fixtureDef.shape = &b2_dynamicCircle;
        b2_fixtureDef.density = 1.0f;
        b2_fixtureDef.friction = 0.3f;
        b2_fixtureDef.restitution = 0.5f;

        b2_body->CreateFixture(&b2_fixtureDef);

        //b2_body->SetUserData(this);
    }

    int getHealth() const { 
        return i_health; 
    }

    void setHealth(int health) {
        i_health = health;
    }

    std::string getType() {
        return str_type;
    }

    void setType(std::string type) {
        str_type = type;
    }

    bool checkIfPopped() const {
        return b_isDestroyed;
    }

    b2Vec2 getPos() {
        return b2_pos;
    }

    void setPos(b2Vec2 newPos) {
        b2_pos = newPos;
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
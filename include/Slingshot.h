#pragma once
#include "DynamicObject.h"
#include "Bird.h"

/// <summary>
/// A simple class that you can use to begin the testing process using Googletest.
/// </summary>
class Slingshot : public DynamicObject {
private:
    /// <summary>
    /// Variables that define the slingshot.
    /// </summary>
    int i_tension;
    std::string str_birdType;
    const int MAX_TENSION = 100;

public:
    Slingshot() = default;
    Slingshot(float x, float y) {
        this->i_tension = 0;
        this->str_birdType = "Red";
        this->f_xPos = x;
        this->f_yPos = y;
        this->v_Pos = b2Vec2(x, y);
    }
    ~Slingshot() {}

    //Functions to test.
    void loadBird(std::string str_type) { str_birdType = str_type; }

    bool pullBack(int amount) {
        if (amount < 0) return false;
        i_tension = (i_tension + amount > MAX_TENSION) ? MAX_TENSION : i_tension + amount;
        return true;
    }

    int getTension() const { 
        return i_tension; 
    }

    std::string getBirdType() const { 
        return str_birdType; 
    }

    void release() { i_tension = 0; }
};
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include "Pig.h"
#include "Bird.h"
#include "Slingshot.h"
#include "ContactListener.h"

/// <summary>
///Taken from the GoogleTest primer. 
/// </summary>

// The fixture for testing class Pig.
class EnemyTest : public testing::Test {
public:
    std::unique_ptr<Pig> enemy;
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    EnemyTest() {
        // You can do set-up work for each test here.
                    
    }

    ~EnemyTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        enemy = std::make_unique<Pig>("pig", 0, 0); // All enemnies in this test suite start with 50 HP.
                    
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        //delete *enemy;
    }


};

// The fixture for testing class Slingshot.
class SlingshotTest : public testing::Test {
public:
    std::unique_ptr<Slingshot> slingshot;
protected:

    SlingshotTest() {

    }

    ~SlingshotTest() {}

    void SetUp() override {
        slingshot = std::make_unique<Slingshot>(0,0);
    }

    void TearDown() override {
        //delete &slingshot;
    }
};

// The fixture for testing class Bird.
class BirdTest : public testing::Test {
public:
    std::unique_ptr<Bird> redBird;
    std::unique_ptr<Bird> yellowBird;
    std::unique_ptr<Bird> blueBird;
protected:

    BirdTest() {

    }

    ~BirdTest() {}

    void SetUp() override {
        redBird = std::make_unique<Bird>("red", 0, 0);
        yellowBird = std::make_unique<Bird>("yellow", 0, 0);
        blueBird = std::make_unique<Bird>("blue", 0, 0);
    }

    void TearDown() override {
        //delete &redBird;
        //delete &yellowBird;
        //delete &blueBird;
    }
};

//The fixture for testing positions and movement
class PosTest : public testing::Test {
public:
    std::unique_ptr<Pig> normalPig;
    std::unique_ptr<Pig> armouredPig;
    std::unique_ptr<Pig> baronPig;
    std::unique_ptr<Bird> redBird;
    std::unique_ptr<Bird> yellowBird;
    std::unique_ptr<Bird> blueBird;

    //Box2D works in meters. SFML works in pixels.
    const float SCALE = 30.0f;

    b2World world;

protected:

    PosTest() = default;

    ~PosTest() {}

    void SetUp() override {
        normalPig = std::make_unique<Pig>("pig", 0, 0);
        armouredPig = std::make_unique<Pig>("armoured", 0, 0);
        baronPig = std::make_unique<Pig>("baron", 0, 0);
        redBird = std::make_unique<Bird>("red", 0, 0);
        yellowBird = std::make_unique<Bird>("yellow", 0, 0);
        blueBird = std::make_unique<Bird>("blue", 0, 0);

        //setup world.
        b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
        b2World world(b2_gravity);
    }

    void TearDown() override {

    }
};

//A single test, not a fixture. No setup is called.
TEST(Pig, PigConstructorAssignsCorrectHealthValue) {
    Pig e("pig", 0, 0);
    EXPECT_EQ(e.getHealth(), 100);
    /*SUCCEED() << "Test test passed";
    FAIL() << "Test didn't pass";*/
}

TEST(Pig, PigStartsNotPopped) {
    Pig e("pig", 0, 0);
    EXPECT_FALSE(e.checkIfPopped());
}

TEST(Pig, PigPosSetCorrectly) {
    Pig e("pig", 15, 20);
    ASSERT_EQ(e.getXPos(), 15);
    ASSERT_EQ(e.getYPos(), 20);
}

//Enemy Fixture Tests
TEST_F(EnemyTest, LethalDamagePopsPig) {
    enemy->takeDamage(150);
    EXPECT_TRUE(enemy->checkIfPopped());
}

TEST_F(EnemyTest, NonLethalDamageDoesNotPopPig) {
    enemy->takeDamage(30);
    EXPECT_FALSE(enemy->checkIfPopped());
}

TEST_F(EnemyTest, EnemyTypeStartsAsSwine) {
    std::string str = "pig";
    const char* c = str.c_str();
    EXPECT_STRCASEEQ(enemy->getType().c_str(), c);
}

TEST_F(EnemyTest, EnemyTypeCanBeChanged) {
    std::string newType = "armoured";
    enemy->setType(newType);
    const char* c = newType.c_str();
    EXPECT_STREQ(enemy->getType().c_str(), c);
}

TEST_F(EnemyTest, EnemyHealthCanBeChanged) {
    enemy->setHealth(150);
    EXPECT_EQ(enemy->getHealth(), 150);
}

//Slingshot Fixture tests
TEST_F(SlingshotTest, SlingshotTensionStartsAt0) {
    EXPECT_EQ(slingshot->getTension(), 0);
}

TEST_F(SlingshotTest, DefaultBirdIsRed) {
    std::string str = "red";
    const char* c = str.c_str();
    EXPECT_STREQ(slingshot->getBirdType().c_str(), c);
}

//Bird Fixture Tests
TEST_F(BirdTest, BirdHasSpeed) {
    ASSERT_GT(redBird->GetSpeed(), 0);
    ASSERT_GT(yellowBird->GetSpeed(), 0);
    ASSERT_GT(blueBird->GetSpeed(), 0);
}

TEST_F(BirdTest, BirdHasMass) {
    ASSERT_GT(redBird->GetMass(), 0);
    ASSERT_GT(yellowBird->GetMass(), 0);
    ASSERT_GT(blueBird->GetMass(), 0);
}

TEST_F(BirdTest, BirdSpriteLoads) {
    ASSERT_TRUE(redBird->loadSprite());
    ASSERT_TRUE(yellowBird->loadSprite());
    ASSERT_TRUE(blueBird->loadSprite());
}

//Position Fixture Tests
/*TEST_F(PosTest, DynamicObjectMovesUponImpulse) {
    redBird->loadSprite();
    redBird->setupB2d(world);
    b2Body* b2_birdBody = redBird->GetBody();
    b2_birdBody->ApplyLinearImpulse(b2Vec2(5.0f, 0.0f), b2_birdBody->GetWorldCenter(), true);
    world.Step(1.0f / 60.0f, 8, 3);
    ASSERT_EQ(redBird->GetPos(), b2Vec2(5, 0));
}
*/

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
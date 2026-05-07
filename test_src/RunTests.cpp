#include <gtest/gtest.h>
#include "Pig.h"
#include "Slingshot.h"

/// <summary>
///Taken from the GoogleTest primer. 
/// </summary>

// The fixture for testing class Foo.
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
        enemy = std::make_unique<Pig>("pig", 50, 0, 0); // All enemnies in this test suite start with 50 HP.
                    
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }


};

// The fixture for testing class Slingshot.
class SlingshotTest : public testing::Test {
public:
    std::unique_ptr<Slingshot> slingshot;
protected:

    SlingshotTest() {

    }

    void SetUp() override {
        slingshot = std::make_unique<Slingshot>();
    }


};

//A single test, not a fixture. No setup is called.
TEST(Pig, PigConstructorAssignsCorrectHealthValue) {
    Pig e("pig", 100, 0, 0);
    EXPECT_EQ(e.getHealth(), 100);
    /*SUCCEED() << "Test test passed";
    FAIL() << "Test didn't pass";*/
}

TEST(Pig, PigStartsNotPopped) {
    Pig e("pig", 100, 0, 0);
    EXPECT_FALSE(e.checkIfPopped());
}

TEST(Pig, PigPosSetCorrectly) {
    Pig e("pig", 100, 15, 20);
    ASSERT_EQ(e.getXPos(), 15);
    ASSERT_EQ(e.getYPos(), 20);
}

TEST_F(EnemyTest, LethalDamagePopsPig) {
    enemy->takeDamage(60);
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

TEST_F(SlingshotTest, SlingshotTensionStartsAt0) {
    EXPECT_EQ(slingshot->getTension(), 0);
}

TEST_F(SlingshotTest, DefaultBirdIsRed) {
    std::string str = "Red";
    const char* c = str.c_str();
    EXPECT_STREQ(slingshot->getBirdType().c_str(), c);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
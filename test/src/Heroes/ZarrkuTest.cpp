#include <limits.h>
#include <gtest/gtest.h>
// #include "../../src/Domain/Units/IUnit.h"
// #include "../../src/Domain/Units/Heroes/Zarrku.h"

class ZarrkuTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        
    }
    
    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST_F(ZarrkuTest,getMoveSpeed){
//     IUnit zarrku;
//     int movSpeed {zarrku.getMoveSpeed()};
//     ASSERT_EQ(10, movSpeed) << "Movement speed should be equal to 10";
    
    int actual = 11;
    ASSERT_EQ(10, actual) << "Movement speed should be equal to 10";
}
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Mocks/IGameMock.h"
#include "../../../src/Input/Callbacks/ZoomCameraCallback.h"

class ZoomCameraCallbackTest : public ::testing::Test
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

TEST_F(ZoomCameraCallbackTest,ZoomIn){
    IGameMock* iGameMock {new IGameMock};
    ZoomCameraCallback zcc {iGameMock, 1, "PLUS"};
    // TODO Mock IEngineFacade (waits for PR by Stephan)
    
}

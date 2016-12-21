#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Mocks/IGameMock.h"
#include "../Mocks/IEngineFacadeMock.h"
#include "../../../src/Domain/EngineFacade.h"
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
    // https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
    
    IGameMock* iGameMock {new IGameMock};
    ZoomCameraCallback zcc {iGameMock, "PLUS"};
    IEngineFacadeMock* iEngineFacadeMock {new IEngineFacadeMock};
    EngineFacade::setEngine(iEngineFacadeMock);
    
    EXPECT_CALL(*iEngineFacadeMock, zoomIn()).Times(1);
    EXPECT_CALL(*iEngineFacadeMock, zoomOut()).Times(0);
    
    zcc.execute();
    
    delete iGameMock;
    EngineFacade::destroy();
}

TEST_F(ZoomCameraCallbackTest,ZoomOut){
    IGameMock* iGameMock {new IGameMock};
    ZoomCameraCallback zcc {iGameMock, "MINUS"};
    IEngineFacadeMock* iEngineFacadeMock {new IEngineFacadeMock};
    EngineFacade::setEngine(iEngineFacadeMock);
    
    EXPECT_CALL(*iEngineFacadeMock, zoomOut()).Times(1);
    EXPECT_CALL(*iEngineFacadeMock, zoomIn()).Times(0);
    
    zcc.execute();
    
    delete iGameMock;
    EngineFacade::destroy();
}

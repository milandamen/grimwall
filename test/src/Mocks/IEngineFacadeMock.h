#include <gmock/gmock.h>
#include "../../../src/Domain/IEngineFacade.h"

class IEngineFacadeMock : public IEngineFacade
{
public:
    MOCK_METHOD1(setRenderBackend, void(std::string engine));
    MOCK_METHOD1(setScreenWidth, void(int width));
    MOCK_METHOD1(setScreenHeight, void(int height));
    MOCK_METHOD1(setFullScreen, void(bool fullScreen));
    MOCK_METHOD1(setWindowTitle, void(std::string title));
    MOCK_METHOD1(setFPSLimit, void(int fpsLimit));
    MOCK_METHOD0(init, void());
    MOCK_METHOD1(loadMap, void(std::string path));
    MOCK_METHOD0(render, void());
    MOCK_METHOD0(getFPS, int());
    MOCK_METHOD0(getTime, int());
    MOCK_METHOD2(registerCallback, void(std::string keys, ICallback* callback));
    MOCK_METHOD0(zoomIn, void());
    MOCK_METHOD0(zoomOut, void());
    MOCK_METHOD1(updateLocation, void(std::string location));
    MOCK_METHOD3(setInstanceLocation, void(std::string name, double x, double y));
    MOCK_METHOD0(tick, void());
    MOCK_METHOD0(loadTowers, std::vector<std::string>());
    
};
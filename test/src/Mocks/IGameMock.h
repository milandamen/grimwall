#include <gmock/gmock.h>
#include "../../../src/Domain/IGame.h"

class IGameMock : public IGame
{
public:
    virtual ~IGameMock() {}
    MOCK_METHOD0(getHero, UnitManager<AHero>*());
    MOCK_METHOD0(quit, void());
};
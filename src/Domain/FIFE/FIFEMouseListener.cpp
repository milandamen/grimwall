#include "FIFEMouseListener.h"

using namespace std;

FIFEMouseListener::FIFEMouseListener(IGame *game) : game{game} {}
FIFEMouseListener::~FIFEMouseListener() {
    for (auto &&item : callbackMap) {
        delete item.second;
    }
    callbackMap.clear();
}

void FIFEMouseListener::mouseEntered(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mouseExited(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mousePressed(FIFE::MouseEvent& evt) {}

void FIFEMouseListener::mouseReleased(FIFE::MouseEvent& evt) {
    cout << "Hallo Milan \n";
}
void FIFEMouseListener::mouseClicked(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mouseWheelMovedUp(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mouseWheelMovedDown(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mouseMoved(FIFE::MouseEvent& evt) {}
void FIFEMouseListener::mouseDragged(FIFE::MouseEvent& evt) {}


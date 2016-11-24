#include "FIFEMouseListener.h"

using namespace std;

FIFEMouseListener::FIFEMouseListener(IGame *game) : game{game} {}
FIFEMouseListener::~FIFEMouseListener() {
    for (auto &&item : callbackMap) {
        delete item.second;
    }
    callbackMap.clear();
}

void FIFEMouseListener::mouseEntered(FIFE::MouseEvent& evt) {
    cout<< "Mouse Entered \n";
}
void FIFEMouseListener::mouseExited(FIFE::MouseEvent& evt) {
    cout<< "Mouse Exited \n";
}
void FIFEMouseListener::mousePressed(FIFE::MouseEvent& evt) {
    cout<< "Mouse Pressed \n";
}

void FIFEMouseListener::mouseReleased(FIFE::MouseEvent& evt) {
    cout << "Mouse Released \n";
}
void FIFEMouseListener::mouseClicked(FIFE::MouseEvent& evt) {
    cout<< "Mouse clicked \n";
}
void FIFEMouseListener::mouseWheelMovedUp(FIFE::MouseEvent& evt) {
    cout<< "Scrolled up\n";
}
void FIFEMouseListener::mouseWheelMovedDown(FIFE::MouseEvent& evt) {
    cout<< "Scrolled down \n";
}
void FIFEMouseListener::mouseMoved(FIFE::MouseEvent& evt) {
//    cout<< "Mouse has moved \n";
}
void FIFEMouseListener::mouseDragged(FIFE::MouseEvent& evt) {
    cout<< "Dragging the mouse \n";
}

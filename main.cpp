#include "AbstractFactory.h"
#include <iostream>

using namespace std;

// fuifac use kore render kortesi
void clientCode(const GUIFactory& factory) {
    Window* window = factory.createWindow();
    Scrollbar* scrollbar = factory.createScrollbar();

    cout << window->render() << endl;
    cout << scrollbar->render() << endl;

    delete window;
    delete scrollbar;
}

int main() {
    cout << "Cross-Platform GUI Example" << endl;
    cout << "===========================" << endl;

    cout << "\nUsing Windows GUI Factory:" << endl;
    WindowsGUIFactory windowsFactory;
    clientCode(windowsFactory);

    cout << "\nUsing Linux GUI Factory:" << endl;
    LinuxGUIFactory linuxFactory;
    clientCode(linuxFactory);

    return 0;
}


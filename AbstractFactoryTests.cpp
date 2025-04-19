#include <gtest/gtest.h>
#include "../AbstractFactory.h"

using namespace std;

// Test fixture for AbstractFactory tests
class AbstractFactoryTest : public ::testing::Test {
protected:
    WindowsGUIFactory windowsFactory;
    LinuxGUIFactory linuxFactory;
};

// Test Windows GUI Factory
TEST_F(AbstractFactoryTest, WindowsFactoryCreatesCorrectProducts) {
    Window* window = windowsFactory.createWindow();
    Scrollbar* scrollbar = windowsFactory.createScrollbar();

    EXPECT_EQ(window->render(), "Rendering Windows Window");
    EXPECT_EQ(scrollbar->render(), "Rendering Windows Scrollbar");

    delete window;
    delete scrollbar;
}

// Test Linux GUI Factory
TEST_F(AbstractFactoryTest, LinuxFactoryCreatesCorrectProducts) {
    Window* window = linuxFactory.createWindow();
    Scrollbar* scrollbar = linuxFactory.createScrollbar();

    EXPECT_EQ(window->render(), "Rendering Linux Window");
    EXPECT_EQ(scrollbar->render(), "Rendering Linux Scrollbar");

    delete window;
    delete scrollbar;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#pragma once

#include <string>
#include <iostream>

using namespace std;

// interface for window component 
class Window {
public:
    virtual ~Window() = default;
    virtual string render() const = 0;
};

// interface for scrollbar component
class Scrollbar {
public:
    virtual ~Scrollbar() = default;
    virtual string render() const = 0;
};

// implementing the window interface windows
class WindowsWindow : public Window {
public:
    string render() const override {
        return "Rendering Windows Window";
    }
};

// implementing the window interface for linux
class LinuxWindow : public Window {
public:
    string render() const override {
        return "Rendering Linux Window";
    }
};

// implementing the scrollbar interface for windows
class WindowsScrollbar : public Scrollbar {
public:
    string render() const override {
        return "Rendering Windows Scrollbar";
    }
};

// implementing the scrollbar interface for linux
class LinuxScrollbar : public Scrollbar {
public:
    string render() const override {
        return "Rendering Linux Scrollbar";
    }
};

// Abstract Factory - GUIFactory interface
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual Window* createWindow() const = 0;
    virtual Scrollbar* createScrollbar() const = 0;
};

// Concrete Factory 1 - Windows GUI Factory
class WindowsGUIFactory : public GUIFactory {
public:
    Window* createWindow() const override {
        return new WindowsWindow();
    }
    Scrollbar* createScrollbar() const override {
        return new WindowsScrollbar();
    }
};

// Concrete Factory 2 - Linux GUI Factory
class LinuxGUIFactory : public GUIFactory {
public:
    Window* createWindow() const override {
        return new LinuxWindow();
    }
    Scrollbar* createScrollbar() const override {
        return new LinuxScrollbar();
    }
};
// client code that works with factories and product only through ab
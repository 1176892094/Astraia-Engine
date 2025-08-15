#include <iostream>

#include "../Basic.h"

class Sandbox : public Basic::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Basic::Application* CreateApplication()
{
    return new Sandbox();
}

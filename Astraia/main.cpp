#include <iostream>

#include "src/Basic.h"

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

int main()
{
    Sandbox *sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
    return 0;
}

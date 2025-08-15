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

Basic::Application *Basic::CreateApplication()
{
    return new Sandbox();
}

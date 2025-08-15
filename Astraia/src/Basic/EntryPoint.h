#include "../Basic.h"

extern Basic::Application *CreateApplication();

int main(int argc, char **argv)
{
    auto app = Basic::CreateApplication();
    app->Run();
    delete app;
}

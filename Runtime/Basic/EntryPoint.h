extern Basic::Application *CreateApplication();

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    auto app = Basic::CreateApplication();
    app->Run();
    delete app;
}

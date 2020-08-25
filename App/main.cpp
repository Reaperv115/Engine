#include "Engine.h"


class App : public Engine::Application
{
public:
    App()
    {

    }
    ~App()
    {

    }
};


Engine::Application* Engine::CreateApplication()
{
    return new App();
}

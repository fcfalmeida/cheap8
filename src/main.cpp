#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <memory>
#include "renderer.h"

struct AppContext {
    std::unique_ptr<Renderer> renderer;

    AppContext(std::unique_ptr<Renderer> renderer) : renderer(std::move(renderer)) {}
};

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    *appstate = new AppContext(std::make_unique<Renderer>(Dimensions{64, 32}, Dimensions{1920, 1080}));

    auto* app = (AppContext*)*appstate;

    return app->renderer->InitDisplay();
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    auto* app = (AppContext*)appstate;

    app->renderer->Update();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    auto* app = (AppContext*)appstate;

    delete app;
}

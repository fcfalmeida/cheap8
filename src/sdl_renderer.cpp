#include "sdl_renderer.h"

SDLRenderer::SDLRenderer(const Dimensions& frame_buffer_dimensions, const Dimensions& screen_resolution)
    : screen_resolution_(screen_resolution),
      pixel_scale_factor_({screen_resolution_.width / frame_buffer_dimensions.width,
                           screen_resolution_.height / frame_buffer_dimensions.height}) {}

void SDLRenderer::ClearScreen() {
    SDL_SetRenderDrawColorFloat(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE_FLOAT);
}

void SDLRenderer::Update() {
    const double now = ((double)SDL_GetTicks()) / 1000.0; /* convert from milliseconds to seconds. */
    /* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
    const auto red = (float)(0.5 + 0.5 * SDL_sin(now));
    const auto green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const auto blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    SDL_SetRenderDrawColorFloat(renderer_, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT); /* new color, full alpha. */

    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
}

bool SDLRenderer::InitDisplay() {
    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", static_cast<int>(screen_resolution_.width),
                                     static_cast<int>(screen_resolution_.height), 0, &window_, &renderer_)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void SDLRenderer::RenderFrame(const FrameBuffer& frame_buffer) {
    Coordinates current_pixel_pos = {0, 0};
    const auto frame_buf_dims = frame_buffer.GetDimensions();
    const auto frame_data = frame_buffer.GetFrameData();

    for (const auto& chunk : frame_data) {
        std::bitset<8> pixels = {chunk};

        for (uint8_t i = 0; i < 8; i++) {
            if (pixels.test(i)) {
                auto rect = SDL_FRect{static_cast<float>(current_pixel_pos.x), static_cast<float>(current_pixel_pos.y),
                                           static_cast<float>(static_cast<int>(current_pixel_pos.x * pixel_scale_factor_.width)),
                                           static_cast<float>(static_cast<int>(current_pixel_pos.y * pixel_scale_factor_.height))};

                SDL_RenderRect(renderer_, &rect);
            }

            current_pixel_pos.x++;
        }

        if (current_pixel_pos.x == frame_buf_dims.width - 1) {
            current_pixel_pos.y++;
        }
    }
}

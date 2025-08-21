#pragma once

#include <SDL3/SDL.h>
#include <bitset>
#include <cstdint>
#include <vector>
#include "renderer.h"
#include "types.h"

class SDLRenderer : public IRenderer {
   public:
    SDLRenderer(const Dimensions& frame_buffer_dimensions, const Dimensions& screen_resolution);
    bool InitDisplay() override;
    void RenderFrame(const FrameBuffer& frame_buffer) override;
    void ClearScreen() override;
    void Update() override;

   private:
    Dimensions screen_resolution_;
    Dimensions pixel_scale_factor_;
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;

    template<size_t N>
    std::bitset<N> ParseFrameData(std::vector<uint8_t> frame_data) {
        auto pixel_data = std::bitset<N>{0};

       for (const auto& chunk : frame_data) {
       }
    }
};

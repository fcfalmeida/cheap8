#pragma once

#include <array>
#include <cstdint>
#include "types.h"

class Sprite {
   public:
    static constexpr Dimensions kDimensions{8, 15};

    Sprite(std::array<uint8_t, kDimensions.height> data);

    std::array<uint8_t, kDimensions.height> data;
};

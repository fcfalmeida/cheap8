#include <cstdint>
#include <vector>
#include "sprite.h"
#include "types.h"

class FrameBuffer {
   public:
    FrameBuffer(Dimensions dimensions);
    bool DrawSprite(Sprite& sprite, Coordinates& position);
    [[nodiscard]] std::vector<uint8_t>& GetFrameData() const;
    [[nodiscard]] Dimensions& GetDimensions() const;

   private:
    std::vector<uint8_t> frame_data_;
    const Dimensions dimensions_;

    uint32_t CoordsToFrameBufferPos(Coordinates& coordinates);
};

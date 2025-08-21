#include "frame_buffer.h"
#include "types.h"

FrameBuffer::FrameBuffer(Dimensions dimensions) : dimensions_(dimensions) {
    frame_data_ = std::vector<uint8_t>(dimensions_.width * dimensions_.height, 0);
}

bool FrameBuffer::DrawSprite(Sprite& sprite, Coordinates& position) {

}

uint32_t FrameBuffer::CoordsToFrameBufferPos(Coordinates& coordinates) {
    return coordinates.y * dimensions_.width + coordinates.x;
}

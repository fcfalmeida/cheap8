#pragma once

#include "frame_buffer.h"

class IRenderer {
   public:
    IRenderer() = default;
    IRenderer(const IRenderer&) = default;
    IRenderer(IRenderer&&) = delete;
    IRenderer& operator=(const IRenderer&) = default;
    IRenderer& operator=(IRenderer&&) = delete;
    virtual ~IRenderer() = default;
    virtual bool InitDisplay() = 0;
    virtual void RenderFrame(const FrameBuffer& frame_buffer) = 0;
    virtual void ClearScreen() = 0;
    virtual void Update() = 0;
};

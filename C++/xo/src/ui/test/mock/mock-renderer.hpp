#include <gmock/gmock.h>
#include "renderer.hpp"
#include "types.hpp"
#include <string>

namespace mock
{
    class MockRenderer : public gfx::Renderer
    {
    public:
        MOCK_METHOD(void, initGameWindow, (), (const, override));

        MOCK_METHOD(void, draw, (std::function<void()> onDraw), (const, override));

        MOCK_METHOD(void, closeGameWindow, (), (const, override));

        MOCK_METHOD(int, drawGuiButton, (Rect rect, std::string text), (const, override));

        MOCK_METHOD(int,
                    drawGuiMessageBox,
                    (Rect rect,
                     std::string title,
                     std::string message,
                     std::string buttons),
                    (const, override));

        MOCK_METHOD(void,
                    drawText,
                    (std::string text,
                     int posX,
                     int posY,
                     int fontSize,
                     Col color),
                    (const, override));

        MOCK_METHOD(void,
                    drawRectangleRounded,
                    (Rect rec,
                     float roundness,
                     int segments,
                     Col color),
                    (const, override));

        MOCK_METHOD(void,
                    handleLeftClick,
                    (Rect r, std::function<void()> onClick),
                    (const, override));
    };
}
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

        MOCK_METHOD(
            void,
            draw,
            (const std::function<void()> onDraw),
            (const, override));

        MOCK_METHOD(void, closeGameWindow, (), (const, override));

        MOCK_METHOD(
            int,
            drawGuiButton,
            (const Rect rect, const std::string text),
            (const, override));

        MOCK_METHOD(
            int,
            drawGuiMessageBox,
            (const Rect rect,
             const std::string title,
             const std::string message,
             const std::string buttons),
            (const, override));

        MOCK_METHOD(
            void,
            drawText,
            (const std::string text,
             const int posX,
             const int posY,
             const int fontSize,
             Col color),
            (const, override));

        MOCK_METHOD(
            void,
            drawRectangleRounded,
            (const Rect rec,
             const float roundness,
             const int segments,
             const Col color),
            (const, override));

        MOCK_METHOD(
            void,
            handleLeftClick,
            (const Rect r, const std::function<void()> onClick),
            (const, override));
    };
}
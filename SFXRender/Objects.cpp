#include "RectShape.hpp"

RectShape::RectShape() {}

void RectShape::Shape(float& rectHeight, float& rectWidth, float& scale, SDL_Renderer* renderer, float& xPos, float& yPos)
{
    SDL_Rect shape;
    shape.w = rectWidth;
    shape.h = rectHeight;
    shape.y = yPos;
    shape.x = xPos;

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);

    // Draw a filled rectangle
    SDL_RenderFillRect(renderer, &shape);

    // Update the screen to render the rectangle
    SDL_RenderPresent(renderer);
};
	
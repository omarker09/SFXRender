#pragma once
#ifndef RECT_H
#define RECT_H

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <stdio.h>
#include <SDL.h>

class RectShape {

public:
	RectShape();

	void Shape(
		float& rectHeight,
		float& rectWidth,
		float& scale,
		SDL_Renderer* renderer,
		float& xPos,
		float& yPos
	);

	// Clear object memory if not needed
	
};


#endif // !GAME_H

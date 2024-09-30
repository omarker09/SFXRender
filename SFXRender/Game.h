#pragma once
#ifndef GAME_H
#define GAME_H

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <stdio.h>
#include <SDL.h>
#include <iostream>


namespace Game {
	void Game(SDL_Window* window, SDL_Renderer* SDL_RENDRER, SDL_Event event);
}


#endif // !GAME_H

#include "Game.h"
#include "RectShape.hpp"

#include "Game.h"
#include "RectShape.hpp"

// Initial rectangle parameters
float xCord = 10.0f;        // Starting x coordinate
float yCord = 100.0f;       // Starting y coordinate
float rectWidth = 100.0f;   // Width of the rectangle
float rectHeight = 150.0f;  // Height of the rectangle
float speed = 2.0f;         // Speed of the rectangle movement
float scale = 1.0f;         // Scale of the rectangle
float xSpeed = 2.0f;        // Speed of the rectangle on x-axis
float ySpeed = 2.0f;

void Game::Game(SDL_Window* window, SDL_Renderer* renderer, SDL_Event event)
{
    // Get window dimensions
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Update position of the rectangle
    xCord += xSpeed;
    yCord += ySpeed;

    // Check for collisions with the window boundaries and reverse direction
    if (xCord <= 0 || (xCord + rectWidth) >= windowWidth) {
        xSpeed = -xSpeed; // Reverse direction on x-axis
        std::cout << "Touch horizontal side at y : " << yCord << " and x : " << xCord << std::endl;
    }
    if (yCord <= 0 || (yCord + rectHeight) >= windowHeight) {
        ySpeed = -ySpeed; // Reverse direction on y-axis
        std::cout << "Touch vertical side at y : " << yCord << " and x : " << xCord << std::endl;
    }

    // Clear the renderer
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black background
    SDL_RenderClear(renderer);

    // Draw the rectangle at the updated position
    RectShape shape;
    shape.Shape(rectHeight, rectWidth, scale, renderer, xCord, yCord);

    // Now render ImGui elements
    ImGui::Begin("HH");
    ImGui::Text("Move the rect");
    ImGui::SliderFloat("slider x", &xCord, 0.0f, static_cast<int>(windowWidth - rectWidth));
    ImGui::SliderFloat("slider y", &yCord, 0.0f, static_cast<int>(windowHeight - rectHeight));
    ImGui::End();

    // Render ImGui after SDL content
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

    // Present the SDL renderer (which includes the game and ImGui now)
    SDL_RenderPresent(renderer);

    // Add a delay to control the frame rate (optional)
    // SDL_Delay(16); // ~60 FPS
}

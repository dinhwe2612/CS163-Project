/*******************************************************************************************
*
*   raylib [shapes] example - Draw raylib logo using basic shapes
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "UI/Button.h"
#include "UI/Other.h"
#include "UI/InputBox.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1460;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "Dictionary - CS163 Project (>'-'<)");

    Font Parable_Regular = LoadFont("../External/source/Font/Parable-Regular.otf");

    Button reset;
    Button addnew;
    Button history;
    Button favourite;
    Button game;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground({ 255, 238, 226 });

        DrawTextEx(Parable_Regular, "Dictionary", { 0.42 * screenWidth, 0.05 * screenHeight }, 75, 0.5, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context
    

    return 0;
}
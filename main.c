#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Holly & Perrin - Hello Raylib!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Holly! 🌿", 200, 260, 40, DARKGREEN);
        DrawText("Raylib + Zig cross-compile test", 180, 320, 20, GRAY);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

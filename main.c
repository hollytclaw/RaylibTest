#include "raylib.h"

int main(void)
{
    // Window setup
    int screenWidth = 800;
    int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Holly & Perrin - Hello Raylib!");
    SetTargetFPS(60);

    // DVD text setup
    const char *dvdText = "DVD";
    int fontSize = 60;
    int textWidth = MeasureText(dvdText, fontSize);
    int textHeight = fontSize;
    Vector2 dvdPos = { (float)(screenWidth/2 - textWidth/2), (float)(screenHeight/2 - textHeight/2) };
    Vector2 dvdVel = { 4.0f, 4.0f };
    Color dvdColor = DARKPURPLE;

    while (!WindowShouldClose())
    {
        // Update DVD position
        dvdPos.x += dvdVel.x;
        dvdPos.y += dvdVel.y;

        // Bounce off edges
        if ((dvdPos.x <= 0) || (dvdPos.x + textWidth >= screenWidth))
        {
            dvdVel.x *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        }
        if ((dvdPos.y <= 0) || (dvdPos.y + textHeight >= screenHeight))
        {
            dvdVel.y *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Holly! 🌿", 200, 70, 40, DARKGREEN);
        DrawText("Raylib + Zig cross-compile test", 180, 130, 20, GRAY);
        DrawFPS(10, 10);
        // Draw the DVD text
        DrawText(dvdText, (int)dvdPos.x, (int)dvdPos.y, fontSize, dvdColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
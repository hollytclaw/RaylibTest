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
    int textHeight = fontSize; // Raylib font height approx to fontSize
    Vector2 dvdPos = { (float)(screenWidth - textWidth) / 2, (float)(screenHeight - textHeight) / 2 };
    Vector2 dvdVel = { 5.0f, 4.0f };
    Color dvdColor = DARKPURPLE;

    while (!WindowShouldClose())
    {
        // Update DVD position
        dvdPos.x += dvdVel.x;
        dvdPos.y += dvdVel.y;

        // Bounce off left/right
        if (dvdPos.x <= 0) {
            dvdPos.x = 0;
            dvdVel.x *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        } else if (dvdPos.x + textWidth >= screenWidth) {
            dvdPos.x = screenWidth - textWidth;
            dvdVel.x *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        }

        // Bounce off top/bottom
        if (dvdPos.y <= 0) {
            dvdPos.y = 0;
            dvdVel.y *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        } else if (dvdPos.y + textHeight >= screenHeight) {
            dvdPos.y = screenHeight - textHeight;
            dvdVel.y *= -1.0f;
            dvdColor = (Color){ GetRandomValue(32, 255), GetRandomValue(32, 255), GetRandomValue(32, 255), 255 };
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Holly! \xf0\x9f\x8c\xbf", 200, 70, 40, DARKGREEN);
        DrawText("Raylib + Zig cross-compile test", 180, 130, 20, GRAY);
        DrawFPS(10, 10);
        DrawText(dvdText, (int)dvdPos.x, (int)dvdPos.y, fontSize, dvdColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

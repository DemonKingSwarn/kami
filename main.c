#include "raylib.h"
#include "config.h"

float timeScale = 1.0f;

int main(void) {
  SetTargetFPS(fps);
  InitWindow(width, height, title);

  while (!WindowShouldClose()) {
    float delta = GetFrameTime() * timeScale;

    ClearBackground(GRAY);

    BeginDrawing();
      DrawText("This is a text!", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

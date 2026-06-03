#include "raylib.h"
#include "config.h"
#include "purgatory.h"

float timeScale = 1.0f;
float fixedTimeStep = .0f;
float accumulator = .0f;

int main(void) {
  Awake();

  Start();


  fixedTimeStep = 1.0f / 50.0f * timeScale;
  accumulator = 0.0;

  while (!WindowShouldClose()) {
    float delta = GetFrameTime() * timeScale;

    ClearBackground(GRAY);

    Update(delta);

    accumulator += GetFrameTime();

    while (accumulator >= fixedTimeStep) {
      FixedUpdate(fixedTimeStep);
      accumulator -= fixedTimeStep;
    }
  }

  CloseWindow();

  return 0;
}

void Awake() {
  SetTargetFPS(60);
  InitWindow(width, height, title);
}

void Start() {

}

void Update(float delta) {
  BeginDrawing();
    DrawText("this is a text", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RAYWHITE);
  EndDrawing();
}

void FixedUpdate(float fixedDelta) {

}

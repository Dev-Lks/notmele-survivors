#include "Game.h"
#include <raylib.h>

Game::Game() {}

void Game::Run() {
  const int screenWidth = 1280;
  const int screenHeight = 720;
  InitWindow(screenWidth, screenHeight, "[dev] - notmele surv");
  SetTargetFPS(144);

  TraceLog(LOG_INFO, "Game initialized");

  player.SetPosition({screenWidth / 2.0f, screenHeight / 2.0f});

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    player.Update(deltaTime);

    BeginDrawing();
    ClearBackground(BLACK);

    player.Draw();

    EndDrawing();
  }

  CloseWindow();
  TraceLog(LOG_INFO, "Game closed");
}

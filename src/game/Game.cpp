#include "Game.h"
#include <raylib.h>

Game::Game() {}

void Game::DrawHud() {
  Vector2 currentPosition = player.GetPosition();
  DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, WHITE);
  DrawText(TextFormat("Kills: %d", player.GetKills()), 10, 30, 20, WHITE);
  DrawText(TextFormat("GameTime: %d Seconds", (int)gameTime), 10, 50, 20,
           WHITE);
  DrawText(TextFormat("Position: (%f, %f)", currentPosition.x, currentPosition.y),
           10, 70, 20, WHITE);
}

void Game::Run() {
  const int screenWidth = 1280;
  const int screenHeight = 720;
  InitWindow(screenWidth, screenHeight, "[dev] - notmele surv");
  SetTargetFPS(60);

  TraceLog(LOG_INFO, "Game initialized");

  player.SetPosition({screenWidth / 2.0f, screenHeight / 2.0f});

  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    player.Update(deltaTime);
    gameTime += deltaTime;

    BeginDrawing();
    ClearBackground(BLACK);

    player.Draw();
    DrawHud();

    EndDrawing();
  }

  CloseWindow();
  TraceLog(LOG_INFO, "Game closed");
}

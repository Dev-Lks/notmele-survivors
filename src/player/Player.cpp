#include "Player.h"
#include <raylib.h>

Player::Player() {
  position = {0, 0};
  baseSpeed = 200.0f;
  runMultiplier = 5.0f;
}

void Player::Update(float deltaTime) {
  Vector2 direction = {0.0f, 0.0f};

  float speed = baseSpeed;

  if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
    speed *= runMultiplier;
  }

  if (IsKeyDown(KEY_W))
    direction.y -= 1.0f;

  if (IsKeyDown(KEY_A))
    direction.x -= 1.0f;

  if (IsKeyDown(KEY_S))
    direction.y += 1.0f;

  if (IsKeyDown(KEY_D))
    direction.x += 1.0f;

  if (IsKeyPressed(KEY_SPACE)) {
    AddKill();
  }

  if (Vector2Length(direction) > 0.0f)
    direction = Vector2Normalize(direction);

  Vector2 movement = Vector2Scale(direction, speed * deltaTime);
  position = Vector2Add(position, movement);
}

void Player::Draw() { DrawCircleV(position, 50.0f, BLUE); }

void Player::SetPosition(Vector2 newPosition) { position = newPosition; }

int Player::GetKills() const { return kills; }

void Player::AddKill() {
  kills++;
  TraceLog(LOG_INFO, "Kill added: %d", kills);
}

Vector2 Player::GetPosition() const { return position; }

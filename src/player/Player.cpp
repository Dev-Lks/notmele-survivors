
#include "Player.h"

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

    if (Vector2Length(direction) > 0.0f)
        direction = Vector2Normalize(direction);

    Vector2 movement = Vector2Scale(direction, speed * deltaTime);
    position = Vector2Add(position, movement);
}

void Player::Draw() { DrawCircleV(position, 50.0f, BLUE); }

void Player::SetPosition(Vector2 newPosition) { position = newPosition; }

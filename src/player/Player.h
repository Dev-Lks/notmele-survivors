#include <raylib.h>
#include <raymath.h>

class Player {
    Vector2 position;
    float baseSpeed;
    float runMultiplier;

public:
    Player();
    void Update(float deltaTime);
    void Draw();
    void SetPosition(Vector2 newPosition);
};

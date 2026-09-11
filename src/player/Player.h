#include <raylib.h>
#include <raymath.h>

class Player {
    Vector2 position;
    float baseSpeed;
    float runMultiplier;
    int kills = 0;

public:
    Player();
    void Update(float deltaTime);
    void Draw();
    void SetPosition(Vector2 newPosition);
    void AddKill();
    int GetKills() const;
    Vector2 GetPosition() const;
};

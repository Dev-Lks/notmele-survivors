#include "../player/Player.h"

class Game {
public:
    Game();
    void Run();

private:
    Player player;
    float gameTime = 0.0f;
    void DrawHud();
};

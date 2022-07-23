#include "../Cards-Against-Programmers/Game.h"

auto main() -> int {
    Game game;
    while (game.isRunning()) {
        game.update();
        game.render();
    }
    return 0;
}
#include "core/scene_manager.hpp"
int main() {
    SceneManager game(960, 720,false);
    game.load_scene("../data/test_map.tmx");
    while(game.run()) {}
    return 0;
}

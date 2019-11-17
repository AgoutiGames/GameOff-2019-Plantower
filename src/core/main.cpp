#include "scene_manager.hpp"
int main() {
    SceneManager game(960, 720,false);
    game.load_scene("../salmon/data/maps/orthogonal_demo.tmx");
    while(game.run()) {}
    return 0;
}

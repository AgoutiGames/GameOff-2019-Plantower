#include "gameinfo.hpp"
int main() {
    salmon::GameInfo game(1920,1080);
    game.load_map("../salmon/data/maps/orthogonal_demo.tmx");
    while(game.update()) {game.render();}
    return 0;
}

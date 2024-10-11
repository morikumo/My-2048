#include "../header/2048.hpp"

int main(){

    Game game;

    char x = 'a';
    while (x != '!')
    {
        cin >> x;
        game.makeMove(x);
        break;
    }
    
    cout << game;
    return 0;
}


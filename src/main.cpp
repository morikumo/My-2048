#include "../header/2048.hpp"

int main()
{

    Game game;

    char x = 'a';
    while (x != '!')
    {
        cout << game;
        std::cout << "Entrez une direction (z: haut, s: bas, q: gauche, d: droite) ou '!' pour quitter : ";
        cin >> x;
        game.makeMove(static_cast<int>(x));
        if (game.checkLoose())
        {
            cout << "You loose !!" << endl;
            break;
        }
        if (game.checkWin())
        {
            cout << "You WIN !!" << endl;
            break;
        }
    }

    return 0;
}

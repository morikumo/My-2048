#include "../header/2048.hpp"

int main()
{
    Game game;

    char x = 'a';
    while (x != '!')
    {
        cout << game;
        std::cout << "Entrez une direction (z: haut, s: bas, q: gauche, d: droite) ou '!' pour quitter : " ;;
        x = game.getche();
        cout << "\n";
        game.makeMove(static_cast<int>(x));
        if (game.checkLoose())
        {
            cout << BOLDRED << "You loose !!" << RESET << endl;
            break;
        }
        if (game.checkWin())
        {
            cout << BOLDGREEN << "You WIN !!" << RESET << endl;
            break;
        }
    }

    return 0;
}

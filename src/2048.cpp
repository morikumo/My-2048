#include "../header/2048.hpp"

Game::Game()
{
    grille = vector<vector<int>>(GRID_SIZE, vector<int>(GRID_SIZE, 0));
    generateRandomNumberAndPutItOnGrid();
    generateRandomNumberAndPutItOnGrid();
}

// Surcharge de l'opérateur << pour afficher la grille
std::ostream &operator<<(std::ostream &out, const Game &game)
{
    out << "Grille actuelle : " << endl;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            out << game.grille[i][j] << "\t"; // Affichage de la grille avec des tabulations pour aligner
        }
        out << "\n";
    }
    return out;
}

void Game::makeMove(const int direction)
{

    switch (direction)
    {
    case LEFT:
        left();
        break;
    case RIGHT:
        right();
        break;
    case UP:
        up();
        break;
    case DOWN:
        down();
        break;
    case SALEM:
        cout << BOLDYELLOW << "Goodbye !" << RESET << endl;
        break;
    default:
        cout << BOLDRED << "Wrong input, stupid !" << RESET << endl;
        break;
    }
}

void Game::left()
{
    cout << BOLDCYAN << "We go to the left" << RESET << endl;
    generateRandomNumberAndPutItOnGrid();
}

void Game::right()
{
    cout << BOLDCYAN << "We go to the right" << RESET << endl;
}

void Game::up()
{
    cout << BOLDCYAN << "We go to the up" << RESET << endl;
}

void Game::down()
{
    cout << BOLDCYAN << "We go to the down" << RESET << endl;
}

void Game::generateRandomNumberAndPutItOnGrid()
{
    srand(time(0));
    int value = (rand() % 10 == 0) ? 4 : 2;

    int random1 = (rand() % GRID_SIZE);
    int random2 = (rand() % GRID_SIZE);

    cout << "Rand index 1: " << random1 << endl;
    cout << "Rand index 2: " << random2 << endl;

    while (grille[random1][random2] != 0)
    {
        random1 = (rand() % GRID_SIZE);
        random2 = (rand() % GRID_SIZE);
    }
    grille[random1][random2] = value;
}
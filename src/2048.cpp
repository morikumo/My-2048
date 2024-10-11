#include "../header/2048.hpp"


std::ostream& operator<<(std::ostream &out, const Game &game) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            out << game.grille[i][j] << "\t"; 
        }
        out << "\n";
    }
    return out;
}

void Game::makeMove(const int direction)
{

    cout << "Your arrow is: " << direction << endl;

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
    }
}

void Game::left()
{
    cout << "we go to the left" << endl;
}

void Game::right()
{
    cout << "we go to the right" << endl;
}

void Game::up()
{
    cout << "we go to the up" << endl;
}

void Game::down()
{
    cout << "we go to the down" << endl;
}
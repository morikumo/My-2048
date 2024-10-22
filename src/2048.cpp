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
    out << "Grille actuelle : " << std::endl;
    out << "----------------------------" << std::endl;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        out << "|"; // Début de la ligne
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            out << " " << BOLDGREEN << std::setw(3) << game.grille[i][j] << RESET << " "; // Affichage avec un espace pour l'alignement
            out << "|";                                                                   // Séparateur entre les cellules
        }
        out << std::endl;
        out << "----------------------------" << std::endl; // Ligne de séparation
    }
    return out;
}

void Game::makeMove(const int direction)
{
    switch (direction)
    {
    case LEFT:
        mergedLeft();
        break;
    case RIGHT:
        mergedRight();
        break;
    case UP:
        mergedUp();
        break;
    case DOWN:
        mergedDown();
        break;
    case SALEM:
        cout << BOLDYELLOW << "Goodbye !" << RESET << endl;
        break;
    default:
        cout << BOLDRED << "Wrong input, stupid !" << RESET << endl;
        break;
    }
}

void Game::mergedLeft()
{
    bool moved = left();

    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE - 1; ++j)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j + 1])
            {
                grille[i][j] *= 2;
                grille[i][j + 1] = 0;
                moved = true;
            }
        }
    }

    if (left())
        moved = true;
    if (moved)
        generateRandomNumberAndPutItOnGrid();
}

bool Game::left()
{
    cout << BOLDCYAN << "We go to the left" << RESET << endl;
    bool moved = false;

    for (int i = 0; i < GRID_SIZE; i++)
    {
        int new_index = 0;
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grille[i][j] != 0)
            {
                if (new_index != j)
                {
                    grille[i][new_index] = grille[i][j];
                    grille[i][j] = 0;
                    moved = true; // Un déplacement a eu lieu
                }
                new_index++;
            }
        }
    }

    return moved; // Retourne true si un déplacement a eu lieu
}

void Game::mergedRight()
{
    bool moved = right();

    for (int i = GRID_SIZE - 1; i >= 0; i--)
    {
        for (int j = GRID_SIZE - 1; j >= 0; j--)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j - 1])
            {
                grille[i][j] *= 2;
                grille[i][j - 1] = 0;
            }
        }
    }
    if(right())
        moved = true;
    if(moved)    
        generateRandomNumberAndPutItOnGrid();
}

bool Game::right()
{
    cout << BOLDCYAN << "We go to the right" << RESET << endl;
    bool moved = false;
    for (int i = GRID_SIZE - 1; i >= 0; i--)
    {
        int new_index = GRID_SIZE - 1;
        for (int j = GRID_SIZE - 1; j >= 0; j--)
        {
            if (grille[i][j] != 0)
            {
                grille[i][new_index] = grille[i][j];
                if (new_index != j)
                {
                    grille[i][j] = 0;
                    moved = true;
                }
                new_index--;
            }
        }
    }

    return moved;
}

void Game::mergedUp()
{
    bool moved = up();
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE - 1; j++)
        {
            if (grille[j][i] != 0 && grille[j][i] == grille[j + 1][i])
            {
                grille[j][i] *= 2;
                grille[j + 1][i] = 0;
            }
        }
    }

    if(up())
        moved = true;
    if(moved)
        generateRandomNumberAndPutItOnGrid();
}

bool Game::up()
{
    cout << BOLDCYAN << "We go to the up" << RESET << endl;
    bool moved = false;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        int new_index = 0;
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grille[j][i] != 0)
            {
                grille[new_index][i] = grille[j][i];
                if (new_index != j)
                {
                    grille[j][i] = 0;
                    moved = true;
                }
                new_index++;
            }
        }
    }

    return moved;
}

void Game::mergedDown()
{
    bool moved = down();
    for (int i = GRID_SIZE - 1; i >= 0; --i)
    {
        for (int j = GRID_SIZE - 1; j >= 0; --j)
        {
            if (grille[j][i] != 0 && grille[j][i] == grille[j - 1][i])
            {
                grille[j][i] *= 2;
                grille[j - 1][i] = 0;
            }
        }
    }
    if(down())
        moved = true;
    if(moved)
        generateRandomNumberAndPutItOnGrid();
}

bool Game::down()
{
    cout << BOLDCYAN << "We go to the down" << RESET << endl;
    bool moved = false;
    for (int i = GRID_SIZE - 1; i >= 0; i--)
    {
        int new_index = GRID_SIZE - 1;
        for (int j = GRID_SIZE - 1; j >= 0; j--)
        {
            if (grille[j][i] != 0)
            {
                grille[new_index][i] = grille[j][i];
                if (new_index != j)
                {
                    grille[j][i] = 0;
                    moved = true;
                }
                new_index--;
            }
        }
    }

    return moved;
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

bool Game::checkWin()
{
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grille[i][j] == TARGET)
                return true;
        }
    }
    return false;
}

bool Game::checkLoose()
{
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grille[i][j] == 0)
                return false;
            if (i > 0 && grille[i][j] == grille[i - 1][j])
                return false;
            if (i < GRID_SIZE - 1 && grille[i][j] == grille[i + 1][j])
                return false;
            if (j > 0 && grille[i][j] == grille[i][j - 1])
                return false;
            if (j < GRID_SIZE - 1 && grille[i][j] == grille[i][j + 1])
                return false;
        }
    }
    return true;
}
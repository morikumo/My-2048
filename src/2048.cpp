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
            out << " " << BOLDWHITE << std::setw(3) << game.grille[i][j] << RESET << " "; // Affichage avec un espace pour l'alignement
            out << "|"; // Séparateur entre les cellules
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

bool Game::canMoveLeft() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE - 1; ++j) {
            if (grille[i][j] != 0) {
                if (grille[i][j + 1] == 0 || grille[i][j] == grille[i][j + 1]) {
                    return true;
                }
            }
        }
    }
    return false;
}


void Game::mergedLeft()
{
    if (!canMoveLeft()) {
        // Si aucun mouvement n'est possible, ne rien faire
        return;
    }

    left();
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE - 1; ++j)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j + 1])
            {
                grille[i][j] *= 2;
                grille[i][j + 1] = 0;
            }
        }
    }
    left();
    generateRandomNumberAndPutItOnGrid();
}

void Game::left()
{
    cout << BOLDCYAN << "We go to the left" << RESET << endl;
    // Parcourir les lignes
    for (int i = 0; i < GRID_SIZE; i++)
    {
        // Nouvelle index pour deplacer les element, qui repasse a zero apres chaque lignes
        int new_index = 0;
        // Parcourir les colonnes
        for (int j = 0; j < GRID_SIZE; j++)
        {
            // Je vais ici : si le nombre a l'index [i][j] est different de 0 l'affiler a new index pour l'effet de deplacement
            if (grille[i][j] != 0)
            {
                grille[i][new_index] = grille[i][j];
                // Changer la valeur de ou était la position par 0
                if (new_index != j)
                {
                    grille[i][j] = 0;
                }
                // On incremente newIndex pour que le prochain nombre trouvé soit placé dans la case suivante vers la droite.
                new_index++;
            }
        }
    }
}

void Game::mergedRight()
{
    right();
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
    right();
    generateRandomNumberAndPutItOnGrid();
}

void Game::right()
{
    cout << BOLDCYAN << "We go to the right" << RESET << endl;
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
                }
                new_index--;
            }
        }
    }
}

void Game::mergedUp()
{
    up();
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
    up();
    generateRandomNumberAndPutItOnGrid();
}

void Game::up()
{
    cout << BOLDCYAN << "We go to the up" << RESET << endl;
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
                }
                new_index++;
            }
        }
    }
}

void Game::mergedDown()
{
    down();
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
    down();
    generateRandomNumberAndPutItOnGrid();
}

void Game::down()
{
    cout << BOLDCYAN << "We go to the down" << RESET << endl;
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
                }
                new_index--;
            }
        }
    }
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

/*
bool Game::mergedLeft()
{
    bool moved = false; // Variable pour suivre si un mouvement a eu lieu
    left();
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE - 1; ++j)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j + 1])
            {
                grille[i][j] *= 2;
                grille[i][j + 1] = 0;
                moved = true; // Un mouvement a eu lieu
            }
        }
    }
    left();
    // Vérifiez si un mouvement a eu lieu dans la méthode left
    return moved || (/* condition pour vérifier si quelque chose a été déplacé dans left() );
}

*/
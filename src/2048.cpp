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
    generateRandomNumberAndPutItOnGrid();
}

void Game::right()
{
    cout << BOLDCYAN << "We go to the right" << RESET << endl;
    // La partie pour aller a droite
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
    generateRandomNumberAndPutItOnGrid();
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
#ifndef _2048_HPP_
#define _2048_HPP_

#include <iostream>
#include <vector>
#include <string>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */
# define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		/* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"		/* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"		/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */

using namespace std;


enum DIRECTION {
    LEFT = 113,
    RIGHT = 100,
    DOWN =  115,
    UP = 122,
    SALEM = 33,
};

#define GRID_SIZE 4

class Game{

    public:
        Game();
        ~Game() = default;
        void makeMove(const int direction);
        friend std::ostream & operator << (ostream &out, const Game &grid);

    private:
        void up();
        void down();
        void left();
        void mergedLeft();
        void right();
        void generateRandomNumberAndPutItOnGrid();
        vector<vector<int>> grille;
};

#endif
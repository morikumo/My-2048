#ifndef _2048_HPP_
#define _2048_HPP_

#include <iostream>
#include <vector>
#include <string>

using namespace std;


enum DIRECTION {
    LEFT = 113,
    RIGHT = 100,
    DOWN =  115,
    UP = 122,
};

#define GRID_SIZE 4

class Game{

    public:
        Game() = default;
        ~Game() = default;
        void makeMove(const int direction);
        friend std::ostream & operator << (ostream &out, const Game &grid);

    private:
        void up();
        void down();
        void left();
        void right();
        void generateRandomNumberAndPutItOnGrid();
        vector<vector<int>> grille;
};

#endif
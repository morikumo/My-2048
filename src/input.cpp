#include "../header/2048.hpp"

// Variable pour stocker les configurations de terminal
static struct termios oldSettings, currentSettings;

// Initialise les nouvelles configurations du terminal avec ou sans écho
void Game::initTermios(bool echo) {
    tcgetattr(0, &oldSettings);            // Récupère les paramètres actuels du terminal
    currentSettings = oldSettings;          // Copie les paramètres actuels
    currentSettings.c_lflag &= ~ICANON;     // Désactive le mode canonique pour lecture directe
    if (echo) {
        currentSettings.c_lflag |= ECHO;    // Active le mode écho si echo est vrai
    } else {
        currentSettings.c_lflag &= ~ECHO;   // Désactive l'écho sinon
    }
    tcsetattr(0, TCSANOW, &currentSettings); // Applique les nouveaux paramètres immédiatement
}

// Restaure les paramètres d'origine du terminal
void Game::resetTermios() {
    tcsetattr(0, TCSANOW, &oldSettings);
}

// Lit un caractère avec ou sans écho en fonction du paramètre echo
char Game::getch_(bool echo) {
    char ch;
    initTermios(echo);  // Initialise les paramètres avec ou sans écho
    ch = getchar();      // Récupère un caractère
    resetTermios();      // Restaure les paramètres d'origine
    return ch;
}

// Lit un caractère sans écho
char Game::getch() {
    return getch_(false);
}

// Lit un caractère avec écho
char Game::getche() {
    return getch_(true);
}

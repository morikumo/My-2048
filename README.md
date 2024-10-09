## 2048 Project

Il faut compiler avec [compiler] clang/c++/g++ [src files] *.cpp [flags] -lGLEW -lglfw -lGL -lGLU 


Il va falloir segmenter le projet en plusieurs partie :

    - Ouvrir une fenetre
    - Interagir dessus
    - Afficher nos chiffres
    - Creer la logique du 2048 (addition des nombres entre eux, soit les meme nombres peuvent s'additionner)
    - Creer une griller affichable


Voila un léger Roadmap :

Roadmap Simplifiée en 5 Étapes pour le Jeu 2048:

[Étape 1] : Initialisation du Projet
    - Créer le projet :
    - Configure un nouveau projet C++ dans ton IDE préféré.
    - Installe les bibliothèques nécessaires, comme GLFW ou SFML, si tu souhaites utiliser une interface graphique.
[Étape 2] : Création de la Grille de Jeu
    - Développer la logique du plateau :
    - Crée une classe Board qui représente la grille 4x4.
    - Initialise la grille avec deux tuiles (valeurs 2 ou 4) placées aléatoirement.
[Étape 3] : Implémentation des Mouvements
    - Gérer les déplacements :
    - Implémente des fonctions pour déplacer les tuiles dans les quatre directions (gauche, droite, haut, bas).
    - Ajoute la logique pour fusionner les tuiles identiques lors du déplacement.
[Étape 4] : Affichage de l’Interface Utilisateur
    - Affiche le plateau de jeu :
    - Utilise la bibliothèque graphique pour dessiner la grille et les tuiles avec leurs valeurs.
    - Gère les entrées clavier pour que le joueur puisse interagir avec le jeu.
[Étape 5] : Conditions de Victoire et Défaite
    - Ajouter la logique de fin de jeu :
    - Vérifie si le joueur a gagné (tuile 2048) ou perdu (plus de mouvements possibles).
    - Affiche un message approprié à la fin du jeu.

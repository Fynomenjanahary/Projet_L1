/*#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

char* readInput() {
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();

    // Désactive l'affichage de la saisie de l'utilisateur
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    char* input = (char*) malloc(sizeof(char) * 100);  // Alloue de l'espace pour la saisie
    getnstr(input, 100);  // Lit l'entrée de l'utilisateur

    // Restaure les paramètres par défaut du terminal
    endwin();

    return input;
}


int main() {
    char* userInput = readInput();
    printf("Vous avez entré : %s\n", userInput);
    free(userInput);  // Libère la mémoire allouée pour la saisie

    return 0;
}
*/
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void disableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char* readInput() {
    disableEcho();

    char* input = (char*) malloc(sizeof(char) * 100);  // Alloue de l'espace pour la saisie
    fgets(input, 100, stdin);  // Lit l'entrée de l'utilisateur

    return input;
}

int main() {
    char* userInput = readInput();
    printf("Vous avez entré : %s\n", userInput);
    free(userInput);  // Libère la mémoire allouée pour la saisie

    return 0;
}

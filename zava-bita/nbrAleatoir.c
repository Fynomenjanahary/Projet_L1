#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    // On commence par initialiser le générateur de nombre pseudo-aléatoires.
    srand( time( NULL ) );

    while( true ) {
        // Tirer une valeur aléatoire entre 0 et 100.
        int searchedValue = rand() % 101;       // % => Reste de la division entière
        int editedValue;
        int score = 0;
        printf( "MegaGame V1.0 - Valeur secrète == %d\n", searchedValue );

        while( true ) {
            printf( "Veuillez saisir un entier (entre 0 et 100) : " );
            fflush( stdout );
            scanf( "%d", & editedValue );
            score++;

            if ( editedValue == searchedValue ) {
                printf( "Félicitation : trouvé en %d coups !\n", score );
                break;      // intérrompre la boucle des manches (pas celle des parties)
            }
            if ( editedValue < searchedValue ) {
                printf( "La valeur à trouver est plus grande.\n" );
            } else {
                printf( "La valeur à trouver est plus petite.\n" );
            }
        }

        printf( "Souhaitez-vous recommencer une partie (0 Non / 1 Oui) : " );
        fflush( stdout );
        scanf( "%d", & editedValue );
        if ( editedValue == 0 ) break;
    }

    printf( "Bye bye !\n" );

    return EXIT_SUCCESS;
}

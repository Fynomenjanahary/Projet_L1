#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int size;
    scanf("%d", &size);
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<i ; j++){
            printf(" ");
        }
        for(int j=0 ; j<=i ; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

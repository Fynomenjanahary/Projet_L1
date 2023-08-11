#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N1;
    int N2;
    scanf("%d%d", &N1, &N2);
    printf("%d\n",N2-N1*(N2/N1));
	printf("%d modulo",N2%N1);
    

    return 0;
}

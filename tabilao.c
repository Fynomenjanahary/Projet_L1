#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int L;
    scanf("%d", &L);
    int N;
    scanf("%d", &N);
    int k=1;
    for(int i=1 ; i<=N ; i++){
        printf("[");
        int j;
        for(j=k ; j<=i*L ; j++){
            printf("%d",j);
            if(j!=i*L){printf(",");}
        }
         printf("]\n");
         k=j;
    }
    return 0;
}

#ifndef __LIBPC_H__
#define __LIBPC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char marque[30];
	char etiquette[30];
	int num;
	char mac[40];
}Machine;

int count_line(int count , FILE *file);
Machine* taking( FILE *file , int count);
Machine* triage(Machine* Line , int count);
FILE* submit(Machine* Info , int count);

#endif

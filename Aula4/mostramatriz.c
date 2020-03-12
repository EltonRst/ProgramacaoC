#include <stdio.h>
#include <stdlib.h>

#define N 20

void MostraM(char M[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf(" %c", M[i][j]);
		}
		printf("\n");
	}
}

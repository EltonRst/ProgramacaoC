#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

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

int main(int argc, char* argv[]) 
{

	char M[N][N];
	int i, j;
	int Xa, Xb, Ya, Yb;

	// sorteia pontos
	Xa = rand() % N;
	Ya = rand() % N;
	Xb = rand() % N;
	Yb = rand() % N;

	printf("Pontos sorteados:\nA[%d,%d] ::: B[%d,%d]\n", Xa, Ya, Xb, Yb);

	// preenche matriz
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			M[i][j] = 176;
		}
	}
	M[Xa][Ya] = 'A'; M[Xb][Yb] = 'B';
	MostraM(M);

	return 0;
}

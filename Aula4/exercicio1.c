#include <stdio.h>
#include <stdlib.h>

#define N 20

void exercicio1(){
	
	char M[N][N];
	int i,j,k;
	
	float d,x,y;
	float Ax,Ay,Bx,By;
	float iX,iY;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			M[i][j] = '.';			
		}
	}
	
	Ax = 3;
	Ay = 3;
	Bx = 6;
	By = 6;
	
	// Calcular distância e incrementos
	
	d = abs(Ax-Bx) + abs(Ay-By);
	iX = abs(Ax-Bx) / d;
	iY = abs(Ay-By) / d;

	x = Ax;
	y = Ay;
	
	for(k=0;k<d;k++)
	{
		M[(int)x][(int)y] = '*';
		x += iX;
		y += iY;
	}
	
	M[(int)Ax][(int)Ay] = 'A';
	M[(int)Bx][(int)By] = 'B';
	
	MostraM(M);
	
}

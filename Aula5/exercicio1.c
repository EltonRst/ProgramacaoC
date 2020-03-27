#include <stdio.h>
#include <stdlib.h>

#define N 10

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
	
	// Situação 1
	Ax = 1;
	Ay = 1;
	Bx = 8;
	By = 8;
	
	// Situação 2
	Ax = 1;
	Ay = 8;
	Bx = 8;
	By = 1;
	
	// Situação 3
	Ax = 8;
	Ay = 8;
	Bx = 1;
	By = 1;
	
	// Situação 4
	Ax = 8;
	Ay = 1;
	Bx = 1;
	By = 8;
	
	// Calcular distância e incrementos
	
	d = abs(Ax-Bx) + abs(Ay-By);
	iX = abs(Ax-Bx) / d;
	iY = abs(Ay-By) / d;

	x = Ax;
	y = Ay;
	
	// No sentido negativo
	if(Bx < Ax)
		iX *= -1;
		
	if(By < Ay)
		iY *= -1;
	
	for(k=0;k<d;k++)
	{
		M[(int)x][(int)y] = '*';
		//
		x += iX;
		y += iY;
		//
		printf("X:%f Y:%f\n",x,y);
	
	}
	
	M[(int)Ax][(int)Ay] = 'A';
	M[(int)Bx][(int)By] = 'B';
	
	MostraM(M);
	
}

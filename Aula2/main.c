#include <stdio.h>
#include <stdlib.h>

#define W 3
#define H 3

void mostram(int M[H][W]);

void main() {
	
	int MA[H][W];
	int MB[H][W];
	int MC[H][W];
	
	int l,c,k;
	
	//srand(time(NULL));
	
	// Popula matrizes por padrão
	for(l=0;l<H;l++)
	{
		for(c=0;c<W;c++)
		{
			MA[l][c]=1;//rand()%(H*W);
			MB[l][c]=2;
			MC[l][c]=0; // Zerado aqui
		}
	}
	
	for(l=0;l<H;l++)
	{
		for(c=0;c<W;c++)
		{
			//MC[l][c]=0; // Já zerado antes
			for(k=0;k<W;k++)
			{
				MC[l][c]+=MA[l][k]*MB[k][c]; 
			}
		}
		
	}
	
	printf("Matriz A:\n");
	mostram(MA);
	
	printf("Matriz B:\n");
	mostram(MB);
	
	printf("Matriz C:\n");
	mostram(MC);
	
	system("pause");
}

void mostram(int matriz[H][W])
{

	int i,j,c,num = 0;	
	
	printf("   ");	
	for(c=0;c<W;c++) printf("%2d ",c);
	printf("\n");
	
	for(i=0;i<H;i++)
	{
		printf("%2d ",i);
		for(j=0; j<W;j++)
		{
			num = matriz[i][j];
			printf("%2d ",num);
		}
		printf("\n");
	}
}


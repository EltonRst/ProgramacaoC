#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define n 4
/*
void mostram(int mat[n][n]);

void main() {
	
	//int n = 4;
	
	int m1[n][n];
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			m1[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{			
			if(i==j)
			{
				m1[i][j] = 1;				
			}
			if(j>i)
			{
				m1[i][j] = 3;
			}	
			if(j<i)
			{
				m1[i][j] = 4;
			}
			
			if(j==n-i-1)
			{
				m1[i][j] = 2;
			}
			
		}
		//m1[i][n-i-1] = 2;
	}
	
	mostram(m1);
		
	system("pause");
}

void mostram(int mat[n][n])
{

	int i,j,c,num = 0;	
	
	printf("   ");	
	for(c=0;c<n;c++) printf("%2d ",c);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%2d ",i);
		for(j=0; j<n;j++)
		{
			num = mat[i][j];
			printf("%2d ",num);
		}
		printf("\n");
	}
}*/

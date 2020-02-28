#include <stdio.h>
#include <stdlib.h>
#define n 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int contDigitos(int num){
	int dig = 0;
	while(num!=0)
	{
		dig++;
		num/=10;			
	}
	return dig;
}

void main() {
	
	/*int x=0;
	
	while(1){
		x+=10000;
		printf("%d \n",x);	
	}*/
	
	int lin = n;
	int col = n;
	
	int matriz[lin][col];
	
	int i,j,c,num = 0;	
	
	for(i=0;i<lin;i++)
	{
		for(j=0; j<col;j++)
		{
			matriz[i][j] = ++num;
		}
	}

	printf("   ");	
	for(c=0;c<col;c++) printf("%2d ",c);
	printf("\n");
	
	for(i=0;i<lin;i++)
	{
		printf("%2d ",i);
		for(j=0; j<col;j++)
		{
			num = matriz[i][j];
			printf("%2d ",num);
		}
		printf("\n");
	}
	
	system("pause");
}



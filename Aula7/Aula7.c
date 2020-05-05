#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define _QtBombas_  5
#define _Height_   10 
#define _Width_    10
#define _BOMBA_    -8

void MostraTabuleiro(int Tabuleiro[_Height_][_Width_], int TabVisual[_Height_][_Width_])
{
	int i, L, C;

	printf("%c", 201);
	// parte superior da moldura
	for (i = 0; i < _Width_; i++)
	{
		printf("%c%c%c%c%c", 205, 205, 205, 205, 205);
	}
	printf("%c\n", 187);

	for (L = 0; L < _Height_; L++)
	{
		printf("%c", 186);
		for (C = 0; C < _Width_; C++)
		{
			// celula esta aberta?
			if (TabVisual[L][C] == 0)
			{
				switch (Tabuleiro[L][C])
				{
				case -8: printf("  %c  ",/*186*/ 225); break; //188, 200, 201, 205
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:  printf("  %d  ", Tabuleiro[L][C]); break;
				default: printf("  .  "); break;
				}
			}
			else
			{
				printf("  %c  ", 254);
			}
		}
		printf("%c\n", 186);
	}
	printf("%c", 200);
	// parte inferior da moldura
	for (i = 0; i < _Width_; i++)
	{
		printf("%c%c%c%c%c", 205, 205, 205, 205, 205);
	}
	printf("%c\n", 188);
}


void MontaTabuleiro(int Tabuleiro[_Height_][_Width_])
{
	int L, C;
	int qtBombasAlocadas = 0;
	bool achei = false;

	// "limpar" a matriz
	for (L = 0; L < _Height_; L++)
	{
		for (C = 0; C < _Width_; C++)
		{
			Tabuleiro[L][C] = -1;
		}
	}

	// sorteia as posições das bombas
	while (qtBombasAlocadas < _QtBombas_)
	{
		achei = false;
		int X = rand() % (_Width_ - 1); // sorteia uma posição X (coluna)
		int Y = rand() % (_Height_ - 1); // sorteia uma posição Y (linha)

		if (Tabuleiro[Y][X] == _BOMBA_)
		{
			achei = true;
		}

		if (!achei)
		{
			Tabuleiro[Y][X] = _BOMBA_;
			qtBombasAlocadas++;
		}

	}

	// contagem de bombas para cada célula
	int contBombas = 0;
	for (L = 0; L < _Height_; L++)
	{
		for (C = 0; C < _Width_; C++)
		{
			if (Tabuleiro[L][C] != _BOMBA_)
			{
				contBombas = 0;
				// acima - abaixo - direita - esquerda
				if (L > 0)              if (Tabuleiro[L - 1][C] == _BOMBA_) contBombas++; // conta acima
				if (L < (_Height_ - 1)) if (Tabuleiro[L + 1][C] == _BOMBA_) contBombas++; // conta abaixo
				if (C < (_Width_ - 1))  if (Tabuleiro[L][C + 1] == _BOMBA_) contBombas++; // conta a direita
				if (C > 0)              if (Tabuleiro[L][C - 1] == _BOMBA_) contBombas++; // conta a esquerda
				// Diagonais dos cantos
				if (L > 0 && C > 0)							 if (Tabuleiro[L - 1][C - 1] == _BOMBA_) contBombas++; // diag sup esquerda
				if (L > 0 && (C < _Width_ - 1))              if (Tabuleiro[L - 1][C + 1] == _BOMBA_) contBombas++; // diag sup direita
				if (L < (_Height_ - 1) && C < (_Width_ - 1)) if (Tabuleiro[L + 1][C + 1] == _BOMBA_) contBombas++; // diag inf direita
				if (L < (_Height_ - 1) && C > 0)             if (Tabuleiro[L + 1][C - 1] == _BOMBA_) contBombas++; // diag inf esquerda
				//
				Tabuleiro[L][C] = contBombas;
			}
		}
	}

}

void abreCelula(int Tabuleiro[_Height_][_Width_], int TabVisual[_Height_][_Width_], int L, int C)
{
	// Não pode ser bomba e a célula tem que estar vazia e não pode ter sido aberta
	if (Tabuleiro[L][C] != _BOMBA_ /*&& Tabuleiro[L][C] == -1*/ && TabVisual[L][C] != 0)
	{
		// Abre a célula desejada
		TabVisual[L][C] = 0;
		// acima - abaixo - direita - esquerda
		//						// Não pode ser bomba e a célula tem que estar vazia e não pode ter sido aberta
		if (L > 0)              if (Tabuleiro[L - 1][C] != _BOMBA_ /*&& Tabuleiro[L - 1][C] == -1*/ && TabVisual[L - 1][C] != 0) TabVisual[L - 1][C] = 0; //abreCelula(Tabuleiro, TabVisual, L - 1, C); // acima
		if (L < (_Height_ - 1)) if (Tabuleiro[L + 1][C] != _BOMBA_ /*&& Tabuleiro[L + 1][C] == -1*/ && TabVisual[L + 1][C] != 0)TabVisual[L + 1][C] = 0; //abreCelula(Tabuleiro, TabVisual, L + 1, C); // abaixo
		if (C < (_Width_ - 1))  if (Tabuleiro[L][C + 1] != _BOMBA_ /*&& Tabuleiro[L][C + 1] == -1*/ && TabVisual[L][C + 1] != 0)TabVisual[L][C + 1] = 0; //abreCelula(Tabuleiro, TabVisual, L, C + 1); // a direita
		if (C > 0)              if (Tabuleiro[L][C - 1] != _BOMBA_ /*&& Tabuleiro[L][C - 1] == -1*/ && TabVisual[L][C - 1] != 0)TabVisual[L][C - 1] = 0; //abreCelula(Tabuleiro, TabVisual, L, C - 1); // a esquerda
		// Diagonais dos cantos
		if (L > 0 && C > 0)							 if (Tabuleiro[L - 1][C - 1] != _BOMBA_ /*&& Tabuleiro[L - 1][C - 1] == -1*/ && TabVisual[L - 1][C - 1] != 0) TabVisual[L - 1][C - 1] = 0; // diag sup esquerda
		if (L > 0 && (C < _Width_ - 1))              if (Tabuleiro[L - 1][C + 1] != _BOMBA_ /*&& Tabuleiro[L - 1][C + 1] == -1*/ && TabVisual[L - 1][C + 1] != 0) TabVisual[L - 1][C + 1] = 0; // diag sup direita
		if (L < (_Height_ - 1) && C < (_Width_ - 1)) if (Tabuleiro[L + 1][C + 1] != _BOMBA_ /*&& Tabuleiro[L + 1][C + 1] == -1*/ && TabVisual[L + 1][C + 1] != 0) TabVisual[L + 1][C + 1] = 0; // diag inf direita
		if (L < (_Height_ - 1) && C > 0)             if (Tabuleiro[L + 1][C - 1] != _BOMBA_ /*&& Tabuleiro[L - 1][C - 1] == -1*/ && TabVisual[L + 1][C - 1] != 0) TabVisual[L + 1][C - 1] = 0; // diag inf esquerda
	}
}

int main()
{

	int Tabuleiro[_Height_][_Width_];
	int TabVisual[_Height_][_Width_];
	// -1 : celula fechada
	//  0 : celula aberta

	int L, C;

	srand(time(NULL)); // inicia a semente do randomizador

	// teste: abre tabuleiro
	for (L = 0; L < _Height_; L++)
	{
		for (C = 0; C < _Width_; C++)
		{
			TabVisual[L][C] = -1; // todas as células no estado fechado
		}
	}


	MontaTabuleiro(Tabuleiro);

	//TabVisual[5][5] = 0;
	//TabVisual[5][6] = 0;
	//TabVisual[6][5] = 0;
	abreCelula(Tabuleiro, TabVisual, 6, 5);
	//TabVisual[6][6] = 0;


	MostraTabuleiro(Tabuleiro, TabVisual);

	/// Missão!!!!
	// 1 - incluir a contagem de bombas nas demais direções (diagonal superior direita e esquer e diagonal inferior direita e esquerda).
	// 2 - propor uma abordagem para a representação de status ABERTO/FECHADO para cada uma das células do tabuleiro.

}
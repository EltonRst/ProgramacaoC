#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define _QtBombas_  5
#define _Height_   10 
#define _Width_    10
#define _BOMBA_    -8

void MostraTabuleiro(int Tabuleiro[_Height_][_Width_])
{
    int L, C;

    for (L = 0; L < _Height_; L++)
    {
        for (C = 0; C < _Width_; C++)
        {
            printf(" %2d ", Tabuleiro[L][C]);
        }
        printf("\n");
    }

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
                if (L < (_Height_ - 1))  if (Tabuleiro[L + 1][C] == _BOMBA_) contBombas++; // conta abaixo
                if (C < (_Width_ - 1))  if (Tabuleiro[L][C + 1] == _BOMBA_) contBombas++; // conta a direita
                if (C > 0)              if (Tabuleiro[L][C - 1] == _BOMBA_) contBombas++; // conta a esquerda
                // acima - abaixo - direita - esquerda

                Tabuleiro[L][C] = contBombas;
            }
        }
    }

}

int main()
{

    int Tabuleiro[_Height_][_Width_];

    srand(time(NULL)); // inicia a semente do randomizador

    MontaTabuleiro(Tabuleiro);
    MostraTabuleiro(Tabuleiro);

    /// Missão!!!!
    // 1 - incluir a contagem de bombas nas demais direções (diagonal superior direita e esquer e diagonal inferior direita e esquerda).
    // 2 - propor uma abordagem para a representação de status ABERTO/FECHADO para cada uma das células do tabuleiro.

}
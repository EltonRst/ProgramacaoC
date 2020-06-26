/*
// Campo Minado modo texto
// Professor Filipo - filipomor.com
// versão 0.1 Alpha
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define _QtBombas_  8
#define _Height_   10 
#define _Width_    10
#define _BOMBA_    -8
#define _ABERTA_    0
#define _FECHADA_  -1
#define _VAZIA_    -2
#define _BANDEIRA_ -5

int AbreArea(int Tabuleiro[_Height_][_Width_], int TabVisual[_Height_][_Width_], int X /*coluna */, int Y /* linha */, bool celulaAntVazia)
{
	int cont = 0;

	// teste teste
	//printf("TabVisual[%d][%d]: %d  Tabuleiro[%d][%d]: %d \n", Y, X, TabVisual[Y][X], Y, X, Tabuleiro[Y][X]);

	// verifica se posição selecionada pode ser aberta.
	if (TabVisual[Y][X] == _FECHADA_ && Tabuleiro[Y][X] == _VAZIA_)
	{
		TabVisual[Y][X] = _ABERTA_;
		cont++;

		if (Y > 0)              if (TabVisual[Y - 1][X] == _FECHADA_) cont += AbreArea(Tabuleiro, TabVisual, X, Y - 1, true); // conta acima
		if (Y < (_Height_ - 1)) if (TabVisual[Y + 1][X] == _FECHADA_) cont += AbreArea(Tabuleiro, TabVisual, X, Y + 1, true); // conta abaixo
		if (X < (_Width_ - 1))  if (TabVisual[Y][X + 1] == _FECHADA_) cont += AbreArea(Tabuleiro, TabVisual, X + 1, Y, true); // conta a direita
		if (X > 0)              if (TabVisual[Y][X - 1] == _FECHADA_) cont += AbreArea(Tabuleiro, TabVisual, X - 1, Y, true); // conta a direita
	}
	else if (TabVisual[Y][X] == _FECHADA_ && Tabuleiro[Y][X] > 0 && Tabuleiro[Y][X] <= 8 && celulaAntVazia)
	{
		// se a célula selecionada possui uma contagem, esta fechada e foi chamada
		// a partir de uma célula vazia e aberta, entao a abre.
		TabVisual[Y][X] = _ABERTA_;
		cont++;
	}
	else if (TabVisual[Y][X] == _FECHADA_ && Tabuleiro[Y][X] > 0 && Tabuleiro[Y][X] <= 8 && !celulaAntVazia) {
		TabVisual[Y][X] = _ABERTA_;
		cont++;
	}
	else if (TabVisual[Y][X] == _FECHADA_ && Tabuleiro[Y][X] == _BOMBA_) {
		TabVisual[Y][X] = _ABERTA_;
		cont = _BOMBA_;
		// BOMBA, finaliza o jogo
	}
	return (cont);
}

void MostraTabuleiro(int Tabuleiro[_Height_][_Width_],
	int TabVisual[_Height_][_Width_])
{
	int i, L, C;

	// parte superior da moldura
	printf("%c", 201);
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
			if (TabVisual[L][C] == _ABERTA_)
			{
				switch (Tabuleiro[L][C])
				{
				case _BOMBA_: printf("  %c  ", 225); break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:  printf("  %d  ", Tabuleiro[L][C]); break;
				case _BANDEIRA_: printf("  %d  ", 63); break;
				default: printf("  .  "); break;
				}
			}
			else
			{
				if (Tabuleiro[L][C] == _BANDEIRA_) {
					printf("  %c  ", 63);
				}
				else {
					printf("  %c  ", 254);
				}
			}
		}
		printf("%c\n", 186);
	}

	// parte inferior da moldura
	printf("%c", 200);
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
			Tabuleiro[L][C] = _VAZIA_;
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
				if (L > 0)              if (Tabuleiro[L - 1][C] == _BOMBA_) contBombas++; // conta acima
				if (L < (_Height_ - 1)) if (Tabuleiro[L + 1][C] == _BOMBA_) contBombas++; // conta abaixo
				if (C < (_Width_ - 1))  if (Tabuleiro[L][C + 1] == _BOMBA_) contBombas++; // conta a direita
				if (C > 0)              if (Tabuleiro[L][C - 1] == _BOMBA_) contBombas++; // conta a esquerda

				if (L < (_Height_ - 1) && C < (_Width_ - 1)) if (Tabuleiro[L + 1][C + 1] == _BOMBA_) contBombas++; // diag inf direita
				if (L < (_Height_ - 1) && C > 0)             if (Tabuleiro[L + 1][C - 1] == _BOMBA_) contBombas++; // diag inf esquerda
				if (L > 0 && (C < _Width_ - 1))              if (Tabuleiro[L - 1][C + 1] == _BOMBA_) contBombas++; // diag sup direita
				if (L > 0 && C > 0)							     				 if (Tabuleiro[L - 1][C - 1] == _BOMBA_) contBombas++; // diag sup esquerda

				Tabuleiro[L][C] = (contBombas == 0 ? _VAZIA_ : contBombas);
				// caso não exista nenhuma bomba ou contagem igual a zero, entao inicia a célula com o status _VAZIA_.
			}
		}
	}

}

// Função para inserir ou remover bandeira
void Bandeira(int Tabuleiro[_Height_][_Width_], int TabAuxBandeiras[_Height_][_Width_], int l, int c) {
	// Se não existe bandeira na linha e coluna, então adiciona
	if (Tabuleiro[l][c] != _BANDEIRA_) {
		TabAuxBandeiras[l][c] = Tabuleiro[l][c]; // Faz bkp do conteudo original
		Tabuleiro[l][c] = _BANDEIRA_; // Adiciona a bandeira
		printf("Bandeira adicionada !\n");
	}
	// Se já existe a bandeira, então remove
	else {
		// Volta o bkp do tabuleiro de bandeiras
		Tabuleiro[l][c] = TabAuxBandeiras[l][c];
		// Por desencargo de consciência joga a bandeira pro auxiliar de bandeiras
		TabAuxBandeiras[l][c] = _BANDEIRA_;
		printf("Bandeira removida !\n");
	}
}

// Função para abertura ou fechamento de todas as células do tabuleiro
void AbreFechaTabuleiro(int TabVisual[_Height_][_Width_], int AbertaFechada) {
	int L, C;
	for (L = 0; L < _Height_; L++)
	{
		for (C = 0; C < _Width_; C++)
		{
			TabVisual[L][C] = AbertaFechada; // Abre ou fecha todas as células
		}
	}
}

int ContaBandeiras(int Tabuleiro[_Height_][_Width_]) {
	int L, C, nBandeiras = 0;
	for (L = 0; L < _Height_; L++)
	{
		for (C = 0; C < _Width_; C++)
		{
			if (Tabuleiro[L][C] == _BANDEIRA_) nBandeiras++; // bandeiras marcadas
		}
	}
	return nBandeiras;
}

int main()
{
	// Declaramos todas as nossas estruturas
	int Tabuleiro[_Height_][_Width_]; // Tabuleiro de bombas, contagens células vazias
	int TabVisual[_Height_][_Width_]; // Tabuleiro de caracteres visuais
	int TabAuxBandeiras[_Height_][_Width_]; // Tabuleiro de bandeiras

	//srand(time(NULL)); // Iniciamos randomizador

	// Mandamos fechar todo o tabuleiro de visual do jogo
	AbreFechaTabuleiro(TabVisual, _FECHADA_);

	// Montamos o tabuleiro
	MontaTabuleiro(Tabuleiro);
	// Inicializamos a pontuação
	int pontos = 0;

	// Mostramos o tabuleiro inicial
	printf("Campo Minado:\n");
	MostraTabuleiro(Tabuleiro, TabVisual);

	// Laço infinito, enquanto não for quebrado
	while (true) {
		// Solicita para o usuário a ação a ser tomada
		int op = 0;
		printf("Para jogar, digite:\n");
		printf("1 - Abir celula, 2 - Inserir/Remover Bandeira, 3 - Sair do jogo\n");
		scanf_s("%d", &op);
		// Valida a opção de jogada digitada pelo usuário
		if (op < 1 || op >3) {
			printf("Opcao invalida !\n");
			continue;
		}
		// Ação de sair do jogo
		if (op == 3) {
			MostraTabuleiro(Tabuleiro, TabVisual);
			printf("Final de jogo, voce saiu ! sua pontuacao: %d\n", pontos);
			break;
		}
		// Solicita para o usuário a célula onde será efetuada a jogada
		int l = 0, c = 0;
		printf("Digite a linha desejada:\n");
		scanf_s("%d", &l);
		printf("Digite a coluna desejada:\n");
		scanf_s("%d", &c);
		// Valida a célula onde será realizada a jogada
		if (l < 1 || c < 1 || l > _Height_ || c > _Width_) {
			printf("Jogada em linha ou coluna invalidas ! L(%d) C(%d)\n", l, c);
		}
		else {
			// Analisa o tipo de jogada a ser efetuada
			if (op == 1) {
				// Jogada normal, manda abrir a célula
				int celulas = AbreArea(Tabuleiro, TabVisual, c - 1, l - 1, false);
				// Se encontrar uma bomba finaliza o jogo
				if (celulas == _BOMBA_)
				{
					// Mandamos abrir todo o tabuleiro para mostrar as bombas
					AbreFechaTabuleiro(TabVisual, _ABERTA_);
					printf("Campo Minado:\n");
					// Mandamos exibir o tabuleiro
					MostraTabuleiro(Tabuleiro, TabVisual);
					printf("Final de jogo ! Voce abriu uma bomba, sua pontuacao: 0\n");
					break;
				}
				// Incrementa nossos pontos
				pontos += celulas;
			}
			else {
				// Adicionar ou remover bandeira
				Bandeira(Tabuleiro, TabAuxBandeiras, l - 1, c - 1);
			}
			// Faz a contagem das bandeiras já marcadas no tabuleiro
			int nBandeiras = ContaBandeiras(Tabuleiro);
			// Verifica se atingiu a pontuação máxima e marcou todas as bandeiras
			if (pontos == ((_Width_ * _Height_) - _QtBombas_) && _QtBombas_ == nBandeiras) {
				// Mostramos o tabuleiro e finalizamos o jogo
				MostraTabuleiro(Tabuleiro, TabVisual);
				printf("Final de jogo ! Voce venceu por pontuacao maxima, sua pontuacao: %d\n", pontos);
				break;
			}
			// Se atingiu pontuação mas não marcou todas as bombas com bandeiras
			else if (pontos == ((_Width_ * _Height_) - _QtBombas_) && _QtBombas_ != nBandeiras) {
				// Exibimos uma dica para o jogador
				printf("Voce deve marcar todas as bombas com bandeiras para vencer o jogo !\n");
			}
			// Mandamos mostrar o campo e pontuação atual
			printf("Campo Minado:\n");
			MostraTabuleiro(Tabuleiro, TabVisual);
			printf("Pontuacao atual: %d\n", pontos);
		}
	}

	// TODO, ao marcar todas as bandeiras corretamente nos locais das bombas, 
	// finalizar o jogo por pontuação máxima com 100 pontos.
}
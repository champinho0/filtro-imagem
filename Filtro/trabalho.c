#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

// estrutura de um arquivo PGM
typedef struct
{
	char tipo[3];
	char* dados;
	unsigned int largura;
	unsigned int altura;
	unsigned int valormax;
}PGM;

// Função que igrnora os comentários
void ignorecomment(FILE* pgm)
{
	char ch;
	char line[150];
	while(ch = fgetc(pgm) != EOF)
	{
		// Se for # ignora a linha
		if(ch == '#')
		{
			fgets(line, sizeof(line), pgm);
			break;
		}
		else
		{
			fseek(pgm,0,SEEK_CUR);
			break;
		}
	}
}

// Função que abre um arquivo PGM
int openfile(PGM* pgm, char* filename)
{
	// Abre o arquivo no modo de leitura binário
	FILE* pgmfile = fopen(filename, "rb");
	// Se o arquivo não existe, finaliza
	if(!pgmfile) 
	{
		printf("Erro: não foi possível abrir o arquivo '%s'\n", filename);
		exit(1);
	}
	ignorecomment(pgmfile);
	fscanf(pgmfile, "%s",pgm->tipo);
	ignorecomment(pgmfile);
	fscanf(pgmfile, "%d",pgm->largura);
	ignorecomment(pgmfile);
	fscanf(pgmfile, "%d",pgm->altura);
	ignorecomment(pgmfile);
	fscanf(pgmfile, "%d",pgm->valormax);
	fclose(pgmfile);
}
void PGMinfo(PGM* pgm)
{
	printf("Tipo de arquivo: %s\n",pgm->tipo);
	printf("Largura da imagem: %d\n",pgm->largura);
	printf("Altura da imagem: %d\n",pgm->altura);
	printf("Valor máximo do pixel: %d\n",pgm->valormax);
}
int main()
{
	// Configurar acentuação
	setlocale(LC_ALL, "");

	// Alocação dinâmica de memória para leitura da estrutra de um arquivo PGM
	PGM* pgm = malloc(sizeof(PGM));

	// Variável que armazenará o nome do arquivo
	char filename[50];
	printf("Digite o nome do arquivo que será aberto: ");
	scanf("%s",&filename);
	
	//Abertura do arquivo
	openfile(pgm,filename);

	//Exibir informações do arquivo
	PGMinfo(pgm);
}
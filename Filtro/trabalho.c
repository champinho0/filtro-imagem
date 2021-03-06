#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "");
    FILE *arquivo;
    arquivo = fopen("lena.pgm","r");
    if(!arquivo)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    char tipo[2];
    fscanf(arquivo,"%s",&tipo);
    //printf("Tipo de arquivo: %s\n",tipo);
    int linhas, colunas;
    fscanf(arquivo,"%d %d",&colunas,&linhas);
    //printf("Linhas: %d\t Colunas: %d\n",linhas,colunas);
    int max;
    fscanf(arquivo,"%d",&max);
    //printf("Valor m�ximo do pixel: %d\n",max);
    int matriz[linhas][colunas];
    int i,j;
	int sobelh[3][3] = {1,0,-1,2,0,-2,1,0,-1},sobelv[3][3] = {1,2,1,0,0,0,-1,-2,-1};
	for(i=0;i<linhas;i++)
    {
    	for(j=0;j<colunas;j++)
    	{
    		int e = fscanf(arquivo,"%d",&matriz[i][j]);
    		if(!e)
    		{
    			printf("Erro ao ler dados da imagem");
    			exit(1);
			}
			//printf("%d  ",matriz[i][j]);
		}
		//printf("\n");
	}
	fclose(arquivo);
	arquivo = fopen("filtro.pgm","w");
	if(!arquivo)
	{
		printf("Erro ao criar o arquivo");
		exit(1);
	}
	fprintf(arquivo,"%s",tipo);
	fprintf(arquivo,"%c",'\n');
	fprintf(arquivo,"%d %d",colunas,linhas);
	fprintf(arquivo,"%c",'\n');
	fprintf(arquivo,"%d",max);
	fprintf(arquivo,"%c",'\n');
	
	int sobelvf[linhas][colunas], sobelhf[linhas][colunas];
	
	for(i=0;i<colunas;i++)
	{
		sobelvf[0][i]=0;
	}
	for(i=0;i<linhas;i++)
	{
		sobelvf[i][0];
	}

	

	for (i = 1; i < linhas-1; i++)
	{
		for(j = 1; j < colunas-1; j++)
		{
			sobelvf[i][j] = (sobelv[0][0]*matriz[i-1][j-1])+(sobelv[0][1]*matriz[i-1][j])+(sobelv[0][2]*matriz[i-1][j+1])+
							(sobelv[1][0]*matriz[i][j-1])+(sobelv[1][2]*matriz[i][j+1])+
							(sobelv[2][0]*matriz[i+1][j-1])+(sobelv[2][1]*matriz[i+1][j])+(sobelv[2][2]+matriz[i+1][j+1]);
		}
	}
	system("pause");
	
	for(i=0;i<linhas;i++)
    {
    	for(j=0;j<colunas;j++)
    	{
    		int e = fprintf(arquivo,"%d ",sobelvf[i][j]);
    		if(!e)
    		{
    			printf("Erro ao escrever no arquivo");
    			exit(1);
			}
		}
    	fprintf(arquivo,"%c",'\n');
	}
}
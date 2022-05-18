#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *arquivo;
    arquivo = fopen("lena.pgm","rb");
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
    //printf("Valor máximo do pixel: %d\n",max);
    int matriz[linhas][colunas];
    int i,j;
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
	int perc;
	scanf("%d",&perc);
	fclose(arquivo);
	arquivo = fopen("filtro.pgm","w");
	if(!arquivo)
	{
		printf("Erro ao criar o arquivo");
		exit(1);
	}
    tipo[2]='\0';
	fprintf(arquivo,"%s",tipo);
	fprintf(arquivo,"%c",'\n');
	fprintf(arquivo,"%d %d",colunas,linhas);
	fprintf(arquivo,"%c",'\n');
	fprintf(arquivo,"%d",max);
	fprintf(arquivo,"%c",'\n');
	for(i=0;i<linhas;i++)
    {
    	for(j=0;j<colunas;j++)
    	{
    		if(matriz[i][j]>(max*perc/100))
    		matriz[i][j]=max;
			else
			matriz[i][j]=0;
    		//printf("%d  ",matriz[i][j]);
		}
		//printf("\n");
	}
	//system("pause");
	for(i=0;i<linhas;i++)
    {
    	for(j=0;j<colunas;j++)
    	{
    		int e = fprintf(arquivo,"%d ",matriz[i][j]);
    		if(!e)
    		{
    			printf("Erro ao escrever no arquivo");
    			exit(1);
			}
		}
    	fprintf(arquivo,"%c",'\n');
	}
    fclose(arquivo);
}
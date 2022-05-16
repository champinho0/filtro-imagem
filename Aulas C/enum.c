#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Portuguese");
    enum meses {JANEIRO=1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO}meses;
    
    printf("Digite o número referente ao mês: ");
    scanf("%d", &meses);
    switch (meses) {
        case JANEIRO:
            printf("Janeiroooo\n");
            break;
        case FEVEREIRO:
            printf("Fevereiroooo");
            break;
        case MARCO:
            printf("Marçooooooo");
            break;
        case ABRIL:
            printf("Abrilllll");
            break;
        case MAIO:
            printf("Maioooooo");
            break;
        case JUNHO:
            printf("Junhoooooo");
            break;
        case JULHO:
            printf("Julhoooooo");
            break;
        case AGOSTO:
            printf("Agostoooooo");
            break;
        case SETEMBRO:
            printf("Setembroooo");
            break;
        case OUTUBRO:
            printf("Outubrooooooo");
            break;
        case NOVEMBRO:
            printf("Novembroooooo");
            break;
        case DEZEMBRO:
            printf("Dezembrooooo");
            break;
    }

}
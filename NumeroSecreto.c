#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 5 // constante definida  no programa

int main()
{

    printf("               T~~                                                  \n");
    printf("               |                                                    \n");
    printf("              /'\\                                                  \n");
    printf("      T~~     |'| T~~                                               \n");
    printf("  T~~ |    T~ WWWW|                                                 \n");
    printf("  |  /'\\   |  |  |/\\T~~                                          \n");
    printf(" /'\\ WWW  /'\\ |' |WW|                                           \n");
    printf("WWWWW/\\| /   \\|'/\\|/\"\\                  Bem Vindo ao           \n");
    printf("|   /__\\/]WWW[\\/__\\WWWW               Jogo de Advinhacao!        \n");
    printf("|\"  WWWW'|I_I|'WWWW'  |                                            \n");
    printf("|   |' |/  -  \\|' |'  |                                            \n");
    printf("|'  |  |LI=H=LI|' |   |                                             \n");
    printf("|   |' | |[_]| |  |'  |                                             \n");
    printf("|   |  |_|###|_|  |   |                                             \n");
    printf("'---'--'-/___\\-'--'---'                                            \n");

    int segundos = time(0);    // os segundos passados desde 1/01/1970
    srand(segundos);           // Uma nova base de calculo paraa função rand()
    int numeroGrande = rand(); // Gerar valores aleatorios

    int numeroSecreto = numeroGrande % 100; // Devolve um número entre 0 e 99

    int tentativas = 0;
    int chute;

    double pontos = 1000;
    int numeroDeTentativas;
    int nivel;
    printf("Qual o nivel de  dificuldade: ");
    printf("(1) Facil  (2) Medio  (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel) // Escolher nível com stwich e com if
    {
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    default:
        numeroDeTentativas = 6;
        break;
    }

    // if (nivel == 1)
    //     numeroDeTentativas = 20;
    // else if (nivel == 2)
    //     numeroDeTentativas = 15;
    // else
    //     numeroDeTentativas = 6;

    for (int i = 1; i <= numeroDeTentativas; i++)
    {
        tentativas++;
        printf("Tentaiva: %d de %d\n", tentativas, numeroDeTentativas);
        printf("Qual o seu chute? \n");
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar valores negativos");
            tentativas--;
            continue;
        }
        else if (chute == numeroSecreto)
            break;

        if (chute < numeroSecreto)
            printf("Seu numero e MENOR que o numero secreto\n");
        else if (chute > numeroSecreto)
            printf("Seu numero e MAIOR que o numero secreto\n");

        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;

        pontos = -pontosPerdidos;
    }

    printf("Fim de jogo!\n");
    if (tentativas >= numeroDeTentativas)
    {
        printf("       \\|/ ____ \\|/                                       \n");   
        printf("        @~/ ,. \\~@             Voce perdeu!                \n");   
        printf("       /_( \\__/ )_\\    Voce nao acertou o numero secreto  \n");   
        printf("          \\__U_/                                           \n");
    }
    else
    {

        printf("       {}                                        \n");
        printf("      /__\\                                      \n");
        printf("    /|    |\\               Voce Ganhou!         \n");
        printf("   (_|    |_)            Total de pontos: %.1f   \n", pontos);
        printf("      \\  /                                      \n");
        printf("       )(                                        \n");
        printf("     _|__|_                                      \n");
        printf("   _|______|_                                    \n");
        printf("  |__________|                                   \n");
    }
}
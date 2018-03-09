#include <pthread.h>
#include <stdio.h>





void escreve()
{
    printf("Exemplo Com thread",);
    pthread_exit(NULL);
}
void escreve2()


void main()
{
        pthread_create(&threads[0], NULL, escreve, 0);
    pthread_exit(NULL); /* se a função main não terminar com a função phtread_exit o ultimo

thread não chega a terminar a sua execução */

}

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
    pthread_exit(NULL); /* se a fun��o main n�o terminar com a fun��o phtread_exit o ultimo

thread n�o chega a terminar a sua execu��o */

}

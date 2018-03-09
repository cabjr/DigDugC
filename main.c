#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <conio.c>
#include <time.h>
#include <math.h>
#include <string.h>
#include <dos.h>

#define LINHAS 20
#define COLUNAS 20
#define PERSONAGEM 254
#define MONSTRO 234
#define PEDRA 200
// ****** VARIÁVEIS GLOBAIS ********


// ****************
int b1=1,contp1=0,contp2=0,b2=1,contb1=0,contb2=0,p1=1,p2=1,
    posxI=COLUNAS/2,
    posyI=LINHAS/2,
    posx=COLUNAS/2,
    posy=LINHAS/2,
    posxBixo1=COLUNAS/3,
    posyBixo1=LINHAS/3,
    posxBixo2=2*COLUNAS/3,
    posyBixo2=2*LINHAS/3,
    posxBixo1I=COLUNAS/3,
    posyBixo1I=LINHAS/3,
    posxBixo2I=2*COLUNAS/3,
    posyBixo2I=2*LINHAS/3,
    posxPedra1=(COLUNAS/3)+6,
    posyPedra1=(LINHAS/3)-2,
    posxPedra2=(COLUNAS/2)-3,
    posyPedra2=(LINHAS/3)+3;
char mapa[LINHAS][COLUNAS],comando;

void GOTOXY(int x, int y){
    COORD c;
    c.X = x-1;
    c.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}



void moldura()
{
    int i,laterais=186,cima=205,cantoe=201,cantod=187,cantoee=200,cantodd=188;
    GOTOXY(9,4);
    printf("%c",cantoe);
    GOTOXY(COLUNAS+10,4);
    printf("%c",cantod);
    GOTOXY(9,LINHAS+5);
    printf("%c",cantoee);
    GOTOXY(COLUNAS+10,LINHAS+5);
    printf("%c",cantodd);
    for(i=0; i<= COLUNAS-1; i++)
    {
       // GOTOXY(j+10, i+5); BASE MAPA
        GOTOXY(i+10, 4);
        printf("%c",cima);
        GOTOXY(i+10, 5+LINHAS);
        printf("%c",cima);
    }
    for(i=0; i<= LINHAS-1; i++)
    {
        GOTOXY(9, i+5);
        printf("%c",laterais);
        GOTOXY(COLUNAS+10, i+5);
        printf("%c",laterais);
    }
}

void criarmat(char mapa[LINHAS][COLUNAS])
{
    int i,j;
    for (i=0; i<= LINHAS-1; i++)
    {
        for(j=0; j<= COLUNAS-1; j++)
        {
      /*   if (j== posx && i == posy)
         {
             mapa[i][j] = ascipersonagem;
         }
         else if (j== posxBixo1 && i == posyBixo1)
         {
             mapa[i][j] = MONSTRO;
         }
         else
         {
             mapa[i][j] = 176;
         }*/
         mapa[i][j] = 176;
         mapa[2*LINHAS/3][(2*COLUNAS/3)-1]=' ';
         mapa[2*LINHAS/3][2*COLUNAS/3]=' ';
         mapa[2*LINHAS/3][(2*COLUNAS/3)+1]=' ';
         mapa[LINHAS/3][(COLUNAS/3)-1]=' ';
         mapa[LINHAS/3][COLUNAS/3]=' ';
         mapa[LINHAS/3][(COLUNAS/3)+1]=' ';
         mapa[LINHAS/2][(COLUNAS/2)+1]=' ';
         mapa[LINHAS/2][(COLUNAS/2)-1]=' ';
        mapa[posyPedra1][posxPedra1]= PEDRA;
        mapa[posyPedra2][posxPedra2]= PEDRA;
        }
    }
    // MONSTROS:



    //FIM MONSTROS
}

void escrevermat(char mapa[LINHAS][COLUNAS])
{
    int i,j;
    for(i=0; i<=LINHAS-1; i++)
    {
        for(j=0; j<=COLUNAS-1; j++)
        {
                GOTOXY(j+10,i+5);
                if (i== posy && j == posx)
                {
                    textcolor(WHITE);
                    printf("%c", PERSONAGEM);
                }
                else if (i== posyBixo1 && j==posxBixo1 && b1==1 || i== posyBixo2 && j==posxBixo2 && b2==1 )
                {
                    textcolor(DARKGRAY);
                    printf("%c", MONSTRO);
                }
                else if (i == posyPedra1 && j == posxPedra1 && p1==1 ||i == posyPedra2 && j == posxPedra2 && p2==1)
                {
                    textcolor(GREEN);
                    printf("%c", PEDRA);
                }
                else
                {
                    if (i < (LINHAS)/4)
                    {
                        textcolor(YELLOW);
                        printf("%c", mapa[i][j]);
                    }
                    else if (i >= (LINHAS)/4 && i < 2*(LINHAS)/4)
                    {
                        textcolor(BROWN);
                        printf("%c", mapa[i][j]);
                    }
                    else if (i >= 2*(LINHAS)/4 && i < 3*(LINHAS)/4)
                    {
                       textcolor(LIGHTRED);
                       printf("%c", mapa[i][j]);
                    }
                    else if (i >= 3*(LINHAS)/4)
                    {
                        textcolor(RED);
                        printf("%c",mapa[i][j]);
                    }

                }
                textcolor(BLACK);


        }
    }
}


void recorde(int *pontuacao)
{
    FILE *fp;
    int c;
    textcolor(WHITE);
    GOTOXY(2,3);
    printf("As melhores pontuacoes foram: \n");
    fp = fopen("dados.txt","r");
    while(1)
    {
      c = fgetc(fp);
      if(feof(fp))
      {
          break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   printf("Aperte qualquer tecla para prosseguir...");
   getch();
   system("cls");
   main();
}

void EscreverPontos(int *pontuacao)
{

    textcolor(rand()%10);
    GOTOXY(16,2);
    printf("%d",*pontuacao);
}

void EscVidas(int *vivo)
{
    textcolor(LIGHTRED);
    GOTOXY(25,2);
    printf("Vidas Restantes: %d",*vivo-1);
}

float distancia(int xp,int yp,int bx,int by)
{
    float DistanciaAtePlayer=0;
    DistanciaAtePlayer = sqrt((xp-bx)^2+(yp-by)^2);
    return DistanciaAtePlayer;
}

void MovimentoBixoUm(char mapa[LINHAS][COLUNAS])
{
int flag=0,esquerda,direita,cima,baixo,dir;
if (b1==1)
{
/* BIXO PELA FORMULA DA DISTANCIA E COMPARAÇÃO DE OPCOES
esquerda = distancia(posx,posy,posxBixo1-1,posyBixo1);
direita = distancia(posx,posy,posxBixo1+1,posyBixo1);
cima = distancia(posx,posy,posxBixo1,posyBixo1-1);
baixo = distancia(posx,posy,posxBixo1,posyBixo1+1);
dir = rand()%3;

if (esquerda < direita && esquerda < cima && esquerda < baixo && mapa[posyBixo1][posxBixo1-1]!= 176 && posxBixo1>0)
{
    mapa[posyBixo1][posxBixo1] = ' ';
    posxBixo1--;
}
else if (direita < esquerda && direita < cima && direita < baixo && mapa[posyBixo1][posxBixo1+1]!= 176 && posxBixo1<COLUNAS-1)
{
    mapa[posyBixo1][posxBixo1] = ' ';
    posxBixo1++;
}
else if (cima < esquerda && cima < direita && cima < baixo && mapa[posyBixo1-1][posxBixo1]!= 176 && posyBixo1 > 0)
{
    mapa[posyBixo1][posxBixo1] = ' ';
    posyBixo1--;
}
else if (baixo < esquerda && baixo < cima && baixo < direita && mapa[posyBixo1+1][posxBixo1]!= 176 && posyBixo1<LINHAS-1)
{
    mapa[posyBixo1][posxBixo1] = ' ';
    posyBixo1++;
}
*///BIXO PELA FORMULA DA DISTANCIA E COMPARAÇÃO DE OPCOES


if (contb1 >= 5)
{
contb1=0;
    flag=rand()%4;
    if(distancia(posx,posy,posxBixo1+1,posyBixo1) < distancia(posx,posy,posxBixo1,posyBixo1) && mapa[posyBixo1][posxBixo1+1] == ' ' && posxBixo1 <= COLUNAS)
    {
    mapa[posyBixo1][posxBixo1] = ' ';
    posxBixo1=posxBixo1+1;
    mapa[posyBixo1][posxBixo1] = MONSTRO;
    }
    else if (distancia(posx,posy,posxBixo1-1,posyBixo1) > distancia(posx,posy,posxBixo1,posyBixo1) && mapa[posyBixo1][posxBixo1-1] == ' ' && posxBixo1 >= 1 )
    {
    mapa[posyBixo1][posxBixo1] = ' ';
    posxBixo1=posxBixo1-1;
    mapa[posyBixo1][posxBixo1] = MONSTRO;
    }
    else if(distancia(posx,posy,posxBixo1,posyBixo1+1) < distancia(posx,posy,posxBixo1,posyBixo1)&& posyBixo1 <= COLUNAS-1 )
    {
        if (mapa[posyBixo1+1][posxBixo1] != 176)
        {
        mapa[posyBixo1][posxBixo1] = ' ';
        posyBixo1=posyBixo1+1;
        mapa[posyBixo1][posxBixo1] = MONSTRO;
        }
    }
    else if (distancia(posx,posy,posxBixo1,posyBixo1-1) > distancia(posx,posy,posxBixo1,posyBixo1) && mapa[posyBixo1-1][posxBixo1] == ' ' && posyBixo1 >= 1 )
    {
    mapa[posyBixo1][posxBixo1] = ' ';
    posyBixo1=posyBixo1-1;
    mapa[posyBixo1][posxBixo1] = MONSTRO;
    }/*
    else
    {
        if(flag == 1 && mapa[posyBixo1][posxBixo1+1] == ' ' && posxBixo1 < COLUNAS-1)
        {
        mapa[posyBixo1][posxBixo1] = ' ';
        posxBixo1=posxBixo1+1;
        mapa[posyBixo1][posxBixo1] = MONSTRO;
        }
        else if (flag == 3 && mapa[posyBixo1][posxBixo1-1] == ' ' && posxBixo1 >= 1 )
        {
        mapa[posyBixo1][posxBixo1] = ' ';
        posxBixo1=posxBixo1-1;
        mapa[posyBixo1][posxBixo1] = MONSTRO;
        }
        else if(flag == 2 && mapa[posyBixo1+1][posxBixo1] == ' ' && posyBixo1 < LINHAS-1 )
        {
        mapa[posyBixo1][posxBixo1] = ' ';
        posyBixo1= posyBixo1+1;
        mapa[posyBixo1][posxBixo1] = MONSTRO;
        }
        else if (flag == 0 && mapa[posyBixo1-1][posxBixo1] == ' ' && posyBixo1 >= 1 )
        {
        mapa[posyBixo1][posxBixo1] = ' ';
        posyBixo1=posyBixo1-1;
        mapa[posyBixo1][posxBixo1] = MONSTRO;
        }
    }*/


}
else
{
contb1++;
}

}
else
{
mapa[posyBixo1][posxBixo1] = ' ';
}

}
//Sleep(100);



void MovimentoBixoDois(char mapa[LINHAS][COLUNAS])
{
int flag=0;
flag=rand()%4;

if (b2==1)
{
    if(contb2>= 20)
    {

        if(flag == 0 && mapa[posyBixo2][posxBixo2+1] == ' ' && posxBixo2 < COLUNAS-1)
        {
        mapa[posyBixo2][posxBixo2] = ' ';
        posxBixo2 = posxBixo2+1;
        mapa[posyBixo2][posxBixo2] = MONSTRO;
        contb2=0;
        }
        else if (flag == 1 && mapa[posyBixo2][posxBixo2-1] == ' ' && posxBixo2 >= 1 )
        {
        mapa[posyBixo2][posxBixo2] = ' ';
        posxBixo2= posxBixo2-1;
        mapa[posyBixo2][posxBixo2] = MONSTRO;
        contb2=0;
        }
        else if(flag == 2 && mapa[posyBixo2+1][posxBixo2] == ' ' && posyBixo2 < LINHAS-1)
        {
        mapa[posyBixo2][posxBixo2] = ' ';
        posyBixo2= posyBixo2+1;
        mapa[posyBixo2][posxBixo2] = MONSTRO;
        contb2=0;
        }
        else if (flag == 3 && mapa[posyBixo2-1][posxBixo2] == ' ' && posyBixo2 >= 1 )
        {
        mapa[posyBixo2][posxBixo2] = ' ';
        posyBixo2=posyBixo2-1;
        mapa[posyBixo2][posxBixo2] = MONSTRO;
        contb2=0;
        }

    }
       //Sleep(150);
    else
    {
        contb2++;
    }
}
else
{
    mapa[posyBixo2][posxBixo2] = ' ';
}

}


void verificaPedra(char mapa[LINHAS][COLUNAS],int *pontuacao,int px,int py)
{
    int cont2=0;

if (p1 ==1)
{

    if (mapa[py+1][px] == ' ' || py+1 == posyBixo1 && px == posxBixo1|| py+1 == posyBixo2 && px == posxBixo2)
    {
        if (contp1 >= 15)
        {
           contp1=0;
            while(1)
            {
                if (mapa[py+1][px] == ' ')
                {
                mapa[py][px] = ' ';
                py=py+1;
                    if (py+1== posyBixo1 && px == posxBixo1)
                    {
                        b1 =0;
                        *pontuacao=*pontuacao+10000;

                    }
                    if (py+1== posyBixo2 && px == posxBixo2)
                    {
                        b2 =0;
                        *pontuacao=*pontuacao+10000;
                    }
                }
                else
                {
                    break;
                }

            }
            escrevermat(mapa);
            p1=0;

        }
        else
        {
            contp1++;
        }

    }
}
}

void verificaPedra2(char mapa[LINHAS][COLUNAS],int *pontuacao,int px,int py)
{
    int cont2=0;

if (p2 ==1)
{

    if (mapa[py+1][px] == ' ' || py+1 == posyBixo1 && px == posxBixo1|| py+1 == posyBixo2 && px == posxBixo2)
    {
        if (contp2 >= 15)
        {
           contp1=0;
            while(1)
            {
                if (mapa[py+1][px] == ' ')
                {
                mapa[py][px] = ' ';
                py=py+1;
                    if (py+1== posyBixo1 && px == posxBixo1)
                    {
                        b1 =0;
                        *pontuacao=*pontuacao+10000;

                    }
                    if (py+1== posyBixo2 && px == posxBixo2)
                    {
                        b2 =0;
                        *pontuacao=*pontuacao+10000;
                    }
                }
                else
                {
                    break;
                }

            }
            escrevermat(mapa);
            p2=0;

        }
        else
        {
            contp2++;
        }

    }
}
}


int Perdeu(int *vivo, int *pontuacao)
{
    char nome[50],pont[30];
    if (*vivo > 0)
    {
        if (posx == posxBixo1 && posy == posyBixo1 && b1 == 1 || posx == posxBixo2 && posy == posyBixo2 && b2==1 || posx == posxPedra1 && posy == posyPedra1 && p1 == 1)
        {
            GOTOXY(10,LINHAS+6);
            textcolor(WHITE);
            printf("Voce Morreu. Mas ainda possui %d chances",*vivo-1);
            Sleep(1500);
            GOTOXY(10,LINHAS+6);
            textcolor(WHITE);
            printf("                                        ");
            *vivo -= 1;
            mapa[posy][posx] = ' ';
            mapa[posyBixo1][posxBixo1] = ' ';
            mapa[posyBixo2][posxBixo2] = ' ';
            posxBixo1 = posxBixo1I;
            posyBixo1 = posyBixo1I;
            posxBixo2 = posxBixo2I;
            posyBixo2 = posyBixo2I;
            posx = posxI;
            posy = posyI;
            GOTOXY((COLUNAS/2)+10,(LINHAS/2)+5);
            printf("3");
            Sleep(500);
            GOTOXY((COLUNAS/2)+10,(LINHAS/2)+5);
            printf("2");
            Sleep(500);
            GOTOXY((COLUNAS/2)+10,(LINHAS/2)+5);
            printf("1");
            GOTOXY((COLUNAS/2)+10,(LINHAS/2)+5);
            textcolor(WHITE);
            Sleep(500);
            return 0;
        }
    }
    else
    {

        GOTOXY(10,LINHAS+6);
        textcolor(WHITE);
        printf("Voce Morreu.\n Novo Recorde!\n Insira seu nome para salva-lo: ");
        FILE *fptr;
        fptr=fopen("dados.txt","a"); // "a" = abre ou cria arquivo p/ atualizar, "w" cria ou sobreescreve arquivo ja existente.
        fflush(stdin);
        gets(nome);
        fprintf(fptr, "[%d] - %s\n", *pontuacao, nome);
        fclose(fptr);
        Sleep(1000);
        printf("Retornando ao menu Inicial.");
        Sleep(350);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(350);
        system("cls");
        main();
        return 1;
    }
}


void movimentoPlayer(char *comando,int *pontuacao)
{
                if (*comando == 'A' && posx > 0 && mapa[posy][posx-1] != PEDRA || *comando == 'a' && posx > 0 && mapa[posy][posx-1] != PEDRA )
                {
                    mapa[posy][posx] = ' ';
                    posx--;
                    if (mapa[posy][posx] != ' ' && mapa[posy][posx] != 234)
                    {
                        *pontuacao += 100;
                    }
                    mapa[posy][posx] = PERSONAGEM;
                }
                else if (*comando == 'D' && posx < COLUNAS-1 && mapa[posy][posx+1] != PEDRA  || *comando == 'd' && posx < COLUNAS-1 && mapa[posy][posx+1] != PEDRA )
                {
                    mapa[posy][posx] = ' ';
                    posx++;
                    if (mapa[posy][posx] != ' ' && mapa[posy][posx] != 234)
                    {
                        *pontuacao += 100;
                    }
                    mapa[posy][posx] = PERSONAGEM;
                }

                else if (*comando == 'w' && posy > 0 && mapa[posy-1][posx] != PEDRA || *comando == 'W' && posy > 0 && mapa[posy-1][posx] != PEDRA )
                {
                    mapa[posy][posx] = ' ';
                    posy--;
                    if (mapa[posy][posx] != ' ' && mapa[posy][posx] != 234)
                    {
                        *pontuacao += 100;
                    }
                    mapa[posy][posx] = PERSONAGEM;
                }
                else if (*comando == 's' && posy < LINHAS-1 && mapa[posy+1][posx] != PEDRA || *comando == 'S' && posy < LINHAS-1 && mapa[posy+1][posx] != PEDRA )
                {
                    mapa[posy][posx] = ' ';
                    posy++;
                    if (mapa[posy][posx] != ' ' && mapa[posy][posx] != 234)
                    {
                        *pontuacao += 100;
                    }
                    mapa[posy][posx] = PERSONAGEM;
                }

}

int main()
{
CONSOLE_CURSOR_INFO CURSOR;
HWND StdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CURSOR.bVisible = FALSE;
CURSOR.dwSize = 1;
SetConsoleCursorInfo(StdHandle, &CURSOR);
int i,
    j,
    mpontuacao,
    pontuacao=0,
    ascipersonagem=PERSONAGEM,
    opcao,
    vivo=0;
    srand(time(NULL));
    opcao = 0;
    vivo = 4;
    printf("\nMenu\n\n1-Jogar\n\n2-Ver Recorde\n\n3-Sair\n");
    printf("\nDigite a Opcao desejada.\n\n");
    //Beep(120,10);
    //system("digdug.mid"); // SOM
    scanf("%i", &opcao);
    system("cls");
    switch(opcao){
        case 1:
            moldura();
            criarmat(mapa);
            pontuacao=0;
            GOTOXY(8,2);
            textcolor(WHITE);
            printf("Pontos: ");
        do{
            if (kbhit())
            {
                comando = getch();
                movimentoPlayer(&comando,&pontuacao);
                if (Perdeu(&vivo,&pontuacao)== 1)
                {
                    break;
                }
                else
                {
                    fflush(stdin);
                    EscreverPontos(&pontuacao);
                    EscVidas(&vivo);
                    MovimentoBixoUm(mapa);
                    MovimentoBixoDois(mapa);
                    verificaPedra(mapa,&pontuacao,posxPedra1,posyPedra1);
                    verificaPedra2(mapa,&pontuacao,posxPedra2,posyPedra2);
                    escrevermat(mapa);
                }
                }
            else
            {
                if (Perdeu(&vivo,&pontuacao)== 1)
                {
                    break;
                }
                EscreverPontos(&pontuacao);
                EscVidas(&vivo);
                MovimentoBixoUm(mapa);
                MovimentoBixoDois(mapa);
                verificaPedra(mapa,&pontuacao,posxPedra1,posyPedra1);
                verificaPedra2(mapa,&pontuacao,posxPedra2,posyPedra2);
                escrevermat(mapa);
            }
        }while(comando!= 27);
            break;
        case 2:
            recorde(&mpontuacao);
            break;
        case 3:
            system("pause");
            break;
    }
}


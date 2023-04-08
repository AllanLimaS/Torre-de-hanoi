/*
            _________________
           |    CREDITOS:    |
           |                 |
           |  Allan De Lima  |
           |  Gustavo Mafra  |
           |   João Kogut    |
           |_________________|

*/

#include <stdio.h>
#include <stdlib.h>
#include "codefun.h"
#include <windows.h>

void DELAY(){       //VOID UTILIZADO PARA DEFINIR A VELOCIDADE DA TELA DE TRANSIÇÃO.
    int i;
    while(i < 300000){
        i++;
    }
}

void DELAY2(){      //VOID ULTILIZADO PARA DEFINIR A VELOCIDADE DA TELA DE TRANSIÇÃO DA VITÓRIA.
    int i;
    while(i< 2000000){
        i++;
    }
}

void TRANSICAO(){   // VOID UTILIZADO PARA FAZER A ANIMACAO DA TELA
    int i, L =0;
    Beep(900,80);
    gotoxy(0,1);
    for(i=1;i != 22 && L < 34; i++){
        if(i<21){
            printf("#####");
            DELAY();
        }else{
            printf("\n");
            i=0;
            L = L + 1;
        }                                   //ANIMAÇÂO
    }
    for(i=1, L = 0 ;i != 21 && L < 34; i++){
        if(i<20){
            printf("     ");
            DELAY();
        }else{
            printf("\n");
            i=0;
            L = L + 1;
        }
    }
}

int MENU(){   // FUNÇÃO MENU COM RETORNO PARA O MAIN

    int i=0, op=3, seta=0;
    for(i=0;i<100;i++){
        printf("#");                // MONTAR O QUADRO (DECORATIVO)
    }
    for(i=0;i<34;i++){
        printf("\n");
    }
    for(i=0;i<100;i++){
        printf("#");
    }

    gotoxy(50, 10);
    printf("JOGO");
    gotoxy(43, 11);
    printf("DO CARA DA PIRAMIDE");

    gotoxy(48, 16);
    printf("[]JOGAR");
    gotoxy(47, 19);
    printf("[]CREDITOS");
    gotoxy(46, 22);
    printf("[]INTRUCOES");
    gotoxy(48, 25);
    printf("[]SAIR");


    switch(op){
        case 3:
            gotoxy(42, 16);
            printf("->");
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 2:
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42, 19);
            printf("->");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 1:
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42,22);
            printf("->");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 0:
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("->");
            gotoxy(1,1);
        break;

        }

    while(getch() != 13){           //SELEÇÃO COM SETAS
        seta = getch();

        if(seta == 72){
            Beep(500,30);
            if(op == 3){
                op = 0;
            }else{
                op++;
            }
        }
        if(seta != 72){
            Beep(500,30);
            if(op == 0){
                op = 3;
            }else{
                op--;
            }

        }

        switch(op){
        case 3:
            gotoxy(42, 16);
            printf("->");
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 2:
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42, 19);
            printf("->");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 1:
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42,22);
            printf("->");
            gotoxy(42,25);
            printf("  ");
            gotoxy(1,1);
        break;

        case 0:
            gotoxy(42, 19);
            printf("  ");
            gotoxy(42, 16);
            printf("  ");
            gotoxy(42,22);
            printf("  ");
            gotoxy(42,25);
            printf("->");
            gotoxy(1,1);
        break;

        }
    }

    TRANSICAO();        //CHAMADA PARA A ANIMAÇÃO APOS SELECIONADA A OPÇÃO

    return op;
}

void IMPRIME_DISCO(int i, int j, int LIMITE, int COLUNA, int COR){  //VOID RESPONSÁVEL PELA IMPRESSÃO DE CADA DISCO
    for( ;i<=LIMITE;i++,j--){
        gotoxy(i,COLUNA);       //FAZ A IMPRESSÃO PARA A DIREITA
        textcolor(COR,COR);     //TEXTCOLOR COM DOIS VALORES IGUAIS, PARA SE CRIAR UM BLOCO MACIÇO DE APENAS UMA COR
        printf("0");
        gotoxy(j,COLUNA);       //FAZ A IMPRESSÃO PARA A ESQUERDA
        printf("0");
    }
}

void IMPRIME(int jogadas,int posteA[7],int posteB[7],int posteC[7]){ //BLOCO ONDE SERA IMPRESSO AS INFORMÇÕES DURANTE O JOGO

    textcolor(8,0);
    gotoxy(16,12);
    printf(" _______________________________		 ________________________");
    gotoxy(16,13);
    printf("|                               |		|                        |");       //BLOCO ONDE SERA IMPRESSO AS INFORMÇÕES DURANTE O JOGO
    gotoxy(16,14);
    printf("|_______________________________|		|________________________|");

    gotoxy(67,13);
    textcolor(15,0);
    printf("NUMERO DE JOGADAS: %d",jogadas);

////////////////////////////////////posteA

    switch(posteA[6]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 6 DO POSTE ( A MAIS ALTA )

                                        //CASO FOR O DISCO 7 ( O MAIOR DE TODOS )
    case 7:                             // INFORMAÇÕES DO DISCO PARA SER FEITA A IMPRESSÃO:
        IMPRIME_DISCO(30,30,36,28,7);   //IMPRIME_DISCO("I" E "J" CONTADORES E SÃO TBM QUEM DEFINE EM QUAL POSTE ESTA O DISCO,"LIMITE" SENDO
        break;                          //O LIMITE QUE DEFINIRA O TAMANHO DO DISCO,"COLUNA" DEFINE A POSIÇÃO VERTICAL DO DISCO,"COR" DEFINE
                                        //A QUER QUE SERÁ USADAD PARA PINTAR O DISCO.

    case 6:                             //CASO FOR O DISCO 6 ( O SEGUNDO MAIOR )
        IMPRIME_DISCO(30,30,35,28,6);
        break;
    case 5:                             //CASO FOR O DISCO 5
        IMPRIME_DISCO(30,30,34,28,5);
        break;
    case 4:                             //DISCO 4
        IMPRIME_DISCO(30,30,33,28,4);
        break;
    case 3:                             //DISCO 3
        IMPRIME_DISCO(30,30,32,28,3);
        break;
    case 2:                             //DISCO 2
        IMPRIME_DISCO(30,30,31,28,2);
        break;
    case 1:                             //DISCO 1 ( O MENOR DE TODOS )
        IMPRIME_DISCO(30,30,30,28,9);
        break;
    case 0:                             //SE CASO NÃO HOUVER NENHUM DISCO NESTA POSIÇÃO DO POSTE
        textcolor(15,0);                //SERÁ IMPRESSO UM RISCO, PARA REPRESENTAR O POSTE VAZIO
        gotoxy(30,28);
        printf("|");
        break;
    }

    switch(posteA[5]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 5 DO POSTE
    case 7:                             //A MESMA LÓGICA UTILIZADA PARA O SWITCH "posteA[6]" TENDO COMO UNICA DIFERENÇA A
        IMPRIME_DISCO(30,30,36,27,7);   //A VARIAVEL "COLUNA" QUE DEFINE A POSIÇÃO VERTICAL DO DISCO
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,27,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,27,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,27,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,27,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,27,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,27,9);
        break;
    case 0:
            textcolor(15,0);
            gotoxy(30,27);
            printf("|");
            break;
    }

    switch(posteA[4]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 4 DO POSTE
    case 7:
        IMPRIME_DISCO(30,30,36,26,7);
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,26,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,26,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,26,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,26,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,26,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,26,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(30,26);
        printf("|");
        break;
    }

    switch(posteA[3]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 3 DO POSTE
    case 7:
        IMPRIME_DISCO(30,30,36,25,7);
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,25,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,25,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,25,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,25,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,25,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,25,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(30,25);
        printf("|");
        break;
    }

    switch(posteA[2]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 2 DO POSTE
    case 7:
        IMPRIME_DISCO(30,30,36,24,7);
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,24,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,24,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,24,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,24,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,24,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,24,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(30,24);
        printf("|");
        break;
    }

    switch(posteA[1]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 1 DO POSTE
    case 7:
        IMPRIME_DISCO(30,30,36,23,7);
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,23,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,23,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,23,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,23,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,23,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,23,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(30,23);
        printf("|");
        break;
    }

    switch(posteA[0]){      //VERIFICA QUAL O DISCO PRESENTE NA POSIÇÃO 0 DO POSTE ( A BASE DO POSTE )
    case 7:
        IMPRIME_DISCO(30,30,36,22,7);
        break;
    case 6:
        IMPRIME_DISCO(30,30,35,22,6);
        break;
    case 5:
        IMPRIME_DISCO(30,30,34,22,5);
        break;
    case 4:
        IMPRIME_DISCO(30,30,33,22,4);
        break;
    case 3:
        IMPRIME_DISCO(30,30,32,22,3);
        break;
    case 2:
        IMPRIME_DISCO(30,30,31,22,2);
        break;
    case 1:
        IMPRIME_DISCO(30,30,30,22,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(30,22);
        printf("|");
        break;
    }

/////////////////////////////////////posteB

    switch(posteB[6]){
    case 7:
        IMPRIME_DISCO(45,45,51,28,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,28,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,28,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,28,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,28,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,28,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,28,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,28);
        printf("|");
        break;
    }

    switch(posteB[5]){
    case 7:
        IMPRIME_DISCO(45,45,51,27,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,27,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,27,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,27,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,27,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,27,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,27,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,27);
        printf("|");
        break;
    }

    switch(posteB[4]){
    case 7:
        IMPRIME_DISCO(45,45,51,26,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,26,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,26,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,26,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,26,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,26,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,26,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,26);
        printf("|");
        break;
    }

    switch(posteB[3]){
    case 7:
        IMPRIME_DISCO(45,45,51,25,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,25,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,25,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,25,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,25,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,25,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,25,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,25);
        printf("|");
        break;
    }

    switch(posteB[2]){
    case 7:
        IMPRIME_DISCO(45,45,51,24,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,24,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,24,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,24,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,24,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,24,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,24,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,24);
        printf("|");
        break;
    }

    switch(posteB[1]){
    case 7:
        IMPRIME_DISCO(45,45,51,23,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,23,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,23,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,23,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,23,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,23,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,23,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,23);
        printf("|");
        break;
    }

    switch(posteB[0]){
    case 7:
        IMPRIME_DISCO(45,45,51,22,7);
        break;
    case 6:
        IMPRIME_DISCO(45,45,50,22,6);
        break;
    case 5:
        IMPRIME_DISCO(45,45,49,22,5);
        break;
    case 4:
        IMPRIME_DISCO(45,45,48,22,4);
        break;
    case 3:
        IMPRIME_DISCO(45,45,47,22,3);
        break;
    case 2:
        IMPRIME_DISCO(45,45,46,22,2);
        break;
    case 1:
        IMPRIME_DISCO(45,45,45,22,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(45,22);
        printf("|");
        break;
    }

///////////////////////////////////posteC

    switch(posteC[6]){
    case 7:
        IMPRIME_DISCO(60,60,66,28,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,28,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,28,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,28,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,28,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,28,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,28,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,28);
        printf("|");
        break;
    }

    switch(posteC[5]){
    case 7:
        IMPRIME_DISCO(60,60,66,27,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,27,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,27,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,27,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,27,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,27,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,27,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,27);
        printf("|");
        break;
    }

    switch(posteC[4]){
    case 7:
        IMPRIME_DISCO(60,60,66,26,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,26,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,26,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,26,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,26,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,26,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,26,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,26);
        printf("|");
        break;
    }

    switch(posteC[3]){
    case 7:
        IMPRIME_DISCO(60,60,66,25,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,25,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,25,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,25,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,25,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,25,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,25,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,25);
        printf("|");
        break;
    }

    switch(posteC[2]){
    case 7:
        IMPRIME_DISCO(60,60,66,24,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,24,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,24,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,24,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,24,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,24,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,24,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,24);
        printf("|");
        break;
    }

    switch(posteC[1]){
    case 7:
        IMPRIME_DISCO(60,60,66,23,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,23,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,23,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,23,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,23,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,23,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,23,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,23);
        printf("|");
        break;
    }

    switch(posteC[0]){
    case 7:
        IMPRIME_DISCO(60,60,66,22,7);
        break;
    case 6:
        IMPRIME_DISCO(60,60,65,22,6);
        break;
    case 5:
        IMPRIME_DISCO(60,60,64,22,5);
        break;
    case 4:
        IMPRIME_DISCO(60,60,63,22,4);
        break;
    case 3:
        IMPRIME_DISCO(60,60,62,22,3);
        break;
    case 2:
        IMPRIME_DISCO(60,60,61,22,2);
        break;
    case 1:
        IMPRIME_DISCO(60,60,60,22,9);
        break;
    case 0:
        textcolor(15,0);
        gotoxy(60,22);
        printf("|");
        break;
    }

    textcolor(7,0);
}

int VITORIA(int posteA[7],int posteB[7],int posteC[7],int posi){     // RECURSIVIDADE UTILIZADA PARA VERIFICAR A VITORIA

    if( posi == 6 && posteA[posi] == 0 && posteB[posi] == 0){       // SAIDA CASO HAJA A VITORIA NO POSTE C
        return 1;
    }
    else if ( posi == 6 && posteA[posi] == 0 && posteC[posi] == 0){ // SAIDA CASO HAJA VITORIA NO POSTE B
        return 1;
    }
    else if(posteA[posi]==0 && posteB[posi]==0){                    // TESTE DE VITORIA NO POSTE C COM RECURSIVIDADE
        return VITORIA(posteA,posteB,posteC,posi+1);
    }
    else if(posteA[posi]==0 && posteC[posi]==0){                    // TESTE DE VITORIA NO POSTE B COM RECURSIVIDADE
        return VITORIA(posteA,posteB,posteC,posi+1);
    }
    else{                                                           // SAIDA CASO NÃO HAJA VITÓRIA
        return 0;
    }

}

void TELA_VITORIA (int jogadas){    // TELA DE VITORIA
    int i,L=0, jogadasf=0;

    Beep(900,80);
    gotoxy(0,1);
    for(i=1;i != 12 && L < 34; i++){
        if(i<11){

            printf("PARABAINS ");
            DELAY2();
        }else{
            textcolor(rand()%15,0);
            printf("\n");
            i=0;
            L = L + 1;
        }                                   //ANIMAÇÂO
    }
    for(i=1, L = 0 ;i != 21 && L < 34; i++){
        if(i<20){
            printf("     ");
            DELAY2();

        }else{
            printf("\n");
            i=0;
            L = L + 1;
        }
    }

    textcolor(7,0);
    clrscr();

    for(i=0;i<100;i++){
        printf("#");                // MONTAR O QUADRO (DECORATIVO)
    }
    for(i=0;i<34;i++){
        printf("\n");
    }
    for(i=0;i<100;i++){
        printf("#");
    }


    textcolor(7,0);
    gotoxy(32,5);
    textcolor(3, 0);
    printf("Numero de jogadas foi de %d",jogadas);      // NUMERO DE JOGADAS UTILIZADAS PARA ALCANÇAR A VITORIA

    if(jogadas == 127){
        textcolor(4, 0);
        gotoxy(30, 15);
        printf("F L A W L E S S    V I C T O R Y");
        gotoxy(27, 18);
        printf("VC VENCEU NO MELHOR NUMERO DE JOGADAS");
    }
    else {
        jogadasf = jogadas - 127;
        gotoxy(36, 15);
        textcolor(6, 0);
        printf("P A R A B A I N S");
        textcolor(4, 0);
        gotoxy(17,18);
        printf("VC REALIZOU %d JOGADAS A MAIS DO Q O NECESSARIO PARA GANHAR", jogadasf);
    }

    textcolor(7,0);
    getch();
    main();
}

void TELA_CREDITOS (){  // TELA DE CREDITOS
    int i;

    for(i=0;i<100;i++){
        printf("#");                // MONTAR O QUADRO (DECORATIVO)
    }
    for(i=0;i<34;i++){
        printf("\n");
    }
    for(i=0;i<100;i++){
        printf("#");
    }

    gotoxy(47, 8);
    printf("CREDITOS DO");
    gotoxy(50, 10);
    printf("JOGO");
    gotoxy(43, 11);
    printf("DO CARA DA PIRAMIDE");
    textcolor(5,0);
    gotoxy(41, 15);
    printf("    ALLAN A LIMA");
    textcolor(3,0);
    gotoxy(41, 19);
    printf("GUXTAVO O BRUxxxQUENCE");
    textcolor(6,0);
    gotoxy(41, 23);
    printf("    KOGUT O LINDO");
    textcolor(7, 0);
    getch();
    main();

}

void TELA_INSTRUCOES(){ // TELA INSTRUÇÕES
    int i;

    for(i=0;i<100;i++){
        printf("#");                // MONTAR O QUADRO (DECORATIVO)
    }
    for(i=0;i<34;i++){
        printf("\n");
    }
    for(i=0;i<100;i++){
        printf("#");
    }

    gotoxy(47, 8);
    printf("INSTRUCOES DO");
    gotoxy(50, 10);
    printf("JOGO");
    gotoxy(43, 11);
    printf("DO CARA DA PIRAMIDE");
    textcolor(8,0);
    gotoxy(20, 15);
    printf(" O desafio consiste em transportar uma em uma essas sete pecas para");
    gotoxy(20,16);
    printf(" um dos outros pinos em um menor numero possivel de movimentos. Nao");
    gotoxy(20,17);
    printf("  e permitido, em nenhuma etapa, que uma peça fique pousada sobre");
    gotoxy(20,18);
    printf("                     outra de menor tamanho.");
    textcolor(8,0);
    gotoxy(20, 20);
    printf(" So e possivel movimentar-se um disco por vez para qualquer pino");
    gotoxy(20,21);
    printf("  utilize as setas (esquerda e direita) para escolher os discos");
    gotoxy(20,22);
    printf("  pressione enter para seleciona-lo, e depois selecione um pino ");
    gotoxy(20,23);
    printf("               destino para o disco selecionado ");
    gotoxy(20,25);
    textcolor(4,0);
    printf("    Voce pode voltar para o menu a qualquer momento durante o");
    gotoxy(20,26);
    printf("          jogo, pressionando a tecla ESC duas vezes");
    textcolor(7, 0);
    getch();
    main();
}

int SEL_INGAME(int post){   // UTILIZAÇÃO DE SETAS PARA ESCOLHA DE POSTE
    int SEL = 1;             //SEL ARMAZENA O VALOR CAPTURADO PELA FUNÇÃO


    if(post == 1){
        gotoxy(30,18);
        printf("V");
        gotoxy(45,18);
        printf(" ");
        gotoxy(60,18);
        printf(" ");
        gotoxy(90,18);
        printf(" ");
        gotoxy(2,1);            //PRIMEIRAMENTE A SETA É DESENHADA SEGUNDO O VALOR ANTERIOR DE "POST"
    }                           //PARA GARANTIR QUE A SETA NAO PULE DE LOCALIZAÇÃO

    if(post == 2){
        gotoxy(30,18);
        printf(" ");
        gotoxy(45,18);
        printf("V");
        gotoxy(60,18);
        printf(" ");
        gotoxy(90,18);
        printf(" ");
        gotoxy(2,1);
    }

    if(post == 3){
        gotoxy(30,18);
        printf(" ");
        gotoxy(45,18);
        printf(" ");
        gotoxy(60,18);
        printf("V");
        gotoxy(90,18);
        printf(" ");
        gotoxy(2,1);
    }

    if(post == 4){
        gotoxy(30,18);
        printf(" ");
        gotoxy(45,18);
        printf(" ");
        gotoxy(60,18);
        printf(" ");
        gotoxy(90,18);
        printf("V");
        gotoxy(2,1);
    }

    while(getch() != 13){                   // GETCH DIFERENTE DE ENTER PARA QUE A FUNÇÃO INICIE CADA VEZ QUE
        SEL = getch();                      // UM BOTÃO É PRESSIONADO, EVITANDO DELAY NA RESPOSTA

        if(SEL == 77){
            Beep(500,30);
            if(post == 3){  //SETA PARA DIREITA
                post = 1;
            }else{
                post = post + 1;
            }
        }
        if(SEL == 75){
            Beep(500,30);
            if(post == 1){  //SETA PARA ESQUERDA
                post = 3;
            }else{
                post = post - 1;
            }
        }

        if(SEL == 27){
            textcolor(7,0);
            gotoxy(25,25);  //UTILIZAÇÃO DA TECLA ESC PARA SAIR DO JOGO
            clrscr();
            main();
        }


        if(post == 1){
            gotoxy(30,18);
            printf("V");
            gotoxy(45,18);
            printf(" ");
            gotoxy(60,18);
            printf(" ");        //NOVAMENTE A SETA É DESENHADA CONFORME O NOVO VALOR DADO PARA POST
            gotoxy(90,18);
            printf(" ");
            gotoxy(2,1);
        }

        if(post == 2){
            gotoxy(30,18);
            printf(" ");
            gotoxy(45,18);
            printf("V");
            gotoxy(60,18);
            printf(" ");
            gotoxy(90,18);
            printf(" ");
            gotoxy(2,1);
        }

        if(post == 3){
            gotoxy(30,18);
            printf(" ");
            gotoxy(45,18);
            printf(" ");
            gotoxy(60,18);
            printf("V");
            gotoxy(90,18);
            printf(" ");
            gotoxy(2,1);
        }

        if(post == 4){
            gotoxy(30,18);
            printf(" ");
            gotoxy(45,18);
            printf(" ");
            gotoxy(60,18);
            printf(" ");
            gotoxy(90,18);
            printf("V");
            gotoxy(2,1);
        }

    }

    Beep(640, 50); //BEEP
    gotoxy(25,8);
    return post;
}

void JOGO(int *jogadas){
    int posteA[7]={1,2,3,4,5,6,7}, posteB[7]={ }, posteC[7]={ }, post = 1 ,i , disco[2];

        // -- POSTES EM FORMATO DE VETOR, O PRIMEIRO COMEÇA PREENCHIDO COM TODOS OS DISCOS ( NUMERADOS DE 1 A 7 DE ACORDO COM O TAMANHO ),
        // ENQUANTO O OUTROS DOIS POSTES NAO COMEÇAM COM NADA.
        // -- "post" UTILIZADO PARA VERIFICAR O POSTE SELECIONADO PELO USARIO
        // -- I, UTILIZADO COMO CONTADOR EM DIVERSAS OCASIÕES.
        // -- VETOR "disco" COM DUAS POSIÇÕES, PARA ARMAZENAR TANTO A POSIÇÃO DO DISCO SELECIONADO COMO TAMBEM SEU TAMANHO.
        // -- "jogadas" UTILIZADA PARA ARMAZENAR A QUANTIDADE DE JOGADAS FEITAS PELO USUARIO.

    IMPRIME(*jogadas, posteA, posteB, posteC);

    while(VITORIA(posteA,posteB,posteC,0) == 0){       // CONDIÇÃO DE VITÓRIA
            break;
        *jogadas = *jogadas + 1;                        // CONTADOR DE JOGADAS
        gotoxy(17,13);
        textcolor(14,0);
        printf("      Escolha um disco: ");
        post = SEL_INGAME(post);                          // CHAMADA DA FUNÇÃO DE SELEÇÃO
        textcolor(7,0);

        if(post == 4){
            clrscr();
            MENU();
        }else

        if (post==1){                                       // CASO QUEIRA MEXER NO PRIMEIRO POSTE
            if (posteA[6]==0){
                gotoxy(17,13);
                textcolor(4,0);
                printf("    NAO TEM NENHUM DISCO AKI ");      //SELEÇÃO DE POSTE DE ONDE VAI TIRAR O DISCO
                textcolor(7,0);
                Sleep(500);
            }else{
                for(i=0;i<7;i++){
                    if(posteA[i]!= 0){
                        disco[0] = posteA[i];             // O VETOR "DISCO" RECEBE O LOCAL E O TAMANHO DO DISCO MAIS ALTO DO POSTE
                        disco[1] = i;
                        break;
                    }
                }
                gotoxy(17,13);
                textcolor(6,0);
                printf("Escolha um destino para o disco");
                post = SEL_INGAME(post);                    //SELECAO DO POSTE PARA TRANSFERIR O DISCO
                textcolor(7,0);


                if(post == 4){
                    clrscr();
                    MENU();
                }
                else if (post == 1){
                    gotoxy(17,13);
                    textcolor(4,0);
                    printf("      MOVIMENTO INVALIDO       ");    //O DISCO NAO PODE SER MOVIDO PARA O MESMO POSTE
                    textcolor(7,0);
                    Sleep(500);
                }
                else if (post == 2){
                    for(i=6; i>=0; i--){
                        if (posteB[i] == 0){                  //VERIFICA QUAL A POSICAO MAIS PROXIMA DA BASE QUE NAO POSSUI DISCOS

                            if(i == 6){
                                posteB[i] = disco[0];         //SE CASO NAO HOUVER NENHUM DISCO NO POSTE, SERA FEITA A TROCA
                                posteA[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteB[i+1]){
                                posteB[i] = disco[0];         //SE CASO O DISCO PRESENTE NO POSTE FOR MAIOR QUE O DISCO SELECIONADO PARA
                                posteA[disco[1]] = 0;         //TROCA FOR MAIOR, SERA FEITA A TROCA
                                break;
                            }
                            else if(disco[0] > posteB[i+1]){  //SE CASO O DISCO PRESENTE NO POSTE FOR MENOR, NAO SERA FEITA A TROCA
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }

                else if (post == 3){
                    for(i=6; i>=0; i--){
                        if (posteC[i] == 0){

                            if(i == 6){
                                posteC[i] = disco[0];
                                posteA[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteC[i+1]){
                                posteC[i] = disco[0];
                                posteA[disco[1]] = 0;
                                break;
                            }
                            else if(disco[0] > posteC[i+1]){
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }
            }
        }

        else if (post==2){                                  // CASO QUEIRA MEXER NO POSTE 2
            if (posteB[6]==0){
                gotoxy(17,13);
                textcolor(4,0);
                printf("   NAO TEM NENHUM DISCO AQUI ");     //SELEÇÃO DE POSTE DE ONDE VAI TIRAR O DISCO
                textcolor(7,0);
                Sleep(500);
            }else{
                for(i=0;i<7;i++){
                    if(posteB[i]!= 0){
                        disco[0] = posteB[i];
                        disco[1] = i;
                        break;
                    }
                }

                gotoxy(17,13);
                textcolor(6,0);
                printf("Escolha um destino para o disco");
                post = SEL_INGAME(post);                       //SELECAO DO POSTE PARA TRANSFERIR O DISCO
                textcolor(7,0);

                if (post == 2){
                    gotoxy(17,13);
                    textcolor(4,0);
                    printf("      MOVIMENTO INVALIDO       ");
                    textcolor(7,0);
                    Sleep(500);
                }

                else if (post == 1){
                    for(i=6; i>=0; i--){
                        if (posteA[i] == 0){

                            if(i == 6){
                                posteA[i] = disco[0];
                                posteB[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteA[i+1]){
                                posteA[i] = disco[0];
                                posteB[disco[1]] = 0;
                                break;
                            }
                            else if(disco[0] > posteA[i+1]){
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }
                else if (post == 3){
                    for(i=6; i>=0; i--){
                        if (posteC[i] == 0){

                            if(i == 6){
                                posteC[i] = disco[0];
                                posteB[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteC[i+1]){
                                posteC[i] = disco[0];
                                posteB[disco[1]] = 0;
                                break;
                            }
                            else if(disco[0] > posteC[i+1]){
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }

            }
        }

        else if (post==3){                                  // CASO QUEIRA MEXER NO DISCO 3
            if (posteC[6]==0){
                gotoxy(17,13);
                textcolor(4,0);
                printf("    NAO TEM NENHUM DISCO AKI ");       //SELEÇÃO DE POSTE DE ONDE VAI TIRAR O DISCO
                textcolor(7,0);
                Sleep(500);
            }else{
                for(i=0;i<7;i++){
                    if(posteC[i]!= 0){
                        disco[0] = posteC[i];
                        disco[1] = i;
                        break;
                    }
                }

                gotoxy(17,13);
                textcolor(6,0);
                printf("Escolha um destino para o disco");
                textcolor(6,0);
                post = SEL_INGAME(post);                      //SELECAO DO POSTE PARA TRANSFERIR O DISCO
                textcolor(7,0);

                if (post == 3){
                    gotoxy(17,13);
                    textcolor(4,0);
                    printf("      MOVIMENTO INVALIDO       ");
                    textcolor(7,0);
                    Sleep(500);
                }

                else if (post == 1){
                    for(i=6; i>=0; i--){
                        if (posteA[i] == 0){

                            if(i == 6){
                                posteA[i] = disco[0];
                                posteC[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteA[i+1]){
                                posteA[i] = disco[0];
                                posteC[disco[1]] = 0;
                                break;
                            }
                            else if(disco[0] > posteA[i+1]){
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }
                else if (post == 2){
                    for(i=6; i>=0; i--){
                        if (posteB[i] == 0){

                            if(i == 6){
                                posteB[i] = disco[0];
                                posteC[disco[1]] = 0;
                                break;
                            }

                            else if(disco[0] < posteB[i+1]){
                                posteB[i] = disco[0];
                                posteC[disco[1]] = 0;
                                break;
                            }
                            else if(disco[0] > posteB[i+1]){
                                gotoxy(17,13);
                                textcolor(4,0);
                                printf("   MOVIMENTO NAO PERMITIDO     ");
                                textcolor(7,0);
                                Sleep(500);
                                break;
                            }
                        }
                    }
                }
            }
        }

        Sleep(250);
        clrscr();
        IMPRIME(*jogadas, posteA, posteB, posteC);           // REEMPRIME OS POSTES E DISCOS APOS A JOGADA
    }
}

int main(){

    int jogadas=0;

        // -POSTES EM FORMATO DE VETOR, O PRIMEIRO COMEÇA PREENCHIDO COM TODOS OS DISCOS ( NUMERADOS DE 1 A 7 DE ACORDO COM O TAMANHO ),
        // ENQUANTO O OUTROS DOIS POSTES NAO COMEÇAM COM NADA.
        // -"post" UTILIZADO PARA VERIFICAR O POSTE SELECIONADO PELO USARIO
        // -I, UTILIZADO COMO CONTADOR EM DIVERSAS OCASIÕES.
        // -VETOR "disco" COM DUAS POSIÇÕES, PARA ARMAZENAR TANTO A POSIÇÃO DO DISCO SELECIONADO COMO TAMBEM SEU TAMANHO.
        // -"SEL" UTILIZADO PARA ( PORRA NENHUMA ? )
        // -"posi" UTILIZADO NA VERIFICAÇÃO DA VITÓRIA ( SÓ PRA ISSO ? )
        // -"jogadas" UTILIZADA PARA ARMAZENAR A QUANTIDADE DE JOGADAS FEITAS PELO USUARIO.

    system("MODE 100,35");                      // DEFINE TAMANHO DE TELA
    switch(MENU()){                             // RECEBE O RETURN DO MENU
        case 3:
            JOGO(&jogadas);                     // CHAMADA DO JOGO
            break;

        case 2:
            TELA_CREDITOS();                     // CHAMADA DA TELA DE CREDITOS
            break;

        case 1:
            TELA_INSTRUCOES();                   // CHAMADA DA TELA DE ISNTRUÇÕES
            break;

        case 0:
            exit(666);                           // CHAMADA PARA SAIR DO PROGRAMA
            break;
    }
    TELA_VITORIA(jogadas);                       // CASO O JOGADOR TERMINE O JOGO COM VITÓRIA
}

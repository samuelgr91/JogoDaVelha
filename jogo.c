#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "jogo.h"

Tabuleiro AlocarTabuleiro(Tabuleiro jogo){
    jogo.tabuleiro=malloc(3*sizeof(char*));
    for(int j = 0; j < 3; j++)
        jogo.tabuleiro[j]=malloc(3*sizeof(char));
    return jogo;
}

void JogoDesalocar(Tabuleiro jogo){
    for(int k = 0;k < 3;k++)
        free(jogo.tabuleiro[k]);
    free(jogo.tabuleiro);
}

void LeituraTabuleiro(Tabuleiro jogo){
    fflush(stdin); 
    char entrada[30];
    int k=0;
    scanf("%s",entrada);
    while(strlen(entrada) > 9)
        scanf("%s",entrada);
    entrada[10]='\0';
    for(int i = 0;i < 3; i++)
        for(int j = 0;j < 3; j++){
            jogo.tabuleiro[i][j]=entrada[k];
            k++;
        }
    fflush(stdin);    
}

int TabuleiroEhValido(Tabuleiro jogo){
    int contx=0,conto=0,contv=0;
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3; j++){
            if(jogo.tabuleiro[i][j] == 'X')
                contx++;
            else if(jogo.tabuleiro[i][j] == 'O')
                conto++;
            else if(jogo.tabuleiro[i][j] == 'V')
                contv++;
        }
    }
    if((contx - conto) > 1 || (conto - contx) > 1 || (contx+conto+contv) != 9)
        return -1;
    int xganhou=0,oganhou=0;
    for(int i=0;i<3;i++){
            contx=0,conto=0;
            for(int j=0;j<3;j++){
                if(jogo.tabuleiro[i][j] == 'X')
                    contx++;
                else if(jogo.tabuleiro[i][j] == 'O')
                        conto++;     
            }
            if(contx == 3)
                xganhou++;    
            else if(conto == 3)
                oganhou++;
        }
    for(int i=0;i<3;i++){
            contx=0,conto=0;
            for(int j=0;j<3;j++){
                if(jogo.tabuleiro[j][i] == 'X')
                    contx++;
                else if(jogo.tabuleiro[j][i] == 'O')
                        conto++;     
            }
            if(contx == 3)
                xganhou++;    
            else if(conto == 3)
                oganhou++;   
        }
    contx=0,conto=0;
    for(int i=0;i<3;i++){
            if(jogo.tabuleiro[i][i] == 'X')
                contx++;
            else if(jogo.tabuleiro[i][i]=='O')
                    conto++;
        }
        if(contx == 3)
            xganhou++;    
        else if(conto == 3)
                oganhou++;
    contx=0,conto=0;
    for(int i=0;i<3;i++){
            if(jogo.tabuleiro[i][2-i] == 'X')
                contx++;
            else if(jogo.tabuleiro[i][2-i]=='O')
                    conto++;
        }
        if(contx == 3)
            xganhou++;    
        else if(conto == 3)
                oganhou++;
    if(xganhou > 0 && oganhou > 0)
            return -1;
    return 1;
}

int Empate(Tabuleiro jogo){
    int contv=0;
    for(int i = 0;i < 3; i++)
        for(int j = 0;j < 3; j++)
            if(jogo.tabuleiro[i][j] == 'V')
                contv++;
    if(contv == 0)
            return 1;
    return 0;
}

int Venceu(Tabuleiro jogo){
    
    if((jogo.tabuleiro[0][0] == 'O' && jogo.tabuleiro[0][1] == 'O' && jogo.tabuleiro[0][2] == 'O') || (jogo.tabuleiro[1][0] == 'O' && jogo.tabuleiro[1][1] == 'O' && jogo.tabuleiro[1][2] == 'O') ||
        (jogo.tabuleiro[2][0] == 'O' && jogo.tabuleiro[2][1] == 'O' && jogo.tabuleiro[2][2] == 'O') || (jogo.tabuleiro[0][0] == 'O' && jogo.tabuleiro[1][0] == 'O' && jogo.tabuleiro[2][0] == 'O') ||
        (jogo.tabuleiro[0][1] == 'O' && jogo.tabuleiro[1][1] == 'O' && jogo.tabuleiro[2][1] == 'O') || (jogo.tabuleiro[0][2] == 'O' && jogo.tabuleiro[1][2] == 'O' && jogo.tabuleiro[2][2] == 'O') ||
        (jogo.tabuleiro[0][0] == 'O' && jogo.tabuleiro[1][1] == 'O' && jogo.tabuleiro[2][2] == 'O') || (jogo.tabuleiro[0][2] == 'O' && jogo.tabuleiro[1][1] == 'O' && jogo.tabuleiro[2][0] == 'O'))
        return 2;
    else if((jogo.tabuleiro[2][0] == 'X' && jogo.tabuleiro[2][1] == 'X' && jogo.tabuleiro[2][2] == 'X') || (jogo.tabuleiro[0][0] == 'X' && jogo.tabuleiro[1][0] == 'X' && jogo.tabuleiro[2][0] == 'X') ||
            (jogo.tabuleiro[0][1] == 'X' && jogo.tabuleiro[1][1] == 'X' && jogo.tabuleiro[2][1] == 'X') || (jogo.tabuleiro[0][2] == 'X' && jogo.tabuleiro[1][2] == 'X' && jogo.tabuleiro[2][2] == 'X') ||
            (jogo.tabuleiro[0][0] == 'X' && jogo.tabuleiro[1][1] == 'X' && jogo.tabuleiro[2][2] == 'X') || (jogo.tabuleiro[0][2] == 'X' && jogo.tabuleiro[1][1] == 'X' && jogo.tabuleiro[2][0] == 'X') ||
            (jogo.tabuleiro[0][0] == 'X' && jogo.tabuleiro[0][1] == 'X' && jogo.tabuleiro[0][2] == 'X') || (jogo.tabuleiro[1][0] == 'X' && jogo.tabuleiro[1][1] == 'X' && jogo.tabuleiro[1][2] == 'X'))
            return 1;
    return -1;
}

void JogadaMestre(Tabuleiro jogo,int *cont){
    printf("Tabuleiro %d em andamento ",(*cont)+1);
    int contv=0,contx=0,conto=0;
    for(int i = 0;i < 3; i++)
        for(int j = 0;j < 3; j++){
            if(jogo.tabuleiro[i][j] == 'V')
                contv++;
            else if(jogo.tabuleiro[i][j] == 'X')
                contx++;
            else if(jogo.tabuleiro[i][j] == 'O')
                conto++;
        }
    if(contx == conto)
        printf("[proximo jogador indefinido]\n"); 
    else if(contv > 0){
        char jogador;
        if(conto > contx)
            jogador='X';
        else if(contx > conto)
                jogador='O';
        int linhaganhar[3],colunaganhar[3],k=0;
        for(int i=0;i<3;i++){
            int cont=0,espaco=0,colunaespaco=0;
            for(int j=0;j<3;j++){
                if(jogo.tabuleiro[i][j] == jogador)
                    cont++;
                else if(jogo.tabuleiro[i][j] == 'V'){
                        espaco=1;
                        colunaespaco=j;
                }        
            }
            if(cont == 2 && espaco == 1){
                linhaganhar[k]=i;
                colunaganhar[k]=colunaespaco;
                k++;
            }
        }
        for(int i=0;i<3;i++){
            int cont=0,espaco=0,linhaespaco=0;
            for(int j=0;j<3;j++){
                if(jogo.tabuleiro[j][i] == jogador)
                    cont++;
                else if(jogo.tabuleiro[j][i]=='V'){
                        espaco=1;
                        linhaespaco=j;
                }        
            }
            if(cont == 2 && espaco == 1){
                linhaganhar[k]=linhaespaco;
                colunaganhar[k]=i;
                k++;
            }
        }
        int cont=0,espaco=0,lugarespaco=0;
        for(int i=0;i<3;i++){
            if(jogo.tabuleiro[i][i] == jogador)
                cont++;
            else if(jogo.tabuleiro[i][i]=='V'){
                    espaco=1;
                    lugarespaco=i;
            }
        }
        if(cont == 2 && espaco == 1){
                linhaganhar[k]=lugarespaco;
                colunaganhar[k]=lugarespaco;
                k++;
            }
        cont=0,espaco=0;
        int linhaespaco=0,colunaespaco=0;
        for(int i = 0;i < 3; i++){
            if(jogo.tabuleiro[i][2-i] == jogador)
                cont++;
            else if(jogo.tabuleiro[i][2-i]=='V'){
                    espaco=1;
                    linhaespaco=i;
                    colunaespaco=2-i;
            }
        }
        if(cont == 2 && espaco == 1){
                linhaganhar[k]=linhaespaco;
                colunaganhar[k]=colunaespaco;
                k++;
            }
        if(k == 1)
            printf("[%c: (%d,%d)]\n",jogador,linhaganhar[0]+1,colunaganhar[0]+1);   
        else if(k == 2)
                printf("[%c: (%d,%d)(%d,%d)]\n",jogador,linhaganhar[0]+1,colunaganhar[0]+1,linhaganhar[1]+1,colunaganhar[1]+1);  
        else if(k == 3)
                printf("[%c: (%d,%d)(%d,%d)(%d,%d)]\n",jogador,linhaganhar[0]+1,colunaganhar[0]+1,linhaganhar[1]+1,colunaganhar[1]+1,linhaganhar[2]+1,colunaganhar[2]+1);  
        else
            printf("[%c: sem jogada mestre]\n",jogador);
    }

}
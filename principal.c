#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    int n;
    scanf("%d",&n);
    while(n <= 0)
        scanf("%d",&n);
    fflush(stdin);
    for(int i = 0; i < n; i++){
        Tabuleiro jogo;
        fflush(stdin);
        jogo=AlocarTabuleiro(jogo);
        LeituraTabuleiro(jogo);
        int validez=TabuleiroEhValido(jogo);
        if(validez == 1){
            int venceu=Venceu(jogo);
            if(venceu == 1)
                printf("Tabuleiro %d com vitoria [X]\n",i+1);
            else if(venceu == 2)
                    printf("Tabuleiro %d com vitoria [O]\n",i+1);
            else{
                int velha=Empate(jogo);
                if(velha == 1)
                    printf("Tabuleiro %d deu velha\n",i+1);
                else
                    JogadaMestre(jogo,&i); 
                }
            }   
        
        else if(validez == -1)
            printf("Tabuleiro %d invalido\n",i+1);
        JogoDesalocar(jogo);        
    }
    return 0;
}

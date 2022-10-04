#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

char** mapa;
int linhas, colunas;




int main(){
    lemapa();
    for(int i=0; i<linhas; i++){
        printf("%s\n",mapa[i]);  //Lendo mapa da matriz (linha por linha)
    }

    do{
        char comando;
        scanf(" %c", &comando);  //The blank space in " %c" is to avoid capturing the special \n character
        move(comando);
        for(int i=0; i<linhas; i++){
            printf("%s\n",mapa[i]);  //Lendo mapa da matriz (linha por linha)
        }
    } while(!acabou());

    liberamapa();
    return 0;
}

// Lê arquivo
void lemapa(){
    FILE* f;
    f = fopen("mapa.txt","r");
    if(f==0){
        printf("Erro ao tentar abrir arquivo");
        exit(1);
    }
    fscanf(f,"%d %d",&linhas,&colunas);
    printf("O mapa tem %d linhas e %d colunas\n",linhas,colunas);

    alocamapa();

    for(int i=0; i<linhas; i++){
        fscanf(f,"%s",mapa[i]);  //Escrevendo mapa na matriz (linha por linha)
    }

}

void alocamapa(){
    // Alocando espaço para o mapa dinamicamente,
    mapa = malloc(sizeof(char*) * linhas);
    for(int i=0; i<linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void liberamapa(){
    for(int i=0; i<linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

int acabou(){
    return 0;  //Nunca acaba
}

void move(char direcao){
    int x;  //Posição no eixo horizontal
    int y;  //Posição no eixo vertical

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(mapa[i][j]=='@'){
                x = j;
                y = i;
                i = linhas; //Gambiarra para sair do laço mais externo
                break;
            }
        }
    }

    // Escrevendo '@' na nova posição
    switch(direcao){
        case 'a':
            mapa[y][x-1] = '@';
            break;
        case 'w':
            mapa[y-1][x] = '@';
            break;
        case 's':
            mapa[y+1][x] = '@';
            break;
        case 'd':
            mapa[y][x+1] = '@';
            break;
    }

    mapa[y][x] = '.';

}
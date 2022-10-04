#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas, colunas;

void lemapa();
void alocamapa();
void liberamapa();

int main(){
    

    lemapa();
    
    

    for(int i=0; i<linhas; i++){
        printf("%s\n",mapa[i]);  //Lendo mapa da matriz (linha por linha)
    }

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
#include <stdio.h> //basico
#include <windows.h> // to support ResetScreenPosition()
#include <stdlib.h> // to supp...
#include <conio.h>
#include <time.h>


#define N 10
#define M 20

int i, j, field[N][M],x,y,gy,head,tail, game;

void SnakeInitialization();
void print();
void ResetScreenPosition();

void main(){
// A ORDEM DAS FUNÇÕES ALTERAM O CÓDIGO!!!!!!!!!!!!!!!!!!!
    SnakeInitialization();

    while(game == 0){
        print();
        ResetScreenPosition();
        //break;// ResetScreenPosition tá com erro
    }

//    system("pause");
}


void SnakeInitialization(){ 
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            field[i][j] = 0;
        }
    }
    //iniciando variáveis
    x=N/2; y=M/2; gy = y; head = 5; tail = 1; game = 0;

    for(i=0; i<head; i++){
        gy++;
        field[x][gy-head] = i+1;
    }

}

void print(){
//definindo bordas com char da tab ASCII
    for(i=0;i<=M+1;i++){
        if(i==0){
           printf("%c",201);//diagonal superior esquerda
        }else if(i==M+1){
            printf("%c",187);//diogonal superior direita
        }else{
            printf("%c", 205);//borda superior
        }
    }

    printf("\n");

//estrutura das colunas
    for(i=0; i<N; i++){
        printf("%c", 186);//barra borda esquerda

        for(j=0;j<M;j++){
            if(field[i][j]==0)
                printf(" "); //identar borda direita
            if(field[i][j]>0 && field[i][j]!=head)
                printf("%c",176);//176=calda (POSIÇÃO)
            if(field[i][j]==head)
                printf("%c", 178);//head position
            if(j==M-1)
                printf("%c\n",186);//barra lateral
            
        }
    }

    for(i=0 ; i<=M+1; i++){
        if(i==0){
            printf("%c", 200);//diagonal inferior esquerda
        }else if(i==M+1){
            printf("%c", 188);//diagonal inferior direita
        }else{
            printf("%c",205);//borda inferior
        }
    }
        
// Usando caracteres da tabela ASCII   
 //   printf("\n\n\nASCII of 201 gives: %c\n", 201); printf("ASCII of 187 gives: %c\n", 187); printf("ASCII of 205 gives: %c\n", 205);  printf("ASCII of 186 gives: %c\n", 186);  printf("ASCII of 200 gives: %c\n", 200);  printf("ASCII of 188 gives: %c\n", 188);  printf("ASCII of 178 gives: %c\n", 178);  printf("ASCII of 176 gives: %c\n", 176);
}

void ResetScreenPosition(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}



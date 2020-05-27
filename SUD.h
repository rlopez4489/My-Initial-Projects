#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define RANGOVALOR(x) ((x)>=0 && (x)<10)?1:0 //valores validos
#define POSICION(x) ((x)>0 && (x)<10)?1:0 //verifica casilleros de la matriz
#include<windows.h>//libreria para sleep
#define NCASILLAS 81
#define FILAS 9
#define COLUMNAS 9
#define ELEMENTOS 30

void mostrar(int[FILAS][COLUMNAS]);
void AYUDA(int[FILAS][COLUMNAS],int[FILAS][COLUMNAS],int);

void AYUDA(int USO[FILAS][COLUMNAS],int SOLUCION[FILAS][COLUMNAS],int casillascompletas){
    int i,j,ayuda;

    ayuda=rand()%(NCASILLAS-casillascompletas);

    for(i=0;i<FILAS;i++){
        for(j=0;j<COLUMNAS;j++){
            if(USO[i][j]==0){
                if(ayuda==0){
                    USO[i][j]=SOLUCION[i][j];
                }
                ayuda--;
            }
        }
    }
}

void mostrar(int U[FILAS][COLUMNAS]){
int i,j;


for(i=0;i<FILAS;i++){
    if(i%3==0){printf("------+-------+------\n");}
    for(j=0;j<COLUMNAS;j++){
        if((j%3==0)&&(j!=0)){printf("| ");}
            if(U[i][j]==0){
            printf("  ");
            }else{
            printf("%d ",U[i][j]);
            }
    }
    printf("\n");
}
printf("----------------------\n");
}

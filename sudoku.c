#include "SUD.h"
#include "cargaTAB.h"

int main(){

  int valor=0;
  int dificultad=0;
  int TABLERO_PRECARGADOS[FILAS][COLUMNAS];
  int TABLERO_USO [FILAS][COLUMNAS];
  int TABLERO_SOLUCION [FILAS][COLUMNAS];
  int casillascompletas=0;
  int i,j,k,l,fila,columna;
  int ayudas=0, ayudasmax[3]={3,4,5};
  int help=0;//variable si necesita ayuda
  int variablequenecesitabamosparahacerandaresto=0;
  int var=1;
  int seguirjugando=1;
  int partidas=1;


  srand(getpid());


  printf("                         =========Bienvenido======== ");


  printf("\n\n                             =======SUDOKU=======");
  printf("\n\n                               ===Version 1.0===");


  printf("                    \n\nReglas del S U D O K U:\n\nEste juego esta compuesto por una cuadricula de 9x9 casillas\ndividida en cuadrantes de 3x3.\nPartiendo de algunos numeros ya dispuestos en algunas de las casillas\nhay que completar las casillas vacias con digitos del 1 al 9 sin que se repitan por fila y columna o cuadrante.");
  printf("\n\n\nVamos a jugar!!!!!");
  do{
  printf("\n\nLas  Dificultades de los niveles son las siguientes:\n\n1)Facil        (Dispondra de 3 ayudas como maximo).\n2)Intermedia   (Dispondra de 4 ayudas como maximo). \n3)Dificil      (Dispondra de 5 como ayudas maximo).\n\nSeleccione la dificultad que desea jugar: ");

    if (scanf("%d",&dificultad)!= 1){


    while (getchar() != '\n');


  }


    while(dificultad<1 || dificultad>3){

    printf("Dificultad no valida\n");
    printf("Ingrese una dificultad correcta:\n");
    if (scanf("%d",&dificultad)!= 1){

    while (getchar() != '\n');


  }




  }


  cargar(TABLERO_PRECARGADOS,TABLERO_USO,TABLERO_SOLUCION,dificultad);

  for(i=0;i<FILAS;i++){
    for(j=0;j<COLUMNAS;j++){
      if(TABLERO_USO[i][j]!=0){

        casillascompletas++;

      }


    }


  }

while(casillascompletas<NCASILLAS){


    Sleep(1000);
    system("cls");

    mostrar(TABLERO_USO);

    printf("Ayudas disponibles: %d / %d\n", ayudas, ayudasmax[dificultad-1]);
    printf("Requiere ayuda? (1=SI, 2=NO): ");
    if (scanf("%d",&help) != 1){


    while (getchar() != '\n');


  }



    if(help>2 || help<1){
      printf("Error respuesta no valida, favor de ingresar nuevamente.1\n");
      Sleep(200);
      continue;


    }else if(help==1){

        if(ayudas<ayudasmax[dificultad-1]){
            ayudas++;
            AYUDA(TABLERO_USO,TABLERO_SOLUCION,casillascompletas);
            casillascompletas++;

        }

        else {

            printf("NO CUENTA CON AYUDAS DISPONIBLES\n");


       }continue;
    }


  do{
    variablequenecesitabamosparahacerandaresto=0;
    printf("Ingresar Fila:");
    if (scanf("%d",&fila)!= 1){

    while (getchar() != '\n');


  }
    do{
        if(!POSICION(fila)){

          printf("Numero de fila no valido\n");
          printf("Igresar fila valida:");
          if (scanf("%d",&fila)!= 1){

            while (getchar() != '\n');


          }
        }


    }while(!POSICION(fila));

      printf("Ingresar Columna:");
      if (scanf("%d",&columna)!= 1){

            while (getchar() != '\n');


          }
do{

    if(!POSICION(columna)){

        printf("Numero de columna no valido\n");
        printf("Ingresar columna valida:");
        if (scanf("%d",&columna)!= 1){

            while (getchar() != '\n');


          }
    }


    }while(!POSICION(columna));

    if(TABLERO_PRECARGADOS[fila-1][columna-1]!=0){
            printf("La casilla selecionada pertenece a un numero precargado \n");
            variablequenecesitabamosparahacerandaresto=1;
    }
  }while(variablequenecesitabamosparahacerandaresto==1);

    printf("Ingrese un valor:");
    if (scanf("%d",&valor)!= 1){

            while (getchar() != '\n');


          }
    do{
        if(!RANGOVALOR(valor)){

            printf("Valor incorrecto\n");
            printf("Ingrese valor valido :");
            if (scanf("%d",&valor)!= 1){

            while (getchar() != '\n');


          }

        }


    }while(!RANGOVALOR(valor));
int borrar=valor;
int ver=1;
if(borrar==0){
    if(valor==0){
      if(TABLERO_USO[fila-1][columna-1]){

        TABLERO_USO[fila-1][columna-1]=0;
        casillascompletas--;

      }

    }
}else{
   for(k=0;k<FILAS;k++){

    if(TABLERO_USO[fila-1][k]==valor){

        printf("El valor %d ya se encuentra en la fila.\n",valor);
        ver=0;
    }

   }

for(l=0;l<COLUMNAS;l++){

    if(TABLERO_USO[l][columna-1]==valor){

        printf("El valor %d ya se encuentra en la columna.\n",valor);
        ver=0;
    }

   }
int m,n;
int cordenadax, cordenaday;

cordenadax=(fila-1)/3;
cordenaday=(columna-1)/3;

for(m=0;m<3;m++){

    for(n=0;n<3;n++){

        if(TABLERO_USO[3*cordenadax+m][3*cordenaday+n]==valor){

            printf("El valor %d ya se encuentra en el cuadrante. \n",valor);
            ver=0;
        }

    }

  }

}
  if(ver==1){
    casillascompletas++;
    TABLERO_USO[fila-1][columna-1]=valor;
  }


  }

  system("cls");
  mostrar(TABLERO_USO);
  printf("Felicitaciones, ha completado este Sudoku.\n");
  if(partidas<10){
    printf("¿Desea seguir jugando?(1=SI, 2=NO)\n");
    scanf("%d", &seguirjugando);


  }else{

    printf("Llego al maximo de partidas por ejecucion.\n");

  }partidas++;
  casillascompletas=0;
  ayudas=0;

  }while(partidas<11 && seguirjugando==1);


return 0;
}

//Tempo o0 com os FORs otimizados 12 segundos
//Tempo o3 com os FORs otimizados 0.9 segundos
//Tempo o0 com os FORs não otimizados 18 segundos
//Tempo o3 com os FORs não otimizados 3.2 segundos
#include <stdio.h>
#define tam 1000
int matriz1[tam][tam];
int matriz2[tam][tam];
int matrizResult[tam][tam]={0};
int main(void) {
  int x,y,z,result;
  //inicializar matrizes
  for(x=0;x<tam;x++){
    for(y=0;y<tam;y++){
      matriz1[x][y]=x*y+1;
      matriz2[x][y]=(x+y)*2;
    }
  }
  //Cálculo da multiplização
  for(z=0;z<tam;z++)
  {//printf("\n");
    for(y=0;y<tam;y++){
      result=0;
      for(x=0;x<tam;x++){
        matrizResult[z][x]+=(matriz1[z][y]*matriz2[y][x]);
      }
    }
  }
  if(tam<=5){
    for(z=0;z<tam;z++){
      for(y=0;y<tam;y++){
        printf("%i ",matrizResult[z][y]);
      }
      printf("\n");
    }
  }
  printf("Finalizado\n");
  return 0;
}
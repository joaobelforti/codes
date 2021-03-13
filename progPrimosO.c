#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
//gcc -pthread -o progPrimosO progPrimosO.c
//time -p ./progPrimosO 1000000 10 
//primeiro valor é o número em si, o segundo o n de threads
int nums=0,*primos,n=0,ind=1,tam=0;
pthread_mutex_t lock;
void verifica(int y){
    int x=0,var=0;
    for(x=1;x<n/2;x++){
      //if((primos[x]!=0)&&(y/2>primos[x])){
      if(primos[x]!=0){
        if(y%primos[x]==0){
          var++;
          break;
        }
      }
    }if(var==0){
      pthread_mutex_lock(&lock);
      primos[n]=y;
      n++;
      pthread_mutex_unlock(&lock);
    }
}
void *func(){
    int aux=0;
    while(ind<nums){
      pthread_mutex_lock(&lock);
      ind=ind+2;
      aux=ind;
      pthread_mutex_unlock(&lock);
      if(aux>=nums){break;}
      verifica(aux);
    }pthread_exit(NULL);
}
int main(int argc,char *argv[]){
    long x;
    pthread_mutex_init(&lock, NULL);
    nums=strtol(argv[1],NULL,10);
    tam=strtol(argv[2],NULL,10);
    pthread_t t[tam];
    primos = malloc (nums * sizeof (int));
    printf("\nINICIANDO %d THREADs\n",tam);
    if(nums>=2){primos[0]=2;n++;
      for(x=0;x<tam;x++){
          pthread_create(&t[x],NULL,func,NULL);
      }
        printf("\nSAINDO DAS THREADS\n");
      for(x=0;x<tam;x++){
          pthread_join(t[x],NULL);
      }
        printf("\nPRIMOS=%d\n",n);
    }
    else{
      printf("\nEntrada Inválida.\n");
    }
  pthread_exit(NULL);
}
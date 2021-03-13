#include<stdio.h>

int main(){
	int matriz[15][15], aux[15][15];
	int x, y,cont,cont2,esc;
	int val1,val2;
	//LIMPAR MATRIZ
	for(x =0;x < 15; x++){
		for(y=0;y < 15; y++){
			matriz[x][y] = 0;
			aux[x][y] = 0;
		}
	}
	//PRINTAR MATRIZ
	for(;;){
		system("cls");
		cont = 0;
		cont2 = 0;
		printf(" ");
		for(x =0;x < 15; x++){
			if (cont2 <11){
				printf("    %i",cont2);
			}
			else{
				printf("   %i",cont2);
			}
			cont2++;
		}
		for(x =0;x < 15; x++){
			printf("\n%i",cont);
			for(y=0;y < 15; y++){
				if(cont >= 10){
					printf("   %i ", matriz[x][y]);
				}
				else{
					printf("    %i", matriz[x][y]);
				}
			}
			cont++;
		}	
		printf("\n\n(1)Para adicionar celulas\n(2)Rodar o jogo\n");
		scanf("%i",&esc);
		if(esc == 1){
			printf("Digite as coordenada de onde deseja inserir um ponto de forma espacada(XX YY):\n");
			scanf("%i %i", &val1, &val2);
			matriz[val1][val2] = 1;
			aux[val1][val2] = 1;
		}
		else{
			system("pause");
			int vizinhos = 0;
			for(x = 0;x < 15;x++){
				for(y = 0;y < 15; y++){
					vizinhos=0;
					//baixo
					if (x<14){
						if (matriz[x+1][y]==1){vizinhos++;} //baixo
					//errp na segunda condicao
					}
					//cima 
					if (x>0){
						if (matriz[x-1][y]==1){vizinhos++;} //cima
					}
					//esquerda 
					if (y>0){
						if (matriz[x][y-1]==1){vizinhos++;} //esquerda
					}
					//direita 
					if (y<14){
						if(matriz[x][y+1]==1){vizinhos++;}//direita
					}
					//diagonal direita inferior
					if (x<14 && y<14){
						if (matriz[x+1][y+1]==1){vizinhos++;}//diagonal direita inferior
					}
					//diagonal direita superior
					if (x>0 && y<14){
						if (matriz[x-1][y+1]==1){vizinhos++;}
					}
					//diagonal esquerda inferior 
					if (x<14 && y>0){
						if (matriz[x+1][y-1]==1){vizinhos++;} 
					}
					//diagonal esquerda superior
					if (x>0 && y>0){
						if (matriz[x-1][y-1]==1){vizinhos++;}
					}
					if ((vizinhos<=1 )||(vizinhos >=4)){
						aux[x][y]=0; //morte
					}
					if (vizinhos==3){
						aux[x][y]=1; //vida
					}
				}//final do for colunas
			
			}//final do for linhas
			for(x =0;x < 15; x++){
				for(y=0;y < 15; y++){
					matriz[x][y] = aux[x][y];
				}
			}
		}//final do else
	}// final do loop
}

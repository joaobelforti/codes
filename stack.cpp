#include <stdio.h>
#include <iostream>

#define tamanho 10
using namespace std;
class Pilha{
     private:
        int contador;
        int vetorpilha[tamanho];
     public:
        Pilha(){
          /* a pilha eh inicializada para estar vazia*/
            contador=0;}
        bool ehvazia();
        bool pop();
        bool top(int &item);
        bool push(int item);
        bool equal(Pilha &S);
        void reverse();
        void inverteoutrapilha(Pilha &S);
        void copia(Pilha &);
        void imprime();
};

void Pilha::imprime () /*este m?todo imprime o vetor, n?o a pilha!*/
{
  int i;
  for(i=0;i<contador;i++)
    cout<<vetorpilha[i]<<" ";
}

bool Pilha::push(int item)
{
  /*Se a Stack nao esta cheia, um item eh adicionado ao topo da pilha. Se a pilha esta cheia
  1 eh retornado e a pilha nao eh modificada*/
  if(contador>=tamanho)
   return 0;
  else
  {
   vetorpilha[contador]=item;
   contador++;
   return 1;
  }
}

bool Pilha::pop()
{
  /*Se a Stack nao esta vazia, topo da pilha eh removido. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado*/
  if(contador==0)
     return false;
  else
  {
    --contador;
    return true;
  }
}

bool Pilha::top(int &item)
{
  /*Se a Stack nao esta vazia, topo da pilha eh retornado. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado*/
  if(contador ==0)
     return false;
  else
  {
     item = vetorpilha[contador-1];
     return true;
  }
}

bool Pilha::ehvazia()
{
  /*Se a Stack esta vazia, retorna true, se nao, retorna false*/
  if(contador>0) return false;
  return true;
}


int main(int argc, char *argv[])
{

  int n,i;
  int item;
  Pilha P1,P2,Paux;
  cout<<"Entre com o numero de elementos para Pilha 1 "; 
  cin>>n;
  if(n<=tamanho)
  {
    for(i=1;i<=n;i++){
       cout<<"\nelemento:";
       cin>>item;
       P1.push(item);
    }
    cout<<endl;
    getchar();
  }
 cout<<"\nEntre com o numero de elementos para Pilha 2 "; 
 cin>>n;
  if(n<=tamanho){
    for(i=1;i<=n;i++){
       cout<<"\nelemento:";
       cin>>item;
       P2.push(item);
    }
    cout<<endl;
  }
  
  getchar();
  return 0;
}

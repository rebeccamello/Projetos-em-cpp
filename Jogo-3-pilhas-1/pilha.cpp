//arquivo pilha.cpp

#include "pilha.h"
using namespace std;

Pilha::Pilha(){
  topo = -1;
}

// verifica se a pilha esta cheia
bool Pilha::cheia(){
  if (topo + 1 >= tam){   //se estiver cheia
    if (ordenada()){      //se estiver ordenada
      return true;}
  }
  return false;
}

// verifica se a pilha esta vazia
bool Pilha::vazia(){
  if (topo == -1){   //se estiver vazia
    return true;
  }
  return false;
}

// 1 - opcao de inserir numero se nao estiver cheia
bool Pilha::push(int n){ 
  if (cheia() == true){    //se estiver cheia, nao pode inserir
    cout << "Sua pilha ja esta cheia.";
    return false;
  } 
  else{
    vetor[topo + 1] = n;
    topo += 1;
    return true;
  }
}

// 2 - extrair numero da pilha
bool Pilha::pop(){
  if (vazia() == true){      //se estiver vazia, nao pode extrair
    cout << "Impossivel extrair pois o vetor ja esta vazio";
    return false;
  }
  else{
    topo -= 1;
    return true;
  }
}

//
bool Pilha::top(int &item){
  if (vazia() == true){ 
    return false;  }

  else{
    item = vetor[topo];
    return true;
  }
}

// imprimir pilhas
void Pilha::imprimir(){
  for (int i = 0; i <= topo;  i++){
    cout << vetor[i]<<"  ";
  }
}

//verifica se esta ordenada
bool Pilha::ordenada(){
  Pilha aux;
  int x, y = 0, ord = 0;

  while (vazia() == false){    //crescente
    top(x);
    if (x >= y){   
      y = x;                  //guarda o valor de x para comparar com o proximo elemento da pilha
      aux.push(x);     
      pop();
      ord++;
    }
    else{ break; ord = 0; y = 0;}
  }
  while (vazia() == false){    //decrescente
    top(x);
    if (x <= y){  
      y = x;
      aux.push(x);
      pop();
      ord++;
    }
    else{ break; ord = 0;}
  }

  while (!aux.vazia()){      //recoloca os elementos na pilha principal
    aux.top(x);
    aux.pop();
    push(x);
  }

  if (ord == tam){   return true;}    //se a quantidade de ordenados for o tamanho da pilha, esta ordenada
  return false;
}


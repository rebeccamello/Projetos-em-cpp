//arquivo pilha.cpp

#include "fila.h"
using namespace std;

Fila::Fila(){
  contador = 0;
  inicio = 0;      //indice do primeiro elemento
  fim = tam - 1;         //indice do ultimo elemento
}

//  --------------- VE SE FILA ESTA VAZIA -------------
bool Fila::vazia(){
  if (contador == 0){return true;}
  return false;
}

// --------------- VE SE FILA ESTA CHEIA ---------------
bool Fila::cheia(){
  if (contador == tam){
    if (ordenada())
      return true; 
  }
  return false;
}

// -------------- INSERE UM NUMERO --------------------
bool Fila::inserir(int item){
  if (cheia()){ return false;}
  
  if (fim == tam - 1){
    fim = 0;
  }
  else{ fim ++; }

  vetor[fim] = item;
  contador ++;
  return true;
}

// --------------- EXTRAI UM NUMERO --------------------
bool Fila::extrair(){
  if (vazia()){ return false; }
  if (inicio == tam - 1){
    inicio = 0;
  }
  else
    inicio ++;
  contador -- ;
  return true;
}

// ------------ CONSULTAR O PRIMEIRO DA FILA ----------
bool Fila::consulta(int &item){
  if (vazia()) return false;
  item = vetor[inicio];
  return true;
}

// ------------- VERIFICA A QTD DE ELEMENTOS -----------
int Fila::quantidade(){
  return contador;
}

// --------------- IMPRIMIR A FILA -------------------
void Fila::imprimir(){
  int a, i, item;
  a = quantidade();         //pega a qtd. de elementos 
  for (i = 0; i < a; i ++){
    consulta(item);
    cout << item << " ";
    inserir(item);
    extrair();
  }
}

// --------------- VE SE A FILA ESTA ORDENADA ------
bool Fila::ordenada(){
  Fila aux;
  int x, y = 0, ord = 0, ord2 = 0;

  while (vazia() == false){    //crescente
    consulta(x);
    if (x >= y){   
      y = x;                  //guarda o valor de x para comparar com o proximo elemento da pilha
      ord++;
    }

    aux.inserir(x);     
    extrair();
  }

  while (!aux.vazia()){      //recoloca os elementos na pilha principal
    aux.consulta(x);
    aux.extrair();
    inserir(x);
  }

  if (ord == tam){return true;}
  y = 1000;

  while (vazia() == false){    //decrescente
    consulta(x);
    if (x <= y){  
      y = x;
      ord2++;
    }

    aux.inserir(x);
    extrair();
  }

  while (!aux.vazia()){      //recoloca os elementos na pilha principal
      aux.consulta(x);
      aux.extrair();
      inserir(x);
    }
  if (ord2 == tam){   return true;}    //se a quantidade de ordenados for o tamanho da pilha, esta ordenada
  return false;
}



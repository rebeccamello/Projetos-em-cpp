#include <cstdlib>
#include <iostream>
#include <sstream>
#include "celula.h"
#include "ListaLigada.h"

using namespace std;


ListaLigada::ListaLigada() {
	prim = NULL;
	qtdCelulas = 0;
}

// --------- VAZIA ------------
bool ListaLigada::vazia() {
	return prim == NULL;
}

//---------- TAMANHO ----------
int ListaLigada::tamanho() {
	return this->qtdCelulas;
}

//----------- INSERE INICIO -----------
void ListaLigada::insereInicio(int i) {
	Celula * c = new Celula(i);
	c->setProx(prim);  //o prim vira o proximo
	prim = c;          //primeiro agora eh c
	qtdCelulas++;
}


//------------- INSERE EM N -------------
void ListaLigada::insereEmN(Celula * c, int pos) {
	while (true) {

		if (pos < 1) {
			cout << "A posicao deve ser maior ou igual a 1";
			break;
		}

		if (pos > qtdCelulas + 1) {
			cout << "Nao existe esta posicao. A fila esta' com " << qtdCelulas << " elemento(s)";
			break;
		}

		if (pos == 1) {
			insereInicio(c -> getInfo()); // o metodo insereInicio ja' estava implementado; aqui foi feita uma adaptacao.
			cout << "Inserido no inicio";
			break;
		}

		Celula * cursor = this->prim;
		for (int i = 1; i < pos - 1; i++) {
			cursor = cursor->getProx();
		}

		c->setProx(cursor->getProx()); //o proximo vira proximo da nova celula
		cursor->setProx(c);   //c vira proximo da que parou no for
		
		qtdCelulas++;

		cout << "Inserido na posicao " << pos;
		break;
	}
}

// ------------ EXCLUI N -----------
void ListaLigada::exclui_n(int pos){
  Celula *cursor = prim;
  Celula *aux = prim;

  if (pos == 1){  //exclui o primeiro
    prim = cursor -> getProx();  //faz do segundo o primeiro
    delete cursor;
  }
    
  else{
    for (int i = 1; i < pos - 1; i++){
      cursor = cursor->getProx();
    }
    aux = cursor -> getProx();  //guarda o elemento que cursor esta apontando
    cursor -> setProx(aux -> getProx());  //faz o cursor apontar para o que o aux aponta (dois pra frente)      
    delete aux;  
  }
  qtdCelulas --;
  cout << "\nElemento da posicao " << pos << " foi excluido.";
}

//------------ IMPRIME -------------
void ListaLigada::imprime() {
	Celula * cursor = prim;
	cout << "[ ";
	while (cursor != NULL) {
		cout << cursor->getInfo() << " ";
		cursor = cursor->getProx();
	}
	cout << "]\n";
}


//------------ STATUS ATUAL ---------------
int ListaLigada::Status_atual(int i){
  Celula * c = prim;

  for (int r = 0; r < i - 1; r++){
    c = c -> getProx();
  }
  return c -> Status_atual();
}

//------------ STATUS NOVO ---------------
void ListaLigada::Status_novo(int i, int pos){
  Celula * c = prim;

  for (int r = 0; r < pos - 1; r++){
    c = c -> getProx();
  }
  c -> Status_novo(i);
}

//------------ MUDOU ---------------
void ListaLigada::Set_NVezes(int i){
  Celula * c = prim;

  for (int r = 0; r < i - 1; r++){
    c = c -> getProx();
  }

  c -> Invad_vag_novo();
}

//------------ MUDOU ---------------
int ListaLigada::Get_NVezes(int i){
  Celula * c = prim;

  for (int r = 0; r < i - 1; r++){
    c = c -> getProx();
  }

  return c -> Invad_vag_atual();
}


// ----------- JOGADOR NOVO -----------
void ListaLigada::Jogad_novo(int j, int pos){
  Celula * c = prim;

  for (int r = 0; r < pos - 1; r++){
    c = c -> getProx();
  }
  c -> Set_jog(j);
}

// ----------- JOGADOR ATUAL -----------
int ListaLigada::Jogad_atual(int pos){
  Celula * c = prim;

  for (int r = 0; r < pos - 1; r++){
    c = c -> getProx();
  }

  return c -> Get_jog();
}

// ------------ PONTOS ELEMENTO ---------
void ListaLigada::SetPontos(int pos, int n){
  Celula * c = prim;

  for (int r = 0; r < pos - 1; r++){
    c = c -> getProx();
  }

  c -> SetPonto(n);
}

// ------------ PONTOS ELEMENTO ---------
int ListaLigada::GetPontos(int pos){
  Celula * c = prim;

  for (int r = 0; r < pos - 1; r++){
    c = c -> getProx();
  }

  return c -> GetPonto();
}
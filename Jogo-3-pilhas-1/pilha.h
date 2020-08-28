//arquivo pilha.h

#include <iostream>
using namespace std;

#ifndef TADPILHA_H
#define TADPILHA_H
#define tam 10

class Pilha{
	private:
		int vetor[tam];       //criacao do vetor
    int topo;         //variavel do indice do primeiro numero
     
	public:
		Pilha();

		bool push (int n);
    bool pop ();
    bool top(int &item);
    void imprimir();
    bool vazia();
    bool cheia();
    bool ordenada();
};
#endif


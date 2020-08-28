//arquivo pilha.h

#include <iostream>
using namespace std;

#ifndef TADFILA_H
#define TADFILA_H
#define tam 10

class Fila{
	private:
    int vetor[tam];
    int inicio;
    int fim;
    int contador;

  public:
    Fila();
    bool inserir(int n);
    bool extrair();
    void imprimir();
    bool cheia();
    bool vazia();
    bool consulta (int &item);
    int quantidade();
    bool ordenada();
};
#endif


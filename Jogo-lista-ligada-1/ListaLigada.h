#include <iostream>
#include <string.h>
#include "celula.h"

using namespace std;

class ListaLigada {
	
	//= privado
	private:
	Celula * prim;
	int qtdCelulas;
	
	//= publico
	public:
	ListaLigada();
	bool vazia();
	int tamanho();
	void insereInicio(int i);
	void insereEmN(Celula * c, int pos);
	void imprime();
  void exclui_n(int pos);
  int Status_atual(int i);
  void Status_novo(int i, int pos);
  int Get_NVezes(int i);
  void Set_NVezes(int i);
  void Jogad_novo(int j, int pos);
  int Jogad_atual(int pos);
  void SetPontos(int pos, int n);
  int GetPontos(int pos);

};
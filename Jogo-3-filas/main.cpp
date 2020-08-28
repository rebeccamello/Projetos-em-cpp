//Autora: Rebecca Mello
//TIA: 31911161

#include "fila.h"
using namespace std;

int main() {
  int rand (void);
  Fila f1, f2, f3;
  int cont = 0;   //quantidade de jogadas

  for (int i = 0; i < tam; i++){
    f1.inserir(rand() & 100 + 1);
  }

  while (true){ 
    cout <<"\nFila 1: ";   f1.imprimir();
    cout <<"\nFila 2: ";   f2.imprimir();
    cout <<"\nFila 3: ";   f3.imprimir();

		cout <<"\n\n------------------------------";
		cout<<"\n            TESTES";
		cout <<"\n------------------------------";
    cout<<"\n 0 - Sair do jogo";
		cout<<"\n 1 - Movimentar";

    int opc;
    cout <<"\nQual opcao voce deseja? "; cin >> opc;

    while (opc != 0 && opc != 1){    //verifica se opcao é valida
      cout << "Opcao invalida. Digite novamente: ";
      cin >> opc;
    }

    if (opc == 0){
      cout << "Jogo encerrado";
      break; }

    else{
      int x, y, n;
      cont++;
      cout <<"\nDe qual Fila deseja extrair (1, 2 ou 3)? ";
      cin >> x;

      //OPCOES DE MUDANCAS
      if (x == 1){
        if (!f1.vazia()){
          cout << "Em qual fila deseja colocar (2 ou 3)? ";
          cin >> y;

          while (y == 1){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y; 
          } 

          f1.consulta(n);
          if (y == 2){f1.extrair(); f2.inserir(n);}
          else if (y == 3){f1.extrair(); f3.inserir(n);}
        }
        else{ cout << "\nPilha vazia!";}
      }

      else if (x == 2){
        if (!f2.vazia()){
          cout << "Em qual fila deseja colocar (1 ou 3)? ";
          cin >> y;

          while (y == 2){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y; 
          } 

          f2.consulta(n);
          if (y == 1){f2.extrair(); f1.inserir(n);}
          else if (y == 3){f2.extrair(); f3.inserir(n);}
        }
        else{ cout << "\nPilha vazia!";}
      }

      else{
        if (!f3.vazia()){
          cout << "Em qual fila deseja colocar (1 ou 2)? ";
          cin >> y;

          while (y == 3){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y; 
          } 

          f3.consulta(n);
          if (y == 1){f3.extrair(); f1.inserir(n);}
          else if (y == 2){f3.extrair(); f2.inserir(n);}
        }
        else{ cout << "\nPilha vazia!";}
      }
    
    }
    //VERIFICA SE ALGUMA JA ESTA CHEIA E ORDENADA
    if (f1.cheia() || f2.cheia() || f3.cheia()){
      cout << "\nOrdenacao feita em " << cont << " movimentos!";
      break;
    }
  }
}
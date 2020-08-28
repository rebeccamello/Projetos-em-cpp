//Autora: Rebecca Mello
//TIA: 31911161

#include "pilha.h"
using namespace std;

int main(){
  int rand (void);
  Pilha p1, p2, p3;
  int cont = 0;

  for (int i = 0; i < tam; i++){
    p1.push(rand() & 100 + 1);
  }

	while (true){
    cout <<"\nPilha 1: ";   p1.imprimir();
    cout <<"\nPilha 2: ";   p2.imprimir();
    cout <<"\nPilha 3: ";   p3.imprimir();

		cout <<"\n\n------------------------------";
		cout<<"\n            TESTES";
		cout <<"\n------------------------------";
    cout<<"\n 0 - Sair do jogo";
		cout<<"\n 1 - Movimentar";

		cout<<"\n\nInformar a opcao: " ;
		int opc;
		cin >> opc;

    while (opc != 0 && opc != 1){    //verifica se opcao é valida
      cout << "Opcao invalida. Digite novamente: ";
      cin >> opc;
    }
		
		if(opc == 0){
      cout << "Programa encerrado.";
			break;
  	}

    else if (opc == 1){  
      int x, y, n;
      cont++;
      cout <<"\nDe qual pilha deseja extrair (1, 2 ou 3)? ";
      cin >> x;

      // OPCOES DE MUDANCAS DAS PILHAS
      if (x == 1){ 
        if (!p1.vazia()) {  
          cout << "Em qual pilha deseja colocar (2 ou 3)? ";
          cin >> y;

          while (y == 1){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y;  } 
      
          p1.top(n);
          if (y == 2){  p1.pop(); p2.push(n);   }
          else if (y == 3){ p1.pop(); p3.push(n);  } 
        }
        else{ cout << "\nPilha vazia!"; }
      }

      else if (x == 2){
        if (!p2.vazia()) {  
          cout << "Em qual pilha deseja colocar (2 ou 3)? ";
          cin >> y;

          while (y == 2){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y;  } 
          
          p2.top(n);
          if (y == 1){  p2.pop(); p1.push(n);   }
          else if (y == 3){ p2.pop(); p3.push(n);  } 
        }
        else{ cout << "\nPilha vazia!"; }
      }

      else{
        if (!p3.vazia()) {  
          cout << "Em qual pilha deseja colocar (2 ou 3)? ";
          cin >> y;

          while (y == 3){ 
            cout << "\nMovimento nao permitido. Digite novamente a pilha em que deseja colocar: "; cin >> y;  } 
          
          p3.top(n);
          if (y == 2){  p3.pop(); p2.push(n);   }
          else if (y == 1){ p3.pop(); p1.push(n);  } 
        }
        else{ cout << "\nPilha vazia!"; }
      }
    }

    //VERIFICA SE ALGUMA PILHA ESTA CHEIA E ORDENADA
    if (p1.cheia() || p2.cheia() || p3.cheia()){  
      cout<<"\nOrdenacao concluida com " << cont << " jogadas"; 
      break;
    }
	}
}
// Rebecca Mello dos Santos - 31911161
// Jogo com lista ligada

//rever questao de dar enter - pausa()??

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "ListaLigada.h"

using namespace std;

void pausa();
void pausa() {
	cout << "\n\n\n\n";
	system("pause");
}


int main() {

	ListaLigada lista;
  int elem, jogadores, jogadas, rod=0, status, pontos;
  
  cout << "\nInsira a quantidade de elementos: "; cin >> elem;
  for (int i = 0; i < elem; i++){
    lista.insereInicio(0);
  }

  cout << "\nInsira a quantidade de jogadores: "; cin >> jogadores;

  cout << "\nInsira a quantidade de jogadas por jogador: "; cin >> jogadas;


  // ---------------- Laco das rodadas -------------------
	while (rod < jogadas) {

    cout << "\n\n***** RODADA " << rod+1 << " *****";
    for (int i = 0; i < jogadores; i++){
      int s;

      cout << "\n\n------------------------------------------";
      cout<< "\nLista dos elementos: "; lista.imprime();

      
      for (int t = 1; t <= elem; t++){  //busca os atributos de cada elemento
        cout << "\n\nAtributos do " <<t<<" elemento: ";
        cout << "\nStatus: " << lista.Status_atual(t);;
        cout << "\nVezes que passou de invadido para vago: " << lista.Get_NVezes(t);
        cout << "\nPontos marcados: " << lista.GetPontos(t);
        cout << "\nJogador que invadiu: " << lista.Jogad_atual(t);
      }

      cout << "\n---------------------------------------------";
      cout << "\n\nVez do jogador " << i+1;
      
      cout << "\nPressione qualquer numero para comecar sua jogada. "; cin >> s;
      pausa();

      srand((int)time(0)); //para gerar números aleatórios reais entre 1 e o numero de elemento.
      int aleatorio = rand()%(elem-1+1) + 1;
      cout << "\nPosicao sorteada = " << aleatorio;
      
      status = lista.Status_atual(aleatorio);
      pontos = lista.GetPontos(aleatorio);


      // ---------- Validacao do elemento -----------
      if (status == 0){                       //se estiver vago
        lista.Status_novo(1, aleatorio);      //invadido
        lista.Jogad_novo(i+1, aleatorio);  //qual jogador invadiu a casa
      }

      else if (status == 1){                 //se estiver invadido
        if (lista.Jogad_atual(aleatorio) != i+1){  //se for de outro jogador
          lista.Status_novo(0, aleatorio);   //passa pra vago
          lista.Set_NVezes(aleatorio);       //incrementa um na qtd de vezes dessa mudanca nesse elemento
          lista.Jogad_novo(0,aleatorio);  //elemento nao tem mais jogador

          if (lista.Get_NVezes(aleatorio) == 3){ //se mudar tres vezes, o elemento eh retirado da lista
            lista.exclui_n(aleatorio);
            elem--;
          }
        }

        else{ //proprio jogador
          lista.Status_novo(2, aleatorio); //passa pra proprietario
          pontos++;
          lista.SetPontos(aleatorio, pontos);
        }
      }

      else{                    //se tiver proprietario
        pontos = lista.GetPontos(aleatorio);
        if (lista.Jogad_atual(aleatorio) != i+1){ //se for de outro jogador
          if (pontos > 1){ //tem 1 ponto
            pontos--;
            lista.SetPontos(aleatorio, pontos);  //elemento perde um ponto
          }
        }

        else{
          pontos++;
          lista.SetPontos(aleatorio, pontos);
        }
      }

    }

    int opc;
    cout << "\n\nDeseja continuar o jogo (1 para sim, 2 para nao)? "; cin >> opc;
    if (opc == 1){ rod++;} //incrementa a rodada para parar o while;
    else{ break;}
    
	}


  // ----------- Pontuacao --------------
  cout << "\n\n****** PONTUACAO ******";
  int * vet_pontos= new int[jogadores]; //vetor que guarda a pontuação de cada jogador
  
  for (int i = 0; i < jogadores; i++){
    vet_pontos[i] = 0;   //inicialmente todos os jogadores tem 0 pontos
  }

  int ponto, maior = 0, ind = 0, jog = 0;
  for (int i = 0; i < elem; i++){
    ponto = lista.GetPontos(i+1);
    jog = lista.Jogad_atual(i+1);
    vet_pontos[jog - 1] += ponto;
  }

  for (int i = 0; i<jogadores;i++){
    cout << "\nJogador " << i+1 << ": " << vet_pontos[i];

    if (vet_pontos[i] > maior){ 
      maior = vet_pontos[i]; 
      ind = i+1;
    }
  }

  if (maior == 0){
    cout << "\n\nNinguem venceu :(";
  }
  else{
    cout << "\n\nParabens ao(s) jogador(es) de " << maior << " pontos!";
  }
	return 0;
}
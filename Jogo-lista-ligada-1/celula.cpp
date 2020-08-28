#include <cstdlib>
#include "celula.h"

Celula::Celula(int i) {
	info =  i;
	prox = NULL;
  status = 0;     //vago
  invad_vag = 0;  //vezes que passa de invadido para vago
  jog = 0;
  pontos = 0;
}

int Celula::getInfo() {
	return info;
}

void Celula::setInfo(int i) {
	info = i;
}

Celula * Celula::getProx() {
	return prox;
}

void Celula::setProx(Celula * p) {
	prox = p;
}

int Celula::Status_atual(){
  return info;
}

void Celula::Status_novo(int i){
  info = i;
}

int Celula::Invad_vag_atual(){
  return invad_vag;
}

void Celula::Invad_vag_novo(){
  invad_vag++;
}

void Celula::Set_jog(int i){
  jog = i;
}

int Celula::Get_jog(){
  return jog;
}

void Celula::SetPonto(int i){
  pontos = i;
}

int Celula::GetPonto(){
  return pontos;
}


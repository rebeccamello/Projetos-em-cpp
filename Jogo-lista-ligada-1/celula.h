//#ifndef __CELULA__
//#define __CELULA__

#ifndef CELULA_H
#define CELULA_H

class Celula {

	//= privado
	private:
	int info;
	Celula * prox;
  int status;
  int invad_vag;
  int jog;
  int pontos;


	//= publico
	public:
	Celula(int);
	void setInfo(int);
  int getInfo();
	Celula * getProx();
	void setProx(Celula * );
  int Status_atual();
  void Status_novo(int i);
  int Invad_vag_atual();
  void Invad_vag_novo();
  void Set_jog(int i);
  int Get_jog();
  void SetPonto(int i);
  int GetPonto();
};
#endif

// Caroline Malaguti Taus
// Rebecca Mello dos Santos

// dados de: https://www.boxofficemojo.com/chart/ww_top_lifetime_gross/?area=XWW
// leitura do arquivo: https://www.youtube.com/watch?v=da8prmVYul8

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class No {
  private:
  No *esq, *dir;

  string rank;
  string titulo;
  string lucro;
  string ano;

  public:
  No(string rank, string titulo, string lucro, string ano){

    //informações do nó
    this->rank = rank; 
    this->titulo = titulo;
    this->lucro = lucro;
    this->ano = ano;

    esq = NULL;
		dir = NULL;
  }

  string getRank(){
    return rank;
  }

  string getTitulo(){
    return titulo;
  }

  string getLucro(){
    return lucro;
  }

  string getAno(){
    return ano;
  }

  No* getEsq(){
      return esq;
  }

  No* getDir(){
    return dir;
  }

  void setEsq(No *no){
    esq = no;
  }

  void setDir(No *no){
    dir = no;
  }
};

class Arvore{
  private:
    No* raiz;

  public:
    Arvore(){
      raiz = NULL;
    }

    No* getRaiz(){
      return raiz;
    }

    // ------------------- INSERIR TITULO -----------------------
    // Funcao de inserir para arvore organizada por titulo
    void inserir_alf(string rank, string titulo, string lucro, string ano){
      
      if(raiz == NULL) {
        raiz = new No(rank, titulo, lucro, ano); 
      }
      else
        inserirAux_alf(raiz, rank, titulo, lucro, ano);
    }

    void inserirAux_alf(No *no, string rank, string titulo, string lucro, string ano){
      if(titulo < no -> getTitulo()){
        if(no->getEsq() == NULL){
          No *novo_no = new No(rank, titulo, lucro, ano);
          no->setEsq(novo_no); 
        }
        else{				
          inserirAux_alf(no->getEsq(), rank, titulo, lucro, ano);
        }
      }
      else if(titulo > no->getTitulo()){
        if(no->getDir() == NULL){
          No *novo_no = new No(rank, titulo,lucro,ano);
          no->setDir(novo_no);
        }
        else{
          inserirAux_alf(no->getDir(), rank, titulo, lucro, ano);
        }
      }
    }


    // ------------------- INSERIR POR RANK -----------------------
    // Funcao de inserir para arvore organizada por rank/lucro
    void inserir_rank(string rank, string titulo, string lucro, string ano){
      
      if(raiz == NULL) {
        raiz = new No(rank, titulo, lucro, ano); 
      }
      else
        inserirAux_rank(raiz, rank, titulo, lucro, ano);
      }

    void inserirAux_rank(No *no, string rank, string titulo, string lucro, string ano){
      
      
      if(stoi(rank) < stoi(no -> getRank())){
        if(no->getEsq() == NULL){
          No *novo_no = new No(rank, titulo, lucro, ano);
          no->setEsq(novo_no); 
        }
        else{				
          inserirAux_rank(no->getEsq(), rank, titulo, lucro, ano);
        }
      }
      else if(stoi(rank) > stoi(no->getRank())){
        if(no->getDir() == NULL){
          No *novo_no = new No(rank, titulo,lucro,ano);
          no->setDir(novo_no);
        }
        else{
          inserirAux_rank(no->getDir(), rank, titulo, lucro, ano);
        }
      }
    }
    
    
    
// ------------------- INSERIR ANO -----------------------
    // Funcao de inserir para arvore organizada por titulo
    void inserir_ano(string rank, string titulo, string lucro, string ano){
      
      if(raiz == NULL) {
        raiz = new No(rank, titulo, lucro, ano); 
      }
      else
        inserirAux_ano(raiz, rank, titulo, lucro, ano);
    }

    void inserirAux_ano(No *no, string rank, string titulo, string lucro, string ano){
      // ano menor à esquerda
      if(ano < no -> getAno()) {
        if(no->getEsq() == NULL) {
          No *novo_no = new No(rank, titulo, lucro, ano);
          no->setEsq(novo_no); 
        }
        else {				
          inserirAux_ano(no->getEsq(), rank, titulo, lucro, ano);
        }
      }

      // ano maior à direita
      else if(ano > no->getAno()) {
        if(no->getDir() == NULL) {
          No *novo_no = new No(rank, titulo,lucro,ano);
          no->setDir(novo_no);
        }
        else {
          inserirAux_ano(no->getDir(), rank, titulo, lucro, ano);
        }
      }

      // se ano for igual organiza pelo rank
      else if (ano == no -> getAno()){
        if (stoi(rank) < stoi(no -> getRank())){
          if(no->getEsq() == NULL) {
          No *novo_no = new No(rank, titulo, lucro, ano);
          no->setEsq(novo_no); 
          }
          else {				
            inserirAux_ano(no->getEsq(), rank, titulo, lucro, ano);
          }
        }
        else{
          if(no->getDir() == NULL) {
          No *novo_no = new No(rank, titulo,lucro,ano);
          no->setDir(novo_no);
          }
          else {
          inserirAux_ano(no->getDir(), rank, titulo, lucro, ano);
          }
        }
      } 
    }

    // imprime em ordem
    void emOrdem(No* no){
      if(no != NULL){
        emOrdem(no->getEsq());
        cout << no->getRank()<<" -- "<<no->getTitulo()<<" -- "<<no->getLucro()<<" -- "<<no->getAno()<<"\n";
        emOrdem(no->getDir());
      }
    }

    // Localizar elemento por rank
    bool local_rank(No* no, int rank){
      
      while (no != NULL){            // enquanto entrar um elemento
        int raiz = stoi(no -> getRank());   //pega o valor da raiz/nó

        if (rank == raiz){              //se o rank for igual
          cout << "\nFilme do rank " << rank <<": " << no -> getTitulo()<<" -- "<<no -> getLucro()<<" -- "<< no -> getAno()<<"\n";
          return true;
        }

        else if (rank < raiz){         //se o numero for menor que a raiz/nó
          no = no -> getEsq();      //procura a partir do filho da esquerda, ja que sempre sera menor 
        }
          
        else{                       //se o numero for maior que a raiz/nó
          no = no -> getDir();      //procura a partir do filho da direta
        }
      }
      cout << "\nNão existe esse rank\n";
      return false;
    }

  // Localizar elemento por ano
    bool local_ano(No* no, int ano){
      
      while (no != NULL){            // enquanto entrar um elemento
        int raiz = stoi(no -> getAno());   //pega o valor da raiz/nó
 
        while (ano == raiz){              //se o ano for igual
          cout << no->getRank()<<" -- "<< no -> getTitulo()<<"\n";
          local_ano(no -> getEsq(),ano);
          local_ano(no -> getDir(),ano);
          return true; 
        }

        if (ano < raiz){         //se o numero for menor que a raiz/nó
          no = no -> getEsq();      //procura a partir do filho da esquerda, ja que sempre sera menor 
        }
          
        else{                       //se o numero for maior que a raiz/nó
          no = no -> getDir();      //procura a partir do filho da direta
        }
      }
      return false;
    }

    // Localizar elemento por lucro
    bool local_lucro(No* no, long int lucro){
      
      while (no != NULL){            // enquanto entrar um elemento
        long int raiz = atof(no -> getLucro().c_str());   //pega o valor da raiz/nó
 
        if (lucro <= raiz){              //se o lucro do filme >= que o lucro inputado
          while (no != NULL){
            cout << no ->getRank()<< " -- "<< no -> getTitulo() <<" -- "<<no ->getLucro()<<"\n";
            local_lucro(no -> getDir(),lucro);
            local_lucro(no-> getEsq(),lucro);
            return true; 
          }
        }
          
        else{                       //se o numero for maior que a raiz/nó
          no = no -> getEsq();      //procura a partir do filho da esquerda (rank menor-lucro maior)
        }
      }
      return false;
    }

  // maior lucro
  void maiorElem(No* no){
    int maior;

    while (no -> getEsq() != NULL){
      maior = stoi(no->getRank());
      no = no-> getEsq();  //maior lucro esta no menor rank (esq)
    }
    cout << no ->getRank()<< " -- "<< no -> getTitulo() <<" -- "<<no ->getLucro()<<"\n"; 
  }

  // menor lucro
  void menorElem(No* no){
    int menor;
    while (no -> getDir() != NULL){
      menor = stoi(no->getRank());
      no = no-> getDir(); //menor lucro esta no maior rank (dir)
    }
    cout << no ->getRank()<< " -- "<< no -> getTitulo() <<" -- "<<no ->getLucro()<<"\n";
  }


  // lucro total
  //soma os da esquerda da arvore
  long double Luc_totalesq(No* no){  
    long double soma = stold(no -> getLucro()); //pega o valor da raiz
    
    while (no -> getEsq() != NULL){
      no = no-> getEsq();
      soma += stold(no->getLucro());           //transforma o valor do lucro de string para long double e adiciona na soma
    }
    return soma;
  }

  // soma os da direita da árvore
  long double Luc_totaldir(No* no){
    long double soma = 0;
    while (no -> getDir() != NULL){
      no = no -> getDir();
      soma += stold(no->getLucro());
    }
    return soma;
  }
};


string mat[200][4]; // matriz para armazenar
int main() {
  Arvore arv_alf, arv_ano, arv_rank; 
  long double soma = 0;

  // leitura do arquivo
  int cont_lin = 0, cont_col = -1; // contadores para linha e coluna 
  int r;

  ifstream myfile;
  myfile.open("filmes.csv"); 

  while (myfile.good()){

    string line;
    getline(myfile,line,';'); // faz a quebra nos ;

    if(line == ""){
      line = "0";
    }

    cont_col++;  // incrementa o contador de colunas para ver os outros dados

    if(cont_col == 4){  // quando chega na quarta coluna
      cont_col = 0;     // volta pra primeira coluna
      cont_lin++;       // muda de linha
    }

    mat[cont_lin][cont_col] = line; // Armazenando cada linha na matriz
  }
  
  myfile.close(); 
  
  // --- criação das árvores ---

  // colocando dados na arvore alfabetica
  for (int i = 0; i < 200; i++){ 
    arv_alf.inserir_alf(mat[i][0], mat[i][1], mat[i][2], mat[i][3]);
  }

  // colocando dados na arvore por lucro
  for (int i = 100; i >=0 ; i--){ 
    arv_rank.inserir_rank(mat[i][0], mat[i][1], mat[i][2], mat[i][3]);
  }
  for (int i = 101; i < 200; i++){ 
    arv_rank.inserir_rank(mat[i][0], mat[i][1], mat[i][2], mat[i][3]);
  }

  // colocando dados na arvore por ano
  for (int i = 0; i < 200; i++){ 
    arv_ano.inserir_ano(mat[i][0], mat[i][1], mat[i][2], mat[i][3]);
  }

  cout << "\nEste programa exibe dados referentes a filmes classificados de acordo com seus lucros (em dólares) obtidos no mundo inteiro, alem de trazer informações sobre seu ano de lançamento.\n";


  // ############  MENU ###########
  while(true){
    cout << "\n\n========================================================";
    cout << "\n                         MENU                          ";
    cout << "\n========================================================";
    cout << "\n    0 - Sair do programa";
    cout << "\n    1 - Exibir filmes por ordem de lucro";
    cout << "\n    2 - Exibir filmes por ordem de ano de lançamento";
    cout << "\n    3 - Exibir filmes por ordem alfabética";
    cout << "\n    4 - Fazer busca por rank";
    cout << "\n    5 - Fazer busca por lucros >= que _____";
    cout << "\n    6 - Fazer busca por ano";
    cout << "\n    7 - Exibir filme de maior lucro";
    cout << "\n    8 - Exibir filme de menor lucro";
    cout << "\n    9 - Exibir lucro total (soma dos 200 filmes)";

    cout << "\n========================================================\n";

    int opc;
    cout << "\nOpção: ";
    cin >> opc;

    while (opc < 0 || opc > 9){
      cout << "\nOpção inválida. Digite novamente: "; 
      cin >> opc;
    }

    // ----- OPC 0 ------ 
    if (opc == 0){
      break;
    }

    // ----- OPC 1------ imprimir arv_rank em ordem
    else if (opc == 1) {
      arv_rank.emOrdem(arv_rank.getRaiz());
    }

    // ----- OPC 2 ------ imprimir arv_ano em ordem
    else if (opc == 2) {
      arv_ano.emOrdem(arv_ano.getRaiz());
    }

    // ----- OPC 3 ------ imprimir arv_alf em ordem
    else if (opc == 3) {
      arv_alf.emOrdem(arv_alf.getRaiz());
    }

    // ---- OPC 4 ------ busca por rank
    else if (opc == 4){
      cout << "\nQual rank deseja buscar? ";
      cin >> r;
      arv_rank.local_rank(arv_rank.getRaiz(), r);
    }

    // ---- OPC 5 ------ busca por lucros maiores
    else if (opc == 5){
      long int l;
      cout << "\nQual lucro? ";
      cin >> l;
      cout << "\nFilmes com lucros maiores que " << l << ": \n";
      if (!arv_rank.local_lucro(arv_rank.getRaiz(), l)){
        cout << "\nNão há filmes com lucro maior";
      }
    }

    // ---- OPC 6 ------ busca por ano
    else if (opc == 6){
      cout << "\nQual ano deseja buscar? ";
      cin >> r;
      cout << "\nFilme(s) do ano: \n\n";
      arv_ano.local_ano(arv_ano.getRaiz(), r);
    }

    // ---- OPC 7 ------ maior lucro
    else if (opc == 7){
      cout << "\nFilme de maior lucro: \n\n";
      arv_rank.maiorElem(arv_rank.getRaiz());
    }

    // ---- OPC 8 ------ menor
    else if (opc == 8){
      cout << "\nFilme de menor lucro: \n";
      arv_rank.menorElem(arv_rank.getRaiz());
    }

    // ---- OPC 9 ------ total
    else if (opc == 9){
      long double soma;
      soma = arv_rank.Luc_totalesq(arv_rank.getRaiz())+arv_rank.Luc_totaldir(arv_rank.getRaiz());
      cout << "\nO lucro total com os filmes é de: $" <<
      soma;
    }
  }
}
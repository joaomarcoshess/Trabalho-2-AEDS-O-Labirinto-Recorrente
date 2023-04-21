#include "Labirinto.hpp"

Lab::Lab(int vidas, int passos, int itensPegos, int perigos, int sacola) {
  setVidas(vidas);
  setPassos(passos);
  setItensPegos(itensPegos);
  setPerigos(perigos);
  setSacola(sacola);
}
Lab::Lab() {}

void Lab::setVidas(int vidas) { this->vidas = vidas; }
int Lab::getVidas() { return this->vidas; }

void Lab::setPassos(int passos) { this->passos = passos; }
int Lab::getPassos() { return this->passos; }

void Lab::setItensPegos(int itensPegos) { this->itensPegos = itensPegos; }
int Lab::getItensPegos() { return this->itensPegos; }

void Lab::setPerigos(int perigos) { this->perigos = perigos; }
int Lab::getPerigos() { return this->perigos; }

void Lab::setSacola(int sacola) { this->sacola = sacola; }
int Lab::getSacola() { return this->sacola; }

void Lab::CriandoLab() {
  this->lab = new string *[this->tamLab];

  for (int i = 0; i < this->tamLab; i++) {
    this->lab[i] = new string[this->tamLab];
  }

  this->verificador = new bool *[this->tamLab];

  for (int i = 0; i < this->tamLab; i++) {
    this->verificador[i] = new bool[this->tamLab];
  }
}

void Lab::DeletandoLab() {
  for (int i = 0; i < this->tamLab; i++) {
    delete[] this->lab[i];
  }
  delete[] this->lab;

  for (int i = 0; i < this->tamLab; i++) {
    delete[] this->verificador[i];
  }
  delete[] this->verificador;
}

void Lab::ApagarArq() {
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  remove("segundoArquivoVerificador.txt");

  exit(0);
}

void Lab::Welcome() {
  cout << "--------------------------- Bem Vindo ao Labirinto Recorrente! "
          "--------------------------- "
       << endl
       << endl;
  cout << "O objetivo deste programa é fazer um garoto percorrer pelo mapa e "
          "sobreviver aos obstáculos"
       << endl;
  cout << "ao máximo que puder, evitando perder vidas nos perigos e ficar sem "
          "saídas com as paredes."
       << endl << endl;
}

void Lab::CriarArqAux() {
  ofstream arqAux;
  ifstream arq;
  string line;

  arq.open("./dataset/input.data");
  if (!arq.is_open()) {
    cout << "Erro na abertura do arquivo: input.data!!!" << endl;
    exit(0);
  }
  arqAux.open("arquivoAuxiliar.txt");

  arq >> this->tamLab;
  arq >> this->tamLab;
  arq >> this->numLab;

  while (arq) {
    getline(arq, line);
    arqAux << line;
    arqAux << "\n";
  }

  arq.close();
  arqAux.close();

  arqAux.open("segundoArquivoAuxiliar.txt");
  arqAux.close();
}

void Lab::CriarArqVerificador() {
  ofstream arqVerificador;
  ifstream arq;
  char ch;
  string line;

  arq.open("./dataset/input.data");
  if (!arq.is_open()) {
    cout << "Erro na abertura do arquivo: input.data!!!" << endl;
    exit(0);
  }
  arqVerificador.open("arquivoVerificador.txt");

  getline(arq, line);
  arq >> ch;
  while (arq) {
    arq >> ch;
    arqVerificador << 0;
    arqVerificador << " ";
  }

  arq.close();
  arqVerificador.close();
  arqVerificador.open("segundoArquivoVerificador.txt");
  arqVerificador.close();
}

void Lab::AtualizarArqAux() {
  ofstream arq;
  ifstream arqAux;
  string line;

  remove("arquivoAuxiliar.txt");
  arq.open("arquivoAuxiliar.txt");
  arqAux.open("segundoArquivoAuxiliar.txt");
  if (!arqAux.is_open()) {
    cout << "Erro na abertura do arquivo: segundoArquivoAuxiliar.txt!!!"
         << endl;
    DeletandoLab();
    ApagarArq();
  }

  while (arqAux) {
    getline(arqAux, line);
    arq << line;
    arq << "\n";
  }

  arq.close();
  arqAux.close();
}

void Lab::AtualizarArqVerificador() {
  ofstream arqVerificador;
  ifstream arqAux;
  string line;

  remove("arquivoVerificador.txt");
  arqVerificador.open("arquivoVerificador.txt");
  arqAux.open("segundoArquivoVerificador.txt");
  if (!arqAux.is_open()) {
    cout << "Erro na abertura do arquivo: segundoArquivoVerificador.txt!!!"
         << endl;
    DeletandoLab();
    ApagarArq();
  }

  while (arqAux) {
    getline(arqAux, line);
    arqVerificador << line;
    arqVerificador << "\n";
  }

  arqVerificador.close();
  arqAux.close();
}

void Lab::AtualizarSegundoArqAux() {
  ofstream arqAux;

  arqAux.open("segundoArquivoAuxiliar.txt", ios::app);

  for (int i = 0; i < this->tamLab; i++) {
    for (int j = 0; j < this->tamLab; j++) {
      arqAux << this->lab[i][j];
      arqAux << " ";
    }
    arqAux << "\n";
  }
  arqAux << "\n";
  arqAux.close();
}

void Lab::AtualizarSegundoArqVerificador() {
  ofstream arqAux;

  arqAux.open("segundoArquivoVerificador.txt", ios::app);

  for (int i = 0; i < this->tamLab; i++) {
    for (int j = 0; j < this->tamLab; j++) {
      arqAux << this->verificador[i][j];
      arqAux << " ";
    }
    arqAux << "\n";
  }
  arqAux << "\n";
  arqAux.close();
}

void Lab::ObterPosInicial() {
  int linha, coluna, erro;

  do {
    erro = 0;
    cout << "Informe uma linha: ";
    cin >> linha;
    cout << "Informe uma coluna: ";
    cin >> coluna;

    if (cin.fail() || coluna < 0 || coluna >= this->tamLab || linha < 0 ||
        linha >= this->tamLab || this->lab[linha][coluna] == "#") {
      erro = 1;
      cin.clear();
      cin.ignore(80, '\n');
    }
    if (erro == 1) {
      cout << endl << "Digite uma opção valida!" << endl << endl;
    }
  } while (erro == 1);

  this->linha = linha;
  this->coluna = coluna;
  VerificarParede(linha, coluna);
}

void Lab::ObterPosAleatoria() {
  int linha, coluna;

  do {
    linha = rand() % this->tamLab;
    coluna = rand() % this->tamLab;

    if (this->lab[linha][coluna] == "#") {
      linha = -1;
    } else {
      this->linha = linha;
      this->coluna = coluna;
      VerificarParede(linha, coluna);
    }
  } while (linha == -1);
}

void Lab::VerificarParede(int linha, int coluna) {
  if (!(linha + 1 >= this->tamLab || coluna + 1 >= this->tamLab ||
        linha - 1 < 0 || coluna - 1 < 0)) {
    if (this->lab[linha + 1][coluna] == "#" &&
        this->lab[linha + 1][coluna - 1] == "#" &&
        this->lab[linha][coluna - 1] == "#" &&
        this->lab[linha - 1][coluna - 1] == "#" &&
        this->lab[linha - 1][coluna] == "#" &&
        this->lab[linha - 1][coluna + 1] == "#" &&
        this->lab[linha][coluna + 1] == "#" &&
        this->lab[linha + 1][coluna + 1] == "#") {
      cout << "O garoto acabou sendo cercado por 8 paredes ao seu redor..."
           << endl
           << endl;
      cout << "Posicoes percorridas: " << getPassos() << endl;
      cout << "Total de itens coletados: " << getItensPegos() << endl;
      cout << "Posicoes nao exploradas: " << VerificarCasa() << endl;
      cout << "Perigos confrontados: " << getPerigos() << endl;
      DeletandoLab();
      ApagarArq();
    }
  }
}

void Lab::PegarValoresLab() {
  ifstream arq, arqVerificador;
  int itensCaminho;
  bool aux = 0, condicaoParada = 0;

  do {
    remove("segundoArquivoAuxiliar.txt");
    remove("segundoArquivoVerificador.txt");
    itensCaminho = itensPegos;

    arq.open("arquivoAuxiliar.txt");
    if (!arq.is_open()) {
      cout << "Erro na abertura do arquivo: arquivoAuxliar.txt!!!" << endl;
      DeletandoLab();
      ApagarArq();
    }
    arqVerificador.open("arquivoVerificador.txt");
    if (!arq.is_open()) {
      cout << "Erro na abertura do arquivo: arquivoVerificador.txt!!!" << endl;
      DeletandoLab();
      ApagarArq();
    }

    for (int k = 0; k < this->numLab; k++) {
      for (int i = 0; i < this->tamLab; i++) {
        for (int j = 0; j < this->tamLab; j++) {
          arq >> this->lab[i][j];
          arqVerificador >> this->verificador[i][j];
        }
      }
      if (aux == 1) {
        if (getVidas() != 0) {
          while (condicaoParada == 0) {
            ObterPosAleatoria();
            condicaoParada = VerificarPasso(this->linha, this->coluna);
          }
        }
        condicaoParada = 0;
      } else {
        ObterPosInicial();
        aux = 1;
      }
      CaminharNoLab();
      AtualizarSegundoArqAux();
      AtualizarSegundoArqVerificador();
    }

    arq.close();
    arqVerificador.close();
    AtualizarArqAux();
    AtualizarArqVerificador();
    if (getVidas() == 0) {
      cout << endl << "Game over!!!" << endl;
      cout << "O garoto perdeu todas as suas vidas..." << endl;
      Resultado();
      DeletandoLab();
      ApagarArq();
    }
  } while (itensCaminho != this->itensPegos);
}

void Lab::CaminharNoLab() {
  int linha, coluna;

  while (1) {
    if (getVidas() == 0) {
      return;
    }
    linha = (rand() % 3) - 1;
    coluna = (rand() % 3) - 1;

    if (this->linha + linha >= 0 && this->coluna + coluna >= 0 &&
        this->linha + linha < tamLab && this->coluna + coluna < tamLab) {
      if (linha != 0 || coluna != 0) {
        VerificarPasso(this->linha + linha, this->coluna + coluna);
      }
    } else {
      return;
    }
  }
}

bool Lab::VerificarPasso(int newLinha, int newColuna) {
  int aux;

  if (this->lab[newLinha][newColuna] != "#") {
    this->passos++;
    this->linha = newLinha;
    this->coluna = newColuna;
    this->verificador[this->linha][this->coluna] = 1;
    if (this->lab[this->linha][this->coluna] == "*") {
      this->vidas--;
      this->perigos++;
    } else {
      if (this->lab[this->linha][this->coluna] != "0") {
        this->itensPegos++;
        this->sacola++;
        VerificarSacola();

        istringstream(this->lab[this->linha][this->coluna]) >> aux;
        aux--;
        this->lab[this->linha][this->coluna] = to_string(aux);
      }
    }
    return 1;
  }
  return 0;
}

void Lab::VerificarSacola() {
  if (getSacola() == 4) {
    if (getVidas() == 10) {
      setSacola(0);
    } else {
      setSacola(0);
      this->vidas++;
    }
  }
}

int Lab::VerificarCasa() {
  ifstream arqVerificador;
  int casasInexploradas = 0;
  bool aux;

  arqVerificador.open("arquivoVerificador.txt");
  if (!arqVerificador.is_open()) {
    cout << "Erro na abertura do arquivo: arquivoVerificador.txt!!!" << endl;
    DeletandoLab();
    ApagarArq();
  }

  for (int k = 0; k < this->numLab; k++) {
    for (int i = 0; i < this->tamLab; i++) {
      for (int j = 0; j < this->tamLab; j++) {
        arqVerificador >> aux;
        if (aux == 0) {
          casasInexploradas++;
        }
      }
    }
  }
  arqVerificador.close();
  return casasInexploradas;
}

void Lab::Resultado() {
  cout << endl << "Posicoes percorridas: " << getPassos() << endl;
  cout << "Total de itens obtidos: " << getItensPegos() << endl;
  cout << "Posicoes nao exploradas: " << VerificarCasa() << endl;
  cout << "Perigos confrontados: " << getPerigos() << endl;
}

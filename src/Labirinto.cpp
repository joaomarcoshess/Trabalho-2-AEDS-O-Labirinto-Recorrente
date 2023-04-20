#include "Labirinto.hpp"

Labirinto::Labirinto(int vidas, int passos, int itensPegos, int perigos, int sacola)
{
  setVidas(vidas);
  setPassos(passos);
  setItensPegos(itensPegos);
  setPerigos(perigos);
  setSacola(sacola);
}
Labirinto::Labirinto()
{
}

void Labirinto::setVidas(int vidas)
{
  this->vidas = vidas;
}
int Labirinto::getVidas()
{
  return this->vidas;
}

void Labirinto::setPassos(int passos)
{
  this->passos = passos;
}
int Labirinto::getPassos()
{
  return this->passos;
}

void Labirinto::setItensPegos(int itensPegos)
{
  this->itensPegos = itensPegos;
}
int Labirinto::getItensPegos()
{
  return this->itensPegos;
}

void Labirinto::setPerigos(int perigos)
{
  this->perigos = perigos;
}
int Labirinto::getPerigos()
{
  return this->perigos;
}

void Labirinto::setSacola(int sacola)
{
  this->sacola = sacola;
}
int Labirinto::getSacola()
{
  return this->sacola;
}

void Labirinto::criandoLabirinto()
{
  this->labirinto = new string*[this->tamLabirinto];
  
  for (int i = 0; i < this->tamLabirinto; i++)
  {
    this->labirinto[i] = new string[this->tamLabirinto];
  }

  this->verificador = new bool*[this->tamLabirinto];
  
  for (int i = 0; i < this->tamLabirinto; i++)
  {
    this->verificador[i] = new bool[this->tamLabirinto];
  }
}

void Labirinto::deletandoLabirinto()
{
  for (int i = 0; i < this->tamLabirinto; i++)
  {
    delete[] this->labirinto[i];
  }
  delete[] this->labirinto;
  
for (int i = 0; i < this->tamLabirinto; i++)
  {
    delete[] this->verificador[i];
  }
  delete[] this->verificador;
}

void Labirinto::apagarArquivos()
{
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  remove("segundoArquivoVerificador.txt");
  
  exit(0);
}

void Labirinto::criandoArquivoAuxiliar()
{
  ofstream arqAux;
  ifstream arq;
  string line;

  arq.open("./dataset/input.data");
  if(!arq.is_open())
  {
    cout << "Erro na abertura do arquivo: input.data!!!" << endl;
    exit(0);
  }
  arqAux.open("arquivoAuxiliar.txt");

  arq >> this->tamLabirinto;
  arq >> this->tamLabirinto;
  arq >> this->numLabirinto;
  
  while(arq)
  {
    getline(arq, line);
    arqAux << line;
    arqAux << "\n";
  }
  
  arq.close();
  arqAux.close();
  
  arqAux.open("segundoArquivoAuxiliar.txt");
  arqAux.close();
}

void Labirinto::criandoArquivoVerificador()
{
  ofstream arqVerificador;
  ifstream arq;
  char ch;
  string line;

  arq.open("./dataset/input.data");
  if(!arq.is_open())
  {
    cout << "Erro na abertura do arquivo: input.data!!!" << endl;
    exit(0);
  }
  arqVerificador.open("arquivoVerificador.txt");

  getline(arq, line);
  arq >> ch;
  while(arq)
  {
    arq >> ch;
    arqVerificador << 0;
    arqVerificador << " ";
  }
  
  arq.close();
  arqVerificador.close();
  arqVerificador.open("segundoArquivoVerificador.txt");
  arqVerificador.close();
}

void Labirinto::atualizarArquivoAuxiliar()
{
  ofstream arq;
  ifstream arqAux;
  string line;

  remove("arquivoAuxiliar.txt");
  arq.open("arquivoAuxiliar.txt");
  arqAux.open("segundoArquivoAuxiliar.txt");
  if(!arqAux.is_open())
  {
    cout << "Erro na abertura do arquivo: segundoArquivoAuxiliar.txt!!!" << endl;
    deletandoLabirinto();
    apagarArquivos();
  }

  while(arqAux)
  {
    getline(arqAux, line);
    arq << line;
    arq << "\n";
  }
  
  arq.close();
  arqAux.close();
}

void Labirinto::atualizarArquivoVerificador()
{
  ofstream arqVerificador;
  ifstream arqAux;
  string line;

  remove("arquivoVerificador.txt");
  arqVerificador.open("arquivoVerificador.txt");
  arqAux.open("segundoArquivoVerificador.txt");
  if(!arqAux.is_open())
  {
    cout << "Erro na abertura do arquivo: segundoArquivoVerificador.txt!!!" << endl;
    deletandoLabirinto();
    apagarArquivos();
  }

  while(arqAux)
  {
    getline(arqAux, line);
    arqVerificador << line;
    arqVerificador << "\n";
  }
  
  arqVerificador.close();
  arqAux.close();
}

void Labirinto::atualizarSegundoArquivoAuxiliar()
{
  ofstream arqAux;
  
  arqAux.open("segundoArquivoAuxiliar.txt", ios::app);

  for(int i = 0; i < this->tamLabirinto; i++)
  {
    for(int j = 0; j < this->tamLabirinto; j++)
    {
      arqAux << this->labirinto[i][j];
      arqAux << " ";
    }
    arqAux << "\n";
  }
  arqAux << "\n";
  arqAux.close();
}

void Labirinto::atualizarSegundoArquivoVerificador()
{
  ofstream arqAux;
  
  arqAux.open("segundoArquivoVerificador.txt", ios::app);

  for(int i = 0; i < this->tamLabirinto; i++)
  {
    for(int j = 0; j < this->tamLabirinto; j++)
    {
      arqAux << this->verificador[i][j];
      arqAux << " ";
    }
    arqAux << "\n";
  }
  arqAux << "\n";
  arqAux.close();
}

void Labirinto::obtendoPosicaoInicial()
{
  int linha, coluna, erro;
  
  do
  {
    erro = 0;
    cout << "Linha: ";
    cin >> linha;
    cout << "Coluna: ";
    cin >> coluna;
    
    if(cin.fail() || coluna < 0 || coluna >= this->tamLabirinto || linha < 0 || linha >= this->tamLabirinto || this->labirinto[linha][coluna] == "#")
    {
      erro = 1;
      cin.clear();
      cin.ignore(80, '\n');
    }
    if(erro == 1)
    {
      cout << endl << "Digite uma opção valida!" << endl << endl;
    }
  }while(erro == 1);

  this->linha = linha;
  this->coluna = coluna;
  verificandoParedes(linha, coluna);
}

void Labirinto::obtendoPosicaoAleatoria()
{
  int linha, coluna;
  
  do
  {
    linha = rand()%this->tamLabirinto;
    coluna = rand()%this->tamLabirinto;
    
    if(this->labirinto[linha][coluna] == "#")
    {
      linha = -1;
    }
    else
    {
      this->linha = linha;
      this->coluna = coluna;
      verificandoParedes(linha, coluna);
    }
  }while(linha == -1);
}

void Labirinto::verificandoParedes(int linha, int coluna)
{
  if(!(linha+1 >= this->tamLabirinto || coluna+1 >= this->tamLabirinto || linha-1 < 0 || coluna-1 < 0))
  {
    if(this->labirinto[linha+1][coluna] == "#"  && this->labirinto[linha+1][coluna-1] == "#"  && this->labirinto[linha][coluna-1] == "#"  && this->labirinto[linha-1][coluna-1] == "#"  && this->labirinto[linha-1][coluna] == "#"  && this->labirinto[linha-1][coluna+1] == "#"  && this->labirinto[linha][coluna+1] == "#"  && this->labirinto[linha+1][coluna+1] == "#")
    {
      cout << "O garoto não conseguiu sair pois estava cercado nas 8 posições por paredes!!!" << endl << endl;
      cout << "Casas percorridas ao todo: " << getPassos() << endl;
    cout << "Soma de itens coletados pelo caminho: " << getItensPegos() << endl;
    cout << "Número de casas não exploradas no labirinto: " << verificarCasasInexploradas() << endl;
    cout << "Perigos enfrentados durante o caminho: " << getPerigos() << endl;
      deletandoLabirinto();
      apagarArquivos();
    }
  }
}

void Labirinto::pegandoValoresLabirinto()
{
  ifstream arq, arqVerificador;
  int itensCaminho;
  bool aux = 0, condicaoParada = 0;
  
  do
  {
    remove("segundoArquivoAuxiliar.txt");
    remove("segundoArquivoVerificador.txt");
    itensCaminho = itensPegos;
    
    arq.open("arquivoAuxiliar.txt");
    if(!arq.is_open())
    {
      cout << "Erro na abertura do arquivo: arquivoAuxliar.txt!!!" << endl;
      deletandoLabirinto();
      apagarArquivos();
    }
    arqVerificador.open("arquivoVerificador.txt");
    if(!arq.is_open())
    {
      cout << "Erro na abertura do arquivo: arquivoVerificador.txt!!!" << endl;
      deletandoLabirinto();
      apagarArquivos();
    }
    
    for(int k = 0; k < this->numLabirinto; k++)
    {
      for(int i = 0; i < this->tamLabirinto; i++)
      {
        for(int j = 0; j < this->tamLabirinto; j++)
        {
          arq >> this->labirinto[i][j];
          arqVerificador >> this->verificador[i][j];
        }
      }
      if(aux == 1)
      {
        if(getVidas() != 0)
        {
          while(condicaoParada == 0)
          {
            obtendoPosicaoAleatoria();
            condicaoParada = verificarPasso(this->linha, this->coluna);
          }
        }
        condicaoParada = 0;
      }
      else
      {
        obtendoPosicaoInicial();
        aux = 1;
      }
      caminhandoLabirinto();
      atualizarSegundoArquivoAuxiliar();
      atualizarSegundoArquivoVerificador();
    }
    
    arq.close();
    arqVerificador.close();
    atualizarArquivoAuxiliar();
    atualizarArquivoVerificador();
    if(getVidas() == 0)
    {
      cout << endl << "Fim de jogo!!!" << endl;
      cout << "O garoto infelizmente perdeu todas suas vidas!!!" << endl;
      printResultados();
      deletandoLabirinto();
      apagarArquivos();
    }
  }while(itensCaminho != this->itensPegos);
}

void Labirinto::caminhandoLabirinto()
{
  int linha, coluna;

  while(1)
  {
    if(getVidas() == 0)
    {
      return;
    }
    linha = (rand()%3)-1;
    coluna = (rand()%3)-1;

    if(this->linha+linha >= 0 && this->coluna+coluna >= 0 && this->linha+linha < tamLabirinto && this->coluna+coluna < tamLabirinto)
    {
      if(linha != 0 || coluna != 0)
      {
        verificarPasso(this->linha+linha, this->coluna+coluna);
      }
    }
    else
    {
      return;
    }
  }
}

bool Labirinto::verificarPasso(int newLinha, int newColuna)
{
  int aux;
  
  if(this->labirinto[newLinha][newColuna] != "#")
  {
    this->passos++;
    this->linha = newLinha;
    this->coluna = newColuna;
    this->verificador[this->linha][this->coluna] = 1;
    if(this->labirinto[this->linha][this->coluna] == "*")
    {
      this->vidas--;
      this->perigos++;
    }
    else
    {
      if(this->labirinto[this->linha][this->coluna] != "0")
      {
        this->itensPegos++;
        this->sacola++;
        verificandoSacola();
        
        istringstream(this->labirinto[this->linha][this->coluna]) >> aux;
        aux--;
        this->labirinto[this->linha][this->coluna] = to_string(aux);
      }
    }
    return 1;
  }
  return 0;
}

void Labirinto::verificandoSacola()
{
  if(getSacola() == 4)
  {
    if(getVidas() == 10)
    {
      setSacola(0);
    }
    else
    {
      setSacola(0);
      this->vidas++;
    }
  }
}

int Labirinto::verificarCasasInexploradas()
{
  ifstream arqVerificador;
  int casasInexploradas = 0;
  bool aux;
  
  arqVerificador.open("arquivoVerificador.txt");
  if(!arqVerificador.is_open())
  {
    cout << "Erro na abertura do arquivo: arquivoVerificador.txt!!!" << endl;
    deletandoLabirinto();
    apagarArquivos();
  }

  for(int k = 0; k < this->numLabirinto; k++)
  {
    for(int i = 0; i < this->tamLabirinto; i++)
    {
      for(int j = 0; j < this->tamLabirinto; j++)
      {
        arqVerificador >> aux;
        if(aux == 0)
        {
          casasInexploradas++;
        }
      }
    }  
  }
  arqVerificador.close();
  return casasInexploradas;
}

void Labirinto::printResultados()
{
  cout << endl << "Casas percorridas ao todo: " << getPassos() << endl;
  cout << "Soma de itens coletados pelo caminho: " << getItensPegos() << endl;
  cout << "Número de casas não exploradas no labirinto: " << verificarCasasInexploradas() << endl;
  cout << "Perigos enfrentados durante o caminho: " << getPerigos() << endl;
}

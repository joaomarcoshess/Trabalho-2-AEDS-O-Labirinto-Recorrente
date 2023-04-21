#include <bits/stdc++.h>
#include "Labirinto.hpp"

using namespace std;

int main() 
{
  
  Lab l(10, 0, 0, 0, 0);

  l.Welcome();
  l.CriarArqAux();
  l.CriarArqVerificador();
  l.CriandoLab();
  l.PegarValoresLab();
  l.DeletandoLab();
  cout << endl << "Vitória!!!" << endl;
  l.Resultado();
  
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  remove("segundoArquivoVerificador.txt");
  
  return 0;
}

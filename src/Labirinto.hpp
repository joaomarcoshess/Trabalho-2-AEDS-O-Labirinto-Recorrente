#include <bits/stdc++.h>

#ifndef LAB_HPP_INCLUDED
#define LAB_HPP_INCLUDED

using namespace std;

class Lab
{
  private:
    string **lab;
    bool **verificador;
    int linha, coluna, tamLab, numLab;
    int vidas, passos, itensPegos, perigos, sacola;

  public:

	  Lab(int vidas, int passos, int itensPegos,int perigos, int sacola);
    Lab();

    void Welcome();

    void setVidas(int vidas);
    int getVidas();
    void setPassos(int passos);
    int getPassos();
    void setItensPegos(int itensPegos);
    int getItensPegos();
    void setPerigos(int perigos);
    int getPerigos();
    void setSacola(int sacola);
    int getSacola();

    void CriandoLab();
    void DeletandoLab();

    void ApagarArq();
    void CriarArqAux();
    void AtualizarArqAux();
    void AtualizarSegundoArqAux();

    void CriarArqVerificador();
    void AtualizarArqVerificador();
    void AtualizarSegundoArqVerificador();

    void ObterPosInicial();
    void ObterPosAleatoria();
    void VerificarParede(int linha, int coluna);

    void PegarValoresLab();
    void CaminharNoLab();
    void VerificarSacola();
    bool VerificarPasso(int newLinha, int newColuna);
    int VerificarCasa();
    void Resultado();
};
#endif

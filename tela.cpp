#include "tela.h"
#include <iostream>

using namespace std;

/*
    A função limpar tela verifica se o sistema é linux ou windows, e depois,
   limpa a tela do console
*/

void Tela::limparTela() {
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else defined(__linux__) || defined(__unix__)
  system("clear");
#endif
}

string Tela::acrescentarZero(string num) {
  if (num.size() == 1) {
    return "0" + num;
  }

  return num;
}

string Tela::espacamento(int quantidade) {
  string espaco;

  while (quantidade--) {
    espaco.append(" ");
  }

  return espaco;
}

int Tela::calcularEspacamento(int fixo, int variavel) {
  return abs(fixo - variavel) / 2;
}
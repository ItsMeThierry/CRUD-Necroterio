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
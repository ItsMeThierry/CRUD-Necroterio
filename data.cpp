#include "data.h"
#include "tela.h"
#include <iostream>
#include <string>
using namespace std;

string Data::getData() {
  return Tela::acrescentarZero(dia) + "/" + Tela::acrescentarZero(mes) + "/" +
         Tela::acrescentarZero(ano);
}

void Data::setData(string data) {
  // XX/XX/XXXX
  dia = data.substr(0, 2);
  mes = data.substr(3, 2);
  ano = data.substr(6, data.size() - 6);
}

int Data::lerData() {
  string teclado;
  int erro;

  int pos[2];
  int espaco = 0;

  do {
    getline(cin, teclado);

    if (teclado == "-1") {
      return -1;
    }

    espaco = 0;
    pos[0] = -1, pos[1] = -1;
    erro = 0;

    for (int i = 0; i < teclado.size() && espaco <= 2; i++) {
      if (teclado[i] == '/' || teclado[i] == ' ') {
        pos[espaco] = i;
        espaco++;
      } else if (!isdigit(teclado[i])) {
        erro = 1;
        break;
      }
    }

    if (erro != 1) {
      erro = (espaco > 2) ? 2 : 0;

      if (erro != 2) {
        if ((teclado[pos[0]] == teclado[pos[1]]) &&
            (pos[0] == 1 || pos[0] == 2) &&
            (pos[1] - pos[0] == 2 || pos[1] - pos[0] == 3)) {
          dia = teclado.substr(0, pos[0]);
          mes = teclado.substr(pos[0] + 1, pos[1] - pos[0] - 1);
          ano = teclado.substr(pos[1] + 1, teclado.size() - pos[1] + 1);

          break;
        } else {
          erro = 3;
        }
      }
    }

    switch (erro) {
    case 1:
      cout << "Data inválida! (apenas números): ";
      break;
    case 2:
      cout << "Data inválida! (apenas dia/mes/ano): ";
      break;
    case 3:
      cout << "Dia, mês ou ano inválidos! : ";
    }

  } while (1);

  return 0;
}
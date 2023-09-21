#include "morto.h"
#include <iostream>

using namespace std;

void Morto::lerAtributos() { // Lê os atributos da classe morto
  Pessoa::lerAtributos();
  string teclado;

  cout << "Informe a causa da morte: ";
  getline(cin, causaDaMorte);

  do {
    cout << "Informe se é doador de órgãos ('s' - Sim, 'n' - Não): ";
    cin >> teclado;

    if (teclado.size() == 1) {
      if (teclado == "s" || teclado == "S") {
        ehDoador = true;
        break;
      } else if (teclado == "n" || teclado == "N") {
        ehDoador = false;
        break;
      } else {
        cout << "Opção inválida!\n";
        continue;
      }
    } else {
      cout << "Opção inválida!\n";
    }
  } while (1);

  cout << "Informe o ID: ";
  cin >> id;

  Tela::limparTela();
}

void Morto::exibirAtributos() { // Exibe os atributos da classe morto
  cout << "=================================================\n\n"
       << "Estado: MORTO\n" << endl;
  Pessoa::exibirAtributos();
  cout << "\nData da morte: " << dataDaMorte.getData() << endl
       << "Causa da morte: " << causaDaMorte << endl
       << "Doador de órgãos: " << ehDoador << endl
       << "\nID: " << id << endl;
}
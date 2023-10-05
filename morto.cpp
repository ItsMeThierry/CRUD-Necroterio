#include "morto.h"
#include <iostream>

using namespace std;

int Morto::lerAtributos() { // Lê os atributos da classe morto
  if (Pessoa::lerAtributos() == -1) {
    return -1;
  }

  string teclado;

  if (lerDataDaMorte() == -1) {
    return -1;
  }

  if (lerCausaDaMorte() == -1) {
    return -1;
  }

  if (lerEhDoador() == -1) {
    return -1;
  }

  Tela::limparTela();

  return 0;
}

void Morto::exibirAtributos() {
  Pessoa::exibirAtributos();
  cout << "==================================================\n\n"
       << "Estado: MORTO\n"
       << endl;
  cout << "\nData da morte: " << dataDaMorte.getData() << endl
       << "Causa da morte: " << causaDaMorte << endl
       << "Doador de órgãos: " << ((ehDoador) ? "SIM" : "NÃO") << endl
       << "\nID: " << getID() << "\n\n";
}

int Morto::lerDataDaMorte() {
  string teclado;

  cout << "Informe a data da morte (dia/mês/ano): ";

  if (dataDaMorte.lerData() == -1) {
    return -1;
  }

  return 0;
}

int Morto::lerCausaDaMorte() {
  string teclado;

  cout << "Informe a causa da morte: ";
  getline(cin, teclado);

  if (teclado == "-1") {
    return -1;
  }

  causaDaMorte = teclado;

  return 0;
}

int Morto::lerEhDoador() {
  string teclado;

  cout << "Informe se é doador de órgãos ('s' - Sim, 'n' - Não): ";

  do {
    getline(cin, teclado);

    if (teclado == "-1") {
      return -1;
    }

    if (teclado == "s" || teclado == "S") {
      ehDoador = true;
      break;
    }

    if (teclado == "n" || teclado == "N") {
      ehDoador = false;
      break;
    }

    cout << "Opção inválida!: ";
  } while (1);

  return 0;
}

Data Morto::getDataDaMorte() { return dataDaMorte; }
string Morto::getCausaDaMorte() { return causaDaMorte; }
bool Morto::getEhDoador() { return ehDoador; }

void Morto::setDataDaMorte(string data) { dataDaMorte.setData(data); }

void Morto::setCausaDaMorte(string causaDaMorte) {
  this->causaDaMorte = causaDaMorte;
}

void Morto::setEhDoador(bool ehDoador) { this->ehDoador = ehDoador; }
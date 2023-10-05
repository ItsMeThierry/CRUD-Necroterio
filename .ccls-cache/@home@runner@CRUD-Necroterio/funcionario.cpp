#include "funcionario.h"
#include <iostream>

using namespace std;

int Funcionario::lerAtributos() {
  if (Pessoa::lerAtributos()) {
    return -1;
  }

  if (lerCargo() == -1) {
    return -1;
  }

  if (lerSalarioMensal() == -1) {
    return -1;
  }

  return 0;
}

void Funcionario::exibirAtributos() {
  Pessoa::exibirAtributos();
  cout << "==================================================\n\n"
       << "Estado: FUNCIONÁRIO\n"
       << endl;
  cout << "Cargo: " << cargo << endl
       << "Salário mensal: R$ " << salarioMensal << endl
       << "ID: " << getID() << "\n\n";
}

int Funcionario::lerCargo() {
  string teclado;

  cout << "Digite o cargo: ";
  getline(cin, teclado);

  if (teclado == "-1") {
    return -1;
  }

  cargo = teclado;

  return 0;
}

int Funcionario::lerSalarioMensal() {
  string teclado;

  cout << "Digite o salário mensal: ";

  do {
    getline(cin, teclado);

    if (teclado == "-1") {
      return -1;
    }

    if (Teclado::ehNumeroFloat(teclado) || Teclado::ehNumeroInt(teclado)) {
      salarioMensal = stof(teclado);
      break;
    }

    cout << "Salário inválido!: ";
  } while (1);

  return 0;
}

std::string Funcionario::getCargo() { return cargo; }

float Funcionario::getSalarioMensal() { return salarioMensal; }

void Funcionario::setCargo(std::string cargo) { this->cargo = cargo; }

void Funcionario::setSalarioMensal(float salarioMensal) {
  this->salarioMensal = salarioMensal;
}

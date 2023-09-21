#include "funcionario.h"
#include <iostream>

using namespace std;

void Funcionario::lerAtributos() { // Lê os atributos da classe funcionário
  Pessoa::lerAtributos();
  getline(cin, cargo);
  cin >> salarioMensal >> id;
}

void Funcionario::exibirAtributos() { // Exibe os atributos da classe
  Pessoa::xibirAtributos();
  cout << "Cargo: " << cargo << endl
       << "Salário mensal: R$ " << salarioMensal << endl
       << "ID: " << id << endl;
}
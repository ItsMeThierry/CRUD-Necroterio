#include "pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa() {}

Pessoa::~Pessoa() {
  cout << nome
       << " foi removido do necrotério. Pressione qualquer tecla pra retornar "
          "ao menu.";

  system("pause");
}

void Pessoa::lerAtributos() { // Lê os atributos da classe pessoa
  cout << "Digite o nome: ";
  getline(cin, nome);

  cout << "Digite o CPF: ";
  getline(cin, cpf);

  cout << "Digite a naturalidade: ";
  getline(cin, naturalidade);

  cout << "Informe o tipo sanguíneo: ";
  getline(cin, tipoSanguineo);

  cout << "Informe o sexo (F ou M): ";
  cin >> sexo;

  cout << "Digite a data de nascimento: ";
  dataDeNascimento.lerData();
}

void Pessoa::exibirAtributos() { // Exibe os atributos da classe pessoa
  cout << "=================================================\n"
       << "Nome: " << nome << "\nCPF: " << cpf
       << "\nNascimento: " << dataDeNascimento.getData() << "\nSexo: " << sexo
       << "\nNaturalidade: " << naturalidade
       << "\nTipo Sanguíneo: " << tipoSanguineo << endl;
}

string Pessoa::getNome() { return nome; }
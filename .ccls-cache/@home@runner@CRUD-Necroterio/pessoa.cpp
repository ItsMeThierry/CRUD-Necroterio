#include "pessoa.h"
#include "necroterio.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa() {}

Pessoa::~Pessoa() {}

int Pessoa::lerAtributos() {
  cout << "DIGITE -1 PARA VOLTAR AO MENU" << endl;

  if (lerNome() == -1) {
    return -1;
  }

  if (lerCPF() == -1) {
    return -1;
  }

  if (lerNaturalidade() == -1) {
    return -1;
  }

  if (lerTipoSanguineo() == -1) {
    return -1;
  }

  if (lerSexo() == -1) {
    return -1;
  }

  if (lerDataDeNascimento() == -1) {
    return -1;
  }

  return 0;
}

void Pessoa::exibirAtributos() {
  cout << "==================================================\n"
       << "Nome: " << nome << "\nCPF: " << cpf
       << "\nNascimento: " << dataDeNascimento.getData() << "\nSexo: " << sexo
       << "\nNaturalidade: " << naturalidade
       << "\nTipo Sanguíneo: " << tipoSanguineo << endl;
}

int Pessoa::lerNome() {
  string teclado;

  cout << "Digite o nome: ";

  do {
    getline(cin, teclado);

    if (teclado == "-1") {
      return -1;
    }

    if (!Teclado::ehNumeroInt(teclado)) {
      nome = teclado;
      break;
    }

    cout << "Nome inválido! (apenas letras): ";
  } while (1);

  return 0;
}

int Pessoa::lerCPF() {
  string teclado;

  cout << "Digite o CPF: ";

    int controle = 1;

    do {
        getline(cin, teclado);

        if (teclado == "-1") {
            return -1;
        }

        if(teclado[3]!= '.' || teclado[7]!= '.' || teclado[11]!= '-'){
            cout << "FORMATO INVÁLIDO! (Digite XXX.XXX.XXX-XX)\n"
                    "Digite o CPF: ";
        } else {
            cpf = teclado;
            controle = NULL;
        }

    }while(controle);

  return 0;
}

int Pessoa::lerNaturalidade() {
  string teclado;

  cout << "Digite a naturalidade: ";
  getline(cin, teclado);

  if (teclado == "-1") {
    return -1;
  }

  naturalidade = teclado;

  return 0;
}

int Pessoa::lerTipoSanguineo() {
  string teclado;

  cout << "Informe o tipo sanguíneo: ";
  getline(cin, teclado);

  if (teclado == "-1") {
    return -1;
  }

  tipoSanguineo = teclado;

  return 0;
}

int Pessoa::lerSexo() {
  string teclado;

  cout << "Informe o sexo ('f' - Feminino, 'm' - Masculino): ";
  do {
    getline(cin, teclado);

    if (teclado == "-1") {
      return -1;
    }

    if (teclado == "f" || teclado == "F") {
      sexo = "Feminino";
      break;
    }

    if (teclado == "m" || teclado == "M") {
      sexo = "Masculino";
      break;
    }

    cout << "Informação inválida! ('f' - Feminino, 'm' - Masculino): ";
  } while (1);

  return 0;
}

int Pessoa::lerDataDeNascimento() {
  cout << "Digite a data de nascimento (dia/mês/ano): ";
  if (dataDeNascimento.lerData() == -1) {
    return -1;
  }

  return 0;
}

string Pessoa::getNome() { return nome; }
string Pessoa::getCPF() { return cpf; }
string Pessoa::getNaturalidade() { return naturalidade; }
string Pessoa::getTipoSanguineo() { return tipoSanguineo; }
string Pessoa::getSexo() { return sexo; }
Data Pessoa::getDataDeNascimento() { return dataDeNascimento; }
int Pessoa::getID() { return id; }

void Pessoa::setNome(string nome) { this->nome = nome; }
void Pessoa::setCPF(string cpf) { this->cpf = cpf; }
void Pessoa::setNaturalidade(string naturalidade) {
  this->naturalidade = naturalidade;
}
void Pessoa::setTipoSanguineo(string tipoSanguineo) {
  this->tipoSanguineo = tipoSanguineo;
}
void Pessoa::setSexo(string sexo) { this->sexo = sexo; }
void Pessoa::setDataDeNascimento(string data) {
  dataDeNascimento.setData(data);
}
void Pessoa::setID(int id) { this->id = id; }
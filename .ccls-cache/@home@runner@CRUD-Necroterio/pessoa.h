#pragma once
#include "data.h"
#include "tela.h"
#include <iostream>

class Pessoa {
private:
  std::string nome;
  std::string cpf;
  std::string naturalidade;
  std::string tipoSanguineo;
  char sexo;
  Data dataDeNascimento;

public:
  Pessoa();
  ~Pessoa();
  virtual void lerAtributos();
  virtual void exibirAtributos();

  std::string getNome();
};
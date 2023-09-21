#pragma once
#include "data.h"
#include "pessoa.h"
#include <iostream>

class Funcionario : public Pessoa {
private:
  std::string cargo;
  float salarioMensal;
  int id;

public:
  void lerAtributos();
  void exibirAtributos();
};
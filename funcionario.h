#pragma once
#include "data.h"
#include "pessoa.h"
#include <iostream>

class Funcionario : public Pessoa {
private:
  std::string cargo;
  float salarioMensal;

public:
  int lerAtributos();
  void exibirAtributos();

  int lerCargo();
  int lerSalarioMensal();

  std::string getCargo();
  float getSalarioMensal();

  void setCargo(std::string cargo);
  void setSalarioMensal(float salarioMensal);
};
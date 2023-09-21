#pragma once
#include "data.h"
#include "pessoa.h"
#include <iostream>

class Morto : public Pessoa {
private:
  Data dataDaMorte;
  std::string causaDaMorte;
  bool ehDoador;
  int id;

public:
  void lerAtributos();
  void exibirAtributos();
};
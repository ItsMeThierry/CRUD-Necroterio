#pragma once
#include "data.h"
#include "pessoa.h"
#include <iostream>

class Morto : public Pessoa {
private:
  Data dataDaMorte;
  std::string causaDaMorte;
  bool ehDoador;

public:
  int lerAtributos();
  void exibirAtributos();

  int lerDataDaMorte();
  int lerCausaDaMorte();
  int lerEhDoador();

  Data getDataDaMorte();
  std::string getCausaDaMorte();
  bool getEhDoador();

  void setDataDaMorte(std::string data);
  void setCausaDaMorte(std::string causaDaMorte);
  void setEhDoador(bool ehDoador);
};
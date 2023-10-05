#pragma once
#include "pessoa.h"
#include <fstream>
#include <iostream>
#include <vector>

class OperadorDeArquivo {
private:
  int arquivoID;

public:
  void salvaDados(std::vector<Pessoa *> pessoas, std::string nome);
  void carregaDados(std::vector<Pessoa *> *pessoas, std::string *nome);

  bool temArquivo(int id);

  int getArquivoID();
  void setArquivoID(int id);
};
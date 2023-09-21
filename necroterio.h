#pragma once
#include "pessoa.h"
#include <iostream>
#include <vector>

class Necroterio {
private:
  std::vector<Pessoa *> pessoas;
  std::string nome;
  int capacidadeMax;
  int quantidadeDeFuncionarios;
  int quantidadeDeMortos;

  int escolherOpcao();
  Pessoa *pesquisar(std::string nome);

public:
  Necroterio();
  void lerPessoa();
  void exibirPessoa();
  void alterarPessoa();
  void removerPessoa();
  void lerAtributos();

  std::string getNome();
};
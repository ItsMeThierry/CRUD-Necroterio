#pragma once
#include "operadorDeArquivo.h"
#include "pessoa.h"
#include <iostream>
#include <vector>

class Necroterio {
private:
  std::vector<Pessoa *> pessoas;
  std::string nome;
  int quantidadeDeFuncionarios;
  int quantidadeDeMortos;

  int escolherOpcao();
  Pessoa *pesquisar(std::string nome);

public:
  Necroterio(OperadorDeArquivo *op);

  void lerPessoa();
  void listarTodos();
  void exibirPessoa();
  void alterarPessoa();
  void removerPessoa();
  void exibirRelatorio();
  void lerAtributos();

  std::string getNome();
  std::vector<Pessoa *> getPessoas();
};
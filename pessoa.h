#pragma once
#include "data.h"
#include "teclado.h"
#include "tela.h"
#include <iostream>

class Pessoa {
private:
  std::string nome;
  std::string cpf;
  std::string naturalidade;
  std::string tipoSanguineo;
  std::string sexo;
  Data dataDeNascimento;
  int id;

public:
  Pessoa();
  ~Pessoa();
  virtual int lerAtributos();
  virtual void exibirAtributos();

  int lerNome();
  int lerCPF();
  int lerNaturalidade();
  int lerTipoSanguineo();
  int lerSexo();
  int lerDataDeNascimento();

  std::string getNome();
  std::string getCPF();
  std::string getNaturalidade();
  std::string getTipoSanguineo();
  std::string getSexo();
  Data getDataDeNascimento();
  int getID();

  void setNome(std::string nome);
  void setCPF(std::string cpf);
  void setNaturalidade(std::string naturalidade);
  void setTipoSanguineo(std::string tipoSanguineo);
  void setSexo(std::string sexo);
  void setDataDeNascimento(std::string data);
  void setID(int i);
};
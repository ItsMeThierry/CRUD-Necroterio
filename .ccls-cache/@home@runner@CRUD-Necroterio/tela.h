#pragma once
#include <iostream>

class Tela {
public:
  static std::string espacamento(int quantidade);
  static std::string acrescentarZero(std::string num);
  static void limparTela();
  static int calcularEspacamento(int fixo, int variavel);
};
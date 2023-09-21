#pragma once
#include <iostream>

class Data {
private:
  int dia;
  int mes;
  int ano;

public:
  std::string getData();
  void lerData();
};
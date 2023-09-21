#include "data.h"
#include <iostream>

using namespace std;

string
Data::getData() { // Retorna a data no seguinte formato string: dia/mes/ano
  return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}

void Data::lerData() { // Lê os atributos da classe data
  cin >> dia >> mes >> ano;
  cin.ignore();
}
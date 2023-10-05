#include "teclado.h"
#include <iostream>

using namespace std;

bool Teclado::ehNumeroInt(string string) {
  for (int i = 0; i < string.size(); i++) {
    if (!isdigit(string[i])) {
      return false;
    }
  }

  return true;
}

bool Teclado::ehNumeroFloat(string string) {
  bool temPeloMenosUmNumero = false;

  for (int i = 0; i < string.size(); i++) {
    if (!isdigit(string[i]) && (string[i] != ',' || string[i] == '.')) {
      return false;
    }

    if (isdigit(string[i])) {
      temPeloMenosUmNumero = true;
    }
  }

  return temPeloMenosUmNumero;
}
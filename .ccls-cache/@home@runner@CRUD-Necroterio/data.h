#pragma once
#include <iostream>

class Data {
private:
  std::string dia;
  std::string mes;
  std::string ano;

public:
  std::string getData();
  void setData(std::string data);
  int lerData();
};
#include "operadorDeArquivo.h"
#include "funcionario.h"
#include "morto.h"
#include <iostream>
#include <string>

using namespace std;

void OperadorDeArquivo::salvaDados(vector<Pessoa *> pessoas, string nome) {
  ofstream file;

  file.open("arquivo_0" + to_string(arquivoID) + ".txt");

  if (!file.is_open()) {
    cout << "Erro ao abrir aquivo para escrita\n";
    return;
  }

  cout << "Salvando...\n";

  bool ehMorto;

  file << "Necrotério: " << nome << ";\n\n";

  for (Pessoa *p : pessoas) {
    ehMorto = dynamic_cast<Morto *>(p) != NULL;

    file << "Tipo: " << ((ehMorto) ? "1" : "2") << ";\n";
    file << "Nome: " << p->getNome() << ";\n";
    file << "CPF: " << p->getCPF() << ";\n";
    file << "Naturalidade: " << p->getNaturalidade() << ";\n";
    file << "Tipo Sanguineo: " << p->getTipoSanguineo() << ";\n";
    file << "Sexo: " << p->getSexo() << ";\n";
    file << "Data de Nascimento: " << p->getDataDeNascimento().getData()
         << ";\n";

    if (ehMorto) {
      file << "Data da Morte: " << ((Morto *)p)->getDataDaMorte().getData()
           << ";\n";
      file << "Causa da Morte: " << ((Morto *)p)->getCausaDaMorte() << ";\n";
      file << "É doador: " << ((Morto *)p)->getEhDoador() << ";\n";
    } else {
      file << "Cargo: " << ((Funcionario *)p)->getCargo() << ";\n";
      file << "Salario Mensal: " << ((Funcionario *)p)->getSalarioMensal()
           << ";\n";
    }

    file << "-\n";
  }

  file.close();
}

void OperadorDeArquivo::carregaDados(vector<Pessoa *> *pessoas, string *nome) {
  ifstream file;

  file.open("arquivo_0" + to_string(arquivoID) + ".txt");

  if (!file.is_open()) {
    cout << "Erro ao abrir aquivo para escrita\n";
    return;
  }

  string s;

  Pessoa *p;
  int tipo = -1;

  cout << "Carregando...\n";

  while (!file.eof()) {
    getline(file, s);

    if (s == "") {
      continue;
    }

    if (s == "-") {
      (*pessoas).push_back(p);
      continue;
    }

    size_t i = s.find_first_of(':');

    if (i == string::npos) {
      cout << "ERRO de arquivo! O arquivo está indevidamente escrito!\n";
      break;
    }

    string atributo = s.substr(0, i);

    if (atributo == "Necrotério") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O necrotério está indevidamente escrito!\n";
        break;
      }

      *nome = s.substr(i + 2, j - i - 2);
    }

    if (atributo == "Tipo") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O tipo está indevidamente escrito!\n";
        break;
      }

      char c = (s.substr(i + 2, 1))[0];

      if (c == '1') {
        p = new Morto();
        tipo = 1;
      } else if (c == '2') {
        p = new Funcionario();
        tipo = 2;
      } else {
        cout << "ERRO DE ARQUIVO! O tipo está indevidamente escrito!\n";
        break;
      }
    }

    if (atributo == "Nome") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O nome está indevidamente escrito!\n";
        break;
      }

      p->setNome(s.substr(i + 2, j - i - 2));
    }

    if (atributo == "CPF") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O CPF está indevidamente escrito!\n";
        break;
      }

      p->setCPF(s.substr(i + 2, j - i - 2));
    }

    if (atributo == "Naturalidade") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! A naturalidade está indevidamente escrito!\n";
        break;
      }

      p->setNaturalidade(s.substr(i + 2, j - i - 2));
    }

    if (atributo == "Tipo Sanguineo") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O tipo sanguineo está indevidamente "
                "escrito!\n";
        break;
      }

      p->setTipoSanguineo(s.substr(i + 2, j - i - 2));
    }

    if (atributo == "Sexo") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! O sexo está indevidamente escrito!\n";
        break;
      }

      p->setSexo(s.substr(i + 2, j - i - 2));
    }

    if (atributo == "Data de Nascimento") {
      size_t j = s.find_last_of(";");

      if (j == string::npos) {
        cout << "ERRO DE ARQUIVO! A data de nascimento está indevidamente "
                "escrito!\n";
        break;
      }

      p->setDataDeNascimento(s.substr(i + 2, j - i - 2));
    }

    if (tipo == 1) {
      if (atributo == "Data da Morte") {
        size_t j = s.find_last_of(";");

        if (j == string::npos) {
          cout << "ERRO DE ARQUIVO! A data da morte está indevidamente "
                  "escrito!\n";
          break;
        }

        ((Morto *)p)->setDataDaMorte(s.substr(i + 2, j - i - 2));
      }

      if (atributo == "Causa da Morte") {
        size_t j = s.find_last_of(";");

        if (j == string::npos) {
          cout << "ERRO DE ARQUIVO! A causa da morte está indevidamente "
                  "escrito!\n";
          break;
        }

        ((Morto *)p)->setCausaDaMorte(s.substr(i + 2, j - i - 2));
      }

      if (atributo == "É doador") {
        size_t j = s.find_last_of(";");

        if (j == string::npos) {
          cout << "ERRO DE ARQUIVO! O é doador está indevidamente escrito!\n";
          break;
        }

        ((Morto *)p)->setEhDoador(stoi(s.substr(i + 2, j - i - 2)));
      }
    } else if (tipo == 2) {
      if (atributo == "Cargo") {
        size_t j = s.find_last_of(";");

        if (j == string::npos) {
          cout << "ERRO DE ARQUIVO! O cargo está indevidamente escrito!\n";
          break;
        }

        ((Funcionario *)p)->setCargo(s.substr(i + 2, j - i - 2));
      }

      if (atributo == "Salario Mensal") {
        size_t j = s.find_last_of(";");

        if (j == string::npos) {
          cout << "ERRO DE ARQUIVO! O salário mensal está indevidamente "
                  "escrito!\n";
          break;
        }

        ((Funcionario *)p)->setSalarioMensal(stof(s.substr(i + 2, j - i - 2)));
      }
    }
  }

  for (int i = 0; i < (*pessoas).size(); i++) {
    (*pessoas)[i]->setID(i);
  }

  file.close();
}

bool OperadorDeArquivo::temArquivo(int id) {
  fstream file;
  bool existe;

  /*
  arquivo_01.txt
  arquivo_02.txt
  arquivo_03.txt
  */
  file.open("arquivo_0" + to_string(id) + ".txt");

  existe = file.is_open();

  if (!existe) {
    file.close();
  }

  return existe;
}

int OperadorDeArquivo::getArquivoID() { return arquivoID; }

void OperadorDeArquivo::setArquivoID(int id) { arquivoID = id; }

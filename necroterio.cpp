#include "necroterio.h"
#include "funcionario.h"
#include "morto.h"
#include "tela.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Necroterio::Necroterio() { lerAtributos(); }

/*
      Método para pesquisar por nome ou índice, e reuse ele nas opções, exibir
     um, alterar, remover. Este método deve retornar o endereço do objeto, e
     deve receber como parâmetro o string do nome e o índice a ser buscado.
*/

Pessoa *Necroterio::pesquisar(std::string nome) {

  for (Pessoa *p : pessoas) {
    if (p->getNome() == nome) {
      return p;
    }
  }

  return 0;
}

int Necroterio::escolherOpcao() {
  int opcao;

  cout << "É um morto ou um funcionário? [1- Morto, 2- Funcionário]: ";

  do {
    cin >> opcao;
    cin.ignore();

    if (opcao == 1 || opcao == 2) {
      break;
    }

    cout << "Opção inválida! [1- Morto, 2- Funcionário]: ";
  } while (1);

  return opcao;
}

/*
  A função lerPessoa verifica que está sendo adicionado um morto ou funcionário,
  e depois, lê os atributos do objeto e o adiciona no vector de pessoas.
*/

void Necroterio::lerPessoa() {
  Pessoa *p;

  int opcao = escolherOpcao();

  Tela::limparTela();

  if (opcao == 1) {
    p = new Morto();
  } else if (opcao == 2) {
    p = new Funcionario();
  }

  p->lerAtributos();

  pessoas.push_back(p);
}

void Necroterio::exibirPessoa() {
  string nome;

  do {
    cout
        << "Digite o nome da pessoa que você deseja exibir (digite 'sair' para "
           "voltar ao menu): ";
    getline(cin, nome);

    Tela::limparTela();

    if (nome == "sair") {
      break;
    }

    Pessoa *p = pesquisar(nome);

    if (p == 0) {
      cout << "Nome não encontrado!\n";
      continue;
    }

    p->exibirAtributos();
    break;
  } while (1);
}

void Necroterio::alterarPessoa() {
  cout << "Digite o nome da pessoa que você deseja ";
}

void Necroterio::removerPessoa() {
  string nome;

  do {
    cout << "Digite o nome da pessoa que você deseja remover (digite 'sair' "
            "para voltar ao menu): ";
    getline(cin, nome);

    Tela::limparTela();

    if (nome == "sair") {
      break;
    }

    Pessoa *p = pesquisar(nome);

    if (p == 0) {
      cout << "Nome não encontrado!\n";
      continue;
    }

    delete p;
    break;
  } while (1);
}

/*Lê todos os atributos da classe necrotério.
Limite de 35 caracteres para nome.
*/

void Necroterio::lerAtributos() {
  do {
    cout << "Escreva o nome do necrotério (35 caracteres): ";
    getline(cin, nome);

    if (nome.size() <= 35) {
      break;
    }

    cout << "ERRO! No máximo 35 caracteres!\n";
  } while (1);

  cout << "Descreva a capacidade máxima de mortos: ";
  cin >> capacidadeMax;
  cin.ignore();

  Tela::limparTela();
}

string Necroterio::getNome() { return nome; }
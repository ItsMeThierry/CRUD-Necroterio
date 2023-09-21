#include "necroterio.h"
#include "pessoa.h"
#include "tela.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
    A função espaçamento é um loop que adiciona espaços brancos em um texto e o
   retorna em string
*/

string espacamento(int quantidade) {
  string espaco;

  while (quantidade--) {
    espaco.append(" ");
  }

  return espaco;
}

/*
    A função calcularEspaçamento retorna um numero inteiro de espaços
   necessários para centralizar um texto variavel em relação a um fixo
*/

int calcularEspacamento(int fixo, int variavel) {
  return abs(fixo - variavel) / 2;
}

int main() {
  /*
      Template do Menu:

      =================================================
              +NECROTÉRIO {nome do necrotério}+
      =================================================
      1. Inserir
      2. Listar todos
      3. Exibir
      4. Alterar
      5. Remover
      6. Exibir Relatório
      7. Sair
      =================================================

      ATENÇÃO: os itens 1,3,4 e 5 devem, antes, perguntar se é um funcionário ou
     morto.
  */

  Necroterio necroterio = Necroterio();

  string teclado;
  bool running = true;

  do {
    cout << "=================================================\n\n"
         << espacamento(calcularEspacamento(
                50, ("+ NECROTÉRIO  +" + necroterio.getNome()).size()))
         << "+ NECROTÉRIO " << necroterio.getNome()
         << " +\n\n=================================================";
    cout << "\n1. Inserir\n2. Listar todos\n3. Exibir\n4. Alterar\n5. "
            "Remover\n6. Exibir Relatório\n7. "
            "Sair\n=================================================\n";

    do {
      cout << "Escolha uma opção: ";
      cin >> teclado;
      cin.ignore();

      if (teclado.size() == 1 && stoi(teclado) >= 1 && stoi(teclado) <= 7) {
        break;
      } else {
        cout << "Opção inválida!\n";
      }
    } while (1);

    switch (stoi(teclado)) {
    case 1:
      necroterio.lerPessoa();
      break;
    case 2:
      // Listar todos mortos ou funcionarios
      break;
    case 3:
      necroterio.exibirPessoa();
      break;
    case 4:
      necroterio.alterarPessoa();
      break;
    case 5:
      necroterio.removerPessoa();
      break;
    case 6:
      // Exibe relatório
      break;
    case 7:
      running = false;
    }

  } while (running);

  return 0;
}
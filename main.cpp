
#include "necroterio.h"
#include "operadorDeArquivo.h"
#include "teclado.h"
#include "tela.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

  string teclado;

  OperadorDeArquivo op = OperadorDeArquivo();

  cout << "==================================================\n1. "
       << ((op.temArquivo(1)) ? "arquivo_01.txt" : " ") << "\n2. "
       << ((op.temArquivo(2)) ? "arquivo_02.txt" : " ") << "\n3. "
       << ((op.temArquivo(3)) ? "arquivo_03.txt" : " ")
       << "\n==================================================\n";
  cout << "Escolha um slot para o arquivo: ";

  do {
    getline(cin, teclado);

    if (teclado.size() == 1 && Teclado::ehNumeroInt(teclado) &&
        stoi(teclado) > 0 && stoi(teclado) <= 3) {
      op.setArquivoID(stoi(teclado));
      break;
    }

    cout << "Opção inválida!: ";
  } while (1);

  Tela::limparTela();

  Necroterio necroterio = Necroterio(&op);

  string display = "+ NECROTÉRIO " + necroterio.getNome() + " +";
  bool running = true;

  do {
    cout << "==================================================\n\n"
         << Tela::espacamento(Tela::calcularEspacamento(50, display.size()))
         << display
         << "\n\n==================================================\n";
    cout << "1. Inserir\n2. Listar todos\n3. Exibir\n4. Alterar\n5. "
            "Remover\n6. Exibir Relatório\n7. "
            "Sair\n==================================================\n";

    cout << "Escolha uma opção: ";
    do {
      getline(cin, teclado);

      if (teclado.size() == 1 && Teclado::ehNumeroInt(teclado) &&
          stoi(teclado) > 0 && stoi(teclado) <= 7) {
        break;
      }

      cout << "Opção inválida!: ";
    } while (1);

    switch (teclado[0]) {
    case '1':
      necroterio.lerPessoa();
      break;
    case '2':
      necroterio.listarTodos();
      break;
    case '3':
      necroterio.exibirPessoa();
      break;
    case '4':
      necroterio.alterarPessoa();
      break;
    case '5':
      necroterio.removerPessoa();
      break;
    case '6':
      necroterio.exibirRelatorio();
      break;
    case '7':
      running = false;
      op.salvaDados(necroterio.getPessoas(), necroterio.getNome());
    }

  } while (running);

  return 0;
}

#include "necroterio.h"
#include "funcionario.h"
#include "morto.h"
#include "operadorDeArquivo.h"
#include "teclado.h"
#include "tela.h"
#include <iostream>
#include <string>

using namespace std;

Necroterio::Necroterio(OperadorDeArquivo *op) {
  quantidadeDeMortos = 0;
  quantidadeDeFuncionarios = 0;

  if ((*op).temArquivo((*op).getArquivoID())) {
    (*op).carregaDados(&pessoas, &nome);

    for (Pessoa *p : pessoas) {
      if (dynamic_cast<Morto *>(p) != NULL) {
        quantidadeDeMortos++;
      } else {
        quantidadeDeFuncionarios++;
      }
    }

    return;
  }

  lerAtributos();
}

Pessoa *Necroterio::pesquisar(std::string nome) {

  for (Pessoa *p : pessoas) {
    if (p->getNome().find(nome) != string::npos) {
      return p;
    }
  }

  return 0;
}

int Necroterio::escolherOpcao() {
  int opcao;
  string teclado;

  cout << "É um morto ou um funcionário? [1- Morto, 2- Funcionário]: ";

  do {
    getline(cin, teclado);

    if (teclado == "1") {
      opcao = 1;
      break;
    }

    if (teclado == "2") {
      opcao = 2;
      break;
    }

    cout << "Opção inválida! [1- Morto, 2- Funcionário]: ";
  } while (1);

  return opcao;
}

void Necroterio::lerPessoa() {
  Pessoa *p;

  int opcao = escolherOpcao();

  Tela::limparTela();

  if (opcao == 1) {
    p = new Morto();
  } else if (opcao == 2) {
    p = new Funcionario();
  }

  if (p->lerAtributos() == 0) {
    p->setID(quantidadeDeMortos + quantidadeDeFuncionarios);
    pessoas.push_back(p);

    if (opcao == 1) {
      quantidadeDeMortos++;
    } else {
      quantidadeDeFuncionarios++;
    }

    cout << "Pessoa cadastrada.\n\n";

  } else {
    delete p;
    Tela::limparTela();
  }
}

void Necroterio::listarTodos() {

  Tela::limparTela();

  int i = 0;

  if (pessoas.size() == 0) {
    Tela::limparTela();
    cout << "Não há pessoas cadastradas!\n";
    return;
  }

  bool running = true;
  string teclado;

  do {
    Tela::limparTela();

    string display = "Página: " + Tela::acrescentarZero(to_string(i + 1)) +
                     "/" + Tela::acrescentarZero(to_string(pessoas.size()));

    cout << "DIGITE -1 PARA SAIR!\n";

    cout << "==================================================\n";
    cout << Tela::espacamento(Tela::calcularEspacamento(50, display.size()))
         << display << endl;
    pessoas[i]->exibirAtributos();
    cout << "==================================================\n";

    cout << "Digite o indice: ";

    do {
      getline(cin, teclado);

      if (teclado == "-1") {
        running = false;
        break;
      }

      if (teclado.size() == 1 && stoi(teclado) > 0 &&
          stoi(teclado) <= pessoas.size()) {
        i = stoi(teclado) - 1;
        break;
      }

      cout << "Indice inválido!: ";
    } while (1);

  } while (running);

  Tela::limparTela();
}

void Necroterio::exibirPessoa() {
  string nome;

  cout << "Digite o nome da pessoa que você deseja exibir (digite 'sair' para "
          "voltar ao menu): ";
  do {
    getline(cin, nome);

    if (nome == "sair") {
      Tela::limparTela();
      break;
    }

    Pessoa *p = pesquisar(nome);

    if (p != 0) {
      Tela::limparTela();
      p->exibirAtributos();
      break;
    }

    cout << "Nome não encontrado! (digite 'sair' para "
            "voltar ao menu): ";
  } while (1);
}

void Necroterio::alterarPessoa() {
  string teclado;

  cout << "Digite o nome da pessoa que você deseja alterar (digite 'sair' "
          "para "
          "voltar ao menu): ";

  do {
    getline(cin, teclado);

    if (teclado == "sair") {
      break;
    }

    Pessoa *p = pesquisar(teclado);

    if (p != 0) {

      bool ehMorto = dynamic_cast<Morto *>(p) != NULL;

      Tela::limparTela();

      cout << "DIGITE -1 PARA VOLTAR AO MENU" << endl;

      cout << "==================================================\n1. "
              "Nome\n2. CPF\n3. Naturalidade\n4. Tipo Sanguíneo\n5. Sexo\n6. "
              "Data de Nascimento\n";

      if (ehMorto) {
        cout << "7. Data da Morte\n8. Causa da Morte\n9. É Doador\n";
      } else {
        cout << "7. Cargo\n8. Salário Mensal\n";
      }

      cout << "==================================================\n";
      cout << "Qual atributo você deseja alterar?: ";

      bool running;

      do {
        running = true;

        getline(cin, teclado);

        if (teclado == "-1") {
          break;
        }

        if (teclado.size() == 1) {
          running = false;

          switch (teclado[0]) {
          case '1':
            p->lerNome();
            break;
          case '2':
            p->lerCPF();
            break;
          case '3':
            p->lerNaturalidade();
            break;
          case '4':
            p->lerTipoSanguineo();
            break;
          case '5':
            p->lerSexo();
            break;
          case '6':
            p->lerDataDeNascimento();
            break;
          default:
            if (ehMorto) {
              switch (teclado[0]) {
              case '7':
                ((Morto *)p)->lerDataDaMorte();
                break;
              case '8':
                ((Morto *)p)->lerCausaDaMorte();
                break;
              case '9':
                ((Morto *)p)->lerEhDoador();
                break;
              default:
                cout << "Opção inválida!: ";
                running = true;
              }
            } else {
              switch (teclado[0]) {
              case '7':
                ((Funcionario *)p)->lerCargo();
                break;
              case '8':
                ((Funcionario *)p)->lerSalarioMensal();
                break;
              default:
                cout << "Opção inválida!: ";
                running = true;
              }
            }
          }
        } else {
          cout << "Opção inválida!: ";
          running = true;
        }
      } while (running);

      cout << "Atributo atualizado.\n\n";
      break;
    }

    cout << "Nome não encontrado! (digite 'sair' para "
            "voltar ao menu): ";
  } while (1);

  Tela::limparTela();
}

void Necroterio::removerPessoa() {
  string nome;

  cout << "Digite o nome da pessoa que você deseja remover (digite 'sair' "
          "para voltar ao menu): ";

  do {
    getline(cin, nome);

    if (nome == "sair") {
      Tela::limparTela();
      break;
    }

    Pessoa *p = pesquisar(nome);

    if (p != 0) {
      Tela::limparTela();
      cout << p->getNome() << " removido do sistema.\n\n";
      pessoas.erase(pessoas.begin() + p->getID());
      delete p;
      break;
    }

    cout << "Nome não encontrado! (digite 'sair' "
            "para voltar ao menu): ";
  } while (1);
}

void Necroterio::exibirRelatorio() {
  Tela::limparTela();

  if (pessoas.size() > 0) {

    string display = "+ NECROTÉRIO " + nome + " +";

    cout << "==================================================\n\n"
         << Tela::espacamento(Tela::calcularEspacamento(50, display.size()))
         << display
         << "\n\n==================================================\n";

    cout << "Pessoas cadastradas: " << pessoas.size() << endl;
    cout << "Mortos cadastrados: " << quantidadeDeMortos << endl;
    cout << "Funcionários cadastrados: " << quantidadeDeFuncionarios << endl;

    int qHomens = 0;
    int qMulheres = 0;

    for (Pessoa *p : pessoas) {
      if (p->getSexo() == "Masculino") {
        qHomens++;
      } else {
        qMulheres++;
      }
    }

    cout << "Total de mulheres cadastradas: " << qMulheres << endl;
    cout << "Total de homens cadastrados: " << qHomens << endl;

    if (quantidadeDeMortos > 0) {
      cout << "=================================================="
              "\n\n"
           << Tela::espacamento(Tela::calcularEspacamento(50, 6))
           << "MORTOS\n\n============================================"
              "======\n\n";

      int qDoadores = 0;

      for (Pessoa *p : pessoas) {
        if (dynamic_cast<Morto *>(p) != NULL) {
          if (((Morto *)p)->getEhDoador()) {
            qDoadores++;
          }
        }
      }

      cout << "Quantidade de doadores de órgãos: " << qDoadores << endl;
      cout << "Causas da morte: " << endl;

      for (Pessoa *p : pessoas) {
        if (dynamic_cast<Morto *>(p) != NULL) {
          cout << "\t" << ((Morto *)p)->getCausaDaMorte() << endl;
        }
      }

      cout << endl;
    }

    if (quantidadeDeFuncionarios > 0) {
      cout << "=================================================="
              "\n\n"
           << Tela::espacamento(Tela::calcularEspacamento(50, 12))
           << "FUNCIONÁRIOS\n\n======================================"
              "======"
              "======\n\n";

      cout << "Cargos ocupados: " << endl;

      for (Pessoa *p : pessoas) {
        if (dynamic_cast<Funcionario *>(p) != NULL) {
          cout << "\t" << ((Funcionario *)p)->getCargo() << endl;
        }
      }

      cout << endl;
    }

    string teclado;

    cout << "Pressione qualquer tecla e enter para sair...";
    getline(cin, teclado);

    Tela::limparTela();

  } else {
    cout << "Não há pessoas registradas!\n\n";
  }
}

void Necroterio::lerAtributos() {
  cout << "Escreva o nome do necrotério (35 caracteres): ";

  do {
    getline(cin, nome);

    if (nome.size() <= 35 && !Teclado::ehNumeroInt(nome)) {
      break;
    }

    cout << "ERRO! No máximo 35 caracteres!: ";
  } while (1);

  for (int i = 0; i < nome.size(); i++) {
    nome[i] = toupper(nome[i]);
  }

  Tela::limparTela();
}

string Necroterio::getNome() { return nome; }

vector<Pessoa *> Necroterio::getPessoas() { return pessoas; }

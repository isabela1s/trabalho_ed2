#include <iostream>
#include "tabelahash.hpp"

using namespace std;
int main() {
    tabelahash tabela(1000);

    try {
        // Tentar ler o arquivo CSV
        tabela.ler_csv("NationalNames.csv");
        cout << "Arquivo CSV lido com sucesso!\n";
    } catch (const exception &e) {
        cerr << "Erro ao ler o arquivo CSV: " << e.what() << "\n";

        //std::cout << "Inserindo valores manualmente...\n";
        //tabela.insere("Alice", 2000, 1);
        //tabela.insere("Bob", 1999, 2);
        //tabela.insere("Charlie", 2001, 1);
        //tabela.insere("David", 2005, 3);
        //tabela.insere("Eve", 2020, 5);
    }

    tabela.imprime_tabela();

    size_t x = 2;
    cout << "\nMaiores ocorrências (" << x << " primeiros):\n";
    auto maiores = tabela.maiores_ocorrencias(x);
    for (const auto &reg : maiores) {
        cout << "Nome: " << reg->get_nome() << ", Ano: " << reg->get_ano()
                  << ", Ocorrências: " << reg->get_ocorrencias() << endl;
    }

    return 0;
}
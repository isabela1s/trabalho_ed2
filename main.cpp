#include "tabelahash.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void carregaCsv(tabelahash &tabela, const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }

    std::string line;
    // Pular o cabeçalho
    if (std::getline(file, line))
    {
        std::cout << "Cabeçalho ignorado: " << line << std::endl;
    }

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string id, nome, ano_str, genero, ocorrencias_str;

        // Ler os dados do CSV considerando que os campos são separados por vírgula
        if (std::getline(ss, id, ',') &&
            std::getline(ss, nome, ',') &&
            std::getline(ss, ano_str, ',') &&
            std::getline(ss, genero, ',') &&
            std::getline(ss, ocorrencias_str, ','))
        {
            unsigned ano = std::stoi(ano_str);
            unsigned ocorrencias = std::stoi(ocorrencias_str);

            //std::cout << "Inserindo: " << nome << ", " << ano << ", " << ocorrencias << std::endl;
            tabela.insere(nome, ano, ocorrencias);
        }
    }

    file.close();
}

int main()
{
    // Criação da tabela hash com um tamanho pequeno para forçar colisões
    tabelahash tabela(10);

    // Inserir alguns registros na tabela
    tabela.insere("Alice", 2000, 1);
    tabela.insere("Bob", 1999, 2);
    tabela.insere("Charlie", 2001, 1);
    tabela.insere("David", 2005, 3);
    tabela.insere("Eve", 2020, 5);

    // Imprimir a tabela para ver o que foi inserido
    tabela.imprime_tabela();

    // Testar a função que retorna os registros com maiores ocorrências
    std::cout << "\nMaiores ocorrências (2 primeiros):\n";
    auto maiores = tabela.maiores_ocorrencias(2);
    for (const auto& reg : maiores) {
        std::cout << "Nome: " << reg->get_nome() << ", Ano: " << reg->get_ano()
                  << ", Ocorrências: " << reg->get_ocorrencias() << std::endl;
    }

    return 0;
}

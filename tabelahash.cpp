#include "tabelahash.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

size_t tabelahash::hash2(const string &chave) const
{
    const int base2 = 53;
    const int mod = 1e9 + 7;
    unsigned long long hashValue = 0;
    for (char c : chave)
    {
        hashValue = (hashValue * base2 + static_cast<unsigned long long>(c)) % mod;
    }
    return hashValue % tamanho;
}

tabelahash::tabelahash(size_t tamanho)
    : tamanho(tamanho), tabela(tamanho, nullptr) {}

tabelahash::~tabelahash()
{
    for (auto reg : tabela)
    {
        delete reg;
    }
}

class TabelaCheiaException : public exception {
    virtual const char *what() const throw() {
        return "Tabela hash cheia!";
    }
};

void tabelahash::insere(const string &nome, unsigned ano, unsigned ocorrencias)
{
    size_t index = hash(nome);

    if (tabela[index] == nullptr)
    {
        tabela[index] = new registro(nome, ano, ocorrencias);
        cout << "Registro inserido na posição " << index << endl;
    }
    else
    {
        size_t i = 1;
        size_t newIndex = (index + i * hash2(nome)) % tamanho;
        while (tabela[newIndex] != nullptr && newIndex != index)
        {
            i++;
            newIndex = (index + i * hash2(nome)) % tamanho;
        }

        if (newIndex != index)
        {
            tabela[newIndex] = new registro(nome, ano, ocorrencias);
            cout << "Registro inserido na posição " << newIndex << endl;
        }
        else
        {
            cerr << "Tabela hash cheia ou erro ao inserir " << nome << endl;
        }
    }
}

void tabelahash::imprime_tabela() const
{
    for (size_t i = 0; i < tabela.size(); ++i)
    {
        if (tabela[i] != nullptr)
        {
            std::cout << "Posição " << i << ": "
                      << tabela[i]->get_nome() << " ("
                      << tabela[i]->get_ano() << ", "
                      << tabela[i]->get_ocorrencias() << " ocorrências)" << std::endl;
        }
        else
        {
            std::cout << "Posição " << i << ": Vazia" << std::endl;
        }
    }
}

std::vector<registro *> tabelahash::maiores_ocorrencias(size_t x) const
{
    std::vector<registro *> maiores;
    for (const auto& reg : tabela) {
        if (reg != nullptr) {
            maiores.push_back(reg);
        }
    }

    std::sort(maiores.begin(), maiores.end(), [](registro *a, registro *b) {
        return a->get_ocorrencias() > b->get_ocorrencias();
    });

    if (maiores.size() > x) {
        maiores.resize(x);
    }

    return maiores;
}

registro *tabelahash::pega_registro(const std::string &nome) const
{
    size_t index = acha_registro(nome);
    if (index != -1)
    {
        return tabela[index];
    }
    return nullptr;
}

size_t tabelahash::acha_registro(const std::string &nome) const
{
    size_t index = hash(nome);
    if (tabela[index] != nullptr && tabela[index]->get_nome() == nome)
    {
        return index;
    }
    else
    {
        size_t newIndex = (index + 1) % tamanho;
        while (tabela[newIndex] != nullptr && tabela[newIndex]->get_nome() != nome && newIndex != index)
        {
            newIndex = (newIndex + 1) % tamanho;
        }
        if (tabela[newIndex] != nullptr && tabela[newIndex]->get_nome() == nome)
        {
            return newIndex;
        }
    }
    return -1;
}

size_t tabelahash::hash(const std::string &chave) const
{
    size_t hash_value = 0;
    size_t base = 31;
    size_t mod = 1e9 + 7;
    for (char c : chave) {
        hash_value = (hash_value * base + static_cast<unsigned long long>(c)) % mod;
    }

    return hash_value % tamanho;
}

void tabelahash::ler_csv(const std::string &arquivo) {
    std::ifstream arquivo_csv(arquivo);

    if (!arquivo_csv.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo: " + arquivo);
    }

    std::string linha;

    if (!std::getline(arquivo_csv, linha)) {
        throw std::runtime_error("Arquivo CSV está vazio ou inválido.");
    }

    while (std::getline(arquivo_csv, linha)) {
        std::istringstream stream(linha);
        std::string id, nome, ano_str, genero, ocorrencias_str;

        if (!std::getline(stream, id, ',') ||
            !std::getline(stream, nome, ',') ||
            !std::getline(stream, ano_str, ',') ||
            !std::getline(stream, genero, ',') ||
            !std::getline(stream, ocorrencias_str, ',')) {
            throw std::runtime_error("Erro ao processar linha do CSV: " + linha);
        }

        try {
            unsigned ano = std::stoul(ano_str);
            unsigned ocorrencias = std::stoul(ocorrencias_str);

            insere(nome, ano, ocorrencias);
        } catch (const std::exception &e) {
            throw std::runtime_error("Erro ao converter dados na linha: " + linha);
        }
    }
}
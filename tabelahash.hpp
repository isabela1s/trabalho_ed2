#ifndef TABELA_HASH_HPP
#define TABELA_HASH_HPP

#include "registro.hpp"
#include <vector>

using namespace std;

class tabelahash
{
private:
    size_t tamanho;
    vector<registro *> tabela;

public:
    tabelahash(size_t tamanho);
    ~tabelahash();

    void insere(const string &nome, unsigned ano, unsigned ocorrencias);
    void imprime_tabela() const;
    vector<registro *> maiores_ocorrencias(size_t x) const;

    registro *pega_registro(const string &nome) const;
    size_t acha_registro(const string &nome) const;
    void ler_csv(const string &nome_arquivo);

private:
    size_t hash(const string &chave) const;
    size_t hash2(const string &chave) const;
};

#endif /* TABELA_HASH_HPP */

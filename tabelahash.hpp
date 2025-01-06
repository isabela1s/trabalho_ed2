#ifndef TABELA_HASH_HPP
#define TABELA_HASH_HPP

#include "registro.hpp"
#include <vector>

class tabelahash
{
private:
    size_t tamanho;
    std::vector<registro *> tabela;

public:
    tabelahash(size_t tamanho);
    ~tabelahash();

    void insere(const std::string &nome, unsigned ano, unsigned ocorrencias);
    void imprime_tabela() const;
    std::vector<registro *> maiores_ocorrencias(size_t x) const;

    registro *pega_registro(const std::string &nome) const;
    size_t acha_registro(const std::string &nome) const;

private:
    size_t hash(const std::string &chave) const;
    size_t hash2(const std::string &chave) const;  // Declaração da função hash2
};

#endif /* TABELA_HASH_HPP */
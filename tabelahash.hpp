#ifndef TABELA_HASH
#define TABELA_HASH

#include "registro.hpp"

class tabelahash
{
private:
    size_t tamanho;

    registro **tabela;

public:
    tabelahash();
    ~tabelahash();

    void insere(std::string nome, unsigned ano, unsigned ocorrencias);
    void imprime_tabela();

    registro *pega_registro(std::string nome, unsigned ano, unsigned ocorrencias);

    size_t acha_registro(std::string nome, unsigned ano, unsigned ocorrencias);
};

#endif /* TABELA_HASH */

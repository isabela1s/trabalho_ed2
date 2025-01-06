#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>

class registro
{
private:
    std::string nome;
    unsigned ano;
    unsigned ocorrencias;
    size_t _posicao;

public:
    registro(const std::string &nome, unsigned ano, unsigned ocorrencias);
    ~registro();

    void set_posicao(size_t posicao);
    std::string get_nome() const;
    unsigned get_ano() const;
    unsigned get_ocorrencias() const;
    size_t get_posicao() const;
};

#endif /* REGISTRO_HPP */


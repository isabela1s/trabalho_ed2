#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>
using namespace std;

class registro
{
private:
    string nome;
    unsigned ano;
    unsigned ocorrencias;
    size_t _posicao;

public:
    registro(const string &nome, unsigned ano, unsigned ocorrencias);
    ~registro();

    void set_posicao(size_t posicao);
    string get_nome() const;
    unsigned get_ano() const;
    unsigned get_ocorrencias() const;
    size_t get_posicao() const;
};

#endif /* REGISTRO_HPP */
#include "registro.hpp"
using namespace std;
registro::registro(const string &nome, unsigned ano, unsigned ocorrencias)
    : nome(nome), ano(ano), ocorrencias(ocorrencias), _posicao(0) {}

registro::~registro() {}

void registro::set_posicao(size_t posicao)
{
    _posicao = posicao;
}

string registro::get_nome() const
{
    return nome;
}

unsigned registro::get_ano() const
{
    return ano;
}

unsigned registro::get_ocorrencias() const
{
    return ocorrencias;
}

size_t registro::get_posicao() const
{
    return _posicao;
}
#include "Ferramenta.h"
int Ferramenta::DESCONTO;

Ferramenta::Ferramenta(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda)
{
    Ferramenta::DESCONTO = 10;
}

Ferramenta::~Ferramenta(){}

float Ferramenta::get_preco_avista()
{
    return get_preco() - (preco_venda * (float(DESCONTO)/100));
}
string Ferramenta::to_string()
{
    return "Ferramenta, " + nome + ", " + std::to_string(preco_compra) + ", " + std::to_string(preco_venda) + ", " + std::to_string(get_preco_avista());
}

string Ferramenta::get_tipo()
{
    return "Ferramenta";
}

#include "Ferramenta.h"

Ferramenta::Ferramenta(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda){}

Ferramenta::~Ferramenta(){}

float Ferramenta::desconto_a_vista()
{
    return preco_venda * DESCONTO;
}

#include "Produto.h"

Produto::Produto(string nome, float preco_compra, float preco_venda)
{
    this->nome = nome;
    this->preco_compra = preco_compra;
    this->preco_venda = preco_venda;
}

Produto::~Produto(){}

string Produto::get_nome()
{
    return nome;
}

void Produto::set_nome(string nome)
{
    this->nome = nome;
}

float Produto::get_preco_compra()
{
    return preco_compra;
}

float Produto::get_preco()
{
    return preco_venda;
}

float Produto::set_preco(float preco)
{
    preco_venda = preco;
}

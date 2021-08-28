#include "MaterialEletrico.h"
MaterialEletrico::MaterialEletrico(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda){}

MaterialEletrico::~MaterialEletrico(){}

float MaterialEletrico::desconto_a_vista()
{
    return preco_venda * DESCONTO;
}

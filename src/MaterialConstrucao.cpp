#include "MaterialConstrucao.h"
MaterialConstrucao::MaterialConstrucao(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda){}

MaterialConstrucao::~MaterialConstrucao(){}

float MaterialConstrucao::desconto_a_vista()
{
    return preco_venda * DESCONTO;
}

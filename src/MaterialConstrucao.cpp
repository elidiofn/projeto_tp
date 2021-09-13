#include "MaterialConstrucao.h"

int MaterialConstrucao::DESCONTO;

MaterialConstrucao::MaterialConstrucao(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda)
{
    MaterialConstrucao::DESCONTO = 5;
}

MaterialConstrucao::~MaterialConstrucao(){}

float MaterialConstrucao::get_preco_avista()
{
    return preco_venda - (preco_venda * (float(DESCONTO)/100));
}

string MaterialConstrucao::to_string()
{
    return "Material Construcao, " + nome + ", " + std::to_string(preco_compra) + ", " + std::to_string(preco_venda) + ", " + std::to_string(get_preco_avista());
}

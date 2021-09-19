#include "MaterialEletrico.h"

int MaterialEletrico::DESCONTO;

MaterialEletrico::MaterialEletrico(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda)
{
    MaterialEletrico::DESCONTO = 8;
}

MaterialEletrico::~MaterialEletrico(){}

float MaterialEletrico::get_preco_avista()
{
    return preco_venda - (preco_venda * (float(DESCONTO)/100));
}

string MaterialEletrico::to_string()
{
    return "Material Eletrico, " + nome + ", " + std::to_string(preco_compra) + ", " + std::to_string(preco_venda) + ", " + std::to_string(get_preco_avista());
}

string MaterialEletrico::get_tipo()
{
    return "Material Elétrico";
}

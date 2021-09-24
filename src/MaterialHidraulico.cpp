#include "MaterialHidraulico.h"

int MaterialHidraulico::DESCONTO;

MaterialHidraulico::MaterialHidraulico(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda)
{
    MaterialHidraulico::DESCONTO = 9;
}

MaterialHidraulico::~MaterialHidraulico(){}

float MaterialHidraulico::get_preco_avista()
{
    return preco_venda - (preco_venda * (float(DESCONTO)/100));
}
string MaterialHidraulico::to_string()
{
    return "Material Hidraulico;" + nome + ";" + std::to_string(preco_compra) + ";" + std::to_string(preco_venda) + ";" + std::to_string(get_preco_avista());
}

string MaterialHidraulico::get_tipo()
{
    return "Material Hidráulico";
}

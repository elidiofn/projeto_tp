#include "MaterialHidraulico.h"

MaterialHidraulico::MaterialHidraulico(string nome, float preco_compra, float preco_venda) : Produto(nome,preco_compra, preco_venda){}

MaterialHidraulico::~MaterialHidraulico(){}

float MaterialHidraulico::desconto_a_vista()
{
    return preco_venda * DESCONTO;
}

#include "Venda.h"
#include "Produto.h"
#include "Funcionario.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

Venda::Venda(){}

Venda::~Venda(){}

float Venda::get_valor()
{
    float soma = 0.0;
    for(int i = 0; i < itens.size(); i++){
        soma += itens[i]->get_preco();
    }
    return soma;
}

Funcionario Venda::get_vendendor()
{
    return vendedor;
}

void Venda::set_vendedor(Funcionario Vendedor)
{
    this->vendedor = vendedor;
}

string Venda::get_data()
{
    return data;
}

void Venda::add_intem(Produto novo)
{

}

void Venda::remover_item(Produto item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item.get_nome()){
            itens.erase(begin()+i);
        }
    }
}

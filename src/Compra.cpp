#include "Compra.h"
#include "Produto.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

Compra::Compra(){}

Compra::~Compra(){}

float Compra::get_valor()
{
    float soma = 0.0;
    for(int i = 0; i < itens.size(); i++){
        soma += itens[i]->get_preco();
    }
    return soma;
}

string Compra::get_data()
{
    return data;
}

void Compra::add_intem(Produto novo)
{

}

void Compra::remover_item(Produto item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item.get_nome()){
            itens.erase(begin()+i);
        }
    }
}

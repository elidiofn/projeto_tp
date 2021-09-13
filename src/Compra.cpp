#include "Compra.h"
#include "Produto.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

Compra::Compra()
{
    valor_prazo = 0;
    valor_avista = 0;
}

Compra::Compra(string data, Gerente ge)
{
    this->data = data;
    comprador = ge;
    valor_prazo = 0;
    valor_avista = 0;
}

Compra::~Compra(){}

float Compra::get_valor()
{
  return valor_prazo;
}

float Compra::get_valor_avista()
{
  return valor_avista;
}

void Compra::set_comprador(Gerente ge)
{
    comprador = ge;
}

Gerente Compra::get_comprador()
{
    return comprador;
}

string Compra::get_data()
{
    return data;
}

void Compra::add_intem(Produto* novo)
{
    itens.push_back(novo->to_string());
    valor_prazo += novo->get_preco();
    valor_avista += novo->get_preco_avista();
}

void Compra::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i] == item->to_string()){
            itens.erase(itens.begin()+i);
            valor_prazo -= item->get_preco();
            valor_avista -= item->get_preco_avista();
        }
    }
}

 string Compra::to_string()
 {
    string compra = "\n========================\nGerente: "+ comprador.get_nome() + "\nData: " + this->data + "\nItens:\n";
    for(int i=0;i<itens.size();i++){
        compra += itens[i] + "\n";
   }
   compra += "Valor Total a Prazo: " + std::to_string(valor_prazo);
   compra += "\nValor Total com Desconto de à Vista: " + std::to_string(valor_avista) + "\n========================\n";
   return compra;
 }

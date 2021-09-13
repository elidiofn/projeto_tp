#include "Venda.h"
#include "Produto.h"
#include "Funcionario.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

Venda::Venda()
{
    valor_prazo = 0;
    valor_avista = 0;
}

Venda::Venda(string data)
{
    this->data = data;
    valor_prazo = 0;
    valor_avista = 0;
}
Venda::~Venda(){}

float Venda::get_valor()
{
  return this->valor_prazo;
}

float Venda::get_valor_avista()
{
  return this->valor_avista;
}

Vendedor Venda::get_vendedor()
{
    return vendedor;
}

void Venda::set_vendedor(Vendedor vendedor)
{
    this->vendedor = vendedor;
}

string Venda::get_data()
{
    return data;
}

void Venda::add_intem(Produto* novo)
{
    itens.push_back(novo->to_string());
    valor_prazo += novo->get_preco();
    valor_avista += novo->get_preco_avista();
}

void Venda::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i] == item->to_string()){
            itens.erase(itens.begin()+i);
            valor_prazo -= item->get_preco();
            valor_avista -= item->get_preco_avista();
        }
    }
}

 string Venda::to_string()
 {
    string venda = "\n========================\nVendedor: "+ vendedor.get_nome() + "\nData: " + this->data + "\nItens:\n";
    for(int i=0;i<itens.size();i++){
        venda += itens[i] + "\n";
   }
   venda += "Valor Total a Prazo: " + std::to_string(valor_prazo);
   venda += "\nValor Total com Desconto de à Vista: " + std::to_string(valor_avista) + "\n========================\n";
   return venda;
 }

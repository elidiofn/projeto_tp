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

Compra::~Compra()
{
}

float Compra::get_valor()
{
    return valor_prazo;
}

float Compra::get_valor_avista()
{
    valor_avista = valor_prazo - (valor_prazo*0.1);
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
    string nome = novo->get_nome();
    float preco_compra = novo->get_preco_compra();
    float preco_venda = novo->get_preco();

    if(novo->get_tipo() == "Material Construção")
    {
       itens.push_back(new MaterialConstrucao(nome,preco_compra, preco_venda));
    }
    else if(novo->get_tipo() == "Material Elétrico")
    {
       itens.push_back(new MaterialEletrico(nome,preco_compra, preco_venda));
    }
    else if(novo->get_tipo() == "Material Hidráulico")
    {
        itens.push_back(new MaterialHidraulico(nome,preco_compra, preco_venda));
    }
    else if(novo->get_tipo() == "Ferramenta")
    {
        itens.push_back(new Ferramenta(nome,preco_compra, preco_venda));
    }
    valor_prazo += novo->get_preco_compra();
}

void Compra::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item->get_nome()){
            itens.erase(itens.begin()+i);
            valor_prazo -= item->get_preco();
            valor_avista -= item->get_preco_avista();
        }
    }
}

vector<Produto*> Compra::get_produtos()
{
    return itens;
}

string Compra::to_string()
 {
    string compra = "\n========================\nGerente: "+ comprador.get_nome() + "\nData: " + this->data + "\nItens:\n";
    for(int i=0;i<itens.size();i++){
        compra += itens[i]->to_string() + "\n";
   }
   compra += "Valor Total a Prazo: " + std::to_string(valor_prazo);
   compra += "\nValor Total com Desconto de à Vista: " + std::to_string(get_valor_avista()) + "\n========================\n";
   return compra;
 }

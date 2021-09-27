#include "Compra.h"

Compra::Compra()
{
    valor_total = 0;
}

Compra::Compra(string data, Gerente ge)
{
    this->data = data;
    comprador = ge;
    valor_total = 0;
}

Compra::~Compra()
{
}

float Compra::get_valor(string forma_pagamento)
{
    if(forma_pagamento == "av")
    {
        valor_total = valor_total - (valor_total * 0.10); // desconto de compra a vista
    }
    return valor_total;
}

float Compra::get_total()
{
    return valor_total;
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
    valor_total += novo->get_preco_compra();
}

void Compra::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item->get_nome()){
            itens.erase(itens.begin()+i);
            valor_total -= item->get_preco_compra();
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
   compra += "Valor Total: " + std::to_string(valor_total);
   compra += "\n========================\n";
   return compra;
 }

 string Compra::get_compra()
 {
    string compra = "";
    compra += "{";
    compra += "(" + get_data() + ")";
    compra += comprador.to_string();
    for(int i = 0; i < itens.size(); i++)
    {
        compra += "[" + itens[i]->to_string() + "]";
    }
    compra += "}";
    return compra;
 }

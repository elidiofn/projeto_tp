#include "Venda.h"

Venda::Venda()
{
    valor_total = 0;
    comissao_vendedor = 0;
    vendedor = new Vendedor("", "00/00/00", "0000", 0.0, "", 0.0);
}

Venda::Venda(string data, Funcionario* vendedor)
{
    string nome = vendedor->get_nome();
    string data_nasc = vendedor->get_data_nascimento();
    string rg = vendedor->get_cpf();
    string senha = vendedor->get_senha();
    float sal = vendedor->get_salario();
    if(vendedor->get_tipo() == "Vendedor")
    {
        this->vendedor = new Vendedor(nome, data_nasc, rg, sal, senha);
    }else if(vendedor->get_tipo() == "Gerente")
    {
        this->vendedor = new Gerente(nome, data_nasc, rg, sal, senha);
    }
    this->data = data;
    valor_total = 0;
    comissao_vendedor = 0;
}

Venda::~Venda()
{
}

float Venda::get_valor(string forma_pagamento)
{
    float va = 0;
    if(forma_pagamento == "av")
    {
        for(int i =0; i < itens.size(); i++)
        {
            va += itens[i]->get_preco_avista();
        }
        comissao_vendedor = va * 0.03;//comissão ao vendedor
        valor_total = va;
    }
    else
    {
        comissao_vendedor = valor_total * 0.03;//comissão ao vendedor
    }
    return valor_total;
}

float Venda::get_total()
{
    return valor_total;
}

Funcionario* Venda::get_vendedor()
{
    return vendedor;
}

void Venda::set_vendedor(Funcionario* vendedor)
{
    string nome = vendedor->get_nome();
    string data_nasc = vendedor->get_data_nascimento();
    string rg = vendedor->get_cpf();
    string senha = vendedor->get_senha();
    float sal = vendedor->get_salario();
    if(vendedor->get_tipo() == "Vendedor")
    {
        this->vendedor = new Vendedor(nome, data_nasc, rg, sal, senha);
    }else if(vendedor->get_tipo() == "Gerente")
    {
        this->vendedor = new Gerente(nome, data_nasc, rg, sal, senha);
    }
}

string Venda::get_data()
{
    return data;
}

float Venda::get_comissao()
{
    return comissao_vendedor;
}

void Venda::add_intem(Produto* novo)
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
    valor_total += novo->get_preco();

}

void Venda::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item->get_nome()){
            itens.erase(itens.begin()+i);
            valor_total -= item->get_preco();
        }
    }
}

vector<Produto*> Venda::get_produtos()
{
    return itens;
}

string Venda::to_string()
 {
    string venda = "\n========================\nVendedor: "+ vendedor->get_nome() + "\nData: " + this->data + "\nItens:\n";
    for(int i=0;i<itens.size();i++){
        venda += itens[i]->to_string() + "\n";
   }
   venda += "Valor Total: " + std::to_string(valor_total);
   venda += "\n========================\n";
   return venda;
 }

 string Venda::get_venda()
 {
    string venda = "";
    venda += "{";
    venda += "(" + get_data() + ")";
    venda += vendedor->to_string();
    for(int i = 0; i < itens.size(); i++)
    {
        venda += "[" + itens[i]->to_string() + "]";
    }
    venda += "}";
    return venda;
 }

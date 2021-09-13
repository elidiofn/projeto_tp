#include "Caixa.h"

Caixa::Caixa()
{
    saldo = 0;
}

Caixa::Caixa(float valor)
{
    saldo = valor;
}

Caixa::~Caixa(){}

float Caixa::get_saldo()
{
    return saldo;
}

void Caixa::entrada(Venda venda)
{
    saldo += venda.get_valor();
    vendas.push_back(venda);
}

void Caixa::saida(Compra compra)
{
    saldo -= compra.get_valor();
    compras.push_back(compra);
}

string Caixa::get_vendas()
{
    string vendas = "\n==================================\n";
    for(int i=0; i<this->vendas.size(); i++){
        vendas += this->vendas[i].to_string()+ "\n";
    }
    vendas += "\n==================================\n";
   return vendas;
}

string Caixa::get_compras()
{
    string compras = "\n==================================\n";
    for(int i=0; i<this->compras.size(); i++){
        compras += this->compras[i].to_string() + "\n";
    }
    compras += "\n==================================\n";
    return compras;
}

string Caixa::get_vendas_por_vendedor(string nome_vendedor)
{
    vector<Venda> vend;
    for(int i = 0; i < compras.size(); i++){
        if(vendas[i].get_vendedor().get_nome() == nome_vendedor){
            vend.push_back(vendas[i]);
        }
    }
    string vendas = "\n==================================\n";
    for(int i=0; i<vend.size(); i++){
        vendas += vend[i].to_string() + "\n";
    }
    vendas += "\n==================================\n";
   return vendas;
}

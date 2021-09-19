#include "Caixa.h"
#include "Estoque.h"

extern Estoque estoque;

Caixa::Caixa()
{
    saldo = 0;
}

Caixa::Caixa(float valor)
{
    saldo = valor;
}

Caixa::~Caixa()
{

}

float Caixa::get_saldo()
{
    return saldo;
}

void Caixa::entrada(Venda venda, string pagamento)
{
    vector<Produto*> itens = venda.get_produtos();
    vendas.push_back(venda);
    for(int i = 0; i<itens.size();i++)
    {
        estoque.saida(itens[i], 1);
    }
    if(pagamento == "avista"){
        saldo += venda.get_valor_avista();
    }
    else
    {
        saldo += venda.get_valor();
    }
}

void Caixa::saida(Compra compra, string pagamento)
{
    vector<Produto*> itens = compra.get_produtos();
    for(int i = 0; i<itens.size();i++)
    {
        estoque.entrada(itens[i], 1);
    }
    if(pagamento == "avista")
    {
        saldo -= compra.get_valor_avista();
    }
    else
    {
        saldo -= compra.get_valor();
    }
    compras.push_back(compra);
}

string Caixa::get_vendas()
{
    string vendas = "\n=================================VENDAS CAIXA=================================\n";
    for(int i=0; i<this->vendas.size(); i++){
        vendas += this->vendas[i].to_string()+ "\n";
    }
    vendas += "\n==============================================================================\n";
   return vendas;
}

string Caixa::get_compras()
{
    string compras = "\n=================================COMPRAS CAIXA================================\n";
    for(int i=0; i<this->compras.size(); i++){
        compras += this->compras[i].to_string() + "\n";
    }
    compras += "\n==============================================================================\n";
    return compras;
}

string Caixa::get_vendas_por_vendedor(string nome_vendedor)
{
    vector<Venda> vend;
    for(int i = 0; i < vendas.size(); i++){
        if(vendas[i].get_vendedor()->get_nome() == nome_vendedor){
            vend.push_back(vendas[i]);
        }
    }
    string vendas = "\n==============VENDAS====================\n";
    for(int i=0; i<vend.size(); i++){
        vendas += vend[i].to_string() + "\n";
    }
    vendas += "\n========================================\n";
   return vendas;
}
string Caixa::to_string()
{
    string rel_caixa = "\n===============================\n";
    rel_caixa += "SALDO: " + std::to_string(saldo);
    rel_caixa += get_compras();
    rel_caixa += get_vendas();
    rel_caixa += "\n===============================\n";
    return rel_caixa;
}

#include "Venda.h"

Venda::Venda()
{
    valor_avista = 0;
    valor_prazo = 0;
    vendedor = new Vendedor("", "00/00/00", "0000", 0.0, "");
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
    valor_prazo = 0;
    valor_avista = 0;

}
Venda::~Venda()
{
}

float Venda::get_valor()
{
  return this->valor_prazo;
}

float Venda::get_valor_avista()
{
  return this->valor_avista;
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
    valor_prazo += novo->get_preco();
    valor_avista += novo->get_preco_avista();
}

void Venda::remover_item(Produto* item)
{
    for(int i = 0; i < itens.size(); i++){
        if(itens[i]->get_nome() == item->get_nome()){
            itens.erase(itens.begin()+i);
            valor_prazo -= item->get_preco();
            valor_avista -= item->get_preco_avista();
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
   venda += "Valor Total a Prazo: " + std::to_string(valor_prazo);
   venda += "\nValor Total com Desconto de à Vista: " + std::to_string(valor_avista) + "\n========================\n";
   return venda;
 }

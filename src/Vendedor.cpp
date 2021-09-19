#include "Vendedor.h"

Vendedor::Vendedor()
{
    comissao = 0;
}

Vendedor::Vendedor(string nome, string data_nascimento, string rg, float salario_base, string senha): Funcionario(nome, data_nascimento, rg, salario_base, senha)
{
    comissao = 0;
}

Vendedor::~Vendedor(){}

void Vendedor::set_comissao(float comissao)
{
    this->comissao = comissao;
}

float Vendedor::get_salario()
{
    return salario_base + comissao;
}

string Vendedor::get_tipo()
{
    return "Vendedor";
}

string Vendedor::to_string()
{
    string ob = "";
    ob += get_tipo() + ", " + get_nome() + ", ";
    ob += get_data_nascimento() + ", " ;
    ob += get_rg() + ", ";
    ob += std::to_string(get_salario()) + ", ";
    ob += get_senha();
    return ob;
}

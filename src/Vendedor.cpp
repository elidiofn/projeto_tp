#include "Vendedor.h"

Vendedor::Vendedor()
{
    comissao = 0;
}

Vendedor::Vendedor(string nome, string data_nascimento, string cpf, float salario_base, string senha, float comissao): Funcionario(nome, data_nascimento, cpf, salario_base, senha)
{
    this->comissao = comissao;
}

Vendedor::~Vendedor(){}

float Vendedor::get_comissao()
{
    return comissao;
}

void Vendedor::set_comissao(float comissao)
{
    this->comissao += comissao;
}

float Vendedor::get_salario()
{
    return salario_base;
}

string Vendedor::get_salario_detalhes()
{
    string sal= "";
    sal += "Sal?rio Base: ";
    sal += std::to_string(salario_base);
    sal += "\n";
    sal += "Comiss?o por Vendas: ";
    sal += std::to_string(comissao);
    return sal;

}

string Vendedor::get_tipo()
{
    return "Vendedor";
}

string Vendedor::to_string()
{
    string ob = "";
    ob += get_tipo() + ";" + get_nome() + ";";
    ob += get_data_nascimento() + ";" ;
    ob += get_cpf() + ";";
    ob += std::to_string(get_salario()) + ";";
    ob += get_senha();
    return ob;
}

string Vendedor::get_funcionario()
{
    string ob = "";
    ob += get_tipo() + ";" + get_nome() + ";";
    ob += get_data_nascimento() + ";" ;
    ob += get_cpf() + ";";
    ob += std::to_string(get_salario()) + ";";
    ob += get_senha()+ ";";
    ob += std::to_string(comissao);
    return ob;
}

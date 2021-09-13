#include "Funcionario.h"

Funcionario::Funcionario(){}

Funcionario::Funcionario(string nome, string data_nascimento, string rg, float salario_base)
{
    this->nome = nome;
    this->data_nascimento = data_nascimento;
    this->rg = rg;
    this->salario_base = salario_base;
}

Funcionario::~Funcionario(){}

string Funcionario::get_nome()
{
    return nome;
}

void Funcionario::set_nome(string nome)
{
    this->nome = nome;
}

string Funcionario::get_data_nascimento()
{
    return data_nascimento;
}

void Funcionario::set_data_nascimento(string data)
{
    data_nascimento = data;
}

string Funcionario::get_rg()
{
    return rg;
}

void Funcionario::set_rg(string rg)
{
    this->rg = rg;
}

float Funcionario::get_salario()
{
    return salario_base;
}

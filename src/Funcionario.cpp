#include "Funcionario.h"

Funcionario::Funcionario(){}

Funcionario::Funcionario(string nome, string data_nascimento, string cpf, float salario_base, string senha)
{
    this->nome = nome;
    this->data_nascimento = data_nascimento;
    this->cpf = cpf;
    this->salario_base = salario_base;
    this->senha = senha;
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

string Funcionario::get_cpf()
{
    return cpf;
}

bool Funcionario::verificar_senha(string senha)
{
    if(this->senha == senha)
    {
        return true;
    }
    return false;
}

void Funcionario::set_cpf(string cpf)
{
    this->cpf = cpf;
}

float Funcionario::get_salario()
{
    return salario_base;
}

string Funcionario::get_senha()
{
    return senha;
}

string Funcionario::get_salario_detalhes()
{

}

void Funcionario::set_comissao(float comissao)
{

}

string Funcionario::get_tipo()
{

}

string Funcionario::to_string()
{

}

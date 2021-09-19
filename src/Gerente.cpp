#include "Gerente.h"

Gerente::Gerente()
{
    comissao = 0;
}

Gerente::Gerente(string nome, string data_nascimento, string rg, float salario_base, string senha): Funcionario(nome, data_nascimento, rg, salario_base, senha)
{
    comissao = 0;
}

Gerente::~Gerente()
{

}

void Gerente::set_comissao(float comissao)
{
    this->comissao = comissao;
}

float Gerente::get_salario()
{
    return Funcionario::get_salario() + comissao;
}

string Gerente::get_tipo()
{
    return "Gerente";
}

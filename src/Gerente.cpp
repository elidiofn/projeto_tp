#include "Gerente.h"

Gerente::Gerente(string nome, string data_nascimento, string rg, float salario_base): Funcionario(nome, data_nascimento, rg, salario_base){}

Gerente::~Gerente(){}

float Gerente::get_salario()
{
    return Funcionario::get_salario() + comissao;
}

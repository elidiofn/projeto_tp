#include "Vendedor.h"

Vendedor::Vendedor(){}

Vendedor::Vendedor(string nome, string data_nascimento, string rg, float salario_base): Funcionario(nome, data_nascimento, rg, salario_base)
{
    comissao = 0;
}

Vendedor::~Vendedor(){}

float Vendedor::get_salario()
{
    return salario_base + comissao;
}

#include "Vendedor.h"

Vedendor::Vendedor(string nome, string data_nascimento, string rg, float salario_base): Funcionario(nome, data_nascimento, rg, salario_base){}

Vedendor::~Vendedor(){}

float Vendedor::get_salario()
{
    return Funcionario.get_salario() + comissao;
}

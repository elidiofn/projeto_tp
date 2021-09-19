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

string Gerente::to_string()
{
    string ob = "";
    ob += get_tipo() + ", " + get_nome() + ", ";
    ob += get_data_nascimento() + ", " ;
    ob += get_rg() + ", ";
    ob += std::to_string(get_salario()) + ", ";
    ob += get_senha();
    return ob;
}

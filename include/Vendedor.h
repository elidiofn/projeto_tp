#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Funcionario.h"


class Vendedor : public Funcionario
{
    public:
        Vendedor();
        Vendedor(string nome, string data_nascimento, string cpf, float salario, string senha);
        ~Vendedor();
        void set_comissao(float comissao);
        float get_salario();
        string get_salario_detalhes();
        string get_tipo();
        string to_string();

    private:
        float comissao;
};

#endif // VENDEDOR_H

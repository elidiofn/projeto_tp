#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"


class Gerente : public Funcionario
{
    public:
        Gerente();
        Gerente(string nome, string data_nascimento, string cpf, float salario, string senha);
        ~Gerente();
        void set_comissao(float comissao);
        float get_salario();
        string get_salario_detalhes();
        string get_tipo();
        string to_string();

    private:
        float comissao;
};

#endif // GERENTE_H

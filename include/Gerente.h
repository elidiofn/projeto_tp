#ifndef GERENTE_H
#define GERENTE_H

#include <Funcionario.h>


class Gerente : public Funcionario
{
    public:
        Gerente();
        Gerente(string, string, string, float, string);
        ~Gerente();
        void set_comissao(float);
        float get_salario();
        string get_tipo();
        string to_string();

    private:
        float comissao;
};

#endif // GERENTE_H

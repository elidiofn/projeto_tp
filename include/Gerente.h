#ifndef GERENTE_H
#define GERENTE_H

#include <Funcionario.h>


class Gerente : public Funcionario
{
    public:
        Gerente(string, string, string, float);
        ~Gerente();
        float get_salario();

    private:
        float comissao;
};

#endif // GERENTE_H

#ifndef GERENTE_H
#define GERENTE_H

#include <Funcionario.h>


class Gerente : public Funcionario
{
    public:
        Gerente();
        virtual ~Gerente();

        float get_salario();
        void set_salario(float);
        float get_comissao();
        void set_comissao(float);

    private:
        float salario;
        float comissao;
};

#endif // GERENTE_H

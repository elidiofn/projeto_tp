#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <Funcionario.h>


class Vendedor : public Funcionario
{
    public:
        Vendedor();
        virtual ~Vendedor();

        float get_salario();
        void set_salario(float);
        float get_comissao();

    private:
        float salario;
        float comissao;
};

#endif // VENDEDOR_H

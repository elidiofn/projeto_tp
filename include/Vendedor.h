#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <Funcionario.h>


class Vendedor : public Funcionario
{
    public:
        Vendedor();
        Vendedor(string, string, string, float);
        ~Vendedor();
        float get_salario();

    private:
        float comissao;
};

#endif // VENDEDOR_H

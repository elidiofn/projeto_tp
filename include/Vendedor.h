#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <Funcionario.h>


class Vendedor : public Funcionario
{
    public:
        Vendedor();
        Vendedor(string, string, string, float, string);
        ~Vendedor();
        void set_comissao(float);
        float get_salario();
        string get_tipo();

    private:
        float comissao;
};

#endif // VENDEDOR_H

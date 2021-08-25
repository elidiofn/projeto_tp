#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include "Produto.h"


class Ferramenta : Produto
{
    public:
        Ferramenta();
        virtual ~Ferramenta();

        float get_preco();
        void set_preco(float);

    private:
        float preco;
        static final float desconto;
};

#endif // FERRAMENTA_H

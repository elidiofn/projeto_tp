#ifndef MATERIALELETRICO_H
#define MATERIALELETRICO_H
#include "Produto.h"

class MaterialEletrico : public Produto
{
    public:
        MaterialEletrico();
        virtual ~MaterialEletrico();

        float get_preco();
        void set_preco(float);

    private:
        float preco;
        static final float desconto;
};

#endif // MATERIALELETRICO_H

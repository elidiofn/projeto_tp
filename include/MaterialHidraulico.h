#ifndef MATERIALHIDRAULICO_H
#define MATERIALHIDRAULICO_H
#include "Produto.h"

class MaterialHidraulico : public Produto
{
    public:
        MaterialHidraulico();
        virtual ~MaterialHidraulico();

        float get_preco();
        void set_preco(float);

    private:
        float preco;
        static final float desconto;

};

#endif // MATERIALHIDRAULICO_H

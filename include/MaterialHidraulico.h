#ifndef MATERIALHIDRAULICO_H
#define MATERIALHIDRAULICO_H

#include "Produto.h"

class MaterialHidraulico : public Produto
{
    public:
        MaterialHidraulico(string nome, float preco_compra, float preco_venda);
        ~MaterialHidraulico();
        float get_preco_avista();
        string to_string();
        string get_tipo();

    private:
        static int DESCONTO;
};

#endif // MATERIALHIDRAULICO_H

#ifndef MATERIALELETRICO_H
#define MATERIALELETRICO_H

#include "Produto.h"

class MaterialEletrico : public Produto
{
    public:
        MaterialEletrico(string nome, float preco_compra, float preco_venda);
        ~MaterialEletrico();
        float get_preco_avista();
        string to_string();
        string get_tipo();
    private:
        static int DESCONTO;
};

#endif // MATERIALELETRICO_H

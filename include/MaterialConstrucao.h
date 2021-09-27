#ifndef MATERIALCONSTRUCAO_H
#define MATERIALCONSTRUCAO_H

#include "Produto.h"

class MaterialConstrucao : public Produto
{
    public:
        MaterialConstrucao(string nome, float preco_compra, float preco_venda);
        ~MaterialConstrucao();
        float get_preco_avista();
        string to_string();
        string get_tipo();

    private:
        static int DESCONTO;
};

#endif // MATERIALCONSTRUCAO_H

#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include "Produto.h"

class Ferramenta : public Produto
{
    public:
        Ferramenta(string nome, float preco_compra, float preco_venda);
        ~Ferramenta();
        float get_preco_avista();
        string to_string();
        string get_tipo();

    private:
        static int DESCONTO;
};

#endif // FERRAMENTA_H

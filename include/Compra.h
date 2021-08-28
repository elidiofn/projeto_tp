#ifndef COMPRA_H
#define COMPRA_H

#include "Produto.h"
#include "Gerente.h"

#include <string>
#include <vector>
using std::string;
using std::vector;


class Compra
{
    public:
        Compra();
        ~Compra();
        float get_valor();
        string get_data();
        void add_intem(Produto);
        void remover_item(Produto);
    private:
        vector<Produto*> itens;
        string data;
        Gerente comprador;
};

#endif // COMPRA_H

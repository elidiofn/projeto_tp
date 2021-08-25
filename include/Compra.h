#ifndef COMPRA_H
#define COMPRA_H
#include <string>
#include <vector>
#include "Produto.h"
#include "Gerente.h"
using std::string;
using std::vector;


class Compra
{
    public:
        Compra();
        virtual ~Compra();

        float get_valor();
        string get_data();
        void add_intem(Produto);
        void remover_item(Produto);
    private:
        vector<Produto> itens;
        string data;
        Gerente comprador;
};

#endif // COMPRA_H

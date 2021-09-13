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
        Compra(string, Gerente);
        ~Compra();
        float get_valor();
        float get_valor_avista();
        string get_data();
        void set_comprador(Gerente);
        Gerente get_comprador();
        void add_intem(Produto*);
        void remover_item(Produto*);
        string to_string();
    private:
        vector<string> itens;
        string data;
        Gerente comprador;
        float valor_prazo;
        float valor_avista;
};

#endif // COMPRA_H

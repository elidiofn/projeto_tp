#ifndef VENDA_H
#define VENDA_H

#include "Produto.h"
#include "Vendedor.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

class Venda
{
    public:
        Venda();
        Venda(string);
        ~Venda();
        float get_valor();
        float get_valor_avista();
        Vendedor get_vendedor();
        void set_vendedor(Vendedor);
        string get_data();
        void add_intem(Produto*);
        void remover_item(Produto*);
        string to_string();
    private:
        vector<string> itens;
        string data;
        Vendedor vendedor;
        float valor_prazo;
        float valor_avista;
};
#endif // VENDA_H

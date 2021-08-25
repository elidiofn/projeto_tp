#ifndef VENDA_H
#define VENDA_H

#include <vector>
#include <string>
#include "Produto.h"
#include "Funcionario.h"

using std::vector;
using std::string;

class Venda
{
    public:
        Venda();
        virtual ~Venda();

        float get_valor();
        Funcionario get_vendendor();
        string get_data();
        void add_intem(Produto);
        void remover_item(Produto);
    private:
        vector<Produto> itens;
        string data;
        Funcionario vendedor;
};

#endif // VENDA_H

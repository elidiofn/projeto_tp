#ifndef VENDA_H
#define VENDA_H

#include "Produto.h"
#include "Funcionario.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

class Venda
{
    public:
        Venda();
        ~Venda();
        float get_valor();
        Funcionario get_vendendor();
        void set_vendedor(Funcionario);
        string get_data();
        void add_intem(Produto);
        void remover_item(Produto);
    private:
        vector<Produto*> itens;
        string data;
        Funcionario vendedor;
};

#endif // VENDA_H

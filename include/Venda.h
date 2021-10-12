#ifndef VENDA_H
#define VENDA_H

#include "Funcionario.h"
#include "Gerente.h"
#include "Vendedor.h"
#include "Produto.h"
#include "MaterialConstrucao.h"
#include "MaterialEletrico.h"
#include "MaterialHidraulico.h"
#include "Ferramenta.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

class Venda
{
    public:
        Venda();
        Venda(string data, Funcionario* vendedor);
        ~Venda();
        float get_valor(string forma_pagamento);
        float get_total();
        Funcionario* get_vendedor();
        void set_vendedor(Funcionario* vendedor);
        string get_data();
        float get_comissao();
        void add_intem(Produto* produto);
        void remover_item(Produto* produto);
        vector<Produto*> get_produtos();
        string to_string();
        string get_venda();
    private:
        vector<Produto*> itens;
        string data;
        float comissao_vendedor;
        Funcionario* vendedor;
        float valor_total;
};
#endif // VENDA_H

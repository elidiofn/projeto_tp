#ifndef CAIXA_H
#define CAIXA_H

#include "Venda.h"
#include "Compra.h"
#include<vector>
#include<string>
using std::vector;
using std::string;

class Caixa
{
    public:
        Caixa();
        Caixa(float);
        ~Caixa();
        float get_saldo();
        void entrada(Venda);
        void saida(Compra);
        string get_vendas();
        string get_compras();
        string get_vendas_por_vendedor(string);
    private:
        float saldo;
        vector<Venda> vendas;
        vector<Compra> compras;
};

#endif // CAIXA_H

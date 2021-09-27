#ifndef CAIXA_H
#define CAIXA_H

#include "Venda.h"
#include "Compra.h"
#include "Estoque.h"
#include "Produto.h"
#include "MaterialConstrucao.h"
#include "MaterialEletrico.h"
#include "MaterialHidraulico.h"
#include "Ferramenta.h"
#include "Funcionario.h"
#include "Gerente.h"
#include "Vendedor.h"

#include <vector>
#include <string>
#include <fstream>
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::getline;

class Caixa
{
    public:
        Caixa();
        Caixa(float);
        ~Caixa();
        float get_saldo();
        void entrada(Venda, string);
        void saida(Compra, string);
        string get_vendas();
        string get_compras();
        string get_vendas_por_vendedor(string);
        string to_string();
    private:
        float saldo;
        vector<Venda> vendas;
        vector<Compra> compras;

        void salva_caixa(string);
        void ler_caixa();
        void cria_caixa(string);
        string situacao_caixa();
};

#endif // CAIXA_H

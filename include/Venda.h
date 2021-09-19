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
        Venda(string, Funcionario*);
        ~Venda();
        float get_valor();
        float get_valor_avista();
        Funcionario* get_vendedor();
        void set_vendedor(Funcionario*);
        string get_data();
        void add_intem(Produto*);
        void remover_item(Produto*);
        vector<Produto*> get_produtos();
        string to_string();
    private:
        vector<Produto*> itens;
        string data;
        Funcionario* vendedor;
        float valor_prazo;
        float valor_avista;
};
#endif // VENDA_H

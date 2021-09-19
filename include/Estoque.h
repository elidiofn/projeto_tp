#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "Produto.h"
#include "MaterialConstrucao.h"
#include "MaterialEletrico.h"
#include "MaterialHidraulico.h"
#include "Ferramenta.h"
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::to_string;

class Estoque
{
    public:
        Estoque();
        ~Estoque();
        void salvar_estoque();
        pair<Produto*, int> busca_produto(string);
        void entrada(Produto*, int);
        void saida(Produto*, int);
        string impr_estoque();

    private:
        vector<pair<Produto*, int>> produtos;
        void carregar_estoque();
        int busca_indice_produto(string);
};

#endif // ESTOQUE_H

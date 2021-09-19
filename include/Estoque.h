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
#include <fstream>
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::to_string;
using std::ofstream;
using std::ifstream;
using std::getline;

class Estoque
{
    public:
        Estoque();
        ~Estoque();
        void salvar_estoque(string);
        pair<Produto*, int> busca_produto(string);
        void entrada(Produto*, int);
        void saida(Produto*, int);
        string impr_estoque();

    private:
        vector<pair<Produto*, int>> produtos;
        void ler_estoque();
        int busca_indice_produto(string);
        void carregar_estoque(vector<string>);
};

#endif // ESTOQUE_H

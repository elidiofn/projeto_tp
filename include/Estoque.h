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
using std::ofstream;
using std::ifstream;
using std::getline;

class Estoque
{
    public:
        Estoque();
        ~Estoque();
        void salvar_estoque(string entrada);
        pair<Produto*, int> busca_produto(string nome_produto);
        void entrada(Produto* produto, int quantidade);
        void saida(Produto* produto, int quantidade);
        string impr_estoque();

    private:
        vector<pair<Produto*, int>> produtos;

        void ler_estoque();
        int busca_indice_produto(string nome_produto);
        void cria_produto(string produto, int quantidade);
        int insere_ordenado(string nome_produto);
};

#endif // ESTOQUE_H

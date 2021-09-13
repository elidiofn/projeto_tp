#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "MaterialConstrucao.h"
#include "MaterialEletrico.h"
#include "MaterialHidraulico.h"
#include "Ferramenta.h"
#include <string>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::pair;

class Estoque
{
    public:
        Estoque();
        ~Estoque();
        void salvar_estoque();
        int busca_produto(string);
        void entrada(string, int);
        void saida(string, int);
        string impr_estoque();

    private:
        vector<pair<MaterialConstrucao, int>> est_material_construcao;
        vector<pair<MaterialEletrico, int>> est_material_eletrico;
        vector<pair<MaterialHidraulico, int>> est_material_hidraulico;
        vector<pair<Ferramenta, int>> est_ferramenta;
        void carregar_estoque();
        string busca_produto_est(string);
};

#endif // ESTOQUE_H

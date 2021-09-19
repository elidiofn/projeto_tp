#ifndef MATERIALCONSTRUCAO_H
#define MATERIALCONSTRUCAO_H

#include "Produto.h"
#include <string>
using std::string;

class MaterialConstrucao : public Produto
{
    public:
        MaterialConstrucao(string, float, float);
        ~MaterialConstrucao();
        float get_preco_avista();
        string to_string();
        string get_tipo();

    private:
        static int DESCONTO;
};

#endif // MATERIALCONSTRUCAO_H

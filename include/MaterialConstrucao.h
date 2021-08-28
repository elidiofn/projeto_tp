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
        float desconto_a_vista();

    private:
        static int DESCONTO;
};

#endif // MATERIALCONSTRUCAO_H

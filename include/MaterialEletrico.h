#ifndef MATERIALELETRICO_H
#define MATERIALELETRICO_H

#include "Produto.h"
#include <string>
using std::string;

class MaterialEletrico : public Produto
{
    public:
        MaterialEletrico(string, float, float);
        ~MaterialEletrico();
        float get_preco_avista();
        string to_string();
        string get_tipo();
    private:
        static int DESCONTO;
};

#endif // MATERIALELETRICO_H

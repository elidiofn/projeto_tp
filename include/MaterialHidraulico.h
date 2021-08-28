#ifndef MATERIALHIDRAULICO_H
#define MATERIALHIDRAULICO_H

#include "Produto.h"
#include <string>
using std::string;

class MaterialHidraulico : public Produto
{
    public:
        MaterialHidraulico(string, float, float);
        ~MaterialHidraulico();
        float desconto_a_vista();

    private:
        static int DESCONTO;
};

#endif // MATERIALHIDRAULICO_H

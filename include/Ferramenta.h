#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include "Produto.h"
#include <string>
using std::string;

class Ferramenta : Produto
{
    public:
        Ferramenta(string, float, float);
        ~Ferramenta();
        float desconto_a_vista();

    private:
        static int DESCONTO;
};

#endif // FERRAMENTA_H

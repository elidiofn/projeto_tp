#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include "Produto.h"
#include <string>
using std::string;

class Ferramenta : public Produto
{
    public:
        Ferramenta(string, float, float);
        ~Ferramenta();
        float get_preco_avista();
        string to_string();
        string get_tipo();

    private:
        static int DESCONTO;
};

#endif // FERRAMENTA_H

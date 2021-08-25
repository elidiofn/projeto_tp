#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
using std::string;

class Produto
{
    public:
        Produto();
        virtual ~Produto();

        string get_nome();
        void set_nome(String val);
        float get_preco_compra();

    private:
        String nome;
        float preco_compra;
};

#endif // PRODUTO_H

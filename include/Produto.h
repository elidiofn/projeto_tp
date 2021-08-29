#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using std::string;

class Produto
{
    public:
        Produto(string, float, float);
        virtual ~Produto();
        string get_nome();
        void set_nome(string);
        float get_preco_compra();
        float get_preco();
        void set_preco(float);
        virtual float desconto_a_vista() = 0;//metodo puramente virtual, ou seja, as classes derivadas serao obriagadas a implemetar o metodo.

    protected:
        float preco_venda;
    private:
        string nome;
        float preco_compra;
};

#endif // PRODUTO_H

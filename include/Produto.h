#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using std::string;

class Produto
{
    public:
        Produto(string nome, float preco_compra, float preco_venda);
        virtual ~Produto();
        string get_nome();
        void set_nome(string nome);
        float get_preco_compra();
        float get_preco();
        void set_preco(float preco);
        virtual float get_preco_avista();
        virtual string get_tipo();
        virtual string to_string();//string que representa o objeto.

    protected:
        float preco_venda;
        string nome;
        float preco_compra;
};

#endif // PRODUTO_H

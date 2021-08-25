#ifndef MATERIALCONSTRUCAO_H
#define MATERIALCONSTRUCAO_H


class MaterialConstrucao : public Produto
{
    public:
        MaterialConstrucao();
        virtual ~MaterialConstrucao();

        float get_preco();
        void set_preco(float);

    private:
        float preco;
        static final float desconto;
};

#endif // MATERIALCONSTRUCAO_H

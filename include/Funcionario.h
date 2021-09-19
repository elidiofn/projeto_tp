#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using std::string;

class Funcionario
{
    public:
        Funcionario();
        Funcionario(string, string, string, float, string);
        virtual ~Funcionario();
        string get_nome();
        void set_nome(string);
        string get_data_nascimento();
        void set_data_nascimento(string);
        string get_rg();
        void set_rg(string);
        bool verificar_senha(string);
        string get_senha();
        virtual float get_salario();
        virtual void set_comissao(float);
        virtual string get_tipo();
        virtual string to_string();
    protected:
        float salario_base;
    private:
        string nome;
        string data_nascimento;
        string rg;
        string senha;
};

#endif // FUNCIONARIO_H

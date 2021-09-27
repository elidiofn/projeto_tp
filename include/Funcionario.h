#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using std::string;

class Funcionario
{
    public:
        Funcionario();
        Funcionario(string nome, string data_nascimento, string cpf, float salario, string senha);
        virtual ~Funcionario();
        string get_nome();
        void set_nome(string nome);
        string get_data_nascimento();
        void set_data_nascimento(string data_nascimento);
        string get_cpf();
        void set_cpf(string cpf);
        bool verificar_senha(string senha);
        string get_senha();
        virtual string get_salario_detalhes();
        virtual float get_salario();
        virtual void set_comissao(float comissao);
        virtual string get_tipo();
        virtual string to_string();
    protected:
        float salario_base;
    private:
        string nome;
        string data_nascimento;
        string cpf;
        string senha;
};

#endif // FUNCIONARIO_H

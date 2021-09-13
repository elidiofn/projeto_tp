#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
using std::string;

class Funcionario
{
    public:
        Funcionario();
        Funcionario(string, string, string, float);
        virtual ~Funcionario();
        string get_nome();
        void set_nome(string);
        string get_data_nascimento();
        void set_data_nascimento(string);
        string get_rg();
        void set_rg(string);
        virtual float get_salario();

    protected:
        float salario_base;
    private:
        string nome;
        string data_nascimento;
        string rg;
};

#endif // FUNCIONARIO_H

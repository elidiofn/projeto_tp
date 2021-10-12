/*
>Discentes: Elidio Faustino do Nascimento
            Isa Cristina Gonçalves de Paiva
            Lucas de Sousa Silva
>Matrículas: 120210685
             120110786
             120111779
>Período: 2020.2
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 9: Projeto
*/
#include "Funcionario.h"
#include "Gerente.h"
#include "Vendedor.h"
#include "Caixa.h"
#include "Estoque.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ofstream;
using std::ifstream;

Estoque estoque;
Caixa caixa;
vector<Vendedor> vendedores;
Gerente gerente = Gerente("admin", "00/00/0000", "0000000000", 00.00, "admin");
Funcionario* vendedor_uso;

//prototipos gerente
void cadastrar_vendedor();
void excluir_vendedor();
void exibir_vendedores();
void realizar_compra();
void realizar_venda_gerente();
void relatorio_vendas();
void relatorio_estoque();
void relatorio_caixa();
void menu_gerente();
void consultar_salario_gerente();
bool verifica_cadastro(string);

//prototipos vendendor
void realizar_venda();
void relatorio_minhas_vendas();
void consultar_estoque();
void menu_vendedor();
void consultar_salario();

void login();
void cadastrar_gerente();
string get_funcionarios();
void salva_funcionarios(string);
void ler_funcionarios();
void cria_funcionario(string);

int main()
{
    setlocale(LC_ALL, "portuguese");
    ler_funcionarios();
    login();
    return 0;
}

 void login()
 {
    system("cls");
    cout << "==================================LOGIN=====================================\n";
    string id, pw;
    cout << "Usuário: ";
    getline(cin, id);
    cout << "Senha: ";
    getline(cin, pw);
    cout << "\n============================================================================\n";

    if(id == "admin" && pw == "admin")
    {
        system("cls");
        cadastrar_gerente();
        cin.ignore();
        login();
    }
    else if(gerente.get_cpf() == id && gerente.verificar_senha(pw))
    {
        menu_gerente();
        login();
    }
    for(int i = 0; i < vendedores.size(); i++)
    {
        if(vendedores[i].get_cpf() == id && vendedores[i].verificar_senha(pw))
        {
            string nome = vendedores[i].get_nome();
            string data_nasc = vendedores[i].get_data_nascimento();
            string cpf = vendedores[i].get_cpf();
            string senha = vendedores[i].get_senha();
            float sal = vendedores[i].get_salario();
            float com = vendedores[i].get_comissao();
            Funcionario* f = new Vendedor(nome, data_nasc, cpf, sal, senha, com);
            vendedor_uso = f;
            menu_vendedor();
            delete f;
            login();
        }
    }
    cout << "Usuário ou senha incoreto!!" <<endl;
    system("pause");
    login();
 }

 void cadastrar_gerente()
 {
    string nome, data_nasc, cpf, senha;
    float sal;
    cout << "============================CADASTRAR GERENTE===============================\n";
    cout << "DIGITE O NOME: ";
    getline(cin, nome);
    cout << "DIGITE A DATA DE NASCIMENTO(DD/MM/AAAA): ";
    getline(cin, data_nasc);
    cout << "DIGITE O CPF(SOMENTE NÚMEROS): ";
    getline(cin, cpf);
    cout << "DIGITE A SENHA: ";
    getline(cin, senha);
    cout << "DIGITE O SALÁRIO: ";
    cin >> sal;
    if(!verifica_cadastro(cpf))
    {
        gerente = Gerente(nome, data_nasc, cpf, sal, senha);
        salva_funcionarios(get_funcionarios());
    }
    else
    {
        cout << "ERRO CPF JÁ CADASTRADO";
    }
    cout << "\n============================================================================\n";
    system("pause");
 }

 void salva_funcionarios(string entrada)
 {
    ofstream arquivoWRITE;
    arquivoWRITE.open("funcionarios.txt");
    arquivoWRITE << entrada;
    arquivoWRITE.close();
 }

 void ler_funcionarios()
 {
    string linha;
    ifstream arquivoREAD;
    arquivoREAD.open("funcionarios.txt");
    if(arquivoREAD.is_open())
    {
        while(getline(arquivoREAD, linha))
        {
            cria_funcionario(linha);
        }
    }
 }

 void cria_funcionario(string linha)
 {
    if(linha[0] == 'G')
    {
        int i = 1;
        string nome = "", data_nascimento = "", cpf = "", sal = "", senha = "", comissao;
        float salario, com;
        while(linha[i] != ';')
        {
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            nome += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            data_nascimento += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            cpf += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            sal += linha[i];
            i++;
        }
        int cr = sal.find(',');
        sal.replace(cr, cr, ".");
        salario = std::stof(sal);
        i ++;
        while(linha[i] != ';')
        {
            senha += linha[i];
            i++;
        }
        i++;
        while(i < linha.size())
        {
            comissao += linha[i];
            i++;
        }
        int co = comissao.find(',');
        comissao.replace(co, co, ".");
        com = std::stof(comissao);
        gerente = Gerente(nome, data_nascimento, cpf, salario, senha, com);
    }
    else
    {
        int i = 1;
        string nome = "", data_nascimento = "", cpf = "", sal = "", senha = "", comissao = "";
        float salario, com;
        while(linha[i] != ';')
        {
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            nome += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            data_nascimento += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            cpf += linha[i];
            i++;
        }
        i ++;
        while(linha[i] != ';')
        {
            sal += linha[i];
            i++;
        }
        int cr = sal.find(',');
        sal.replace(cr, cr, ".");
        salario = std::stof(sal);
        i ++;
        while(linha[i] != ';')
        {
            senha += linha[i];
            i++;
        }
        i++;
        while(i < linha.size())
        {
            comissao += linha[i];
            i++;
        }
        int co = comissao.find(',');
        comissao.replace(co, co, ".");
        com = std::stof(comissao);
        Vendedor v = Vendedor(nome, data_nascimento, cpf, salario, senha, com);
        vendedores.push_back(v);
    }
 }

 string get_funcionarios()
{
     string func = "";
     func += gerente.get_funcionario() + "\n";
     for(int i = 0; i < vendedores.size(); i++)
     {
         func += vendedores[i].get_funcionario() + + "\n";
     }
     return func;
}

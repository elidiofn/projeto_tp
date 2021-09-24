/*
>Discentes: Elidio Faustino do Nascimento
            Isa Cristina Gonçalves de Paiva
            Lucas de Souza Silva
>Matrícula: 120210685
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

#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::getline;

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

//prototipos vendendor
void realizar_venda();
void relatorio_minhas_vendas();
void consultar_estoque();
void menu_vendedor();
void consultar_salario();

void login();
void cadastrar_gerente();

int main()
{
    setlocale(LC_ALL, "portuguese");
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
            Funcionario* f = new Vendedor(nome, data_nasc, cpf, sal, senha);
            vendedor_uso = f;
            menu_vendedor();
            login();
        }
    }
    if(id == "SAIR" || id == "sair")
    {
        //
    }
    else
    {
        cout << "Usuário ou senha incoreto!!" <<endl;
        system("pause");
        login();
    }
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
    gerente = Gerente(nome, data_nasc, cpf, sal, senha);
    cout << "\n============================================================================\n";
 }

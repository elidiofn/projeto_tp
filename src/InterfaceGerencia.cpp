#include "InterfaceGerente.h"
#include "Funcionario.h"
#include "Vendedor.h"
#include "Gerente.h"
#include "Venda.h"
#include "Compra.h"
#include "Caixa.h"
#include "Estoque.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::vector;

extern vector<Vendedor> vendedores;
extern Gerente gerente;
extern Estoque estoque;
extern Caixa caixa;

void menu_gerente()
{
    int opcao = 0;
    while(opcao != 7)
    {
        cout << "\n=============================Menu Gerente===================================\n";
        cout << "1 - CADASTRAR VENDEDOR\n";
        cout << "2 - EXCLUIR VENDEDOR\n";
        cout << "3 - REALIZAR VENDA\n";
        cout << "4 - RELAT�RIO DE VENDAS\n";
        cout << "5 - RELAT�RIO ESTOQUE\n";
        cout << "6 - RELAT�RIO CAIXA\n";
        cout << "7 - SAIR\n";
        cout << " SELECIONE A OP��O DESEJADA: ";
        cin >> opcao;
        cout << "\n==============================================================================\n";
        cin.ignore();
        switch(opcao)
        {
            case 1:
                cadastrar_vendedor();
                opcao = 0;
                break;
            case 2:
                excluir_vendedor();
                opcao = 0;
                break;
            case 3:
                realizar_venda_gerente();
                opcao = 0;
                break;
            case 4:
                relatorio_vendas();
                opcao = 0;
                break;
            case 5:
                relatorio_estoque();
                opcao = 0;
                break;
            case 6:
                relatorio_caixa();
                opcao = 0;
                break;
        }
    }
}
void cadastrar_vendedor()
{
    string nome, data_nasc, rg, senha;
    float sal;
    cout << "\n============================CADASTRAR VENDEDOR===============================\n";
    cout << "DIGITE O NOME: ";
    getline(cin, nome);
    cout << "DIGITE A DATA DE NASCIMENTO(DD/MM/AAAA): ";
    getline(cin, data_nasc);
    cout << "DIGITE O RG: ";
    getline(cin, rg);
    cout << "DIGITE A SENHA: ";
    getline(cin, senha);
    cout << "DIGITE O SAL�RIO: ";
    cin >> sal;
    Vendedor vend = Vendedor(nome, data_nasc, rg, sal, senha);
    vendedores.push_back(vend);
    cout << "\n=============================================================================\n";
}
void excluir_vendedor()
{
    string nome;
    cout << "\n============================EXCLUIR VENDEDOR=================================\n";
    cout << "DIGITE O NOME: ";
    getline(cin, nome);
    for(int i = 0; i < vendedores.size(); i++)
    {
        if(vendedores[i].get_nome() == nome)
        {
            vendedores.erase(vendedores.begin()+i);
        }
    }
    cout << "\n=============================================================================\n";
}
void realizar_venda_gerente()
{
    string data, nome_produto = "", pagamento;
    cout << "\n==================================VENDA======================================\n";
    cout << "INFORMA A DATA: ";
    getline(cin, data);
    string nome = gerente.get_nome();
    string data_nasc = gerente.get_data_nascimento();
    string rg = gerente.get_rg();
    string senha = gerente.get_senha();
    float sal = gerente.get_salario();
    Funcionario* ge = new Gerente(nome,data_nasc, rg, sal, senha);
    Venda ve = Venda(data, ge);
    delete ge;
    while(nome_produto != "SAIR" || nome_produto != "sair")
    {
        cout << "\nNOME DO PRODUTO PARA ADICIONAR(DIGITE SAIR PARA FINALIZAR): ";
        getline(cin, nome_produto);
        if(estoque.busca_produto(nome_produto).first != nullptr)
        {
            ve.add_intem(estoque.busca_produto(nome_produto).first);
        }
    }
    cout << "\n COMO SER� O PAGAMENTO � VISTA OU A PRAZO: ";
    getline(cin, pagamento);
    caixa.entrada(ve,pagamento);
    cout << "\n=============================================================================\n";
}
void relatorio_vendas()
{
    cout << "\n=============================RELAT�RIO VENDAS================================\n";
    cout << caixa.get_vendas();
    cout << "\n=============================================================================\n";
}
void relatorio_estoque()
{
    cout << "\n=============================RELAT�RIO ESTOQUE===============================\n";
    cout << estoque.impr_estoque();
    cout << "\n=============================================================================\n";
}
void relatorio_caixa()
{
    cout << "\n=============================RELAT�RIO CAIXA=================================\n";
    cout << caixa.to_string();
    cout << "\n=============================================================================\n";
}

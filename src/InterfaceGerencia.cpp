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
using std::endl;
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
    while(opcao != 9)
    {
        system("cls");
        cout << "=============================Menu Gerente===================================\n";
        cout << "1 - CADASTRAR VENDEDOR\n";
        cout << "2 - EXCLUIR VENDEDOR\n";
        cout << "3 - EXIBIR FUNCIONARIOS\n";
        cout << "4 - REALIZAR COMPRA\n";
        cout << "5 - REALIZAR VENDA\n";
        cout << "6 - RELATÓRIO DE VENDAS\n";
        cout << "7 - RELATÓRIO ESTOQUE\n";
        cout << "8 - RELATÓRIO CAIXA\n";
        cout << "9 - SAIR\n";
        cout << "SELECIONE A OPÇÃO DESEJADA: ";
        cin >> opcao;
        cout << "\n=============================================================================\n";
        cin.ignore();
        switch(opcao)
        {
            case 1:
                system("cls");
                cadastrar_vendedor();
                system("pause");
                opcao = 0;
                break;
            case 2:
                system("cls");
                excluir_vendedor();
                system("pause");
                opcao = 0;
                break;
            case 3:
                system("cls");
                exibir_vendedores();
                system("pause");
                opcao = 0;
                break;
            case 4:
                system("cls");
                realizar_compra();
                system("pause");
                opcao = 0;
                break;
            case 5:
                system("cls");
                realizar_venda_gerente();
                system("pause");
                opcao = 0;
                break;
            case 6:
                system("cls");
                relatorio_vendas();
                system("pause");
                opcao = 0;
                break;
            case 7:
                system("cls");
                relatorio_estoque();
                system("pause");
                opcao = 0;
                break;
            case 8:
                system("cls");
                relatorio_caixa();
                system("pause");
                opcao = 0;
                break;
        }
    }
}
void cadastrar_vendedor()
{
    string nome, data_nasc, rg, senha;
    float sal;
    cout << "============================CADASTRAR VENDEDOR==============================\n";
    cout << "DIGITE O NOME: ";
    getline(cin, nome);
    cout << "DIGITE A DATA DE NASCIMENTO(DD/MM/AAAA): ";
    getline(cin, data_nasc);
    cout << "DIGITE O RG: ";
    getline(cin, rg);
    cout << "DIGITE A SENHA: ";
    getline(cin, senha);
    cout << "DIGITE O SALÁRIO: ";
    cin >> sal;
    cin.ignore();
    Vendedor vend = Vendedor(nome, data_nasc, rg, sal, senha);
    vendedores.push_back(vend);
    cout << "\n============================================================================\n";
}
void excluir_vendedor()
{
    string nome;
    cout << "============================EXCLUIR VENDEDOR================================\n";
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

void exibir_vendedores()
{
    cout << "==================================FUNCIONARIOS================================\n";
    cout << gerente.to_string() << endl;
    for(int i =0; i < vendedores.size(); i++)
    {
        cout << vendedores[i].to_string() << endl;
    }
    cout << "\n==============================================================================\n";
}

void realizar_compra()
{
    string data, pagamento, tipo_produto;
    string nome_produto = "";
    float p_compra, p_venda;
    cout << "==================================COMPRA=====================================\n";
    cout << "INFORMA A DATA: ";
    getline(cin, data);
    Compra co = Compra(data, gerente);
    while(nome_produto != "SAIR" || nome_produto != "sair")
    {
        cout << "\nNOME DO PRODUTO PARA ADICIONAR(DIGITE SAIR PARA FINALIZAR): ";
        getline(cin, nome_produto);
        if(nome_produto == "sair" || nome_produto == "SAIR")
        {
            break;
        }
        cout << "\nTIPO DO PRODUTO:\n 1 PARA MATERIAL DE CONSTRUÇÃO\n 2 PARA MATERIAL DE ELÉTRICO\n 3 PARA MATERIAL DE HIDRÁULICO\n 4 PARA FERRAMENTA\n";
        getline(cin, tipo_produto);
        cout << "\nPREÇO DE COMPRA DO PRODUTO: ";
        cin >> p_compra;
        cout << "\nPREÇO VENDA DO PRODUTO:  ";
        cin >> p_venda;
        cin.ignore();
        Produto* p;
        if(tipo_produto == "1")
        {
            p = new MaterialConstrucao(nome_produto, p_compra, p_venda);
        }
        else if(tipo_produto == "2")
        {
             p = new MaterialEletrico(nome_produto, p_compra, p_venda);
        }
        else if(tipo_produto == "3")
        {
             p = new MaterialHidraulico(nome_produto, p_compra, p_venda);
        }
        else if(tipo_produto == "4")
        {
             p = new Ferramenta(nome_produto, p_compra, p_venda);
        }
        co.add_intem(p);
    }
    cout << "\nDIGITE A FORMA DE PAGAMENTO: 1 - À VISTA OU 2 - A PRAZO: ";
    getline(cin, pagamento);
    if(pagamento == "1")
    {
        pagamento = "avista";
    }
    caixa.saida(co,pagamento);
    cout << "\n============================================================================\n";
}

void realizar_venda_gerente()
{
    string data, nome_produto = "", pagamento;
    cout << "==================================VENDA======================================\n";
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
         if(nome_produto == "sair" || nome_produto == "SAIR")
        {
            break;
        }
        if(estoque.busca_produto(nome_produto).first != nullptr)
        {
            ve.add_intem(estoque.busca_produto(nome_produto).first);
        }
        else
        {
            cout << "\nPRODUTO INDISPONÍVEL";
        }
    }
    cout << "\n DIGITE A FORMA DE PAGAMENTO: 1 - À VISTA OU 2 - A PRAZO: ";
    getline(cin, pagamento);
    if(pagamento == "1")
    {
        pagamento = "avista";
    }
    caixa.entrada(ve,pagamento);
    cout << "\n=============================================================================\n";
}
void relatorio_vendas()
{
    cout << "=============================RELATÓRIO VENDAS================================\n";
    cout << caixa.get_vendas();
    cout << "\n=============================================================================\n";
}
void relatorio_estoque()
{
    cout << "=============================RELATÓRIO ESTOQUE===============================\n";
    cout << estoque.impr_estoque();
    cout << "\n=============================================================================\n";
}
void relatorio_caixa()
{
    cout << "=============================RELATÓRIO CAIXA=================================\n";
    cout << caixa.to_string();
    cout << "\n=============================================================================\n";
}

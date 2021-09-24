#include "Caixa.h"
#include "Estoque.h"
#include "Venda.h"
#include "Funcionario.h"

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::getline;


extern Estoque estoque;
extern Funcionario* vendedor_uso;
extern Caixa caixa;

void realizar_venda()
{
    string data, nome_produto = "", pagamento;
    cout << "==================================VENDA======================================\n";
    cout << "INFORMA A DATA: ";
    getline(cin, data);
    Venda ve = Venda(data, vendedor_uso);
    while(nome_produto != "SAIR" || nome_produto != "sair")
    {
        cout << "\nNOME DO PRODUTO PARA ADICIONAR(DIGITE SAIR PARA FINALIZAR): ";
        getline(cin, nome_produto);
        if(nome_produto == "sair" || nome_produto == "SAIR")
        {
            break;
        }
        else if(estoque.busca_produto(nome_produto).first != nullptr)
        {
            ve.add_intem(estoque.busca_produto(nome_produto).first);
        }
         else
        {
            cout << "\nPRODUTO INDISPONÍVEL";
        }
    }
    cout << "\nDIGITE A FORMA DE PAGAMENTO: 1 - À VISTA OU 2 - A PRAZO: ";
    getline(cin, pagamento);
    if(pagamento == "1")
    {
        pagamento = "avista";
    }
    caixa.entrada(ve,pagamento);
    cout << "\n=============================================================================\n";
}
void relatorio_minhas_vendas()
{
    cout << "=========================RELATÓRIO MINHAS VENDAS=============================\n";
    cout << caixa.get_vendas_por_vendedor(vendedor_uso->get_nome());
    cout << "\n=============================================================================\n";
}
void consultar_estoque()
{
    string nome_produto;
    cout << "=========================CONSULTAR ESTOQUE===================================\n";
    cout << "\nNOME DO PRODUTO: ";
    getline(cin, nome_produto);
    cout << estoque.busca_produto(nome_produto).second;
    cout << "\n=============================================================================\n";
}

void consultar_salario()
{
    cout << "\n=======================SALÁRIO==============================================\n";
    cout << vendedor_uso->get_salario_detalhes();
    cout << "\n=============================================================================\n";
}

void menu_vendedor()
{
    int opcao = 0;
    while(opcao != 5)
    {
        system("cls");
        cout << "=============================Menu Vendedor===================================\n";
        cout << "1 - REALIZAR VENDA\n";
        cout << "2 - RELATÓRIO MINHAS VENDAS\n";
        cout << "3 - CONSULTAR ESTOQUE\n";
        cout << "4 - CONSULTAR SALÁRIO\n";
        cout << "5 - SAIR\n";
        cout << " SELECIONE A OPÇÃO DESEJADA: ";
        cin >> opcao;
        cout << "\n==============================================================================\n";
        cin.ignore();
        switch(opcao)
        {
            case 1:
                system("cls");
                realizar_venda();
                opcao = 0;
                system("pause");
                break;
            case 2:
                system("cls");
                relatorio_minhas_vendas();
                opcao = 0;
                system("pause");
                break;
            case 3:
                system("cls");
                consultar_estoque();
                opcao = 0;
                system("pause");
                break;
            case 4:
                system("cls");
                consultar_salario();
                opcao = 0;
                system("pause");
                break;
        }
    }
}

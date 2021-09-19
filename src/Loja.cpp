#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::getline;


#include "Funcionario.h"
#include "Gerente.h"
#include "Vendedor.h"
#include "Produto.h"
#include "MaterialConstrucao.h"
#include "MaterialEletrico.h"
#include "MaterialHidraulico.h"
#include "Ferramenta.h"
#include "Venda.h"
#include "Caixa.h"
#include "Estoque.h"
#include "InterfaceVendedor.h"
#include "InterfaceGerente.h"

Estoque estoque;
Caixa caixa;
vector<Vendedor> vendedores;
Gerente gerente;
Funcionario* vendedor_uso;
const string admin = "admin";
const string s_admin = "admin";

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
    else if(gerente.get_nome() == id && gerente.verificar_senha(pw))
    {
        menu_gerente();
        login();
    }
    for(int i = 0; i < vendedores.size(); i++)
    {
        if(vendedores[i].get_nome() == id && vendedores[i].verificar_senha(pw))
        {
            string nome = vendedores[i].get_nome();
            string data_nasc = vendedores[i].get_data_nascimento();
            string rg = vendedores[i].get_rg();
            string senha = vendedores[i].get_senha();
            float sal = vendedores[i].get_salario();
            Funcionario* f = new Vendedor(nome, data_nasc, rg, sal, senha);
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
    string nome, data_nasc, rg, senha;
    float sal;
    cout << "============================CADASTRAR GERENTE===============================\n";
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
    gerente = Gerente(nome, data_nasc, rg, sal, senha);
    cout << "\n============================================================================\n";
 }

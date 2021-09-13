#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
using namespace std;
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
#include "InterfaceVendedor.cpp"
#include "InterfaceGerencia.cpp"

Caixa caixa;
vector<Vendedor> vendedores;
Gerente gerente;
Estoque estoque;
string admin = "admin";
string s_admin ="admin";

void login();
int main()
{
    setlocale(LC_ALL, "portuguese");
    Produto* mc = new MaterialConstrucao("areia", 10, 12);
    Produto* me = new MaterialEletrico("fio 2.5", 5, 6);
    Produto* mh = new MaterialHidraulico("curva 90", 12, 14);
    Produto* f = new Ferramenta("alicate", 15, 20);
    cout << mc->to_string() << endl << me->to_string() << endl;
    cout << mh->to_string() << endl << f->to_string() << endl;

    delete mc;
    delete f;
    delete me;
    delete mh;
    return 0;
}
 void login()
 {
    string id, pw;
    cout << "Usuário: ";
    getline(cin, id);
    cout << "Senha: ";
    getline(cin, pw);
 }

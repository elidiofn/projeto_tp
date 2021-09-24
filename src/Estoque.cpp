#include "Estoque.h"

Estoque::Estoque()
{
   ler_estoque();
}

Estoque::~Estoque()
{
    for(int i = 0; i < produtos.size(); i++)
    {
        delete produtos[i].first;
    }
}

void Estoque::salvar_estoque(string entrada)
{
    ofstream arquivoWRITE;
    arquivoWRITE.open("estoque.txt");
    arquivoWRITE << entrada;
    arquivoWRITE.close();
}

//Retorna a informa��o sobre um produto no estoque ou  se n�o houver.
pair<Produto*, int> Estoque::busca_produto(string nome)
{
    int indice = busca_indice_produto(nome);
    if(indice != -1)
    {
        return produtos[indice];
    }
    pair<Produto*, int> n;
    n.first = nullptr;
    n.second = 0;
    return n;
}

void Estoque::entrada(Produto* produto, int quantidade)
{   int indice = busca_indice_produto(produto->get_nome());
    if(indice != -1)
    {
        produtos[indice].second += quantidade;
    }
    else
    {
        cria_produto(produto->to_string(), quantidade);
    }
    string entrada = "";
    for(int i =0; i < produtos.size(); i++)
    {
        entrada += "<" + produtos[i].first->to_string() + "><" + std::to_string(produtos[i].second) + ">\n";
    }
    salvar_estoque(entrada);
}

void Estoque::saida(Produto* produto, int quantidade)
{
    int indice = busca_indice_produto(produto->get_nome());
    if(indice != -1)
    {
        produtos[indice].second -= quantidade;
    }
    string entrada = "";
    for(int i =0; i < produtos.size(); i++)
    {
        entrada += "<" + produtos[i].first->to_string() + "><" + std::to_string(produtos[i].second) + ">\n";
    }
    salvar_estoque(entrada);
}

string Estoque::impr_estoque()
{
    string relatorio = "\n=================================ESTOQUE=====================================\n";
    for(int i = 0; i < produtos.size(); i++)
    {
        relatorio += "Produto: " + produtos[i].first->get_nome() + "\nQuantidade: " + to_string( produtos[i].second) + "\n";
    }
    relatorio +=       "\n=============================================================================\n";
    return relatorio;
}

void Estoque::ler_estoque()
{
    string linha;
    int quantidade;
    ifstream arquivoREAD;
    arquivoREAD.open("estoque.txt");
    if(arquivoREAD.is_open())
    {
        while(getline(arquivoREAD, linha))
        {
            string produto = "", qtd = "";
            int indice = 1;
            while(linha[indice] != '>' && indice <linha.size())
            {
                produto += linha[indice];
                indice++;
            }
            indice+=2;
            while(linha[indice] != '>')
            {
                qtd += linha[indice];
                indice++;
            }
            quantidade = std::stoi(qtd);
            cria_produto(produto, quantidade);
        }

    }
}

//Retorna o indice do produto no estoque ou -1 se n�o houver.
int Estoque::busca_indice_produto(string nome)
{
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].first->get_nome() == nome){
            return i;
        }
    }
    return -1;
}
 void Estoque::cria_produto(string produto, int quantidade)
{
    int indice = 0;
    string tipo = "", nome = "", pc = "", pv = "";
    float preco_compra, preco_venda;
    while(produto[indice] != ';')
    {
        tipo += produto[indice];
        indice++;
    }
    indice ++;
    while(produto[indice] != ';')
    {
        nome += produto[indice];
        indice++;
    }
    indice ++;
    while(produto[indice] != ';')
    {
        pc += produto[indice];
        indice++;
    }
    indice ++;
    while(produto[indice] != ';')
    {
        pv += produto[indice];
        indice++;
    }
    preco_compra = std::stof(pc);
    preco_venda = std::stof(pv);
    if(tipo == "Material Construcao")
    {
         produtos.push_back(make_pair(new MaterialConstrucao(nome, preco_compra, preco_venda), quantidade));
    }
    else if(tipo == "Material Eletrico")
    {
         produtos.push_back(make_pair(new MaterialEletrico(nome, preco_compra, preco_venda), quantidade));
    }
    else if(tipo == "Material Hidraulico")
    {
        produtos.push_back(make_pair(new MaterialHidraulico(nome, preco_compra, preco_venda), quantidade));
    }
    else if(tipo == "Ferramenta")
    {
         produtos.push_back(make_pair(new Ferramenta(nome, preco_compra, preco_venda), quantidade));
    }
}

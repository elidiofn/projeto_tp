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

//Retorna a informação sobre um produto no estoque ou  se não houver.
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
        string nome = produto->get_nome();
        float preco_compra = produto->get_preco_compra();
        float preco_venda = produto->get_preco();

        if(produto->get_tipo() == "Material Construção")
        {
            produtos.push_back(make_pair(new MaterialConstrucao(nome, preco_compra, preco_venda), quantidade));
        }
        else if(produto->get_tipo() == "Material Elétrico")
        {
            produtos.push_back(make_pair(new MaterialEletrico(nome, preco_compra, preco_venda), quantidade));
        }
        else if(produto->get_tipo() == "Material Hidráulico")
        {
            produtos.push_back(make_pair(new MaterialHidraulico(nome, preco_compra, preco_venda), quantidade));
        }
        else if(produto->get_tipo() == "Ferramenta")
        {
            produtos.push_back(make_pair(new Ferramenta(nome, preco_compra, preco_venda), quantidade));
        }
    }
    string entrada = "";
    for(int i =0; i < produtos.size(); i++)
    {
        entrada += "< " + produtos[i].first->to_string() + " >< " + std::to_string(produtos[i].second) + " >\n";
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
        entrada += "< " + produtos[i].first->to_string() + " >< " + std::to_string(produtos[i].second) + " >\n";
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
    vector<string> linhas;
    ifstream arquivoREAD;
    arquivoREAD.open("estoque.txt");
    if(arquivoREAD.is_open())
    {
        while(getline(arquivoREAD, linha))
        {
            linhas.push_back(linha);
        }
    }
    carregar_estoque(linhas);
}

//Retorna o indice do produto no estoque ou -1 se não houver.
int Estoque::busca_indice_produto(string nome)
{
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].first->get_nome() == nome){
            return i;
        }
    }
    return -1;
}
 void Estoque::carregar_estoque(vector<string> linhas)
{

}

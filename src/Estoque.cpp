#include "Estoque.h"

Estoque::Estoque()
{
    carregar_estoque();
}

Estoque::~Estoque(){}

void Estoque::salvar_estoque()
{

}
//retorna a quantidade itens no estoque, caso não tenha retorna 0;
int Estoque::busca_produto(string produto)
{
    int i = 0;
    while(i < est_material_construcao.size()){
        if(est_material_construcao[i].first.get_nome() == produto){
            return est_material_construcao[i].second;
        }
    }
    i = 0;
    while(i < est_material_eletrico.size()){
        if(est_material_eletrico[i].first.get_nome() == produto){
            return est_material_eletrico[i].second;
        }
    }
    i = 0;
    while(i < est_material_hidraulico.size()){
        if(est_material_hidraulico[i].first.get_nome() == produto){
            return est_material_hidraulico[i].second;
        }
    }
    i = 0;
    while(i < est_ferramenta.size()){
        if(est_ferramenta[i].first.get_nome() == produto){
            return est_ferramenta[i].second;
        }
    }
    return 0;
}

void Estoque::entrada(string produto, int quantidade)
{   string busca = busca_produto_est(produto);
    if(busca.size()== 2){
            std::
        if(busca[0] == "C"){
            est_material_construcao[]
        }
    }

}

void Estoque::saida(string produto, int quantidade)
{

}

string Estoque::impr_estoque()
{

}

void Estoque::carregar_estoque()
{

}

//retorna o vector do produto com seu indice;
string Estoque::busca_produto_est(string nome){
    int i = 0;
    while(i < est_material_construcao.size()){
        if(est_material_construcao[i].first.get_nome() == produto){
            return "C" + std::to_string(i);
        }
    }
    i = 0;
    while(i < est_material_eletrico.size()){
        if(est_material_eletrico[i].first.get_nome() == produto){
            return "E" + std::to_string(i);;
        }
    }
    i = 0;
    while(i < est_material_hidraulico.size()){
        if(est_material_hidraulico[i].first.get_nome() == produto){
            return "H" + std::to_string(i);;
        }
    }
    i = 0;
    while(i < est_ferramenta.size()){
        if(est_ferramenta[i].first.get_nome() == produto){
            return "F" + std::to_string(i);;
        }
    }
    return "0";
}

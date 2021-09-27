#include "Caixa.h"

extern Estoque estoque;

Caixa::Caixa()
{
    saldo = 0;
    ler_caixa();
}

Caixa::Caixa(float valor)
{
    saldo = valor;
}

Caixa::~Caixa()
{
}

float Caixa::get_saldo()
{
    return saldo;
}

void Caixa::entrada(Venda venda, string pagamento)
{
    vector<Produto*> itens = venda.get_produtos();
    for(int i = 0; i<itens.size();i++)
    {
        estoque.saida(itens[i], 1);
    }
    if(pagamento == "avista"){
        saldo += venda.get_valor("av");
    }
    else
    {
        saldo += venda.get_valor("");
    }
    vendas.push_back(venda);
    salva_caixa(situacao_caixa());
}

void Caixa::saida(Compra compra, string pagamento)
{
    vector<Produto*> itens = compra.get_produtos();
    for(int i = 0; i<itens.size();i++)
    {
        estoque.entrada(itens[i], 1);
    }
    if(pagamento == "avista")
    {
        saldo -= compra.get_valor("av");
    }
    else
    {
        saldo -= compra.get_valor("");
    }
    compras.push_back(compra);
    salva_caixa(situacao_caixa());
}

string Caixa::get_vendas()
{
    string vendas = "\n=================================VENDAS CAIXA=================================\n";
    for(int i=0; i<this->vendas.size(); i++){
        vendas += this->vendas[i].to_string()+ "\n";
    }
    vendas += "\n==============================================================================\n";
   return vendas;
}

string Caixa::get_compras()
{
    string compras = "\n=================================COMPRAS CAIXA================================\n";
    for(int i=0; i<this->compras.size(); i++){
        compras += this->compras[i].to_string() + "\n";
    }
    compras += "\n==============================================================================\n";
    return compras;
}

string Caixa::get_vendas_por_vendedor(string nome_vendedor)
{
    vector<Venda> vend;
    for(int i = 0; i < vendas.size(); i++){
        if(vendas[i].get_vendedor()->get_nome() == nome_vendedor){
            vend.push_back(vendas[i]);
        }
    }
    string vendas = "\n==============VENDAS====================\n";
    for(int i=0; i<vend.size(); i++){
        vendas += vend[i].to_string() + "\n";
    }
    vendas += "\n========================================\n";
   return vendas;
}
string Caixa::to_string()
{
    string rel_caixa = "\n===============================\n";
    rel_caixa += "SALDO: " + std::to_string(saldo);
    rel_caixa += get_compras();
    rel_caixa += get_vendas();
    rel_caixa += "\n===============================\n";
    return rel_caixa;
}
//cria o arquivo txt com as transações do caixa
void Caixa::salva_caixa(string entrada)
{
    ofstream arquivoWRITE;
    arquivoWRITE.open("caixa.txt");
    arquivoWRITE << entrada;
    arquivoWRITE.close();
}
//ler o arquivo txt com as transações do caixa
void Caixa::ler_caixa()
{
    string linha;
    ifstream arquivoREAD;
    arquivoREAD.open("caixa.txt");
    if(arquivoREAD.is_open())
    {
        while(getline(arquivoREAD, linha))
        {
            cria_caixa(linha);
        }
    }
}
//define como deve ser o arquivo que salva as transações do caixa
string Caixa::situacao_caixa()
{
    string situacao = "";

    for(int i = 0; i < compras.size(); i++)
    {
        situacao += "c";
        situacao += "|" + std::to_string(compras[i].get_total()) + "|";
        if(i == (compras.size() -1))
        {
            situacao += compras[i].get_compra() + ">\n";
        }
        else
        {
            situacao += compras[i].get_compra() + "\n";
        }
    }
    for(int i = 0; i < vendas.size(); i++)
    {
        situacao += "v";
        situacao += "|" + std::to_string(vendas[i].get_total()) + "|";
        if(i == (vendas.size() - 1))
        {
            situacao += vendas[i].get_venda() + ">\n";
        }
        else
        {
            situacao += vendas[i].get_venda() + "\n";
        }
    }
    return situacao;
}
//instancia os objetos a partir do arquivo caixa
void Caixa::cria_caixa(string linha)
{
    Compra c;
    Venda v;
    string tipo, valor = "", data = "", funcionario = "", produtos = "";
    tipo = linha[0];
    int indice = 2;
    vector<string> produ;
    while(linha[indice] != '|')
    {
        valor += linha[indice];
        indice++;
    }
    indice += 3;
    while(linha[indice] != ')')
    {
        data += linha[indice];
        indice++;
    }
    indice += 1;
    while(linha[indice] != '[' && linha[indice] != '}')
    {
        funcionario += linha[indice];
        indice++;
    }
    //criando um gerente ou funcionario para a compra ou venda
    if(funcionario[0] == 'G' && tipo == "c")
    {
        int i = 1;
        string nome = "", data_nascimento = "", cpf = "", sal = "", senha = "";
        float salario;
        while(funcionario[i] != ';')
        {
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            nome += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            data_nascimento += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            cpf += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            sal += funcionario[i];
            i++;
        }
        salario = std::stof(sal);
        i++;
        while(i < funcionario.size())
        {
            senha += funcionario[i];
            i++;
        }
        Gerente g = Gerente(nome, data_nascimento, cpf, salario, senha);
        c = Compra(data, g);
    }
    else if(funcionario[0] == 'G' && tipo =="v")
    {
        int i = 1;
        string nome = "", data_nascimento = "", cpf = "", sal = "", senha = "";
        float salario;
        while(funcionario[i] != ';')
        {
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            nome += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            data_nascimento += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            cpf += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            sal += funcionario[i];
            i++;
        }
        i++;
        while(i < funcionario.size())
        {
            senha += funcionario[i];
            i++;
        }
        Funcionario* f = new Gerente(nome, data_nascimento, cpf, salario, senha);
        v = Venda(data,f);
    }
    else
    {
        int i = 1;
        string nome = "", data_nascimento = "", cpf = "", sal = "", senha = "";
        float salario;
        while(funcionario[i] != ';')
        {
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            nome += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            data_nascimento += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            cpf += funcionario[i];
            i++;
        }
        i ++;
        while(funcionario[i] != ';')
        {
            sal += funcionario[i];
            i++;
        }
        i++;
        while(i < funcionario.size())
        {
            senha += funcionario[i];
            i++;
        }
        Funcionario* f = new Vendedor(nome, data_nascimento, cpf, salario, senha);
        v = Venda(data,f);
    }
    //lendo os prdutos da compra ou venda
    while(linha[indice] != '>' && indice < linha.size())
    {
        produtos += linha[indice];
        indice++;
    }
    indice = 1;
    while(produtos[indice] != '}' && indice < produtos.size())
    {
        string pro = "";
        while(produtos[indice] != ']')
        {
            pro += produtos[indice];
            indice++;
        }
        produ.push_back(pro);
        indice += 2;
    }
    //adiciona os itens em compra ou venda
    if(tipo == "c")
    {
        for(int i =0; i< produ.size();i++)
        {
            string produto = produ[i];
            int j = 0;
            string tipo = "", nome = "", pc = "", pv = "";
            float preco_compra, preco_venda;
            while(produto[j] != ';')
            {
                tipo += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                nome += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                pc += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                pv += produto[j];
                j++;
            }
            int a = pc.find(',');
            int b = pv.find(',');
            pc.replace(a, a, ".");
            pv.replace(b, b, ".");
            preco_compra = std::stof(pc);
            preco_venda = std::stof(pv);
            if(tipo == "Material Construcao")
            {
                c.add_intem(new MaterialConstrucao(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Material Eletrico")
            {
                c.add_intem(new MaterialEletrico(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Material Hidraulico")
            {
                c.add_intem(new MaterialHidraulico(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Ferramenta")
            {
                c.add_intem(new Ferramenta(nome, preco_compra, preco_venda));
            }
        }
        int cr = valor.find(',');
        valor.replace(cr, cr, ".");
        float vt = std::stof(valor);
        if(vt != c.get_total())
        {
            c.get_valor("av");
        }
        saldo -= c.get_total();
        compras.push_back(c);
    }
    else//caso for uma venda
    {
        for(int i =0; i< produ.size();i++)
        {
            string produto = produ[i];
            int j = 0;
            string tipo = "", nome = "", pc = "", pv = "";
            float preco_compra, preco_venda;
            while(produto[j] != ';')
            {
                tipo += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                nome += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                pc += produto[j];
                j++;
            }
            j++;
            while(produto[j] != ';')
            {
                pv += produto[j];
                j++;
            }
            int a = pc.find(',');
            int b = pv.find(',');
            pc.replace(a, a, ".");
            pv.replace(b, b, ".");
            preco_compra = std::stof(pc);
            preco_venda = std::stof(pv);
            if(tipo == "Material Construcao")
            {
                v.add_intem(new MaterialConstrucao(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Material Eletrico")
            {
                v.add_intem(new MaterialEletrico(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Material Hidraulico")
            {
                v.add_intem(new MaterialHidraulico(nome, preco_compra, preco_venda));
            }
            else if(tipo == "Ferramenta")
            {
                v.add_intem(new Ferramenta(nome, preco_compra, preco_venda));
            }
        }
        int cr = valor.find(',');
        valor.replace(cr, cr, ".");
        float vt = std::stof(valor);
        if(vt != v.get_total())
        {
            v.get_valor("av");
        }
        saldo += v.get_total();
        vendas.push_back(v);
    }
}

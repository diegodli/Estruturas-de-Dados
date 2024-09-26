#include <iostream>
#include <string.h>

using namespace std;

class TabelaHash{

    private:

    struct Noh{
        int chave;
        string valor;
        Noh* prox;
    };

    int tamanho;
    int elementos;
    Noh** tabela;
    Noh sentinela;
    

    public:

    TabelaHash()
    {
        tamanho = 1;
        elementos = 0;
        tabela = new Noh*[tamanho];
        tabela[0] = &sentinela;
    }

    int Hash(int chave){
        return chave % tamanho;
    }

    void Redimensionar(int novo_tam){
        Noh** nova_tabela = new Noh*[novo_tam];
        int tam_atual = tamanho;
        tamanho = novo_tam;

        for(int  i = 0; i < novo_tam; i++)
        {
            nova_tabela[i] = &sentinela;
        }

        for (int i = 0; i < tam_atual; i++)
        {
            Noh* coluna = tabela[i];

            while(coluna != &sentinela)
            {
                Noh* auxiliar = coluna->prox;
                int local = Hash(coluna->chave);
                coluna->prox = nova_tabela[local];

                nova_tabela[local] = coluna;
                coluna = auxiliar;
            }
        }

        delete[] tabela;
        tabela = nova_tabela;
    }

    void Adicionar(int chave, string nome)
    {
        if(tamanho == elementos)
        {
            Redimensionar(2*tamanho);
        }

        int local = Hash(chave);

        Noh* novo_noh = new Noh;
        novo_noh->prox = tabela[local];

        tabela[local] = novo_noh;

        novo_noh->chave = chave;
        novo_noh->valor = nome;

        ++elementos;
    }

    struct Achou
    {
        bool achou;
        string nome;
    };

    Achou Buscar(int chave_p)
    {
        int local = Hash(chave_p);

        Achou busca;
        Noh* temporario = tabela[local];

        while(temporario != &sentinela)
        {
            if(temporario->chave == chave_p)
            {
                busca.achou = true;
                busca.nome = temporario->valor;
                return busca;
            }
            else
            {
                temporario = temporario->prox;
            }
        }
        busca.achou = false;
        busca.nome = "";
        return busca;
    }

    //Remover vetor de elementos

    void RemoverVetor(int vetor[], int tam_vetor)
    {
        for(int i = 0; i < tam_vetor; i++)
        {
            int local = Hash(vetor[i]);
            Noh* temporario = tabela[local];

            if(tabela[local]->chave == vetor[i])
            {
                tabela[local] = temporario->prox;
                delete temporario;
                return;
            }

            while(temporario != &sentinela)
            {
                if(temporario->prox->chave == vetor[i])
                {
                    Noh* remocao = temporario->prox;
                    temporario->prox = remocao ->prox;
                    delete remocao;
                    return;
                }
                else
                {
                    temporario = temporario->prox;
                }
            }
        }
    }

    void Remover(int chave_p)
    {
        int local = Hash(chave_p);
        Noh* temporario = tabela[local];

        if(tabela[local]->chave = chave_p)
        {
            tabela[local] = temporario->prox;
            delete temporario;
            return;
        }

        while(temporario != &sentinela)
        {
            if(temporario->prox->chave == chave_p)
            {
                Noh* remocao = temporario->prox;
                temporario->prox = remocao->prox;
                delete remocao;
            }
            else
            {
                temporario = temporario->prox;
            }
        }
    }

};

int main()
{
    TabelaHash Tabela;
    int chave;
    string nome;
    int opcao;
    int tamanho_vetor;
    int vetor[tamanho_vetor];

    while(opcao != 0){

    cout << "digite a operacao que queira realizar:\n";
    cout << "0 - Parar o programa\n";
    cout << "1 - Adicionar elemento\n";
    cout << "2 - buscar elemento\n";
    cout << "3 - remover elemento\n";
    cout << "4 - remover vetor de elementos\n";
    cin >> opcao;

    if(opcao == 1){
        cout << "Digite a chave do elemento e seu valor: \n";
        cin >> chave >> nome;
        Tabela.Adicionar(chave,nome);
    }

    else if(opcao == 2){
        cout << "Digite a chave do elemento a ser buscado: \n";
        cin >> chave;
        cout << Tabela.Buscar(chave).nome << '\n';
    }

    else if(opcao == 3){
        cout << "Digite a chave do elemento a ser removido \n";
        cin >> chave;
        Tabela.Remover(chave);
    }

    else if(opcao == 4){
        cout << "Digite o tamanho do vetor que deseja remover\n";
        cin >> tamanho_vetor ;

        cout << "Digite as chaves que deseja remover";
        for(int i = 0; i < tamanho_vetor; i++)
        {
            cin >> chave;
            vetor[i] = chave;
        }

        Tabela.RemoverVetor(vetor, tamanho_vetor);
    }

    }

}
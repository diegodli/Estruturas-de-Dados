#include <iostream>
#include "Hash.h"

using namespace std;

int Hash::FuncaoHash(Aluno aluno)
{
    return (aluno.obterRa() % max_posicoes);
}

Hash::Hash(int tam_vetor, int max)
{
    qtd_itens = 0;
    max_itens = max;
    max_posicoes = tam_vetor;
    estrutura = new Aluno[tam_vetor];
}

Hash::~Hash()
{
    delete[] estrutura;
}

bool Hash::cheio()
{
    return (qtd_itens == max_itens);
}

int Hash::ObterTamanhoAtual()
{
    return qtd_itens;
}

void Hash::Inserir(Aluno aluno)
{
    if (cheio())
    {
        cout << "A tabela esta cheia!\n";
        cout << "O elemento nao pode ser inserido!\n";
    }
    else
    {
        int local = FuncaoHash(aluno);

        while (estrutura[local].obterRa() > 0)
        {
            local = (local + 1) % max_posicoes;
        }

        estrutura[local] = aluno;
        qtd_itens++;
    }
}

// -1: vazio
// -2: removido

void Hash::Deletar(Aluno aluno)
{
    int local = FuncaoHash(aluno);
    bool teste = false;

    while (estrutura[local].obterRa() != -1)
    {
        if (estrutura[local].obterRa() == aluno.obterRa())
        {
            cout << "Elemento removido!\n";
            estrutura[local] = Aluno(-2, " ");
            qtd_itens--;
            teste = true;
            break;
        }

        local = (local + 1) % max_posicoes;
    }
    if (!teste)
    {
        cout << "Elemento não encontrado!\n";
        cout << "Nenhum elemento foi removido!\n";
    }
}

void Hash::Buscar(Aluno &aluno, bool &busca)
{
    int local = FuncaoHash(aluno);
    busca = false;
    while (estrutura[local].obterRa() != -1)
    {
        if (estrutura[local].obterRa() == aluno.obterRa())
        {
            busca = true;
            aluno = estrutura[local];
            break;
        }
        local = (local + 1) % max_posicoes;
    }
}

void Hash::Imprimir()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++)
    {
        if (estrutura[i].obterRa() > 0)
        {
            cout << i << ":" << estrutura[i].obterRa();
            cout << estrutura[i].obterNome();
        }
    }
}

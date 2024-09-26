#include<iostream>

using namespace std;

class ArvoreBinaria
{
    public:

    struct Noh
    {
        Noh* esquerda;
        Noh* direita;
        int valor;
    };

    Noh* raiz;

    //2) Arvore Binaria de Busca, fazer uma funcao que recebe como parametro um elemento 
    //e ela tem que retornar o proximo elemento na ordem crescente, ou seja, 
    //tem que retorna o proximo numero maior que ele na arvore binaria

    int ProximoElemento(int valor)
    {
        Noh* temporario = raiz;
        Noh* sucessor =  nullptr;

        //encontrar o nó
        while(temporario != nullptr)
        {
            if(valor < temporario->valor)
            {
                sucessor = temporario;
                temporario = temporario->esquerda;
            }
            else if(valor > temporario->valor)
            {
                temporario = temporario->direita;
            }
            else
            {
                break;
            }
        }

        //se o nó não for encontrado 
        if(temporario == nullptr)
        {
            return -1;
        }

        //se o no tem subarvore direita, o sucessor é o menor valor à direita
        if(temporario->direita != nullptr)
        {
            temporario = temporario->direita;
            while(temporario->esquerda !=nullptr)
            {
                temporario = temporario->esquerda;
            }
            return temporario->valor;
        }

        //se não há subarvore direita
        if(sucessor != nullptr)
        {
            return sucessor->valor;
        }
    }
};
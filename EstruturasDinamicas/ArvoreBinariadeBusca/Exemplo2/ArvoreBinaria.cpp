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

    ArvoreBinaria()
    {
        raiz = nullptr;
    }

    bool Vazio()
    {
        return (raiz== nullptr);
    }

    void Adicionar(int valor)
    {
        Noh* novo_noh = new Noh{nullptr, nullptr, valor};

        if(Vazio())
        {
            raiz = novo_noh;
            return;
        }

        Noh* temporario = raiz;

        while(true)
        {
            if(valor < temporario->valor)
            {
                if(temporario->esquerda == nullptr)
                {
                    temporario->esquerda = novo_noh;
                    return;
                }

                temporario = temporario->esquerda;

            }
            else
            {
                if(temporario->direita == nullptr)
                {
                    temporario->direita = novo_noh;
                }
                
                temporario = temporario->direita;

            }
        }
    }

    bool pertence(int valor)
    {
        Noh* temporario = raiz;

        while(temporario != nullptr)
        {
            if(temporario->valor == valor)
            {
                return true;
            }
            else if(valor > temporario->valor)
            {
                temporario = temporario->direita;
            }
            else if (valor < temporario->valor)
            {
                temporario = temporario->esquerda;
            }
        }

        return false;
    }

    void Remover(int valor)
    {
        Noh* temporario = raiz;
        Noh** cima = &raiz;

        while(temporario != nullptr)
        {
            if(valor < temporario->valor)
            {
                cima = &(temporario->esquerda);
                temporario = temporario->esquerda;
            }
            else if(valor > temporario->valor)
            {
                cima = &(temporario->direita);
                temporario = temporario->direita;
            }
            else break;
        }

        if(temporario == nullptr)
        {
            return;
        }

        if(temporario->direita == nullptr)
        {
            *cima = temporario->esquerda;
        }
        else if(temporario->esquerda == nullptr)
        {
            *cima = temporario->direita;
        }
        else
        {
            Noh* busca = temporario->direita;
            Noh** cima_b = &temporario->direita;

            while(busca->esquerda != nullptr)
            {
                cima_b = &busca->esquerda;
                busca = busca->esquerda;
            }

            *cima_b = busca->direita;

            *cima = busca;
            busca->esquerda = temporario->esquerda;
            busca->direita = temporario->direita;

        }
        delete temporario;
    }

    void ExibirArvore(Noh* raiz)
    {
        if (raiz == nullptr)
        {
            return;
        }
        ExibirArvore(raiz->esquerda);
        cout << raiz->valor << " ";
        ExibirArvore(raiz->direita);

    }
};

int main()
{
    ArvoreBinaria arvore;


    arvore.Adicionar(50);
    arvore.Adicionar(30);
    arvore.Adicionar(70);
    arvore.Adicionar(20);
    arvore.Adicionar(40);
    arvore.Adicionar(60);
    arvore.Adicionar(80);

    cout << "Arvore apos insercoes: ";
    arvore.ExibirArvore(arvore.raiz);  

    cout << "Pertence 40? " << (arvore.pertence(40) ? "Sim" : "Não") << endl;
    cout << "Pertence 25? " << (arvore.pertence(25) ? "Sim" : "Não") << endl;


    arvore.Remover(20);  
    cout << "Arvore após remover 20: ";
    arvore.ExibirArvore(arvore.raiz);

    arvore.Remover(30);  
    cout << "Arvore após remover 30: ";
    arvore.ExibirArvore(arvore.raiz);

    arvore.Remover(50);  
    cout << "Arvore após remover 50: ";
    arvore.ExibirArvore(arvore.raiz);

    return 0;
}
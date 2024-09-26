#include <iostream>

using namespace std;

class ConjuntoABB{

    struct Noh{
        Noh *esq;
        double elem;
        Noh *dir;
    };

    Noh *raiz;

    ConjuntoABB(){
        raiz = nullptr;
    }

    bool Vazio(){
        return (raiz == nullptr);
    }

    // pre-condição: "e" nao esta no conjunto

    void Inserir(double e){
        Noh *novo = new Noh {nullptr, e, nullptr};

        if(Vazio()){
            raiz = novo;
            return;
        }

        Noh *n = raiz;

        while (true){
            if (e < n->elem)
            {
                if(n->esq == nullptr)
                {
                    n->esq = novo;
                    return;
                }

                n = n->esq;

            }
            else
            {
                if (n->dir == nullptr)
                {
                    n->dir = novo;
                    return;
                }

                n = n->dir;

            }
        }
    }

    bool Pertence(double e){
        Noh *n = raiz;

        while (n != nullptr)
        {
            if (e < n->elem)
            {
                n = n->esq;
            }
            else if (n->elem < e)
            {
                n = n->dir;
            }
            else{
                return true;
            }
            return false;
        }
    }

    void InserirSeNovo(double e){
        if(!Pertence){
            Inserir(e);
        }
    }

    void Remover(double e)
    {
        Noh *n = raiz;
        Noh* *cima = &raiz;

        while(n != nullptr)
        {
            if (e < n->elem){
                cima = & n->esq;
                n = n->esq;
            }
            else if (n->elem < e)
            {
                cima = & n->dir;
                n = n->dir;
            }
            else
            {
                break;
            }
        }

        if (n == nullptr) //"e" nao pertence
        {
            return;
        }

        if (n->dir == nullptr)
        {
            *cima = n->esq;
        }
        else if ( n->esq == nullptr)
        {
            *cima = n->dir;
        }
        else   // Tem dois filhos
        {
            Noh *s = n->dir;
            Noh* *cima_s = & n->dir;

            while (s->esq != nullptr)
            {
                cima_s = & s->esq;
                s = s->esq;
            }

            *cima_s = s->dir; //Tira s da arvore

            *cima = s;
            s->esq = n->esq;
            s->dir = n->dir;

        }
        delete n;
    }

    ~ConjuntoABB(){
        
    }
       
};
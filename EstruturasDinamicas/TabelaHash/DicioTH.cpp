#include<iostream>

using namespace std;

class DicioTD{
    struct Noh{
        int chave;
        string valor;
        Noh *prox;

    };

    int m;   //tamanho da tabela
    int n;   // elementos do dicionario
    Noh **T;
    Noh sent;

    public:

    DicioTD(){
        m = 1;
        n = 0;
        T = new Noh* [m];

        T[0] = &sent;
    }

    int H (int c) //Função de dispersão
    {
        return c % m;
    }

    void Inserir(int c, string v){
        if (m == n) Redimensionar(2*m);

        int i = H(c);

        T[i] = new Noh {c, v, T[i]};

        ++n;
    }

    void Redimensionar (int novo_tam){
        Noh **U = new Noh *[novo_tam];

        int tam_atual = m;

        m = novo_tam;

        int i;

        for (i=0; i<novo_tam; i++){
            U[i] = &sent;
        }

        for(i=0; i< tam_atual; i++){
            Noh *n = T[i];

            while (n != &sent){
                Noh *p = n->prox;
                int j = H(n->chave);
                n->prox = U[j];
                U[j] = n;
                n = p;
            }
        }
        delete[] T;
        T = U;
    }

    ~DicioTD(){

    }
};
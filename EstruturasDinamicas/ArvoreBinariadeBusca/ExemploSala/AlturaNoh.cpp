// ESCREVA UMA FUNÇÃO QUE RETORNE A ALTRA DO NÓ "N", OU ZERO, CASO "N" SEJA "N" SEJA NULO

#include <iostream>

using namespace std;

class AlturaArvore{
    
    struct Noh{
        Noh *esq;
        double elem;
        Noh *dir;
    };

    int Altura(Noh *n){
        if (n == nullptr)
        {
            return 0;
        }

        int alt_esq = Altura(n->esq);
        int alt_dir = Altura(n->dir);

        if (alt_esq < alt_dir)
        {
            return alt_dir + 1;
        }
        else
        {
            return alt_esq + 1;
        }
    }

    int ImprimirAlturas(Noh *n){
        if (n == nullptr)
        {
            return 0;
        }
        int alt_esq = ImprimirAlturas(n->esq);
        int alt_dir = ImprimirAlturas(n->dir);

        int alt_n = (alt_esq < alt_dir) ? alt_dir + 1 : alt_esq + 1;

        cout << "Alt(" << n->elem << "): " << alt_n << "\n";

        return alt_n;
    }
    
};
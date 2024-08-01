#include <iostream>

using namespace std;

class Fila
{
    int tam_v;
    int *v;
    int n;
    int ultimo = -1;
    int primeiro = -1;

    public:

    Fila()
    {
        tam_v = 1;
        v = new int[tam_v];
        n = 0;
    }

    bool Vazia()
    {
        return (n == 0);
    }

    bool Cheia()
    {
        return (tam_v == n);
    }

    void Redimensionar()
    {
        int novo_tam = 2*tam_v;
        int *w = new int[novo_tam];

        for (int i = 0; i < tam_v; ++i)
        {
            int posicao = (i + primeiro) % tam_v;
            w[i] = v[posicao];
        }

        delete[] v;
        primeiro = 0;
        ultimo = n - 1;
        tam_v = novo_tam;
        v = w;
    }

    void Reduzir()
    {
        int novo_tam = tam_v /2;
        int *w = new int[novo_tam];

        for (int i = 0; i < novo_tam; i++)
        {
            int posicao = (i + primeiro) % tam_v;
            w[i] = v[posicao];
        }

        delete[] v;

        primeiro = 0;
        ultimo = n - 1;
        tam_v = novo_tam;
        v = w;
    }

    void Enfilar(int s)
    {
        if (Cheia())
        {
            Redimensionar();
        }
        if (Vazia())
        {
            primeiro = 0;
            ultimo = 0;
        }
        ultimo = (ultimo + 1) % tam_v;
        v[ultimo] = s;
        n++;
    }

    void Desenfilar()
    {
        if (Vazia())
        {
            return;
        }

        primeiro = (primeiro + 1) % tam_v;
        n--;

        if (n == tam_v * 0.25)
        {
            Reduzir();
        }
    }

    void Imprimir()
    {
        if (Vazia())
        {
            cout << "Fila vazia!" << endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            int posicao = (primeiro + i) % tam_v;

            cout << v[posicao] << ", ";
        }
        cout << endl;

        cout << "Tamanho do vetor: " << tam_v; 
    }
};

int main(){
    try
    {

        Fila fila;
        int item;
        int opcao;

        do
        {
            cout << "digite a operaçao que deseja fazer \n";
            cout << "0: parar o programa \n";
            cout << "1: adicionar um elemento\n";
            cout << "2: remover um elemento\n";
            cout << "3: ver a Fila\n";

            cin >> opcao;
            if (opcao == 1)
            {
                cout << "Digite o elemento a ser inserido:\n";
                cin >> item;
                fila.Enfilar(item);
            }
            else if (opcao == 2)
            {
                fila.Desenfilar();
                cout << "Elemento Removido" << endl;
            }
            else if (opcao == 3)
            {
                fila.Imprimir();
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }



}
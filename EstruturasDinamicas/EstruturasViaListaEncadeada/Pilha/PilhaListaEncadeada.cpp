#include <iostream>

using namespace std;

struct Pilha
{
    struct Noh
    {
        int elem;
        Noh *prox;
    };

    Noh *topo;

    Pilha()
    {
        topo = nullptr;
    }

    bool Vazia()
    {
        return (topo == nullptr);
    }

    void Empilhar(int e)
    {
        Noh *novo = new Noh{e, topo};
        topo = novo;
    }

    void Desempilhar()
    {
        Noh *aux = topo;
        topo = topo->prox;
        delete aux;
    }

    int ConsultarTopo()
    {
        if (!Vazia())
        {
            return topo->elem;
        }
        else
        {
            return 0;
        }
    }

    void Imprimir(){
        Noh *temporario = topo;
        while(temporario != nullptr){ // enquanto não for um null pointer
            
            cout << temporario ->elem << " ";
            temporario = temporario->prox;   

        }
        cout << endl;
    }

    ~Pilha()
    {
        while (topo != nullptr)
        {
            Desempilhar();
        }
    }
};

int main()
{
    try
    {

        Pilha pilha;
        int item;
        int opcao;

        do
        {
            cout << "digite a operaçao que deseja fazer \n";
            cout << "0: parar o programa \n";
            cout << "1: adicionar um elemento\n";
            cout << "2: remover um elemento\n";
            cout << "3: ver a pilha\n";

            cin >> opcao;
            if (opcao == 1)
            {
                cout << "Digite o elemento a ser inserido:\n";
                cin >> item;
                pilha.Empilhar(item);
            }
            else if (opcao == 2)
            {
                pilha.Desempilhar();
                cout << "Elemento Removido: " << item << endl;
            }
            else if (opcao == 3)
            {
                pilha.Imprimir();
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }
}
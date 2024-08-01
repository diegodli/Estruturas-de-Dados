#include <iostream>

using namespace std;

struct Fila
{
    struct Noh
    {
        int elem;
        Noh *prox;
    };

    Noh *inicio;
    Noh *fim;

    Fila()
    {
        fim = nullptr;
        inicio = nullptr;
    }

    bool Vazia()
    {
        return (inicio == fim and inicio == nullptr);
    }

    void Enfilar(int e)
    {
        Noh *novo = new Noh;
        novo->elem = e;
        novo->prox = nullptr;
        if (Vazia())
        {
            inicio = novo;
            fim = inicio;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }

    void EnfilarInicio(int e){
        Noh *novo = new Noh {e, inicio};
        inicio = novo;
        if(Vazia()){
            fim = novo;
        }
    }

    void Desenfilar(){ // pre-condição: NÃO VAZIA
        if (!Vazia())
        {
            Noh *aux = inicio;
            inicio = inicio->prox;
            delete aux;
        }
    }

    int primeiro()
    {
        if (!Vazia())
        {
            return inicio->elem;
        }
        else
        {
            return 0;
        }
    }

    void Imprimir(){
        Noh *temp = inicio;
        while(temp != nullptr){
            cout << temp->elem << " ";
            temp = temp->prox;
        } 

        cout << endl;
    }

    ~Fila(){
        while(fim != nullptr){
            Desenfilar();

        }
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
            cout << "4: Enfilar no inicio\n";

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
            else if (opcao == 4)
            {
                cout << "Digite o elemento a ser inserido:\n";
                cin >> item;
                fila.EnfilarInicio(item);
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }
}
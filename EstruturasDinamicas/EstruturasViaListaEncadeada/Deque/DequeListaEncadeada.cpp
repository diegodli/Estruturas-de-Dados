#include <iostream>

using namespace std;

class Deque
{
    struct Noh
    {
        Noh *ant;
        int elem;
        Noh *prox;
    };

    Noh *dir;
    Noh *esq;

public:
    Deque()
    {
        esq = dir = nullptr;
    }

    bool Vazio()
    {
        return (esq == nullptr and dir == nullptr);
    }

    void InserirEsq(int e)
    {
        Noh *novo = new Noh{nullptr, e, esq};

        if (esq == nullptr)
        {
            dir = novo;
        }
        else
        {
            esq->ant = novo;
        }
        esq = novo;
    }

    void InserirDir(int e)
    {
        Noh *novo = new Noh{dir, e, nullptr};

        if (dir == nullptr)
        {
            esq = novo;
        }
        else
        {
            dir->prox = novo;
        }
        dir = novo;
    }

    void RemoverEsq()
    {
        if (!Vazio())
        {
            Noh *aux = esq;
            esq = esq->prox;

            if (esq == nullptr)
            {
                dir = nullptr;
            }
            else
            {
                esq->ant = nullptr;
            }

            delete aux;
        }
    }

    void RemoverDir(){
        if(!Vazio()){
            Noh *aux = dir;
            dir = dir->ant;

            if(dir == nullptr){  // 1 elemento
                esq = nullptr;
            }  
            else{
                dir->prox = nullptr;
            }

            delete aux;
        }
    }

    int ConsultarEsq(){
        if(!Vazio()){
            return esq->elem;
        }
        else{
            return 0;
        }
    }

    int ConsultarDir(){
        if(!Vazio()){
            return dir->elem;
        }
        else{
            return 0;
        }
    }

    void Imprimir(){
        Noh *aux = esq;

        while(aux != nullptr){
            cout << aux->elem << " ";
            aux = aux->prox;
        }

        cout << endl;
    }

    ~Deque(){
        while(esq != nullptr){
            RemoverEsq();
        }
    }
};

int main(){
    try
    {

        Deque deque;
        int item;
        int opcao;

        do
        {
            cout << "digite a operaçao que deseja fazer \n";
            cout << "0: parar o programa \n";
            cout << "1: adicionar um elemento na esquerda\n";
            cout << "2: adicionar um elemento na direita\n";
            cout << "3: remover um elemento na esquerda\n";
            cout << "4: remover um elemento na direita\n";
            cout << "5: ver o Deque\n";

            cin >> opcao;
            if (opcao == 1)
            {
                cout << "Digite o elemento a ser inserido na esquerda:\n";
                cin >> item;
                deque.InserirEsq(item);
            }
            else if (opcao == 2)
            {
                cout << "Digite o elemento a ser inserido na direita:\n";
                cin >> item;
                deque.InserirDir(item);
            }
            else if (opcao == 3)
            {
                deque.RemoverEsq();
                cout << "Elemento Removido na esquerda: " << endl;
            }
            else if (opcao == 4)
            {
                deque.RemoverDir();
                cout << "Elemento Removido na direita: " << endl;
            }
            else if (opcao == 5)
            {
                deque.Imprimir();
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }
}
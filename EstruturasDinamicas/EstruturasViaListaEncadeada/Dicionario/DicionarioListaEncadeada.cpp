#include<iostream>

using namespace std;

class Dicionario{
    struct Noh{
        int chave;
        string valor;
        Noh *prox;
    };

    Noh *inicio;

    public:

    Dicionario(){
        inicio = nullptr;
    }

    void Inserir(int c, string v){
        Noh *novo = new Noh {c, v, inicio};
        inicio = novo;
    }

    struct ResConsulta{
        bool achou;
        string valor;
    };

    ResConsulta Consultar (int c){
        ResConsulta ret;

        Noh *n = inicio;

        while(n != nullptr){
            if(n->chave == c){
                ret.achou = true;
                ret.valor = n->valor;
                return ret;
            }
            n = n->prox;
        }

        ret.achou = false;
        return ret;
    }

    void InserirSeNovo(int c, string v){
        ResConsulta r = Consultar(c);
        
        if(not r.achou){
            Inserir(c, v);
        }
    }

    void Remover(int c){
        Noh *n = inicio;

        if(n == nullptr) return;
        if(n->chave == c){
            inicio = inicio->prox;
            delete n;
            return;
        }
        while(n->prox != nullptr){
            if(n->prox->chave == c){
                Noh *p = n->prox;
                n->prox = p->prox;
                delete p;
                return;
            }
            n = n->prox;
        }
    }

    void Imprimir(){
        Noh *aux = inicio;
        while(aux != nullptr){
            cout << "| Chave: " << aux->chave << " Valor: " << aux->valor << " |";
            aux = aux->prox;
        }
    }

    ~Dicionario(){
        while(inicio != nullptr){
            Remover(inicio->chave);   
        }
    }
};


int main(){
    try
    {

        Dicionario dicionario;
        int chave;
        string valor;
        int opcao;

        do
        {
            cout << "digite a operacao que deseja fazer \n";
            cout << "0: parar o programa \n";
            cout << "1: inserir um elemento\n";
            cout << "2: inserir um elemento se for novo\n";
            cout << "3: remover um elemento\n";
            cout << "4: ver o Dicionario\n";

            cin >> opcao;
            if (opcao == 1)
            {
                cout << "Digite a chave a ser inserida:\n";
                cin >> chave;
                cout << "Digite o valor da chave:\n";
                cin >> valor;
                dicionario.Inserir(chave, valor);
            }
            else if (opcao == 2)
            {
                cout << "Digite a chave a ser inserida:\n";
                cin >> chave;
                cout << "Digite o valor da chave:\n";
                cin >> valor;
                dicionario.InserirSeNovo(chave, valor);
            }
            else if (opcao == 3)
            {
                cout << "Digite a chave a ser removida:\n";
                cin >> chave;
                dicionario.Remover(chave);
                cout << "Elemento Removido " << endl;
            }
            else if (opcao == 4)
            {
                dicionario.Imprimir();
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }
}
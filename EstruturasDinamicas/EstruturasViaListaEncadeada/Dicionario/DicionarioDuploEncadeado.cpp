#include <iostream>

using namespace std;

class Dicionario
{
    struct Noh
    {
        Noh *ant;
        int chave;
        string valor;
        Noh *prox;
    };

    Noh *inicio;

    public: 

    Dicionario()
    {
        inicio = nullptr;
    }

    bool Vazio(){
        return (inicio == nullptr);
    }

    void Inserir(int c, string v)
    {
        Noh *novo = new Noh{nullptr, c, v, inicio};
        if(!Vazio()){
            inicio->ant = novo;
        }
        inicio = novo;
        
    }

    struct ResConsulta
    {
        bool achou;
        string valor;
    };

    ResConsulta Consultar(int c)
    {
        ResConsulta ret;
        Noh *aux = inicio;
        while (aux != nullptr)
        {
            if (aux->chave == c)
            {
                ret.achou = true;
                ret.valor = aux->valor;
                return ret;
            }
            aux = aux->prox;
        }

        ret.achou = false;
        return ret;
    }

    void InserirSeNovo(int c, string v){
        ResConsulta ret = Consultar(c);
        if (ret.achou == true){
            return;
        }else{
            Inserir(c,v);
        }
    }

    void Remover(int c){
        Noh *aux = inicio;
        if(aux == nullptr){
            return;
        }
        if(aux->chave == c){
            inicio = inicio->prox;
            delete aux;
            return;
        }
        while(aux->prox != nullptr){
            if(aux->prox->chave == c){
                Noh *temp = aux->prox;
                aux->prox = temp->prox;
                Noh *temptwo = temp->prox;
                temptwo->ant = aux;
                delete temp;
                return;
            }
            aux = aux->prox;
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
        while(inicio!= nullptr){
            Remover(inicio->chave);
        }
    }
};


int main(){
    try
    {

        Dicionario dictionary;
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
                dictionary.Inserir(chave, valor);
            }
            else if (opcao == 2)
            {
                cout << "Digite a chave a ser inserida:\n";
                cin >> chave;
                cout << "Digite o valor da chave:\n";
                cin >> valor;
                dictionary.InserirSeNovo(chave, valor);
            }
            else if (opcao == 3)
            {
                cout << "Digite a chave a ser removida:\n";
                cin >> chave;
                dictionary.Remover(chave);
                cout << "Elemento Removido " << endl;
            }
            else if (opcao == 4)
            {
                dictionary.Imprimir();
            }

        } while (opcao != 0);
    }
    catch (const exception &e)
    {
        cerr << "Exceção: " << e.what() << '\n';
    }
}

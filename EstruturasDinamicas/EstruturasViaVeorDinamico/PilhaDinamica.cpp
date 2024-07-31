#include <iostream>
#include <string>
#include <exception>

using namespace std;

struct Pilha{
    int tam_v;
    string *v;
    int n;

    Pilha(){
        tam_v = 1;
        v = new string [tam_v];
        n = 0;
    }

    bool Vazia(){
        return (n == 0);
    }

    string Topo(){ //Pre-condição: pilha não vazia
        return v[n-1];
    }

    void Empilhar (string s){
        if (n == tam_v) {   //verificar se a pilha ta cheia

            int novo_tam = 2 * tam_v;

            string *w = new string [novo_tam];

            for (int i; i<n; ++i){
                w[i] = v[i];
            }

            delete[] v;
            v = w;
            tam_v = novo_tam;
        }

        v[n] = s;
        ++n;
    }

    void Desempilhar(){ // Pre-condição: pilha nao vazia
        --n;
    }

    ~Pilha (){
        delete[] v;
    }

};


int main(){
    try{
        Pilha pilha;  

        cout << "Digite linhas, terminando com linha vazia:\n\n";

        while(true){
            string linha;
            getline(cin, linha);

            if(linha == "") break;

            pilha.Empilhar(linha);
        }

        cout << "Linhas na ordem contrária\n\n";

        while(not pilha.Vazia()){
            cout << pilha.Topo() << '\n';
            pilha.Desempilhar();
        }

    }
    catch(const exception &e){
        cerr << "Exceção: " << e.what() << '\n';
    }
    
}
#include <iostream>

using namespace std;

struct Conjunto{
    static constexpr int tam_v = 5;
    char v[tam_v];
    int n;
};

void iniciar(Conjunto &C){
    C.n = 0;
}

bool cheio(Conjunto &C){
    return (C.n == C.tam_v);

}

bool vazio(Conjunto &C){
    return (C.n == 0);
}

bool pertence(Conjunto &C, char x){
    int m;
    int i,f;
    i = 0;
    f = C.n-1;

    while(i<=f){
        m = (i+f)/2;
        if(x == C.v[m]) return true;
        if(x < C.v[m]) f = m-1;
        else i = m + 1;
    }
    return false;
}

bool inserir(Conjunto &C, char x){
    if(pertence(C,x)) return false;
    if(cheio(C)) return false;
    if(vazio(C)){
        C.v[0] = x;
        C.n++;
        return true;
    }
    int i;
    for(i = C.n - 1 ; i>=0; i--){
        if(C.v[i] < x) break;
        else C.v[i+1] = C.v[i];
    }
    C.v[i+1] = x;
    C.n++;
    return true;
}

bool remover(Conjunto &C, char x){
    if(vazio(C)) return false;
    if(!pertence(C,x)) return false;
    int i;
    for(i = 0 ; i <= C.n-1 ; i++){
        if(C.v[i] == x) break;
        else C.v[i] == C.v[i+1];
    }
    C.n--;
    return true;
}

int main () {
    Conjunto C;
    iniciar(C);
    bool end{false};

    while(!end){
        cout<<"Inserir, Remover, Pertence, Sair\n";
        char opcao;
        cin>>opcao;

        if (opcao == 'I'){
            cout << "Elemento a ser inserido: \n";
            char elemento;
            cin >> elemento;
            if (inserir(C,elemento)) cout << "elemento inserido\n";
            else cout << "elemento nao inserido\n";
        }
        else if(opcao == 'R'){
            cout << "Elemento a ser removido: \n";
            char elemento;
            cin >> elemento;
            if (remover(C,elemento)) cout << "elemento removido\n";
            else cout << "elemento nao removido\n";
        }
        else if(opcao == 'P'){
            cout << "Elemento a ser verificado: \n";
            char elemento;
            cin >> elemento;
            if (pertence(C,elemento)) cout << "elemento pertence\n";
            else cout << "elemento nao pertence\n";
        }
        else if(opcao == 'S'){
            cout << C.v << "\n";
            end = true;
        } 
    }

   
    return 0;
}
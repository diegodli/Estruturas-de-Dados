#include <iostream>
#include <string>

using namespace std;

struct Par {
    int c;
    string t;
};

struct Dicionario{
    static constexpr int tam_v = 5;               
    Par v[5];
    int n;
};  

void iniciar (Dicionario &D){
    D.n == 0;
}

bool cheio(Dicionario &D){
    return (D.n == D.tam_v);
}

bool vazio(Dicionario &D){
    return (D.n == 0);
}

bool Pertence(Dicionario &D,  int x){
    for(int i = 0 ; i <= D.n-1 ; i++){
        if(D .v[i].c == x) return true;
    }
    return false;
}

bool Inserir(Dicionario &D, int x, string t){
    if (cheio(D)) return false;
    if(!Pertence(D, x)){
        D.v[D.n].c = x;
        D.v[D.n].t = t;
        D.n++; 
        return true;
    }

}

bool Remover(Dicionario &D, int x){
    if(vazio(D)) return false;
    if(!Pertence(D, x)) return false;
    for(int i = 0 ; i <= D.n - 1 ; i++){
        if(D.v[i].c == x){
            D.v[i].c = D.v[D.n-1].c;
            D.v[i].t = D.v[D.n-1].t;
            D.n--;
            return true;
        }
    }
    return false;
}

bool consultar(Dicionario &D, int x){
    if(!Pertence(D, x)) return false;
    else {
        for(int i = 0 ; i <= D.n-1 ; i++){
            if(D .v[i].c == x){
                cout << D.v[i].t << endl;
                return true;
            }      
        }   
    }
    return false;
}

int main(){
    Dicionario D;
   
    return 0;
}
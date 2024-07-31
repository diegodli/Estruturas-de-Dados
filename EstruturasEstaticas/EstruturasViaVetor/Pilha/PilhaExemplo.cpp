#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<string> pilha;

    cout << "Digite linhas, terminando com linha vazia:\n\n";

    while(true){
        string linha;
        getline(cin, linha);

        if(linha == "") break;

        pilha.push(linha);
    }

    cout << "Linhas na ordem contrária\n\n";

    while(not pilha.empty()){

        cout << pilha.top() << '\n';
        pilha.pop();
    }
}
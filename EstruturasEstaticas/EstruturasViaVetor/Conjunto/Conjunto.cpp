#include <iostream>

using namespace std;


struct Conjunto {
	static constexpr int tam_v = 5;
	int n;
	char v[tam_v];
};

void iniciar(Conjunto &C) {
	C.n = 0;
}

bool pertence(Conjunto &C, char e) {
	for (int i = 0 ; i <= C.n - 1 ; i++){
		cout<<"e: " << e << endl;
		if(C.v[i] == e) return true;
	}
	return false;
}

bool vazio(Conjunto &C){
	return (C.n == 0);
}

bool cheio(Conjunto &C) {
	return (C.n == C.tam_v);
	
}

bool inserir_novo(Conjunto &C, char e) {
	if (!cheio(C)) {
		C.v[C.n] = e;
		C.n++;
		return true;
	}
	return false;
}

bool inserir_se_novo(Conjunto &C, char e) {
	

	if (!pertence(C, e))  {
		inserir_novo(C, e);
		return true;
	}
	return false;
}

bool inserir(Conjunto &C, char e){
	if(cheio(C)) return false;

	if(!pertence(C, e)){
		C.v[C.n] = e;
		C.n++;
		return true;

	}
	else return false;
}

bool remover(Conjunto &C, char e) {
	if (vazio(C)) return false;
	cout << C.n - 1;
	for (int i = 0; i <= C.n - 1; i++) {
		if (C.v[i] == e) {
			C.v[i] = C.v[C.n - 1];
			C.n--;	
			return true;
		}
	}
	return false;
	
}



int main() {
	Conjunto  C;
	iniciar(C);
	bool end{false};

	while(!end) {
		cout << "Inserir, Remover, Pertence, Sair" << endl;
		char opcao;
		cin >> opcao;
		if (opcao == 'I') {
			cout << "elemento a inserir: " << endl;
			char elemento;
			cin >> elemento;
			if (inserir(C, elemento)) cout << "Inserido\n";
			else cout << "Elemento ja inserido ou cheio\n";
		}
		else if (opcao == 'R') {
			cout << "Elemento a remover: " << endl;
			char elemento;
			cin >> elemento;
			if (remover(C, elemento)) cout << "Removido\n";
			else cout << "Conjunto vazio\n";
		}
		else if (opcao == 'P') {
			cout << "Elemento a ser pesquisado: ";
			char elemento;
			cin >> elemento;
			if (pertence(C, elemento)) cout << "Elemento pertence\n";
			else cout << "Elemento nao pertence\n";
		}
		else if (opcao == 'S') end = true;
	}
	cout << C.v;
}
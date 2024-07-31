#include <iostream>

using namespace std;

struct Fila {
	static constexpr int tam_V = 5;
	int u, p;
	char v[tam_V];
};

void iniciar(Fila &F) {
	F.p = -1;
}

bool vazia(Fila &F) {
	if (F.p == -1) return true;
	else return false;
}

bool cheia(Fila &F) {
	if (F.p == -1) return false;
	// else if (F.p == F.u + 1 || F.p == 0 && F.u == F.tam_V - 1) return true;
	return (F.u + 1 % F.tam_V == F.p);

}

bool enfilar(Fila &F, char c) {
	if (cheia(F)) return false;

	if (F.p == -1) F.u = F.p = 0;
	
	else {
		if (F.u == F.tam_V - 1) F.u = 0;
		else ++F.u;
	}
	F.v[F.u] = c;
	return true;
}

char primeiro(Fila &F) {
	return F.v[F.p];
}


bool desenfilar(Fila &F) {
	if (F.p == -1) return false;

	if (F.u == F.p) F.p = -1;
	else F.p = (F.p + 1) % F.tam_V;
	
	return true;
}

int main() {
	
	Fila F;
	iniciar(F);
	bool end{false};

	while(!end) {
		cout << "Enfilar, Desenfilar, Primeiro, Sair";
		char opcao;
		cin >> opcao;

		if (opcao == 'E') {
			cout << "Elemento a inserir";
			char elemento;
			cin >> elemento;

			if (enfilar(F, elemento)) cout << "Enfilado.\n";
			else cout << "cheia.\n";
		}
		else if (opcao == 'D') {
			if (vazia(F)) cout << "Fila vazia.\n";
			else {
				cout << "Vai ser desenfilado:"
					<< primeiro(F)
					<< endl;
				desenfilar(F);
			}
		}
		else if (opcao == 'P') {
			if (vazia(F)) cout << "invi�vel";
			else {
				cout << "Primeiro:"
					<< primeiro(F)
					<< endl;
			}
		}
		else if (opcao == 'S') end = true;
		else {
			cout << "Opc�o inv�lida!" << endl;
		}
	}
}
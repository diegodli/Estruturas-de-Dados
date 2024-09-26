#include "aluno.h"

class Hash{
    private:

    int FuncaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int qtd_itens;
    Aluno *estrutura;

    public:

    Hash(int tam_vetor, int max);
    ~Hash();
    bool cheio();
    int ObterTamanhoAtual();
    void Inserir(Aluno aluno);
    void Deletar(Aluno aluno);
    void Buscar(Aluno& aluno, bool& busca); // vai entrar so com o ra
    void Imprimir();
};
#include <iostream>
#include "Aluno.h"

struct Noh{
    Aluno aluno;
    Noh *filhoesquerdo;
    Noh *filhodireito;
};

class ArvoreBinariadeBusca{
    private:

    Noh *raiz;

    public:

    ArvoreBinariadeBusca();
    ~ArvoreBinariadeBusca();
    void DeletarArvore(Noh *NohAtual);
    Noh * ObterRaiz();
    bool Estavazio();
    bool EstaCheio();
    void Inserir(Aluno aluno);
    void Remover(Aluno aluno);
    void Buscar(Aluno& aluno, bool& busca);
    void ImprimirPreOredem(Noh* NohAtual);
    void ImprimirEmOredem(Noh* NohAtual);
    void ImprimirPosOredem(Noh* NohAtual);
    

}
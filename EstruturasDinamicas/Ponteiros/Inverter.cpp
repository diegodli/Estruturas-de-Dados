/*Escreva uma função "void inverter (double *p, int n)" que inverta a ordem dos "n"
 elementos do vetor (cujo primeiro elemento é) apontado por "p", ou seja,
  o último número deve passar a estar na primeira posição, o penúltimo na segunda, etc. 
  Utilize a indexação de ponteiros abordada no final da aula de hoje.
*/

#include<iostream>
#include<vector>

using namespace std;

void Inverter(int *p, int n){
  int *inicio = p;
  int *fim = p + n -1;

  while (inicio < fim){
    int temp = *inicio;
    *inicio = *fim;
    *fim = temp;
    inicio++;
    fim--;

  }

}

int main(){

  int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p = & v[0];

  Inverter(p, 10);

  for(int i = 0; i < 10; i++){
    cout << v[i] << " ";
  } 

}
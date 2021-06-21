//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== C�digo elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabe�alho padr�o de entrada/sa�da
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentua��es

void bubbleSort(int vetor[], int n) {

    // 1� La�o - Acessa cada elemento do vetor[]
    for (int i = 0; i < n - 1; ++i) {

    // Verificar se a troca acontece
    int troca = 0;

    // 2� La�o - Compara os elementos do vetor[]
        for (int j = 0; j < n - i - 1; ++j) {

            // Compara 2 elementos do vetor[]
            if (vetor[j] > vetor[j+1]) {
            // Ordem Crescente: operador (>)
            // Ordem Decrescente: operador (<)

            // Realizada a troca somente quando os elementos n�o est�o ordenados
            int aux = vetor[j];
            vetor[j] = vetor[j+1];
            vetor[j+1] = aux;
            troca = 1;
            }
        }
        // Se o vetor j� estiver ordenado, n�o ser�o realizadas mais trocas
        if (troca == 0) {
        break;
        }
    }
}

void imprimeVetor(int vetor[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("| %d ", vetor[i]);
    }
    printf("|\n\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int v[] = {2, -4, 1, -5, -1, 3, 5, 4, 0, -2, -3};

    // Localiza o tamanho do vetor[]
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor - Desordenado:\n\n");
    imprimeVetor(v, n);

    printf("Vetor - Ordenado:\n\n");
    bubbleSort(v, n);
    imprimeVetor(v, n);
}

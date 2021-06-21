//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== C�digo elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabe�alho padr�o de entrada/sa�da
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentua��es

void insertionSort(int vetor[], int n) {

    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Compara a chave com cada elemento � esquerda, at� encontrar um elemento menor
        while (chave < vetor[j] && j >= 0) {
            vetor[j + 1] = vetor[j];
            --j;
            // Ordem Crescente: operador (<)
            // Ordem Decrescente: operador (>)
        }
        vetor[j + 1] = chave;
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
    insertionSort(v, n);
    imprimeVetor(v, n);
}

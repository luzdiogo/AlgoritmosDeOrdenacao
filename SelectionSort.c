//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

// Troca a posição de 2 elementos em um vetor[]
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selectionSort(int vetor[], int n) {

    // 1º Laço - Acessa cada elemento do vetor[]
    for (int i = 0; i < n - 1; i++) {
    int menor = i;

    // 2º Laço - Compara os elementos do vetor[]
        for (int j = i + 1; j < n; j++) {

            // Obtem o menor elemento em cada loop
            if (vetor[j] < vetor[menor])
                menor = j;
            // Ordem Crescente: operador (<)
            // Ordem Decrescente: operador (>)
    }
    // Troca o menor elemento e o insere na posição correta
    troca(&vetor[menor], &vetor[i]);
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
    selectionSort(v, n);
    imprimeVetor(v, n);
}

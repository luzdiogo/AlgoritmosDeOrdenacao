//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

void countingSort(int vetor[], int n) {
    int saida[10];

    // Encontra o maior elemento do vetor
    int maior = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior)
        maior = vetor[i];
    }
    int contador[10];

    // Inicia o vetor de contagem zerado
    for (int i = 0; i <= maior; ++i) {
        contador[i] = 0;
    }
    // Armazena a contagem de cada elemento
    for (int i = 0; i < n; i++) {
        contador[vetor[i]]++;
    }
    // Armazena a contagem acumulada de cada vetor
    for (int i = 1; i <= maior; i++) {
        contador[i] += contador[i - 1];
    }
    // Encontra o índice de cada elemento do vetor original no vetor de contagem, e insere-os no vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        saida[contador[vetor[i]] - 1] = vetor[i];
        contador[vetor[i]]--;
    }
    // Copia os elementos ordenados no vetor original
    for (int i = 0; i < n; i++) {
        vetor[i] = saida[i];
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
    int v[] = {4, 7, 3, 5, 9, 0, 2, 6, 1, 8};

    // Localiza o tamanho do vetor[]
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor - Desordenado:\n\n");
    imprimeVetor(v, n);

    printf("Vetor - Ordenado:\n\n");
    countingSort(v, n);
    imprimeVetor(v, n);
}

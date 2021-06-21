//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== C�digo elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabe�alho padr�o de entrada/sa�da
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentua��es

// Troca a posi��o de 2 elementos em um vetor[]
void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Encontra a posi��o da parti��o
int particao(int vetor[], int menor, int maior) {

    // Seleciona o elemento mais � direita como piv�
    int pivo = vetor[maior];

    // Ponteiro para o maior elemento
    int i = (menor - 1);

    // Percorre cada elemento do vetor e os compara com o piv�
    for (int j = menor; j < maior; j++) {
        if (vetor[j] <= pivo) {

        // Caso encontre um elemento menor que o piv�, troca pelo maior elemento apontado por i
        i++;

        // Troca o elemento em i com o elemento em j
        troca(&vetor[i], &vetor[j]);
        }
    }
    // Troca o elemento piv� com o maior elemento em i
    troca(&vetor[i + 1], &vetor[maior]);

    return (i + 1);
}

void quickSort(int vetor[], int menor, int maior) {
    if (menor < maior) {

    // Elementos menores que o piv� est�o � esquerda do piv�
    // Elementos maiores que o piv� est�o � direita do piv�
    int pivo = particao(vetor, menor, maior);

    // Localiza � esquerda do piv�
    quickSort(vetor, menor, pivo - 1);

    // Localiza � direita do piv�
    quickSort(vetor, pivo + 1, maior);
  }
}

void imprimeVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
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
    quickSort(v, 0, n - 1);
    imprimeVetor(v, n);
}

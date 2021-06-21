//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

// Mesclar dois sub-vetores L e M em um vetor
void merge(int vetor[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vetor[p + i];

    for (int j = 0; j < n2; j++)
        M[j] = vetor[q + 1 + j];

    // Mantém o índice atual de sub-vetores e do vetor principal
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Verifica as extremidades de L ou M, e os insere em suas posições
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            vetor[k] = L[i];
            i++;
        }
        else {
            vetor[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = M[j];
        j++;
        k++;
    }
}

// Divide o vetor em dois sub-vetores, ordenando e mesclando
void mergeSort(int vetor[], int l, int r) {
    if (l < r) {

    // M é o ponto onde o vetor é dividido em dois sub-vetores
    int m = l + (r - l) / 2;

    mergeSort(vetor, l, m);
    mergeSort(vetor, m + 1, r);

    // Mescla os sub-vetores e os ordena
    merge(vetor, l, m, r);
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
    mergeSort(v, 0, n - 1);
    imprimeVetor(v, n);
}

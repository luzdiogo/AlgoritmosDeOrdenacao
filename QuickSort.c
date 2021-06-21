//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

// Troca a posição de 2 elementos em um vetor[]
void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Encontra a posição da partição
int particao(int vetor[], int menor, int maior) {

    // Seleciona o elemento mais à direita como pivô
    int pivo = vetor[maior];

    // Ponteiro para o maior elemento
    int i = (menor - 1);

    // Percorre cada elemento do vetor e os compara com o pivô
    for (int j = menor; j < maior; j++) {
        if (vetor[j] <= pivo) {

        // Caso encontre um elemento menor que o pivô, troca pelo maior elemento apontado por i
        i++;

        // Troca o elemento em i com o elemento em j
        troca(&vetor[i], &vetor[j]);
        }
    }
    // Troca o elemento pivô com o maior elemento em i
    troca(&vetor[i + 1], &vetor[maior]);

    return (i + 1);
}

void quickSort(int vetor[], int menor, int maior) {
    if (menor < maior) {

    // Elementos menores que o pivô estão à esquerda do pivô
    // Elementos maiores que o pivô estão à direita do pivô
    int pivo = particao(vetor, menor, maior);

    // Localiza à esquerda do pivô
    quickSort(vetor, menor, pivo - 1);

    // Localiza à direita do pivô
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

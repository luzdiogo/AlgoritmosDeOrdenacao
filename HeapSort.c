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

void empilhar(int vetor[], int n, int i) {

    // Encontra o maior entre a esquerda e a direita
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    // Troca e continua empilhando
    if (maior != i) {
        troca(&vetor[i], &vetor[maior]);
        empilhar(vetor, n, maior);
    }
}

void heapSort(int vetor[], int n) {

    // Empilha ao máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        empilhar(vetor, n, i);

    // Ordena em pilha
    for (int i = n - 1; i >= 0; i--) {
        troca(&vetor[0], &vetor[i]);

    empilhar(vetor, i, 0);
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
    heapSort(v, n);
    imprimeVetor(v, n);
  }

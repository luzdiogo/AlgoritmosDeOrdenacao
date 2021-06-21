//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

void bubbleSort(int vetor[], int n) {

    // 1º Laço - Acessa cada elemento do vetor[]
    for (int i = 0; i < n - 1; ++i) {

    // Verificar se a troca acontece
    int troca = 0;

    // 2º Laço - Compara os elementos do vetor[]
        for (int j = 0; j < n - i - 1; ++j) {

            // Compara 2 elementos do vetor[]
            if (vetor[j] > vetor[j+1]) {
            // Ordem Crescente: operador (>)
            // Ordem Decrescente: operador (<)

            // Realizada a troca somente quando os elementos não estão ordenados
            int aux = vetor[j];
            vetor[j] = vetor[j+1];
            vetor[j+1] = aux;
            troca = 1;
            }
        }
        // Se o vetor já estiver ordenado, não serão realizadas mais trocas
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

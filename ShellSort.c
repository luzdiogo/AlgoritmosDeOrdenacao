//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

void shellSort(int vetor[], int n) {

    // Reorganiza os elementos a cada n intervalos
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i += 1) {
            int aux = vetor[i];
            int j;

        for (j = i; j >= intervalo && vetor[j - intervalo] > aux; j -= intervalo) {
            vetor[j] = vetor[j - intervalo];
        }
        vetor[j] = aux;
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
    int v[] = {4, 7, 3, 5, 9, 0, 2, 6, 1, 8};

    // Localiza o tamanho do vetor[]
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor - Desordenado:\n\n");
    imprimeVetor(v, n);

    printf("Vetor - Ordenado:\n\n");
    shellSort(v, n);
    imprimeVetor(v, n);
}

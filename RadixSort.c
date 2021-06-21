//  ==========                             ==========
//  ========== https://github.com/luzdiogo ==========
//  ==========                             ==========
//  ==== Código elaborado para fins educacionais ====
//  ==========                             ==========

#include <stdio.h>  //Cabeçalho padrão de entrada/saída
#include <locale.h> //Biblioteca para linguagem nativa e/ou acentuações

int obtemMaior(int vetor[], int n) {
    int maior = vetor[0];

    for (int i = 1; i < n; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    return maior;
}

//Ordenação por contagem (Otimizado)
void countingSort(int vetor[], int n, int local) {
    int saida[n + 1];
    int maior = (vetor[0] / local) % 10;

    for (int i = 1; i < n; i++) {
        if (((vetor[i] / local) % 10) > maior)
            maior = vetor[i];
    }
    int contador[maior + 1];

    for (int i = 0; i < maior; ++i)
        contador[i] = 0;

    // Calcula a contagem de elementos
    for (int i = 0; i < n; i++)
        contador[(vetor[i] / local) % 10]++;

    // Calcula a contagem acumulada
    for (int i = 1; i < 10; i++)
        contador[i] += contador[i - 1];

    // Coloca os elementos ordenados
    for (int i = n - 1; i >= 0; i--) {
        saida[contador[(vetor[i] / local) % 10] - 1] = vetor[i];
        contador[(vetor[i] / local) % 10]--;
    }
    for (int i = 0; i < n; i++)
        vetor[i] = saida[i];
}

void radixsort(int vetor[], int n) {
    // Obtém o maior elemento
    int maior = obtemMaior(vetor, n);

    // Aplica a ordenação por contagem para ordenar os elementos com base no valor local.
    for (int local = 1; maior / local > 0; local *= 10)
        countingSort(vetor, n, local);
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
    radixsort(v, n);
    imprimeVetor(v, n);
}

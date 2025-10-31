#include <stdio.h>
#include <stdlib.h>

void insertSort(int matriz[], int tamanho);
void imprimirMatriz(int matriz[], int tamanho);

void insertSort(int matriz[], int tamanho) {
    int i, key, j;
    for (i = 1; i < tamanho; i++) {
        key = matriz[i];
        j = i - 1;

        while (j >= 0 && matriz[j] > key) {
            matriz[j + 1] = matriz[j];
            j = j - 1;
        }
        matriz[j + 1] = key;
    }
}

void imprimirMatriz(int matriz[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", matriz[i]);
    }
    printf("\n");
}

int main() {
    int minhaMatriz[] = {12, 11, 13, 5, 6, 7, 2};
    int n = sizeof(minhaMatriz) / sizeof(minhaMatriz[0]);

    printf("Array original: \n");
    imprimirMatriz(minhaMatriz, n);

    insertSort(minhaMatriz, n);

    printf("\nArray ordenado (Insertion Sort): \n");
    imprimirMatriz(minhaMatriz, n);

    return 0;
}

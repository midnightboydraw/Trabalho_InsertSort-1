#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

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
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    int escolha;
    int tamanho = 0;

    printf("Escolha o tamanho do array:\n");
    printf("1: 100 elementos\n");
    printf("2: 1000 elementos\n");
    printf("3: 10000 elementos\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            tamanho = 100;
            break;
        case 2:
            tamanho = 1000;
            break;
        case 3:
            tamanho = 10000;
            break;
        default:
            printf("Opção inválida.\n");
            return 1; // Encerra com erro
    }

    // Aloca memória dinamicamente para o array
    int* minhaMatriz = (int*)malloc(tamanho * sizeof(int));
    if (minhaMatriz == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    }

    // Preenche o array com números aleatórios (0 a 9999)
    for (int i = 0; i < tamanho; i++) {
        minhaMatriz[i] = rand() % 10000;
    }

    if (tamanho <= 100) {
        printf("Array original: \n");
        imprimirMatriz(minhaMatriz, tamanho);
    } else {
        printf("Array original de %d elementos criado (grande demais para imprimir).\n", tamanho);
    }

    clock_t start = clock();
    insertSort(minhaMatriz, tamanho);
    clock_t end = clock();

    double tempoDecorrido = (double)(end - start) / CLOCKS_PER_SEC;

    if (tamanho <= 100) {
        printf("\nArray ordenado: \n");
        imprimirMatriz(minhaMatriz, tamanho);
    } else {
        printf("\nArray ordenado.\n");
    }
    
    printf("\nTempo de execução (C) para %d elementos: %.10f segundos\n", tamanho, tempoDecorrido); 

    // Libera a memória alocada
    free(minhaMatriz);

    return 0;
}

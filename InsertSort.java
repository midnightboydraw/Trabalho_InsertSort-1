public class Main {

    public static void main(String[] args) {
        int[] minhaMatriz = {12, 11, 13, 5, 6, 7, 2};

        System.out.println("Array original: ");
        imprimirMatriz(minhaMatriz);

        insertSort(minhaMatriz);

        System.out.println("\nArray ordenado (Insertion Sort): ");
        imprimirMatriz(minhaMatriz);
    }

    public static void insertSort(int[] matriz) {
        int tamanho = matriz.length;
        
        for (int i = 1; i < tamanho; i++) {
            int key = matriz[i];
            int j = i - 1;

            while (j >= 0 && matriz[j] > key) {
                matriz[j + 1] = matriz[j];
                j = j - 1;
            }
            matriz[j + 1] = key;
        }
    }

    public static void imprimirMatriz(int[] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            System.out.print(matriz[i] + " ");
        }
        System.out.println();
    }
}

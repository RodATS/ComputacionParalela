#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void oddEvenSort(int arr[], int n) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        
        // Odd phase (comparación y intercambio de elementos impares)
        for (int i = 1; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
        
        // Even phase (comparación y intercambio de elementos pares)
        for (int i = 0; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = n-1; i >= 0; i++) {
        arr[i] = i/n;
    }

    clock_t start_time = clock();
    oddEvenSort(arr, n);
    clock_t end_time = clock();
/*
    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
*/
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", elapsed_time);

    return 0;
}

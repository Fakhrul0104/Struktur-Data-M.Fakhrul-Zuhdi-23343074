//Created by_M.Fakhrul Zuhdi 23343074
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    int *fibonacci = (int*)malloc(n * sizeof(int)); // Alokasi memori untuk array bilangan Fibonacci

    if (fibonacci == NULL) {
        printf("Error: Tidak dapat mengalokasikan memori\n");
        return;
    }

    // Menghitung bilangan Fibonacci
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Mencetak bilangan Fibonacci hingga ke-n
    printf("Deret Fibonacci hingga %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    free(fibonacci); // Membebaskan memori yang dialokasikan
}

int main() {
    int n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Input tidak valid\n");
        return 1;
    }

    printFibonacci(n);

    return 0;
}

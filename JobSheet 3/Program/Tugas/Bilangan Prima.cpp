//Created by_M.Fakhrul Zuhdi 23343074
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan prima
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Fungsi untuk mencetak bilangan prima pertama hingga ke-n
void printPrimes(int n, int m) {
    int count = 0;
    int *primes = (int*)malloc(n * sizeof(int)); // Alokasi memori untuk array bilangan prima

    if (primes == NULL) {
        printf("Error: Tidak dapat mengalokasikan memori\n");
        return;
    }

    // Mengisi array dengan bilangan prima
    for (int num = 2; count < n; num++) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
    }

    // Mencetak bilangan prima hingga ke-n
    printf("Bilangan prima hingga %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Realokasi memori berdasarkan input m
    primes = (int*)realloc(primes, m * sizeof(int));

    if (primes == NULL) {
        printf("Error: Tidak dapat mengalokasikan memori kembali\n");
        return;
    }

    // Mencetak ulang bilangan prima setelah realokasi
    printf("Bilangan prima setelah realokasi hingga %d:\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes); // Membebaskan memori yang dialokasikan
}

int main() {
    int n, m;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Input tidak valid\n");
        return 1;
    }

    printf("Masukkan ukuran baru m: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Error: Input tidak valid\n");
        return 1;
    }

    printPrimes(n, m);

    return 0;
}

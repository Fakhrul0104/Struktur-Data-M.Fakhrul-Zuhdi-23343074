#include <stdio.h>
#include <conio.h>

int main() {
    int usia1 = 50;
    int usia2 = 18;

    // Menciptakan sebuah pointer
    int *ptr;

    // Menugaskan pointer tersebut kepada usia1
    ptr = &usia1;

    printf("\nUsia saya (usia1): %d ", usia1); // Menampilkan 50
    printf("\nUsia saya (*ptr): %d", *ptr); // Menampilkan 50

    // *ptr merupakan nilai yang disimpan ptr, yaitu 50
    printf("\n(&usia1) %p (ptr) %p", &usia1, ptr);
    // ptr adalah alamat dari usia1 jadi juga merupakan &usia1. Keduanya sama.

    // Sekarang Anda akan menugaskannya kepada usia2
    ptr = &usia2;

    printf("\nUsia Anda (*ptr): %d", *ptr); // Menampilkan 18
    // *ptr merupakan nilai yang disimpan ptr, yaitu 18
    printf("\n(&usia2) %p (ptr) %p", &usia2, ptr);
    // ptr adalah alamat dari usia2 jadi juga merupakan &usia2. Keduanya sama

    // Menampilkan alamat dari variabel ptr. Anda tidak memerlukan
    // alamat ini.
    printf("\n(&ptr) %p", &ptr);

    getch();
    return 0;
}

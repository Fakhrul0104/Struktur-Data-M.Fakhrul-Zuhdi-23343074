#include <stdio.h>
#include <conio.h>

typedef int angka;
typedef char huruf;

int main() {
    angka umur;
    huruf h;
    huruf nama[10];

    printf("Masukkan umur anda : ");
    scanf("%d", &umur);
    printf("Umur anda adalah %d\n", umur);

    printf("Masukkan huruf : ");
    h = getch(); 
    
    printf("\nHuruf anda %c\n", h);

    printf("Masukkan nama : ");
    scanf("%s", nama);
    printf("Nama anda %s\n", nama);

    getch(); 
    return 0;
}

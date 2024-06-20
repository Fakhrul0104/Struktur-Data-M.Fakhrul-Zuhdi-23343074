//Created by M.Fakhrul Zuhdi
#include <stdio.h>

#define ukuran 6
int queue[ukuran]; // deklarasi array
int front = -1;
int rear = -1;

// fungsi untuk menambahkan elemen pada circular queue
void enqueue(int element) {
    if ((rear + 1) % ukuran == front) { // kondisi untuk mengecek apakah queue penuh
        printf("Antrian telah penuh.\n");
    } else {
        if (front == -1 && rear == -1) { // kondisi untuk mengecek apakah queue kosong
            front = 0;
            rear = 0;
            queue[rear] = element;
        } else {
            rear = (rear + 1) % ukuran; // nilai pada rear bertambah
            queue[rear] = element; // memberikan nilai pada queue posisi rear
        }
        printf("Elemen %d berhasil ditambahkan.\n", element);
    }
}

// fungsi untuk menghapus elemen dari queue
void dequeue() {
    if (front == -1 && rear == -1) { // kondisi untuk mengecek apakah queue kosong
        printf("Queue kosong.\n");
    } else if (front == rear) {
        printf("Elemen yang di-dequeue adalah %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Elemen yang di-dequeue adalah %d\n", queue[front]);
        front = (front + 1) % ukuran;
    }
}

// fungsi untuk menampilkan elemen queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue kosong.\n");
    } else {
        printf("Elemen pada queue adalah: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % ukuran;
        }
        printf("%d ", queue[rear]);
        printf("\n");
    }
}

int main() {
    int menu = 1, x; // deklarasi variabel

    while (menu < 4 && menu != 0) { // looping menggunakan while
        printf("\n****************Circular Queue********************\n");
        printf("\n==================================================\n");
        printf("\n1: Tambah sebuah elemen");
        printf("\n2: Hapus sebuah elemen");
        printf("\n3: Tampilkan elemen");
        printf("\n4: Keluar");
        printf("\nMasukkan pilihanmu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Silakan masukkan elemen yang ingin kamu tambah: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Masukkan pilihan menu yang sesuai.\n");
                break;
        }
    }
    return 0;
}

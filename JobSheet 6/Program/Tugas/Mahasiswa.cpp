//Created by_M.Fakhrul Zuhdi_23343074
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data mahasiswa
struct Mahasiswa {
    char nim[20];
    char nama[50];
    float nilai;
};

// Node untuk stack
struct Node {
    struct Mahasiswa data;
    struct Node* next;
};

struct Node* top = NULL; // Pointer ke node paling atas (top) dari stack

// Fungsi untuk mengecek apakah stack kosong
int isEmpty() {
    return top == NULL;
}

// Fungsi untuk menambahkan data mahasiswa ke stack
void push(struct Mahasiswa mhs) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = mhs;
    newNode->next = top;
    top = newNode;
}

// Fungsi untuk mengambil data mahasiswa dari stack
struct Mahasiswa pop() {
    if (isEmpty()) {
        printf("Stack kosong.\n");
        exit(1);
    }
    struct Node* temp = top;
    struct Mahasiswa popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Fungsi untuk menampilkan data mahasiswa yang ada dalam stack
void display() {
    if (isEmpty()) {
        printf("Stack kosong.\n");
        return;
    }
    struct Node* temp = top;
    printf("Data Mahasiswa dalam Stack:\n");
    while (temp != NULL) {
        printf("NIM: %s\n", temp->data.nim);
        printf("Nama: %s\n", temp->data.nama);
        printf("Nilai: %.2f\n\n", temp->data.nilai);
        temp = temp->next;
    }
}

// Fungsi untuk membandingkan dua data mahasiswa berdasarkan nilai (untuk keperluan sorting)
int compareMahasiswa(const void* a, const void* b) {
    float nilaiA = (*(struct Mahasiswa*)a).nilai;
    float nilaiB = (*(struct Mahasiswa*)b).nilai;
    if (nilaiA < nilaiB) return -1;
    else if (nilaiA > nilaiB) return 1;
    else return 0;
}

// Fungsi untuk melakukan sorting data mahasiswa dalam stack berdasarkan nilai
void sortStack() {
    if (isEmpty()) {
        printf("Stack kosong.\n");
        return;
    }

    int size = 0;
    struct Node* temp = top;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    struct Mahasiswa* arr = (struct Mahasiswa*)malloc(size * sizeof(struct Mahasiswa));

    temp = top;
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    qsort(arr, size, sizeof(struct Mahasiswa), compareMahasiswa);

    // Mengosongkan stack
    while (!isEmpty()) {
        pop();
    }

    // Menambahkan data yang telah diurutkan kembali ke stack
    for (int j = 0; j < size; j++) {
        push(arr[j]);
    }

    free(arr);
}

int main() {
    int choice;
    struct Mahasiswa mhs;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Ambil Data Mahasiswa (POP)\n");
        printf("3. Tampilkan Data Mahasiswa dalam Stack\n");
        printf("4. Urutkan Data Mahasiswa Berdasarkan Nilai\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Masukkan NIM: ");
            scanf("%s", mhs.nim);
            printf("Masukkan Nama: ");
            scanf(" %[^\n]", mhs.nama); // Menggunakan " %[^\n]" untuk membaca spasi dalam nama
            printf("Masukkan Nilai: ");
            scanf("%f", &mhs.nilai);
            push(mhs);
            break;
        case 2:
            mhs = pop();
            printf("Data Mahasiswa yang diambil (POP):\n");
            printf("NIM: %s\n", mhs.nim);
            printf("Nama: %s\n", mhs.nama);
            printf("Nilai: %.2f\n", mhs.nilai);
            break;
        case 3:
            display();
            break;
        case 4:
            sortStack();
            printf("Data Mahasiswa dalam Stack telah diurutkan berdasarkan nilai.\n");
            break;
        case 5:
            printf("Program Selesai.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}

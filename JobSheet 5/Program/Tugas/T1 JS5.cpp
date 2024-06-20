#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk data buku
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Buku *prev;
    struct Buku *next;
};

// Fungsi untuk menambah simpul baru pada linked list
void tambahSimpul(struct Buku **head, char judul[], char pengarang[], int tahun) {
    // Mengalokasikan memori untuk simpul baru
    struct Buku *newBuku = (struct Buku *)malloc(sizeof(struct Buku));
    strcpy(newBuku->judul, judul);
    strcpy(newBuku->pengarang, pengarang);
    newBuku->tahun = tahun;
    newBuku->prev = NULL;
    newBuku->next = *head;

    // Mengubah pointer prev dari simpul pertama jika ada
    if (*head != NULL) {
        (*head)->prev = newBuku;
    }

    // Mengubah head menjadi simpul baru
    *head = newBuku;
}

// Fungsi untuk menghapus simpul berdasarkan judul buku
void hapusSimpul(struct Buku **head, char judul[]) {
    struct Buku *current = *head;
    // Mencari simpul dengan judul buku yang sesuai
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            // Menghapus simpul
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Simpul dengan judul '%s' telah dihapus.\n", judul);
            return;
        }
        current = current->next;
    }
    printf("Simpul dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menampilkan semua simpul pada linked list
void tampilkanSimpul(struct Buku *head) {
    struct Buku *current = head;
    printf("Daftar Buku:\n");
    while (current != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", current->judul, current->pengarang, current->tahun);
        current = current->next;
    }
}

int main() {
    struct Buku *head = NULL;

    // Menambahkan beberapa data buku ke linked list
    tambahSimpul(&head, "Harry Potter", "J.K. Rowling", 1997);
    tambahSimpul(&head, "The Lord of the Rings", "J.R.R. Tolkien", 1954);
    tambahSimpul(&head, "To Kill a Mockingbird", "Harper Lee", 1960);

    // Menampilkan data buku sebelum penghapusan
    tampilkanSimpul(head);

    // Menghapus sebuah buku berdasarkan judul
    hapusSimpul(&head, "The Lord of the Rings");

    // Menampilkan data buku setelah penghapusan
    tampilkanSimpul(head);

    return 0;
}

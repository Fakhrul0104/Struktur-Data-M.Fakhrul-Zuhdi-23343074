#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data mobil
struct Mobil {
    char noPlat[20];
    char merk[50];
    char pemilik[100];
    struct Mobil *next;
    struct Mobil *prev;
};

// Fungsi untuk membuat node baru
struct Mobil *buatNodeMobil(char *noPlat, char *merk, char *pemilik) {
    struct Mobil *mobilBaru = (struct Mobil *)malloc(sizeof(struct Mobil));
    if (mobilBaru == NULL) {
        printf("Error: Alokasi memori gagal.\n");
        exit(1);
    }
    strcpy(mobilBaru->noPlat, noPlat);
    strcpy(mobilBaru->merk, merk);
    strcpy(mobilBaru->pemilik, pemilik);
    mobilBaru->next = NULL;
    mobilBaru->prev = NULL;
    return mobilBaru;
}

// Fungsi untuk menambahkan mobil ke antrian parkir
void tambahMobil(struct Mobil **head, char *noPlat, char *merk, char *pemilik) {
    struct Mobil *mobilBaru = buatNodeMobil(noPlat, merk, pemilik);
    if (*head == NULL) {
        *head = mobilBaru;
    } else {
        struct Mobil *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = mobilBaru;
        mobilBaru->prev = temp;
    }
}

// Fungsi untuk mencari mobil berdasarkan nomor plat dan mengembalikan node yang sesuai
struct Mobil *cariMobil(struct Mobil *head, char *noPlat) {
    struct Mobil *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->noPlat, noPlat) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Fungsi untuk menghapus mobil dari antrian parkir berdasarkan nomor plat
void hapusMobil(struct Mobil **head, char *noPlat) {
    struct Mobil *mobilHapus = cariMobil(*head, noPlat);
    if (mobilHapus == NULL) {
        printf("Error: Mobil dengan nomor plat '%s' tidak ditemukan.\n", noPlat);
        return;
    }

    if (mobilHapus->prev == NULL) {
        *head = mobilHapus->next;
    } else {
        mobilHapus->prev->next = mobilHapus->next;
    }

    if (mobilHapus->next != NULL) {
        mobilHapus->next->prev = mobilHapus->prev;
    }

    free(mobilHapus);
}

// Fungsi untuk mencetak semua mobil dalam antrian parkir
void cetakMobil(struct Mobil *head) {
    printf("Antrian Parkir:\n");
    struct Mobil *temp = head;
    while (temp != NULL) {
        printf("Nomor Plat: %s\n", temp->noPlat);
        printf("Merk: %s\n", temp->merk);
        printf("Pemilik: %s\n\n", temp->pemilik);
        temp = temp->next;
    }
}

int main() {
    struct Mobil *antrianParkir = NULL;

    // Tambahkan mobil ke dalam antrian parkir
    tambahMobil(&antrianParkir, "B 1234 ABC", "Toyota", "John Doe");
    tambahMobil(&antrianParkir, "B 5678 XYZ", "Honda", "Jane Doe");
    tambahMobil(&antrianParkir, "B 9876 DEF", "Ford", "Alice Smith");

    // Cetak semua mobil dalam antrian parkir
    cetakMobil(antrianParkir);

    // Hapus mobil dengan nomor plat "B 5678 XYZ" dari antrian parkir
    hapusMobil(&antrianParkir, "B 5678 XYZ");

    // Cetak semua mobil setelah penghapusan
    printf("\nSetelah menghapus mobil 'B 5678 XYZ':\n");
    cetakMobil(antrianParkir);

    return 0;
}

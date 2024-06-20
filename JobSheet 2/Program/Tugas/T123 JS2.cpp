//Created by_M.Fakhrul Zuhdi 23343074
#include <stdio.h>

// Struct untuk data mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mhs) {
    printf("Masukkan NIM: ");
    scanf("%d", &(mhs->NIM));

    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", mhs->Nama);

    printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
    scanf(" %[^\n]s", mhs->TanggalLahir);

    printf("Masukkan IPK: ");
    scanf("%f", &(mhs->IPK));
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa mhs) {
    printf("\nData Mahasiswa\n");
    printf("NIM: %d\n", mhs.NIM);
    printf("Nama: %s\n", mhs.Nama);
    printf("Tanggal Lahir: %s\n", mhs.TanggalLahir);
    printf("IPK: %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs1;

    // Input data mahasiswa
    inputDataMahasiswa(&mhs1);

    // Menampilkan data mahasiswa
    tampilkanDataMahasiswa(mhs1);

    return 0;
}

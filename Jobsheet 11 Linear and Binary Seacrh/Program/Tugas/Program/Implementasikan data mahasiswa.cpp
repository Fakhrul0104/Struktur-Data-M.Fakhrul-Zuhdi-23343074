//Created by M.Fakhrul Zuhid_23343074
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int nim;
    char nama[50];
    char ttl[50];
    float ipk;
} Mahasiswa;

// Fungsi untuk mencetak data mahasiswa
void printMahasiswa(Mahasiswa mhs) {
    printf("NIM : %d\n", mhs.nim);
    printf("Nama: %s\n", mhs.nama);
    printf("TTL : %s\n", mhs.ttl);
    printf("IPK : %.2f\n", mhs.ipk);
}

// Fungsi untuk melakukan sequential search
int sequentialSearch(Mahasiswa mhs[], int n, int nim) {
    for (int i = 0; i < n; i++) {
        if (mhs[i].nim == nim)
            return i;
    }
    return -1;
}

// Fungsi untuk melakukan binary search
int binarySearch(Mahasiswa mhs[], int l, int r, int nim) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (mhs[m].nim == nim)
            return m;

        if (mhs[m].nim < nim)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan NIM menggunakan Bubble Sort
void bubbleSort(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].nim > mhs[j + 1].nim) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

int main() {
    Mahasiswa mhs[MAX];
    int n, nim, index;
    char method[10];

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    getchar(); // Menghapus newline character dari buffer

    for (int i = 0; i < n; i++) {
        printf("Masukkan data mahasiswa ke-%d:\n", i + 1);
        printf("NIM  : ");
        scanf("%d", &mhs[i].nim);
        getchar(); // Menghapus newline character dari buffer

        printf("Nama : ");
        fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
        mhs[i].nama[strcspn(mhs[i].nama, "\n")] = 0; // Menghapus newline character dari string

        printf("TTL  : ");
        fgets(mhs[i].ttl, sizeof(mhs[i].ttl), stdin);
        mhs[i].ttl[strcspn(mhs[i].ttl, "\n")] = 0; // Menghapus newline character dari string

        printf("IPK  : ");
        scanf("%f", &mhs[i].ipk);
        getchar(); // Menghapus newline character dari buffer
    }

    printf("Masukkan NIM yang ingin dicari: ");
    scanf("%d", &nim);
    getchar(); // Menghapus newline character dari buffer

    printf("Metode pencarian (sequential/binary): ");
    fgets(method, sizeof(method), stdin);
    method[strcspn(method, "\n")] = 0; // Menghapus newline character dari string

    if (strcmp(method, "sequential") == 0) {
        index = sequentialSearch(mhs, n, nim);
    } else if (strcmp(method, "binary") == 0) {
        bubbleSort(mhs, n); // Mengurutkan array sebelum melakukan binary search
        index = binarySearch(mhs, 0, n - 1, nim);
    } else {
        printf("Metode pencarian tidak valid!\n");
        return 1;
    }

    if (index != -1) {
        printf("Data mahasiswa ditemukan:\n");
        printMahasiswa(mhs[index]);
    } else {
        printf("Data mahasiswa dengan NIM %d tidak ditemukan.\n", nim);
    }

    return 0;
}

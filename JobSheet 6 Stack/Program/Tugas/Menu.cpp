//Created by_M.Fakhrul Zuhdi_23343074
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk stack
struct Node {
    char data;
    struct Node* next;
};

// Pointer top untuk menunjukkan node paling atas (top) dari stack
struct Node* top = NULL;

// Fungsi untuk mengecek apakah stack kosong
int isEmpty() {
    return top == NULL;
}

// Fungsi untuk menambahkan karakter ke dalam stack
void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

// Fungsi untuk menghapus karakter dari stack dan mengembalikan karakter yang dihapus
char pop() {
    if (isEmpty()) {
        printf("Stack kosong.\n");
        exit(1);
    }
    struct Node* temp = top;
    char popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Fungsi untuk membalikkan kata dengan menggunakan stack
void reverseWord(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        push(word[i]);
    }
    for (int i = 0; i < length; i++) {
        word[i] = pop();
    }
}

int main() {
    int choice;
    char word[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Masukkan kata: ");
            scanf("%s", word);
            break;
        case 2:
            if (strlen(word) == 0) {
                printf("Kata belum dimasukkan.\n");
            } else {
                reverseWord(word);
                printf("Kata setelah dibalik: %s\n", word);
            }
            break;
        case 3:
            printf("Program Selesai.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}

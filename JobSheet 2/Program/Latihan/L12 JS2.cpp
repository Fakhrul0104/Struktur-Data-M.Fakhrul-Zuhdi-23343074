#include <stdio.h>

struct level5 {
    int data5;
};

struct level4 {
    struct level5 nested5;
    float data4;
};

struct level3 {
    struct level4 nested4;
    char data3;
};

struct level2 {
    struct level3 nested3;
    double data2;
};

struct level1 {
    struct level2 nested2;
    int data1;
};

int main() {
    struct level1 nested1;

    nested1.data1 = 10;
    nested1.nested2.data2 = 3.14;
    nested1.nested2.nested3.data3 = 'A';
    nested1.nested2.nested3.nested4.data4 = 5.67;
    nested1.nested2.nested3.nested4.nested5.data5 = 100;

    printf("Data 1: %d\n", nested1.data1);
    printf("Data 2: %.2f\n", nested1.nested2.data2);
    printf("Data 3: %c\n", nested1.nested2.nested3.data3);
    printf("Data 4: %.2f\n", nested1.nested2.nested3.nested4.data4);
    printf("Data 5: %d\n", nested1.nested2.nested3.nested4.nested5.data5);

    return 0;
}

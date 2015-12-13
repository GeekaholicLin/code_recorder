#include <stdio.h>
int a[16] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 34, 71, 79, 97, 103};

void display() {
    int i;
    for (i = 0; i < 16; i++) printf("%d ", a[i]);
}

int main() {
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < 16; i++) {
        if (n <= a[i]) {
            for (j = 15; j > i; j--) {
                a[j] = a[j - 1];
            }
            a[i]=n;
            break;
        }
        if (i == 15) {
            a[15] = n;
        }
    }
    display();
    return 0;
} 
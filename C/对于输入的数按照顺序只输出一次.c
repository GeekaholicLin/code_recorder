#include <stdio.h>

int main() {
    int a[10];
    int i, j;
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++) {
        
        for (j = i + 1; j < 10; j++) {
            if (a[i] == a[j]) {
                a[j]=-999;
            }
        }
       
    }
    for(i=0;i<10;i++){
        if(a[i]!=-999)
        printf("%d\n",a[i]);
    }
    return 0;
} 
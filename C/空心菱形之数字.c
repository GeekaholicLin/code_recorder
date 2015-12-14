#include <stdio.h>
#include<math.h>
int main() {
    int n,half;
    scanf("%d",&n);
    int i,j;
    half=(n+1)/2;
    for (i = 1; i <=n; i++) {
       
        for (j = 1; j<=n; j++) {
            if(j==half+1-i||j==half-(n-i)||2*half-j==half+1-i||2*half-j==half-(n-i)){
                if(i<=half) printf("%d",i);
                else printf("%d",(n+1)-i);
            }
               
            else printf(" ");
        }
        printf("\n");

    }

return 0;
} 
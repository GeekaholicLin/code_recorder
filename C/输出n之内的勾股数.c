#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a, b, c;
    for(a=1;a<=n;a++){
        for(b=a+1;b<=n;b++){
            for(c=b+1;c<=n;c++){
                if(a*a+b*b==c*c)
                    printf("%d %d %d\n",a,b,c);
            }
        }
    }

    return 0;
}


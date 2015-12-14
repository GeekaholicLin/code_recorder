#include<stdio.h>
#include<math.h>
int main() {
    double x1,x2;
    int a;
    scanf("%d",&a);
    x1=1.0;
    x2 = (x1+(a/x1))/2;
    while(fabs(x2-x1)>=1e-5){
        x1= x2;
        x2=(x1+(a/x1))/2;
    }
    printf("%.4lf",x2);
    return 0;
}


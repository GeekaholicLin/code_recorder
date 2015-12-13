#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//从银行贷款金额为d，准备每月还款额为p，月利率为r。请编写程序输入这三个数值
//，计算并输出多少个月能够还清贷款，输出时保留1位小数。 如果无法还清，请输出“God”
int main() {
    int d, p;
    float r, m, i, j;
    scanf("%d %d %f", &d, &p, &r);
    if (p == 0) {
        printf("0.0");
    } else {
        i = log(((float) p) / ((float) p - d * r));
        j = log((float) (1 + r));
        m = i / j;
        if (p < d * r) {
            printf("God");
        } else printf("%.1f", m);
    }

    return 0;
}
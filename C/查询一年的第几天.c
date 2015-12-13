#include <stdio.h>

struct DATE {
    int year;
    int month;
    int day;
};

int days(struct DATE date) {
    int i[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int k, result = 0;
    //闰年
    if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)) {
//日期正确
        if (date.day <= i[date.month - 1]) {
            result = date.day;
            for (k = 0; k < date.month-1; k++) {
                result += i[k];
            }
        }
    } else {
        if (date.day <= j[date.month - 1]) {
            result = date.day;
            for (k = 0; k < date.month-1; k++) {
                result += j[k];
            }
        }

    }
    return result;
}

int main() {
    struct DATE d;
    scanf("%d-%d-%d", &d.year, &d.month, &d.day);
    printf("%d", days(d));
    return 0;
} 
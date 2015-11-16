#include <stdio.h>

int main() {

	int a[3][4] = { 0 };
	int rowMax, j, corlum,countinue=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < 3; i++) {
		rowMax = a[i][0];
		corlum = 0;
		for (j = 0; j < 4; j++) {
			if (a[i][j] > rowMax) {
				rowMax = a[i][j];
				corlum = j;
			}
		}
		for (int k = 0; k < 3; k++) {
			if (a[k][corlum]<rowMax) break;
			if (k==2)
			{
				printf("%d", rowMax);
				countinue++;
				break;
			}
		}
		
	}
	if (countinue==0)
	{
		printf("NO");
	}
	return 0;
}
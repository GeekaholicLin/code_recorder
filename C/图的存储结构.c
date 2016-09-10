#include <stdio.h>
#include <malloc.h>
int main() {
	int n, m;
	int i, j, k;
	int arr[100][100] = {0};
	scanf("%d", &n);
	scanf("%d", &m);
	for (k = 1; k<=m; k++) {
		scanf("%d %d", &i, &j);
		arr[i][j] = 1;
		//arr[j][i] = 1;
	}
	for (i = 1; i<=n; i++) {
		for (j = 1; j<=n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

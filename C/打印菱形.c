#include "stdio.h"
#include "math.h"
int main()
{
	int n, i, j, k, h;
	scanf("%d", &n);
	for ( i = 1; i <=2*n+1; i++)
	{
		k = abs(n + 1 - i);
		for (j = 1; j <=k; j++)
		
			printf(" ");
		
		for (j = 1; j <=2* n+1 -2*k;j++)
			printf("*");
		printf("\n");
		
	}
	return 0;
}


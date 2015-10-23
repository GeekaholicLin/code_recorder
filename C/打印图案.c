#include "stdio.h"
#include "math.h"
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for ( i = 1; i <=2*n-1; i++)
	{
		int pnum = 1,count=1;
		k = abs(n  - i);
		for (j = 1; j <=k; j++)
		
			printf(" ");
		
		for (j = 1; j <= 2 * n - 1 - 2 * k; j++)
		{
			if (count<=n-k)
			{
				printf("%d", pnum++);
			}
			else
			{
				
				printf("%d", pnum-2);
				pnum--;
			}
			
			count++;
		}
		printf("\n");
		
	}
	return 0;
}


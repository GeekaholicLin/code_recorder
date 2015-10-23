#include <stdio.h>

int main()
{
	int a[20], b[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, i, count = 0;
	for (i = 0; i<20; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 20;i++)
	{
		for (int j = i+1; j < 20; j++)
		{
			
			if (b[i]==1&&b[j]==1)
			{
				if (a[i] == a[j])
				{
					b[j] = 0;
				}
			}
		
		}
	}
	for (int n = 0; n < 20; n++)
	{
		if (b[n] == 1)
			count++;
	}
	printf("%d",count);
	return 0;
}

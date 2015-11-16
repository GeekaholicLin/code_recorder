#include "stdio.h"
#include "string.h"
	int main()
	{
		char a[80];
		char b[30];
		int i,j,k;
		gets_s(a);
		gets_s(b);
		for (i = 0; i < 80; i++)
		{
			for (j = 0;j<strlen(b); j++)
			{
				k = 0;
				while(a[i+k]==b[j+k])
				{
					k++;
				}
				if (a[i+k]!=b[j+k])
				{
					break;
				}
			}

			if (k==strlen(b))
			{
				printf("%d", i + 1);
				break;
			}

		}
			return 0;
	}
	
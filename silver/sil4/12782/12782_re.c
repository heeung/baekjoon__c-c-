#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T, i, diff, cnt;
	char arr1[1000001];
	char arr2[1000001];

	scanf("%d", &T);
	while (T)
	{
		diff = 0;
		cnt = 0;
		scanf("%s %s", arr1, arr2);
		for (i = 0 ; arr1[i] ; i++)
		{
			if (arr1[i] == '1')
				cnt++;
			if (arr2[i] == '1')
				cnt--;
		}
		for (i = 0 ; i < arr1[i] ; i++)
		{
			if (arr1[i] != arr2[i])
				diff++;
		}
		printf("%d\n", ((diff + abs(cnt)) / 2));
		T--;
	}
}

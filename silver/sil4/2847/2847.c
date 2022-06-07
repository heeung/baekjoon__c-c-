#include <stdio.h>

int main(void)
{
	int N, i, dest;
	int arr[101] = {0};

	scanf("%d", &N);
	for (i = 0 ; i < N ; i++)
		scanf("%d", &arr[i]);
	int max = arr[N - 1];
	int res = 0;
	for (i = 0 ; i < N - 1 ; i++)
	{
		dest = max - (N - i - 1);
		if (arr[i] > dest)
		{
			res = res + (arr[i] - dest);
			arr[i] = dest;
		}
		if (arr[i] >= arr[i + 1])
		{
			dest = arr[i + 1] - 1;
			res = res + (arr[i] - dest);
			arr[i] = dest;
		}
	}
	printf("%d\n", res);
}

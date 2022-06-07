#include <stdio.h>
#include <stdlib.h>

void	bubble_sort(int *arr, int N)
{
	int	i;
	int	j;
	int	swp;

	i = 0;
	while (i < N - 1)
	{
		j = 0;
		while (j < N - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int	N;
	int	i;
	int	cnt;

	while (1)
	{
		int result = 0;
		int	arr[14] = {0};
		scanf("%d", &N);
		if (N == 0)
			break ;
		if (N % 2 == 0)
		{
			i = 0;
			cnt = 0;
			while (i < N)
			{
				scanf("%d", &arr[i]);
				if (arr[i] == 0)
					cnt++;
				i++;
			}
			if (cnt > N - 2)
				break ;
			int	zero_cnt = cnt;
			bubble_sort(arr, N);
			i = cnt;
			while (i < N)
			{
				while (cnt > 0 && i < N)
				{
					result = result * 10 + arr[i];
					cnt--;
					i++;
				}
				if (i < N)
				{
					result = result * 10 + arr[i] + arr[i + 1];
					i = i + 2;
				}

			}
			printf("%d\n", result);
		}
		else
		{
			i = 0;
			cnt = 1;
			while (i < N)
			{
				scanf("%d", &arr[i]);
				if (arr[i] == 0)
					cnt++;
				i++;
			}
			if (cnt > N - 2)
				break ;
			int	zero_cnt = cnt;
			bubble_sort(arr, N + 1);
			i = cnt;
			while (i < N + 1)
			{
				while (cnt > 0 && i < N)
				{
					result = result * 10 + arr[i];
					cnt--;
					i++;
				}
				if (i < N + 1)
				{
					result = result * 10 + arr[i] + arr[i + 1];
					i = i + 2;
				}
			}
			printf("%d\n", result);
		}

	}
	return (0);
}

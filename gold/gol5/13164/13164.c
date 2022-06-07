#include <stdio.h>

void merge(int *arr, int p, int q, int l)
{
	int i = p, j = q + 1, k = p;
	int tmp[300000];

	while (i <= q && j <= l)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= q)
		tmp[k++] = arr[i++];
	while (j <= l)
		tmp[k++] = arr[j++];
	for (int a = p ; a <= l ; a++)
		arr[a] = tmp[a];
}

void merge_sort(int *arr, int p, int l)
{
	int q;
	if (p < l)
	{
		q = (p + l) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, l);
		merge(arr, p, q, l);
	}
}

int main(void)
{
	int N, K, i, j, result, max, swp;
	int	arr1[300000] = {0};
	int	arr2[300000] = {0};
	int	max_idx;

	scanf("%d %d", &N, &K);
	for (i = 0 ; i < N ; i++)
	{
		scanf("%d", &arr1[i]);
		if (i > 0)
			arr2[i - 1] = arr1[i] - arr1[i - 1];
	}
	i = 0;
	result = 0;
	if (K == 1)
	{
		printf("%d\n", arr1[N - 1] - arr1[0]);
		return (0);
	}
	merge_sort(arr2, 0, N - 2);
	/*for (i = 0 ; i < N - 2 ; i++)
	{
		for (j = i + 1 ; j < N - 1 ; j++)
		{
			if (arr2[i] > arr2[j])
			{
				swp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = swp;
			}
		}
	}*/
	for (i = 0 ; i < (N - 1) - (K - 1) ; i++)
		result = result + arr2[i];
	/*for (i = 1 ; i < K ; i++)
	{
		result = 0;
		max = 0;
		max_idx = 0;
		for (j = 0 ; j < N - 1 ; j++)
		{
			if (max < arr2[j])
			{
				max = arr2[j];
				max_idx = j;
			}
			result = result + arr2[j];
		}
		result = result - max;
		arr2[max_idx] = 0;
	}*/
	printf("%d\n", result);
}

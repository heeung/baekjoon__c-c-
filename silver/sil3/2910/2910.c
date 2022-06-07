#include <stdio.h>
#include <stdlib.h>

typedef struct _nb
{
	int num;
	int order;
	int cnt;
}t_nb;

int cmp_order(const void *a, const void *b)
{
	t_nb *n1 = (t_nb *)a;
	t_nb *n2 = (t_nb *)b;

	if (n1->order > n2->order)
		return (1);
	else if (n1->order < n2->order)
		return (-1);
	else
		return (0);
}

int cmp_cnt(const void *a, const void *b)
{
	t_nb *n1 = (t_nb *)a;
	t_nb *n2 = (t_nb *)b;

	if (n1->cnt > n2->cnt)
		return (-1);
	else if (n1->cnt < n2->cnt)
		return (1);
	else
		return (0);
}


int main(void)
{
	int N, C, i, j;
	int arr1[1001] = {0};
	t_nb *NB;

	scanf("%d %d", &N, &C);
	NB = (t_nb *)malloc(sizeof(t_nb) * (C + 1));
	for (i = 0 ; i <= C ; i++)
	{
		NB[i].num = 0;
		NB[i].order = 0;
		NB[i].cnt = 0;
	}
	j = 1;
	for (i = 0 ; i < N ; i++)
	{
		scanf("%d", &arr1[i]);
		if (NB[arr1[i]].order == 0)
		{
			NB[arr1[i]].order = j;
			j++;
		}
		NB[arr1[i]].num = arr1[i];
		NB[arr1[i]].cnt++;
	}
	qsort(NB, C, sizeof(t_nb), cmp_order);
	qsort(NB, C, sizeof(t_nb), cmp_cnt);
	for (i = 0 ; i < N ; i++)
	{
		while (NB[i].cnt)
		{
			printf("%d ", NB[i].num);
			NB[i].cnt--;
		}
	}
}

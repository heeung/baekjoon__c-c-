#include <iostream>
#include <cstdlib>
#include <algorithm>

typedef struct parcel
{
	int from;
	int to;
	int box;
} t_parcel;

int cmp_from(const void *a, const void *b) {
	t_parcel *p1 = (t_parcel *)a;
	t_parcel *p2 = (t_parcle *)b;

	if (p1->from > p2->from)
		return (1);
	else if (p1->from < p2->from)
		return (-1);
	else
		return (0);
}

int cmp_to(const void *a, const void *b) {
	t_parcel *p1 = (t_parcel *)a;
	t_parcel *p2 = (t_parcle *)b;

	if (p1->to > p2->to)
		return (1);
	else if (p1->to < p2->to)
		return (-1);
	else
		return (0);
}

int main()
{
	int N, C, M, i;
	int res = 0;
	t_parcel *arr;

	scanf("%d %d", &N, &C);
	scanf("%d", M);
	arr = (t_parcel *)malloc(sizeof(t_parcel) * M);
	for (i = 0 ; i < M ; i++)
		scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].box);
	qsort(arr, M, sizeof(t_parcel), cmp_from);
	qsort(arr, M, sizeof(t_parcel), cmp_to);
	for (i = 0 ; i < M ; i++)
		
}

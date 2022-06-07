#include <stdio.h>
#include <stdlib.h>

int dat[1000005], box[1000005], head = 0, tail = 0;

int cmp(const void *a, const void *b){
	return (*(int *)b - *(int *)a);
}

void push(int x, int i){
	box[tail] = i;
	dat[tail++] = x;
}

void pop(){
	head++;
}

void go_back(){
	box[tail] = box[head];
	dat[tail++] = dat[head++];
}

int main(void)
{
	int N, M, K, cnt, i, flag, arr[105] = {0, };

	scanf("%d", &K);
	while (K)
	{
		cnt = 0;
		scanf("%d %d", &N, &M);
		for (i = 0 ; i < N ; i++)
		{
			scanf("%d", &arr[i]);
			push(arr[i], i);
		}
		qsort(arr, N, sizeof(int), cmp);
		i = 0;
		flag = 1;
		while (flag)
		{
			while (dat[head] != arr[i])
				go_back();
			while (dat[head] == arr[i])
			{
				cnt++;
				i++;
				if (box[head] == M)
				{
					printf("%d\n", cnt);
					flag = 0;
					break ;
				}
				pop();
			}
		}
		K--;
	}
}

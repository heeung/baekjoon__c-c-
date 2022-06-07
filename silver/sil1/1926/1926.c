#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_dat
{
	int x;
	int y;
} t_dat;

t_dat dat[500000];
int head = 0, tail = 0;

void push(int a, int b){
	dat[tail].x = a;
	dat[tail++].y = b;
}

void pop(){
	head++;
}

int main(void)
{
	int n, m, i, j;
	int arr[501][501] = {0, };

	scanf("%d %d", &n, &m);
	
}

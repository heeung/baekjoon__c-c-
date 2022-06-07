#include <stdio.h>

int	stack[1000005] = {0, };
int pos = 0;

void	push(int x){
	stack[pos++] = x;
}

void	pop(){
	pos--;
}

int main(void)
{
	int N, i, num, cnt;
	int ans[1000005] = {0, }, ans_idx = 0;

	scanf("%d", &N);
	for (i = 0 ; i < N ; i++)
	{
		cnt = 0;
		scanf("%d", &num);
		while (pos > 0 && stack[pos - 1] < num)
		{
			cnt++;
			pop();
		}
		if (cnt == 0 && i != 0)
			ans_idx++;
		while (cnt)
		{
			ans[ans_idx++] = num;
			cnt--;
		}
		push(num);
	}
}

#include <stdio.h>

char dat[1000005];
int pos = 0;

void push(char x){
	dat[pos++] = x;
}

void signal_a(int *a){
	if (*a == 0)
		*a = 1;
	else if (*a == 1)
		*a = 0;
}

void signal_b(int *b){
	if (*b == 0)
		*b = 1;
	else if (*b == 1)
		*b = 0;
}

void pop(){
	pos--;
}

int main(void)
{
	int N, i, cnt = 0, a, b;

	scanf("%d", &N);
	while (N--)
	{
		a = 0;
		b = 0;
		pos = 0;
		int flag = 0;
		char str[100001];
		scanf("%s", str);
		for (i = 0 ; str[i] ; i++)
		{
			if (str[i] == 'A')
			{
				if (a == 0)
				{
					signal_a(&a);
					push('A');
				}
				else if (a == 1)
				{
					if (dat[pos - 1] == 'A')
					{
						signal_a(&a);
						pop();
					}
					else
					{
						flag = 1;
						break ;
					}
				}
			}
			else if (str[i] == 'B')
			{
				if (b == 0)
				{
					signal_b(&b);
					push('B');
				}
				else if (b == 1)
				{
					if (dat[pos - 1] == 'B')
					{
						signal_b(&b);
						pop();
					}
					else
					{
						flag = 1;
						break ;
					}
				}
			}
		}
		if (flag == 0 && a == 0 && b == 0)
			cnt++;
	}
	printf("%d\n", cnt);
}

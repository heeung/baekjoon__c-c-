#include <stdio.h>
#include <string.h>

char stack[10000][1000005];
int pos = 0;

void push(int cnt, char x){
	stack[cnt][pos++] = x;
}

int main(void)
{
	char S[100002];
	char ans[100002];
	int is_input = 0, cnt = 0;

	fgets(S, 100002, stdin);
	for (int i = 0 ; i < strlen(S) - 1 ; i++)
	{
		if (S[i] == '>')
		{
			is_input = 1;
			continue ;
		}
		else if (S[i] == '<')
		{
			is_input = 0;
			continue ;
		}
		if (is_input = 1)
		{
			push(cnt, S[i]);
		}
		else
		{
		}
	}
}

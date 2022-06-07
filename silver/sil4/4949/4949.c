#include <stdio.h>
#include <string.h>

int stack_1[10000] = {0, };
int stack_2[10000] = {0, };
int stack[10000] = {0, };
int pos = 0;
int pos_1 = 0;
int pos_2 = 0;

void pop(){
	pos--;
}

void push(char x){
	if (x == '(')
		stack[pos++] = 1;
	if (x == '[')
		stack[pos++] = 2;
}

void push_1(char x){
	if (x == '(')
		stack_1[pos_1++] = 1;
	else
		stack_1[pos_1++] = -1;
}

void push_2(char x){
	if (x == '[')
		stack_2[pos_2++] = 1;
	else
		stack_2[pos_2++] = -1;
}

int main(void)
{
	char str[105];
	int res_1, res_2, i;
	int flag_done;

	while (1)
	{
		fgets(str, 105, stdin);
		if (str[0] == '.')
			break ;
		res_1 = 0;
		res_2 = 0;
		i = 0;
		flag_done = 0;
		while (str[i] != '.')
		{
			if (str[i] == '(' || str[i] == ')')
			{
				push(str[i]);
				if (str[i] == ')' && pos > 0)
				{
					if (stack[pos - 1] == 2)
					{
						printf("no\n");
						flag_done = 1;
						break ;
					}
					else if (stack[pos - 1] == 1)
						pop();
				}
				push_1(str[i]);
				res_1 += stack_1[pos_1 - 1];
			}
			else if (str[i] == '[' || str[i] == ']')
			{
				push(str[i]);
				if (str[i] == ']' && pos > 0)
				{
					if (stack[pos - 1] == 1)
					{
						printf("no\n");
						flag_done = 1;
						break ;
					}
					else if (stack[pos - 1] == 2)
						pop();
				}
				push_2(str[i]);
				res_2 += stack_2[pos_2 - 1];
			}
			if ((res_1 < 0 || res_2 < 0) && flag_done != 1)
			{
				printf("no\n");
				flag_done = 1;
				break ;
			}
			i++;
		}
		if (flag_done != 1 && (res_1 > 0 || res_2 > 0))
		{
			printf("no\n");
			continue ;
		}
		if ((res_1 == 0 && res_2 == 0) && flag_done == 0)
			printf("yes\n");
	}
}

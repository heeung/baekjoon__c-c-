#include <stdio.h>
#include <string.h>

int indexs[500] = {0, };
int pos = 0;

void push_back(int a)
{
	indexs[pos++] = a;
}

int main()
{
	char str[2502] = "";

	scanf("%s", str);
	int ans = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		int flag = 1;
		char before = str[i];
		if (str[i] == 'q')
		{
			push_back(i);
			for (int k = i + 1; k < strlen(str); k++)
			{
				if (before == '-')
				{
					if (str[k]=='q')
					{
						before = 'q';
						push_back(k);
					}
				}
				else if (before == 'q' && str[k] == 'u')
				{
					push_back(k);
					before = 'u';
				}
				else if (before == 'u' && str[k] == 'a')
				{
					push_back(k);
					before = 'a';
				}
				else if (before == 'a' && str[k] == 'c')
				{
					push_back(k);
					before = 'c';
				}
				else if (before == 'c' && str[k] == 'k')
				{
					push_back(k);
					if (pos == 5)
					{
						for (int idx = 0; idx < 5; idx++)
							str[indexs[idx]] = '-';
						if (flag)
							ans++;
						flag = 0;
						before = '-';
						pos = 0;
					}
				}
			}
			pos = 0;
		}
	}
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != '-')
		{
			ans = 0;
			break;
		}
	}
	if (ans == 0)
		printf("-1");
	else
		printf("%d", ans);
}
#include <stdio.h>
#include <string.h>

int is_used(char *a, int n, char c)
{
	for (int i = 0 ; i < n ; i++)
	{
		if (c == a[i])
			return (1);
	}
	return (0);
}

int only(char *str)
{
	for (int i = 0 ; str[i] ; i++)
	{
		if (!(str[i] == '6' || str[i] == '9'))
			return (1);
	}
	return (0);
}

int main(void)
{
	char str[1000001];
	int cnt = 1;
	int	cnt6 = 0, cnt9 = 0;

	scanf("%s", str);
	if (only(str) == 0)
	{
		if (strlen(str) % 2 == 1)
			cnt = 1;
		else
			cnt = 0;
	}
	else
		cnt = only(str);
	for (int i = 0 ; str[i] ; i++)
	{
		if (is_used(str, i, str[i]) == 1 && (str[i] != '6' && str[i] != '9'))
			cnt++;
		if (str[i] == '6')
			cnt6++;
		if (str[i] == '9')
			cnt9++;
		if ((cnt6 + cnt9) % 2 == 0 && (cnt6 > 0 || cnt9 > 0))
			cnt++;
	}
	printf("%d\n", cnt);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[1001] = "";
	char b[1001] = "";
	int alpha1[27] = {0, };
	int alpha2[27] = {0, };
	int ret = 0;

	scanf("%s %s", a, b);
	for (int i = 0; i < strlen(a); i++)
		alpha1[a[i] - 'a']++;
	for (int i = 0; i < strlen(b); i++)
		alpha2[b[i] - 'a']++;
	for (int i = 0; i < 27; i++)
	{
		if (alpha1[i] != alpha2[i])
			ret += abs(alpha1[i] - alpha2[i]);
	}
	printf("%d\n", ret);
}

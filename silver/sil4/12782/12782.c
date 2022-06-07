#include <stdio.h>
#include <string.h>

int main(void)
{
	int T, i, diff, cnt, cnt_1, cnt_2;
	char arr1[1000001];
	char arr2[1000001];

	scanf("%d", &T);
	while (T)
	{
		scanf("%s %s", arr1, arr2);
		cnt_1 = 0;
		cnt_2 = 0;
		for (i = 0 ; i < strlen(arr1) ; i++)
		{
			if (arr1[i] == '1')
				cnt_1++;
			if (arr2[i] == '1')
				cnt_2++;
		}
		cnt = 0;
		if (cnt_1 > cnt_2)
		{
			diff = cnt_1 - cnt_2;
			for (i = 0; i < strlen(arr1) ; i++)
			{
				if (arr1[i] != arr2[i])
				{
					arr1[i] = '0';
					diff--;
					cnt++;
				}
				if (diff == 0)
				{
					if (strcmp(arr1, arr2) != 0)
						cnt++;
					break ;
				}
			}
		}
		else if (cnt_1 < cnt_2)
		{
			diff = cnt_2 - cnt_1;
			for (i = 0; i < strlen(arr1) ; i++)
			{
				if (arr1[i] != arr2[i])
				{
					arr2[i] = '0';
					diff--;
					cnt++;
				}
				if (diff == 0)
				{
					if (strcmp(arr1, arr2) != 0)
						cnt++;
					break ;
				}
			}
		}
		else
		{
			if (strcmp(arr1, arr2) != 0)
				cnt++;
		}
		printf("%d\n", cnt);
		T--;
	}
}

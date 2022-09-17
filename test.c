#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int b = 1;
	int i = 0;
	int c = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1;i<=n; i++)
	{
		b = b * i;
		c = c + b;
	}
	printf("%d\n", b);
	printf("%d\n", c);
	return 0;
}
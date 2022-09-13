
#include <stdio.h>
Max(intx, inty)
{
	if (x > y)
		return x;
	else
		return y
}
int main()
	{
	int a = 0;
	int b = 0;
	int max = 0;
	scanf("%d%d", &a, &b);
	max = Max(a,b);
	printf("%d\n", max);
	return 0;
	}

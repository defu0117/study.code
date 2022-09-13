//#include <stdio.h>
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	scanf("%d%d", &num1, &num1);
//	sum = num1 + num2;
//	printf("sum=%d\n", sum);
//	return 0;
}
#include <stdio.h>
int global = 2022;
void test()
{
	printf("test()--%d", global);
}
int main()
{
	test();
	printf("%d", global);
	return 0;
}


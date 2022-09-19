#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**********************\n");
	printf("\n**play：1 退出：0*****\n");
	printf("\n**********************\n");
}
void game()
{
	int b = 0;
	b = rand()%100+1;//生成一个随机数,拿时间戳来设置随机数的生成起点
	//time_t time(time_t* timer)
	int a = 0;
	printf("请输入：");
	while (1)
	{
		scanf("%d", &a);
		if (a > b)
			printf("输大了\n");
		else if (a < b)
			printf("输小了\n");
		else
		{
			printf("正确\n");
			system("cls");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请输入>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("退出程序\n");
			break;
		default:
				break;
		}
	} while (input);
	return 0;
}
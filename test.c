#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**********************\n");
	printf("\n**play��1 �˳���0*****\n");
	printf("\n**********************\n");
}
void game()
{
	int b = 0;
	b = rand()%100+1;//����һ�������,��ʱ�����������������������
	//time_t time(time_t* timer)
	int a = 0;
	printf("�����룺");
	while (1)
	{
		scanf("%d", &a);
		if (a > b)
			printf("�����\n");
		else if (a < b)
			printf("��С��\n");
		else
		{
			printf("��ȷ\n");
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
		printf("������>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
				break;
		}
	} while (input);
	return 0;
}
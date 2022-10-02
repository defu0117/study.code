#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("                          \n");
	printf("    1.play        0.exit  \n");
	printf("                          \n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	do
	{
		srand((unsigned int)time(NULL));
		menu();	
		printf("请选择\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
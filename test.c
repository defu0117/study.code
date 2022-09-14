#include <stdio.h>
#include <string.h>
struct book 
{
	char name[20];
	short price;
};

int main()
{
	struct book b1={"CÓïÑÔÉè¼Æ",55 };
	struct book* pb = &b1;
	printf("%s\n", pb->name);
	printf("%d\n", pb->price);
pb->price = 15;
strcpy (pb->name,"c++");
	printf("%s\n", pb->name);
	printf("%d\n", pb->price);
	return 0;
}
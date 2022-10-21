Status InitStack(SqStack& S)
{ /* 构造一个空栈S */
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); /* 存储分配失败*/
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
int StackLength(SqStack S)
{ // 返回S 的元素个数，即栈的长度, 编写此函数 
	return S.top - S.base;
}
Status Push(SqStack& S, SElemType e)
{ /* 插入元素e 为新的栈顶元素*/
	if (S.top - S.base >= S.stacksize) /* 栈满，追加存储空间*/
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)
			* sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); /* 存储分配失败*/
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top)++ = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e)
{ /* 若栈不空，则删除S 的栈顶元素，用e 返回其值，并返回OK;否则返回ERROR */
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status StackEmpty(SqStack S)
{ /* 若栈S 为空栈，则返回TRUE，否则返回FALSE */
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
void conversion10_8()
{ /* 对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数*/
	SqStack  s;
	unsigned  n; /* 非负整数*/
	SElemType  e;
	InitStack(s); /* 初始化栈*/
	printf("Enter an number(>=0): ");
	scanf("%u", &n); /* 输入非负十进制整数n */
	while (n) /* 当n 不等于0 */
	{
		Push(s, n % 8);              /* 入栈n 除以8 的余数(8 进制的低位) */
		n = n / 8;
	}
	while (!StackEmpty(s)) /* 当栈不空*/
	{
		Pop(s, e); ; /* 弹出栈顶元素且赋值给e */
		printf("%d", e); /* 输出e */
	}
	printf("\n");
}

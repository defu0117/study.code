Status InitStack(SqStack& S)
{ /* ����һ����ջS */
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); /* �洢����ʧ��*/
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
int StackLength(SqStack S)
{ // ����S ��Ԫ�ظ�������ջ�ĳ���, ��д�˺��� 
	return S.top - S.base;
}
Status Push(SqStack& S, SElemType e)
{ /* ����Ԫ��e Ϊ�µ�ջ��Ԫ��*/
	if (S.top - S.base >= S.stacksize) /* ջ����׷�Ӵ洢�ռ�*/
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)
			* sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); /* �洢����ʧ��*/
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top)++ = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e)
{ /* ��ջ���գ���ɾ��S ��ջ��Ԫ�أ���e ������ֵ��������OK;���򷵻�ERROR */
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status StackEmpty(SqStack S)
{ /* ��ջS Ϊ��ջ���򷵻�TRUE�����򷵻�FALSE */
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
void conversion10_8()
{ /* �������������һ���Ǹ�ʮ������������ӡ��������ֵ�İ˽�����*/
	SqStack  s;
	unsigned  n; /* �Ǹ�����*/
	SElemType  e;
	InitStack(s); /* ��ʼ��ջ*/
	printf("Enter an number(>=0): ");
	scanf("%u", &n); /* ����Ǹ�ʮ��������n */
	while (n) /* ��n ������0 */
	{
		Push(s, n % 8);              /* ��ջn ����8 ������(8 ���Ƶĵ�λ) */
		n = n / 8;
	}
	while (!StackEmpty(s)) /* ��ջ����*/
	{
		Pop(s, e); ; /* ����ջ��Ԫ���Ҹ�ֵ��e */
		printf("%d", e); /* ���e */
	}
	printf("\n");
}

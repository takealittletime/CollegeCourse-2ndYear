//20194111 �ֹα�

#include<stdio.h> //ǥ�� ����� ��� ����
#define MAX_SIZE 100 //������ �ִ� ũ��


typedef struct { //���� Ÿ�� ����
	int stack[MAX_SIZE];
	int top;
}stack_type;

typedef stack_type* stack_ptr;

void init(stack_ptr p) //���� �ʱ�ȭ �Լ�
{
	p->top = -1;
}

void push(stack_ptr p, char add) //���� �Է� �Լ�
{
	if (is_full(*p))
	{
		printf("������ ���� á���ϴ�. �� �̻� �߰��� �� �����ϴ�.\n");
		return;
	}

	else
	{
		(p->top)++;
		p->stack[p->top] = add;
	}

}

char pop(stack_ptr p)  //���� �� ���� �� �� ��ȯ �Լ�
{
	if (is_empty(*p))
	{
		printf("������ ������ϴ�. �� �̻� ������ �� �����ϴ�.");
		return;
	}

	else
	{
		char result = p->stack[p->top];
		(p->top)--;

		return result;
	}
}

int is_empty(stack_type s) // ������ ������� Ȯ���ϴ� �Լ�
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}

int is_full(stack_type s) //������ ���� á���� Ȯ���ϴ� �Լ�
{
	if (s.top == MAX_SIZE)
		return 1;
	else
		return 0;
}

int peek(stack_type s) //���� ���� �о� ��ȯ�ϴ� �Լ�
{
	return s.stack[s.top];
}

int reverse(int n) //������ �Ųٷ� ��ȯ�ϴ� �Լ�
{
	stack_type s;

	init(&s);

	int result = 0;

	while (n != 0) //������ �� �ڸ����� ������ ���ÿ� �Ҵ�
	{
		push(&s, n % 10);
		n /= 10;
	}

	//(�� �ڸ����� �������� �������� ���ÿ��� ���� �����ϴ� �۾�)
	int i = 0; //10�� ������ Ƚ��
	while (!is_empty(s)) //���� stc�� �� ������ �ݺ�
	{
		int digit = pop(&s); //���� �ϳ� ����
		for (int j = 0; j < i; j++)
		{
			digit *= 10; //������ i�� Ƚ����ŭ 10�� ����
		}
		i++; // i ����
		result += digit; //result�� ���� ������
	}

	return result; //result�� ��ȯ
}

int main(void)
{
	int num = 1234567;

	printf("%d -> %d\n", num, reverse(num));

	return 0;
}
//20194111 �ֹα�
#include <stdio.h>

//1�� ����
#define MAX(a,b,c) (((a)>(b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c))) 
//a,b���� �� �� ���� c�� ��

int main(void)
{
	printf("<20194111 �ֹα�>\n1�� ����\n2�� ������ ���� �ּ�ó���� �� ��������, �ּ��� Ǯ�� �����ϼ���.\n");
	int num1, num2, num3;

	printf("���� �� ���� �Է��ϼ���:");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	printf("�� ���� �� ���� ū ���� %d �Դϴ�.\n", MAX(num1, num2, num3));

	return 0;
}

//2�� ����
/*
#define UPCASE(c) (( (c)>='a' && (c)<='z') ? (c)-('a'-'A') : (c)) //�ҹ��ڸ� �빮�ڷ� �ٲٴ� ��ũ�� �Լ�
#define LOCASE(c) (( (c)>='A' && (c)<='Z') ? (c)+('a'-'A') : (c))//�빮�ڸ� �ҹ��ڷ� �ٲٴ� ��ũ�� �Լ�

void change(char str[])
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = UPCASE(str[i]);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = LOCASE(str[i]);
		i++;
	}
}

int main(void)
{
	printf("\n2�� ����\n\n");

	char str[100];
	printf("���ڿ��� �Է��ϼ���:");
	gets_s(str, sizeof(str));

	printf("���� ���ڿ�: %s\n", str);
	change(str);
	printf("��ҹ��� ��ȯ ��: %s\n", str);
	return 0;
}
*/
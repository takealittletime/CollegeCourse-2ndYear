#include <stdio.h>
#include <string.h>

typedef enum engweek //������ ���� ������
{
MON = 1, TUE = 2, WED = 3, THURS = 4, FRI = 5, SATUR = 6, SUN = 7
} engweek;

typedef enum korweek //������ �ѱ� ������
{
�� = 1, ȭ = 2, �� = 3, �� = 4, �� = 5, �� = 6, �� = 7
} korweek;

void eng_print(int day) // ����� ��¥ ���
{
	switch (day)
	{
	case MON:
		puts("Today is Monday"); return;
	case TUE:
		puts("Today is Tuesday"); return;
	case WED:
		puts("Today is Wednesday"); return;
	case THURS:
		puts("Today is Thursday"); return;
	case FRI:
		puts("Today is Friday"); return;
	case SATUR:
		puts("Today is Saturday"); return;
	case SUN:
		puts("Today is Sunday"); return;
	default:
		puts("�Է��� �߸��Ǿ����ϴ�.\n");return;
	}
}

void kor_print(int day) //�ѱ۷� ��¥ ���
{
	switch (day)
	{
	case ��:
		puts("������ �������Դϴ�.\n"); return;
	case ȭ:
		puts("������ ȭ�����Դϴ�.\n"); return;
	case ��:
		puts("������ �������Դϴ�.\n"); return;
	case ��:
		puts("������ ������Դϴ�.\n"); return;
	case ��:
		puts("������ �ݿ����Դϴ�.\n"); return;
	case ��:
		puts("������ ������Դϴ�.\n"); return;
	case ��:
		puts("������ �Ͽ����Դϴ�.\n"); return;

	default:
		puts("�Է��� �߸��Ǿ����ϴ�.\n");return;
	}
}

int main(void)
{
	char day[5];
	int today = 0;
	//����� �Է�
	printf("������ ���� �����Դϱ�?:");
	scanf("%s", day);
	
	//�Է¿� �°� today�� ����
	if (!strcmp(day,"��"))
		today = 1;
	else if (!strcmp(day, "ȭ"))
		today = 2;
	else if (!strcmp(day, "��"))
		today = 3;
	else if (!strcmp(day, "��"))
		today = 4;
	else if (!strcmp(day, "��"))
		today = 5;
	else if (!strcmp(day, "��"))
		today = 6;
	else if (!strcmp(day, "��"))
		today = 7;

	eng_print(today); //���� ���
	kor_print(today); //�ѱ� ���

	return 0;
}
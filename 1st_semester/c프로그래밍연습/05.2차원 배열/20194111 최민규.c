#include <stdio.h> //ǥ�� ����� ��� ���� �߰�
#include <stdlib.h> //����  �ʱ�ȭ�� ���� ��� ���� �߰�

int main(void) //main �Լ� ����
{
	srand(time(NULL)); //������ �ʱ�ȭ
	int grade[5][4] = { 0 }; //���� ũ�� 5, ���� ũ�� 4�� 2���� �迭 grade ���� �� 0���� �ʱ�ȭ
	
	//10���� ���� ���� ������ grade �迭 �ʱ�ȭ
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 2; k >= 0; k--)
		{
			grade[i][k] = rand() % 10;
		}
	}

	//�л� �� ���� ���
	for (int a = 0; a < 4; a++) //�迭 ������ �ε��� 3���� �ݺ�
	{
		int sum = 0; //������ �Ҵ��� ������ ���� sum ���� �� 0���� �ʱ�ȭ
		for (int b = 0; b < 3; b++) //�迭 ������ �ε��� 2���� �ݺ�
		{
			sum += grade[a][b]; //���� sum�� grade[a][b] ���� ����
		}
		grade[a][3] = sum; //grade[a][3]�� ���� sum�� �Ҵ�
	}

	//���� �� ���� ���
	for (int c = 0; c < 3; c++) //�迭 ������ �ε��� 2���� �ݺ�
	{
		int total = 0; //������ �Ҵ��� ������ ���� total ���� �� 0���� �ʱ�ȭ
		for (int d = 0; d < 4; d++) //�迭 ������ �ε��� 4���� �ݺ�
		{
			total += grade[d][c]; //���� total�� grade[d][c] ���� ����
		}

		grade[4][c] = total; //grade[4][c]�� ���� total�� �Ҵ�
	}

	//��� ���
	printf("      �� �� ���� ���� ���� ����\n");
	for (int e = 0; e < 5; e++)
	{
		if (e == 0)
			printf("      ö ��");
		if (e == 1)
			printf("      ö ��");
		if (e == 2)
			printf("      �� ��");
		if (e == 3)
			printf("      �� ��");
		if (e == 4)
			printf("���� ����");

		for (int f = 0; f < 4; f++)
		{
			printf("%4d ", grade[e][f]);
		}
		printf("\n");
	}

	return 0; //�Լ��� ���� 0���� ��ȯ
}
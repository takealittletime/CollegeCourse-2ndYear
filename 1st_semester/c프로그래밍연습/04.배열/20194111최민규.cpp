#include <stdio.h>

int main(void)
{
	//1�� ����
	int num[5] = { 0 }; //ũ�Ⱑ 5�� ������ �迭 num ���� �� �ʱ�ȭ

	//5�� ���� �Է�
	printf("5���� ������ �Է��Ͻÿ�:");
	scanf_s("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

	//ũ�� ��, �հ� ����� ���� ���� ������ ����
	int tmp = num[0], big = num[0], small = num[0],sum = 0;

	//5�� �ݺ��ϸ鼭 �ִ�, �ּڰ� ��� �� �հ� ���
	for (int i = 0; i < 5; i++)
	{
		sum += num[i]; //�迭 ���� ������ ���� ���

		//�ִ�, �ּڰ� ���
		if (tmp < num[i]) //�迭 ���� ��Ҹ� ���� ��
		{
			big = num[i]; //ū ���� big�� �Ҵ�
		}

		else
		{
			small = num[i]; //���� ���� small�� �Ҵ�
		}
	}

	//��� ���
	printf("\n\n�ִ밪: %d , �ּҰ�: %d , �� �� : %d\n", big, small, sum);

	//2�� ����
	char string[50] = { 0 }; //ũ�Ⱑ 50�� ���ڿ� string�� ���� �� �ʱ�ȭ
	int len = 0; //���ڿ��� ���̸� �Ҵ��ϱ� ���� ������ ���� len ���� �� �ʱ�ȭ

	//���ڿ� �Է�
	printf("\n\n���ڿ� �Է�:");
	scanf("%s", string);

	//���ڿ��� ���� ���
	for (int i = 0; i < 50; i++)
	{
		//���ڿ� string���� NULL���ڸ� ������ �ݺ��� Ż��
		if (string[i] == NULL)
			break;

		//���� len�� 1�� �ݺ��ؼ� ������.
		len += 1;
	}

	//�ݺ����� Ȱ�� �� ���ڿ� �Ųٷ� ���
	printf("\n�Ųٷ� ��� :");
	for (int j = len; j > -1; j--)
	{
		printf("%c", string[j]);

	}

	//���ڿ� �Է¿��� ���Ͱ� �ߺ����� ó���Ǵ� ���� �ذ��� ���� getchar(); �̿�
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

	//3�� ����
	char str[50] = { 0 }; //ũ�Ⱑ 50�� ���ڿ� str ���� �� �ʱ�ȭ
	int leng = 0; // ���ڿ��� ���̸� �Ҵ��ϱ� ���� ������ ���� leng ���� �� �ʱ�ȭ

	//���ڿ� �Է�
	printf("\n\n\n���ڿ� �Է�:");
	gets_s(str,50);

	//���ڿ��� ���� ���
	for (int i = 0; i < 50; i++)
	{
		//���ڿ� str���� NULL���ڸ� ������ �ݺ��� Ż��
		if (str[i] == NULL)
			break;

		//���� leng�� 1�� �ݺ��ؼ� ������.
		leng += 1;
	}

	//�ݺ����� Ȱ�� �� ���ڿ� �Ųٷ� ���
	printf("\n�Ųٷ� ���: ");

	for (int j = leng; j > -1; j--)
	{
		printf("%c", str[j]);

	}

	printf("\n");

	return 0; //�Լ� ���� 0���� ��ȯ
	
}

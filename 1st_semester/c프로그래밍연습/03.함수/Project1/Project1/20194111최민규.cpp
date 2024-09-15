#include <stdio.h>
#include <time.h>

int fun_1(int n) {
	unsigned long int sum = 0;
	for (int i = 0; i < n; i++)
		{
			sum += 1;
		}
	return sum;
}

int fun_2(int n) {
	unsigned long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
					sum += 1;
			}
		}
	}

	return sum;
}

int main()
{
	unsigned long int sum = 0;
	int n = 0;
	double elapsed;
	
	// �Լ� �Ű����� n�� �Է�
	printf("n���� �Է��Ͻÿ�:");
	scanf_s("%d", &n);
	clock_t start, end;

	// fun_1 �Լ��� ���� �ҿ� �ð� ����
	start = clock();
	sum = fun_1(n); // �Ű����� �迭�� ���� => �Լ� �ڵ忡�� ���ǹ� ����.
	end = clock();

	//fun_1 �Լ� �ᱣ�� ���
	printf("fun_1 �Լ��� �ᱣ��: %d\n", sum);

	// �ҿ� �ð��� msec ������ ���
	elapsed = (end - start) / CLOCKS_PER_SEC;
	printf("fun_1 �Լ� �ҿ� �ð� : %lf\n", elapsed);

	// fun_2 �Լ��� ���� �ҿ� �ð� ����
	start = clock();
	sum = fun_2(n); // �Ű����� �迭�� ���� => �Լ� �ڵ忡�� ���ǹ� ����.
	end = clock();

	//fun_2 �Լ� �ᱣ�� ���
	printf("\nfun_2 �Լ��� �ᱣ��: %d\n", sum);

	// �ҿ� �ð��� msec ������ ���
	elapsed = (end - start) / CLOCKS_PER_SEC;
	printf("fun_2 �Լ� �ҿ� �ð� : %lf\n", elapsed);


	return 0;
}
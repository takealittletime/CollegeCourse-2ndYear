#include <stdio.h> //ǥ�� ����� ��� ���� �߰�

void arr_sum1(int arr[][4], int total[]); //2�� ���� ���1 �Լ� ����
void arr_sum2(int* arr, int total[]); //2�� ���� ���2 �Լ� ����

int main(void)
{
	//1�� ����
	printf("<<1�� ����>>\n\n");
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 11,12,13,14,15,16,17,18,19,20 };

	//������ ���� �� �ʱ�ȭ
	int* ptr1 = &a;
	int* ptr2 = &b;

	//���� ������ ���� �� �ʱ�ȭ
	int** dptr1 = &ptr1;
	int** dptr2 = &ptr2;


	//swap �� �ּҰ� ���
	printf("<swap��>\n");
	printf("a = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", a[x]);
	}
	printf("}\n");

	printf("a�� �޸� �ּ� = %9p\t���� ������ �ּ� = %9p\t���� ������ �ּ� = %9p\n", &a, ptr1, dptr1);

	printf("\n");

	printf("b = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", b[x]);
	}
	printf("}\n");

	printf("b�� �޸� �ּ� = %9p\t���� ������ �ּ� = %9p\t���� ������ �ּ� = %9p\n",&b, ptr2, dptr2);

	//swap (�迭 ��ü�� swap�ϴ� ���� �ƴ϶�, ���� �����͸� swap)
	int* tmp = *dptr1;
	*dptr1 = *dptr2;
	*dptr2 = tmp;

	//swap�� �ּҰ� ��� (���� �����͸� �̿� �� ���)
	printf("\n<swap��>\n");
	printf("a = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", ptr1[x]);
	}
	printf("}\n");

	printf("a�� �޸� �ּ� = %9p\t���� ������ �ּ� = %9p\t���� ������ �ּ� = %9p\n", &a, ptr1, dptr1);

	printf("\n");

	printf("b = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", ptr2[x]);
	}
	printf("}\n");

	printf("b�� �޸� �ּ� = %9p\t���� ������ �ּ� = %9p\t���� ������ �ּ� = %9p\n", &b, ptr2, dptr2);


	//2�� ����
	printf("\n<<2�� ����>>\n\n");
	int arr[3][4]; //3��4���� 2���� �迭 a ����
	int result1[4] = { 0 }; //�� ���� ���� �Ҵ��� ũ�Ⱑ 3�� �迭 result1 ����(���1�� ���)
	int result2[4] = { 0 }; //�� ���� ���� �Ҵ��� ũ�Ⱑ 3�� �迭 result2 ����(���2�� ���)

	//0���� 99���� ������ �迭 a �ʱ�ȭ
	srand(time(NULL));
	for (int k = 0; k < 3; k++)
	{
		for (int z = 0; z < 4; z++)
		{
			arr[k][z] = rand() % 100;
		}
	}

	//�迭 a ���
	printf("<�迭 arr>\n");
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			printf("%3d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("\n");

	arr_sum1(arr, result1); //arr_sum1 �Լ� ȣ��

	//��� 1�� ���� ���� �� ���� �� ���
	printf("��� 1�� ���� ���� ��\n");
	for (int i = 0; i < 3; i++)
	{
		printf("arr �迭�� %d��° ���� ���� %d �Դϴ�.\n", i + 1, result1[i]);
	}

	arr_sum2(arr, result2); //arr_sum2 �Լ� ȣ��

	//��� 2�� ���� ���� �� ���� �� ���
	printf("\n��� 2�� ���� ���� ��\n");
	for (int i = 0; i < 3; i++)
	{
		printf("arr �迭�� %d��° ���� ���� %d �Դϴ�.\n", i + 1, result2[i]);
	}

	return 0;
}

//2�� ���� ��� 1
void arr_sum1(int arr[][4], int total[])
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += arr[i][j];
		}
		total[i] = sum;
	}
}

//2�� ���� ��� 2 (2���� �迭�� �޸� �󿡼��� 1���� ���·� �ּҰ��� �����Ǵ� ���� Ȱ��)
void arr_sum2(int* arr, int total[])
{
	for (int i = 0; i < 16; i = i + 4) //i���� 4�� ����.
	{
		int sum = 0;
		for (int j = 0; j < 4; j++) //i���� j���� 1�� �����ϸ鼭 ���� �� ���
		{
			sum += *(arr + i + j);
		}
		total[i / 4] = sum; //i���� 4�� �����ϹǷ�, 4�� ���� ���� �ε��������� Ȱ��
	}
}


#include <stdio.h> //표준 입출력 헤더 파일 추가

void arr_sum1(int arr[][4], int total[]); //2번 문제 방법1 함수 원형
void arr_sum2(int* arr, int total[]); //2번 문제 방법2 함수 원형

int main(void)
{
	//1번 문제
	printf("<<1번 문제>>\n\n");
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 11,12,13,14,15,16,17,18,19,20 };

	//포인터 선언 및 초기화
	int* ptr1 = &a;
	int* ptr2 = &b;

	//이중 포인터 선언 및 초기화
	int** dptr1 = &ptr1;
	int** dptr2 = &ptr2;


	//swap 전 주소값 출력
	printf("<swap전>\n");
	printf("a = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", a[x]);
	}
	printf("}\n");

	printf("a의 메모리 주소 = %9p\t단일 포인터 주소 = %9p\t이중 포인터 주소 = %9p\n", &a, ptr1, dptr1);

	printf("\n");

	printf("b = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", b[x]);
	}
	printf("}\n");

	printf("b의 메모리 주소 = %9p\t단일 포인터 주소 = %9p\t이중 포인터 주소 = %9p\n",&b, ptr2, dptr2);

	//swap (배열 자체를 swap하는 것이 아니라, 단일 포인터를 swap)
	int* tmp = *dptr1;
	*dptr1 = *dptr2;
	*dptr2 = tmp;

	//swap후 주소값 출력 (단일 포인터를 이용 해 출력)
	printf("\n<swap후>\n");
	printf("a = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", ptr1[x]);
	}
	printf("}\n");

	printf("a의 메모리 주소 = %9p\t단일 포인터 주소 = %9p\t이중 포인터 주소 = %9p\n", &a, ptr1, dptr1);

	printf("\n");

	printf("b = { ");
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", ptr2[x]);
	}
	printf("}\n");

	printf("b의 메모리 주소 = %9p\t단일 포인터 주소 = %9p\t이중 포인터 주소 = %9p\n", &b, ptr2, dptr2);


	//2번 문제
	printf("\n<<2번 문제>>\n\n");
	int arr[3][4]; //3행4열의 2차원 배열 a 선언
	int result1[4] = { 0 }; //각 행의 합을 할당할 크기가 3인 배열 result1 선언(방법1에 사용)
	int result2[4] = { 0 }; //각 행의 합을 할당할 크기가 3인 배열 result2 선언(방법2에 사용)

	//0부터 99사이 난수로 배열 a 초기화
	srand(time(NULL));
	for (int k = 0; k < 3; k++)
	{
		for (int z = 0; z < 4; z++)
		{
			arr[k][z] = rand() % 100;
		}
	}

	//배열 a 출력
	printf("<배열 arr>\n");
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			printf("%3d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("\n");

	arr_sum1(arr, result1); //arr_sum1 함수 호출

	//방법 1을 통해 구한 각 행의 합 출력
	printf("방법 1을 통해 구한 답\n");
	for (int i = 0; i < 3; i++)
	{
		printf("arr 배열의 %d번째 행의 합은 %d 입니다.\n", i + 1, result1[i]);
	}

	arr_sum2(arr, result2); //arr_sum2 함수 호출

	//방법 2를 통해 구한 각 행의 합 출력
	printf("\n방법 2를 통해 구한 답\n");
	for (int i = 0; i < 3; i++)
	{
		printf("arr 배열의 %d번째 행의 합은 %d 입니다.\n", i + 1, result2[i]);
	}

	return 0;
}

//2번 문제 방법 1
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

//2번 문제 방법 2 (2차원 배열이 메모리 상에서는 1차원 형태로 주소값이 지정되는 것을 활용)
void arr_sum2(int* arr, int total[])
{
	for (int i = 0; i < 16; i = i + 4) //i값을 4씩 증가.
	{
		int sum = 0;
		for (int j = 0; j < 4; j++) //i값에 j값을 1씩 증가하면서 행의 합 계산
		{
			sum += *(arr + i + j);
		}
		total[i / 4] = sum; //i값이 4씩 증가하므로, 4로 나눈 값을 인덱스값으로 활용
	}
}


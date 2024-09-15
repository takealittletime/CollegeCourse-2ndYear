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
	
	// 함수 매개변수 n을 입력
	printf("n값을 입력하시오:");
	scanf_s("%d", &n);
	clock_t start, end;

	// fun_1 함수의 실행 소요 시간 측정
	start = clock();
	sum = fun_1(n); // 매개변수 배열을 제외 => 함수 코드에서 조건문 삭제.
	end = clock();

	//fun_1 함수 결괏값 출력
	printf("fun_1 함수의 결괏값: %d\n", sum);

	// 소요 시간을 msec 단위로 출력
	elapsed = (end - start) / CLOCKS_PER_SEC;
	printf("fun_1 함수 소요 시간 : %lf\n", elapsed);

	// fun_2 함수의 실행 소요 시간 측정
	start = clock();
	sum = fun_2(n); // 매개변수 배열을 제외 => 함수 코드에서 조건문 삭제.
	end = clock();

	//fun_2 함수 결괏값 출력
	printf("\nfun_2 함수의 결괏값: %d\n", sum);

	// 소요 시간을 msec 단위로 출력
	elapsed = (end - start) / CLOCKS_PER_SEC;
	printf("fun_2 함수 소요 시간 : %lf\n", elapsed);


	return 0;
}
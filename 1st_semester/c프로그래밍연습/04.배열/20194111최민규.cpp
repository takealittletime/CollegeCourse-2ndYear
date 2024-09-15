#include <stdio.h>

int main(void)
{
	//1번 문제
	int num[5] = { 0 }; //크기가 5인 정수의 배열 num 선언 및 초기화

	//5개 정수 입력
	printf("5개의 정수를 입력하시오:");
	scanf_s("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

	//크기 비교, 합계 계산을 위한 정수 변수들 선언
	int tmp = num[0], big = num[0], small = num[0],sum = 0;

	//5번 반복하면서 최대, 최솟값 계산 및 합계 계산
	for (int i = 0; i < 5; i++)
	{
		sum += num[i]; //배열 안의 값들의 총합 계산

		//최대, 최솟값 계산
		if (tmp < num[i]) //배열 값의 대소를 각각 비교
		{
			big = num[i]; //큰 값을 big에 할당
		}

		else
		{
			small = num[i]; //작은 값을 small에 할당
		}
	}

	//결과 출력
	printf("\n\n최대값: %d , 최소값: %d , 총 합 : %d\n", big, small, sum);

	//2번 문제
	char string[50] = { 0 }; //크기가 50인 문자열 string을 선언 및 초기화
	int len = 0; //문자열의 길이를 할당하기 위한 정수형 변수 len 선언 및 초기화

	//문자열 입력
	printf("\n\n문자열 입력:");
	scanf("%s", string);

	//문자열의 길이 계산
	for (int i = 0; i < 50; i++)
	{
		//문자열 string에서 NULL문자를 만나면 반복문 탈출
		if (string[i] == NULL)
			break;

		//정수 len에 1을 반복해서 더해줌.
		len += 1;
	}

	//반복문을 활용 해 문자열 거꾸로 출력
	printf("\n거꾸로 출력 :");
	for (int j = len; j > -1; j--)
	{
		printf("%c", string[j]);

	}

	//문자열 입력에서 엔터가 중복으로 처리되는 문제 해결을 위해 getchar(); 이용
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

	//3번 문제
	char str[50] = { 0 }; //크기가 50인 문자열 str 선언 및 초기화
	int leng = 0; // 문자열의 길이를 할당하기 위한 정수형 변수 leng 선언 및 초기화

	//문자열 입력
	printf("\n\n\n문자열 입력:");
	gets_s(str,50);

	//문자열의 길이 계산
	for (int i = 0; i < 50; i++)
	{
		//문자열 str에서 NULL문자를 만나면 반복문 탈출
		if (str[i] == NULL)
			break;

		//정수 leng에 1을 반복해서 더해줌.
		leng += 1;
	}

	//반복문을 활용 해 문자열 거꾸로 출력
	printf("\n거꾸로 출력: ");

	for (int j = leng; j > -1; j--)
	{
		printf("%c", str[j]);

	}

	printf("\n");

	return 0; //함수 값을 0으로 반환
	
}

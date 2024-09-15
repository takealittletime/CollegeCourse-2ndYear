#include <stdio.h> //표준 입출력 헤더 파일 추가
#include <stdlib.h> //난수  초기화를 위해 헤더 파일 추가

int main(void) //main 함수 선언
{
	srand(time(NULL)); //난수값 초기화
	int grade[5][4] = { 0 }; //세로 크기 5, 가로 크기 4인 2차원 배열 grade 선언 및 0으로 초기화
	
	//10보다 작은 난수 값으로 grade 배열 초기화
	for (int i = 3; i >= 0; i--)
	{
		for (int k = 2; k >= 0; k--)
		{
			grade[i][k] = rand() % 10;
		}
	}

	//학생 별 총점 계산
	for (int a = 0; a < 4; a++) //배열 세로의 인덱스 3까지 반복
	{
		int sum = 0; //총점을 할당할 정수형 변수 sum 선언 및 0으로 초기화
		for (int b = 0; b < 3; b++) //배열 가로의 인덱스 2까지 반복
		{
			sum += grade[a][b]; //변수 sum에 grade[a][b] 값을 더함
		}
		grade[a][3] = sum; //grade[a][3]에 변수 sum을 할당
	}

	//과목 별 총점 계산
	for (int c = 0; c < 3; c++) //배열 가로의 인덱스 2까지 반복
	{
		int total = 0; //총점을 할당할 정수형 변수 total 선언 및 0으로 초기화
		for (int d = 0; d < 4; d++) //배열 세로의 인덱스 4까지 반복
		{
			total += grade[d][c]; //변수 total에 grade[d][c] 값을 더함
		}

		grade[4][c] = total; //grade[4][c]에 변수 total을 할당
	}

	//결과 출력
	printf("      성 명 국어 영어 수학 총점\n");
	for (int e = 0; e < 5; e++)
	{
		if (e == 0)
			printf("      철 희");
		if (e == 1)
			printf("      철 수");
		if (e == 2)
			printf("      영 희");
		if (e == 3)
			printf("      영 수");
		if (e == 4)
			printf("과목별 총점");

		for (int f = 0; f < 4; f++)
		{
			printf("%4d ", grade[e][f]);
		}
		printf("\n");
	}

	return 0; //함수의 값을 0으로 반환
}
#include <stdio.h> //표준 입출력 헤더파일 추가

int main(void) //main 함수 선언
{
	int height = 0; //크리스마스 트리의 높이를 입력받을 정수형 변수 선언 및 초기화

	//크리스마스 트리의 높이 입력
	printf("크리스마스 트리 높이를 입력하세요:");
	scanf("%d", &height);

	//반복문을 이용 해 크리스마스 트리 출력
	for (int i = 1; i < height+1; i++)
	{
		//오른쪽으로 치우치게하기 위해 height - i만큼 공백 출력
		for (int k = 0; k < height - i; k++)
		{
			printf(" ");
		}

		//문자열 "*"을 줄마다 i의 크기만큼 출력
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}

		//줄바꿈
		printf("\n");
	}

	return 0; //함수의 값을 0으로 반환
}
//20194111 최민규
#include <stdio.h>

//1번 문제
#define MAX(a,b,c) (((a)>(b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c))) 
//a,b먼저 비교 후 각각 c와 비교

int main(void)
{
	printf("<20194111 최민규>\n1번 문제\n2번 문제는 따로 주석처리를 해 놓았으니, 주석을 풀고 실행하세요.\n");
	int num1, num2, num3;

	printf("정수 세 개를 입력하세요:");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	printf("세 정수 중 가장 큰 값은 %d 입니다.\n", MAX(num1, num2, num3));

	return 0;
}

//2번 문제
/*
#define UPCASE(c) (( (c)>='a' && (c)<='z') ? (c)-('a'-'A') : (c)) //소문자를 대문자로 바꾸는 매크로 함수
#define LOCASE(c) (( (c)>='A' && (c)<='Z') ? (c)+('a'-'A') : (c))//대문자를 소문자로 바꾸는 매크로 함수

void change(char str[])
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = UPCASE(str[i]);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = LOCASE(str[i]);
		i++;
	}
}

int main(void)
{
	printf("\n2번 문제\n\n");

	char str[100];
	printf("문자열을 입력하세요:");
	gets_s(str, sizeof(str));

	printf("원래 문자열: %s\n", str);
	change(str);
	printf("대소문자 변환 후: %s\n", str);
	return 0;
}
*/
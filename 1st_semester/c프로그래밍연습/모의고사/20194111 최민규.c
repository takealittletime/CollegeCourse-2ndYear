//C프로그래밍 모의고사 2020.04.20.
//20194111 최민규

#include <stdio.h>

void isOdd(int arr[]); //1번 문제 홀수 출력 함수의 원형
void isEven(int arr[]); //1번 문제 짝수 출력 함수의 원형
void clearLine(void); //\n을 버리는 함수의 원형

/*clearLine함수는 2번 문제에서 수를 입력받고 엔터를 누르면
3번 문제에서 문자열 입력을 넘어가버리는 탓에 사용하였다.*/

int isPalin(char arr[], int len); //3번 문제 회문 판단 함수의 원형

int main()
{
	printf("20194111 최민규\n\n");

	//1번 문제
	/*길이가 10인 배열을 선언하고 총 10개의 정수를 입력 받아서, 홀수와 짝수를 구분 지어 출력하는 프로그램을 작성해 보자.
	일단 홀수부터 출력하고나서 짝수를 출력하도록 하자.
	단, 10개의 정수는 main 함수 내에서 입력 받도록 하고, 배열 내에 존재하는 홀수만 출력하는 함수와
	배열 내에 존재하는 짝수만 출력하는 함수를 각각 정의해서 이 두 함수를 호출하는 방식으로 프로그램을 완성하자.
	*/
	int arr1[10] = { 0 };

	printf("<<1번 문제>>\n총 10개의 숫자 입력\n");
	for (int i = 0; i < 10; i++)
	{
		printf("입력: ");
		scanf_s("%d", &arr1[i]);
		clearLine();
	}

	isOdd(arr1);
	printf("\n");
	isEven(arr1);

	//2번 문제
	/* 길이가 10인 배열을 선언하고 총 10개의 정수를 입력 받는다.
	단, 입력 받은 숫자가 홀수이면 배열의 앞에서부터 채워나가고, 짝수이면 뒤에서부터 채워나가는 형식을 취하기로 하자.
	*/
	int arr2[10] = { 0 };
	int odd = 0, even = 9;

	printf("\n\n<<2번 문제>>\n총 10개의 숫자 입력\n");

	for (int i = 0; i < 10; i++)
	{
		int inp;
		printf("입력: ");
		scanf_s("%d", &inp);
		clearLine();

		if (inp % 2 == 0)
		{
			arr2[even] = inp;
			even--;
		}

		else
		{
			arr2[odd] = inp;
			odd++;
		}
	}

	printf("배열 요소의 출력: ");
	for (int j = 0; j < 10; j++)
		printf("%d ", arr2[j]);

	//3번 문제
	/*회문(Palindrome)은 앞으로 읽으나 뒤로 읽으나 차이가 없는 단어들을 뜻한다.
	예를 들어서 level, bob과 같은 단어들은 회문에 속한다.
	이에 우리는 인자로 전달되는 영단어가 회문인지 아닌지를 판단해서 그 결과를 출력하는 기능의 함수를 정의하고,
	이에 적절한 main 함수를 정의해 보고자 한다.
	단구현의 편의를 위해서 대소문자까지 일치해야 회문으로 인정하기로 하겠다.
	(이는 어디까지나 구현의 편의를 고려한제약사항일 뿐이다).
	*/

	printf("\n\n<<3번 문제>>\n");
	char str[50] = { 0 };

	printf("문자열 입력:");
	gets_s(str, 50);

	printf("\n");

	if (isPalin(str, strlen(str)) == 1)
	{
		printf("%s은(는) 회문입니다.\n", str);
	}
	else
	{
		printf("%s은(는) 회문이 아닙니다.\n", str);
	}

	return 0;
}

void isOdd(int arr[]) //1번 문제 홀수 출력 함수
{
	printf("홀수 출력: ");
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 != 0)
			printf("%d ", arr[i]);
	}
}

void isEven(int arr[]) //1번 문제 짝수 출력 함수
{
	printf("짝수 출력: ");
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
			printf("%d ", arr[i]);
	}
}

void clearLine(void) //\n을 버리는 함수
{
	while (getchar() != '\n');
}

int isPalin(char arr[], int len)  //3번 문제 회문 판단 함수
{
	int j = len - 1;
	int result = 1;

	for (int i = 0; i < len / 2; i++) {

		if (arr[i] != arr[j]) {

			result = 0;

			break;

		}
		j--;

	}

	return result; //회문이면 1, 아니면 0 반환
}

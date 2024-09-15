#include <stdio.h> //표준 입출력 헤더 파일 추가

int main(void) //main 함수 선언
{
	//1번 문제
	printf("<1번 문제>\n\n");
	int num1 = 20, num2 = 30; //int형 변수 num1과 num2를 선언과 동시에 20,30으로 초기화
	int* ptr1 = &num1, * ptr2 = &num2; //num1, num2를 각각 가리키는 포인터 변수 ptr1, ptr2 선언

	//증감 전 num1, *ptr1, num2, *ptr2를 각각 출력
	printf("(증감 전)\nnum1 = %d, *ptr1 = %d\nnum2 = %d, *ptr2 = %d\n\n", num1, *ptr1, num2, *ptr2);

	*ptr1 += 10; *ptr2 -= 20; //ptr1과 ptr2를 이용하여 num1을 10 증가, num2를 20 감소

	//증감 후 num1, *ptr1, num2, *ptr2를 각각 출력
	printf("(증감 후)\nnum1 = %d, *ptr1 = %d\nnum2 = %d, *ptr2 = %d\n\n", num1, *ptr1, num2, *ptr2);

	//2번 문제
	printf("<2번 문제>\n\n");
	int arr[5] = { 1,2,3,4,5 }; //길이가 5인 int형 배열 arr을 선언하고, 이를 1, 2, 3, 4, 5로 초기화
	int* ptr = &arr[4]; //마지막 요소를 가르키는 포인터 변수 ptr을 선언
	int sum = 0; //배열의 총합을 할당할 정수형 변수 sum 선언 및 0으로 초기화

	//배열 요소의 총합을 구하고, 배열 요소를 거꾸로 출력
	for (int i = 4; i >= 0; i--) //배열의 크기만큼 반복
	{
		printf("ptr[%d] = %d\n", i, *ptr); //배열 뒤쪽 요소부터 출력
		sum += *ptr; //정수형 변수 sum에 배열 뒤쪽 요소부터 더함
		ptr--; //ptr 포인터가 배열 요소의 앞을 가리키게끔 -- 연산
	}

	//배열 요소의 총합 출력
	printf("배열 arr의 요소의 총 합 = %d\n\n", sum);

	//3번 문제
	printf("<3번 문제>\n\n");
	int arr2[6] = { 1,2,3,4,5,6 }; //길이가 6인 int형 배열 arr을 선언, 이를 1,2,3,4,5,6으로 초기화
	//함수의 앞쪽을 가리키는 포인터 front, 뒤 쪽을 가리키는 포인터 back 선언
	int* front = &arr2[0]; int* back = &arr2[5];

	//수정 전 배열 출력
	printf("수정 전 배열:");
	for (int j = 0; j < 6; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");

	for (int i = 0; i < 3; i++) //배열 크기 절반 만큼 반복
	{
		int tmp = *front; //정수형 변수 tmp에 배열 앞쪽 포인터가 가리키는 값을 할당
		arr2[i] = *back; //배열 앞쪽을 뒤쪽 포인터가 가리키는 값으로 할당
		arr2[5 - i] = tmp; //배열 뒤쪽을 변수 tmp가 가진 값으로 할당
		front++; //배열 앞쪽을 가리키는 포인터가 다음 배열 요소를 가리키도록 ++ 연산
		back--; //배열 뒤쪽을 가리키는 포인터가 이전 배열 요소를 가리키도록 -- 연산
	}

	//수정 후 배열 출력
	printf("수정 후 배열:");
	for (int j = 0; j < 6; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");

	return 0; //함수의 값을 0으로 반환
}
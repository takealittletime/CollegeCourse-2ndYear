//20194111 최민규

#include<stdio.h> //표준 입출력 헤더 파일
#define MAX_SIZE 100 //스택의 최대 크기


typedef struct { //스택 타입 정의
	int stack[MAX_SIZE];
	int top;
}stack_type;

typedef stack_type* stack_ptr;

void init(stack_ptr p) //스택 초기화 함수
{
	p->top = -1;
}

void push(stack_ptr p, char add) //스택 입력 함수
{
	if (is_full(*p))
	{
		printf("스택이 가득 찼습니다. 더 이상 추가할 수 없습니다.\n");
		return;
	}

	else
	{
		(p->top)++;
		p->stack[p->top] = add;
	}

}

char pop(stack_ptr p)  //스택 값 제거 및 값 반환 함수
{
	if (is_empty(*p))
	{
		printf("스택이 비었습니다. 더 이상 제거할 수 없습니다.");
		return;
	}

	else
	{
		char result = p->stack[p->top];
		(p->top)--;

		return result;
	}
}

int is_empty(stack_type s) // 스택이 비었는지 확인하는 함수
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}

int is_full(stack_type s) //스택이 가득 찼는지 확인하는 함수
{
	if (s.top == MAX_SIZE)
		return 1;
	else
		return 0;
}

int peek(stack_type s) //스택 값을 읽어 반환하는 함수
{
	return s.stack[s.top];
}

int reverse(int n) //정수를 거꾸로 반환하는 함수
{
	stack_type s;

	init(&s);

	int result = 0;

	while (n != 0) //정수를 각 자리별로 분해해 스택에 할당
	{
		push(&s, n % 10);
		n /= 10;
	}

	//(각 자리수로 나누어진 정수들을 스택에서 꺼내 조립하는 작업)
	int i = 0; //10을 곱해줄 횟수
	while (!is_empty(s)) //스택 stc가 빌 때까지 반복
	{
		int digit = pop(&s); //정수 하나 꺼냄
		for (int j = 0; j < i; j++)
		{
			digit *= 10; //정수에 i의 횟수만큼 10을 곱함
		}
		i++; // i 증가
		result += digit; //result에 값을 더해줌
	}

	return result; //result를 반환
}

int main(void)
{
	int num = 1234567;

	printf("%d -> %d\n", num, reverse(num));

	return 0;
}
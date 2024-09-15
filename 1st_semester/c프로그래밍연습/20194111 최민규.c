#include <stdio.h>
#include <string.h>

typedef enum engweek //요일의 영어 열거형
{
MON = 1, TUE = 2, WED = 3, THURS = 4, FRI = 5, SATUR = 6, SUN = 7
} engweek;

typedef enum korweek //요일의 한글 열거형
{
월 = 1, 화 = 2, 수 = 3, 목 = 4, 금 = 5, 토 = 6, 일 = 7
} korweek;

void eng_print(int day) // 영어로 날짜 출력
{
	switch (day)
	{
	case MON:
		puts("Today is Monday"); return;
	case TUE:
		puts("Today is Tuesday"); return;
	case WED:
		puts("Today is Wednesday"); return;
	case THURS:
		puts("Today is Thursday"); return;
	case FRI:
		puts("Today is Friday"); return;
	case SATUR:
		puts("Today is Saturday"); return;
	case SUN:
		puts("Today is Sunday"); return;
	default:
		puts("입력이 잘못되었습니다.\n");return;
	}
}

void kor_print(int day) //한글로 날짜 출력
{
	switch (day)
	{
	case 월:
		puts("오늘은 월요일입니다.\n"); return;
	case 화:
		puts("오늘은 화요일입니다.\n"); return;
	case 수:
		puts("오늘은 수요일입니다.\n"); return;
	case 목:
		puts("오늘은 목요일입니다.\n"); return;
	case 금:
		puts("오늘은 금요일입니다.\n"); return;
	case 토:
		puts("오늘은 토요일입니다.\n"); return;
	case 일:
		puts("오늘은 일요일입니다.\n"); return;

	default:
		puts("입력이 잘못되었습니다.\n");return;
	}
}

int main(void)
{
	char day[5];
	int today = 0;
	//사용자 입력
	printf("오늘은 무슨 요일입니까?:");
	scanf("%s", day);
	
	//입력에 맞게 today값 설정
	if (!strcmp(day,"월"))
		today = 1;
	else if (!strcmp(day, "화"))
		today = 2;
	else if (!strcmp(day, "수"))
		today = 3;
	else if (!strcmp(day, "목"))
		today = 4;
	else if (!strcmp(day, "금"))
		today = 5;
	else if (!strcmp(day, "토"))
		today = 6;
	else if (!strcmp(day, "일"))
		today = 7;

	eng_print(today); //영어 출력
	kor_print(today); //한글 출력

	return 0;
}
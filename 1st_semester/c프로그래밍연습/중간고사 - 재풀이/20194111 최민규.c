#include <stdio.h>

int total(int n)
{
	if (n <= 0)
		return 0;
	else
		return (n + total(n - 2));
}

int main(void)
{
	puts("<1번>");
	int year = 0;
	printf("태어난 년도는?");
	scanf_s("%d", &year);
	printf("%d년에 태어났으므로, %d 살입니다.\n\n", year,2019 - year);
	getchar();

	
	puts("<2번>");
	char num[20];
	int x = 0;
	printf("주민 등록 번호는?");
	gets_s(num, sizeof(num));

	while (num[x] != NULL)
	{
		if (num[x - 1] == '-')
		{
			if (num[x] == '1' || num[x] == '3')
				printf("남자입니다.\n");
			else
				printf("여자입니다.\n");
		}
		x++;
	}
	
	puts("<3번>");
	int grd = 0;
	printf("성적 입력?");
	scanf_s("%d", &grd);

	switch (grd / 10) {
	case 10:
	case 9:
		printf("\'A학점\'\n\n");
		break;
	case 8:
		printf("\'B학점\'\n\n");
		break;
	case 7:
		printf("\'C학점\'\n\n");
		break;
	default:
		printf("\'D학점\'\n");
		break;
	}

	puts("<4번>");
	int n = 0,sum = 0;
	printf("정수를 입력하세요:");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i += 2)
	{
		sum += i;
	}

	printf("반복으로 구한 답: %d\n", sum);
	printf("재귀로 구한 답: %d\n\n", total(n));

	puts("<5번>");
	puts("2차원 배열");
	char dict[4][20] = { "apple","pear","strawberry","orange" };
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", dict[i]);
	}
	printf("\n");
	puts("포인터 배열");
	char* ptr[4];
	ptr[0] = "apple";
	ptr[1] = "pear";
	ptr[2] = "strawberry";
	ptr[3] = "orange";

	for (int k = 0; k < 4; k++)
		printf("%s\n", ptr[k]);
	printf("\n\n");
	//5 - c 못품

	puts("<6번>");
	char prb[100] = "I am a boy. You are a girl!";

	puts("<공백 기준>");
	int z = 0,len = 0;
	int sI = 0, sa = 0, sm = 0, sb = 0, so = 0, sy = 0, sY = 0, sr = 0, se = 0, sg = 0, si = 0,sl = 0;
	
	while (prb[z] != NULL)
	{
		if (prb[z] != ' ' && prb[z] != NULL)
		{
			printf("%c", prb[z]);
			len++;
			switch (prb[z])
			{
			case 'I':
				sI++;
				break;
			case 'a':
				sa++;
				break;
			case 'm':
				sm++;
				break;
			case 'b':
				sb++;
				break;
			case 'o':
				so++;
				break;
			case 'y':
				sy++;
				break;
			case 'Y':
				sY++;
				break;
			case 'r':
				sr++;
				break;
			case 'e':
				se++;
				break;
			case 'g':
				sg++;
				break;
			case 'i':
				si++;
				break;
			case 'l':
				sl++;
			default:
				break;
			}
		}

		else
		{
			printf("%d ",len);
			len = 0;

		}
		z++;
	}
	printf("%d \n\n", len);
	printf("<알파벳 기준>\n");

	printf("I = %d , a = %d, m = %d, b = %d, o = %d, y = %d, Y = %d, r = %d, e = %d, g = %d, i = %d, l = %d\n",
		sI, sa, sm, sb, so, sy, sY, sr, se, sg, si, sl);
	
	return 0;
}
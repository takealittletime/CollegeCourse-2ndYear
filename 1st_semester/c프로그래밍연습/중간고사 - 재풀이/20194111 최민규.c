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
	puts("<1��>");
	int year = 0;
	printf("�¾ �⵵��?");
	scanf_s("%d", &year);
	printf("%d�⿡ �¾���Ƿ�, %d ���Դϴ�.\n\n", year,2019 - year);
	getchar();

	
	puts("<2��>");
	char num[20];
	int x = 0;
	printf("�ֹ� ��� ��ȣ��?");
	gets_s(num, sizeof(num));

	while (num[x] != NULL)
	{
		if (num[x - 1] == '-')
		{
			if (num[x] == '1' || num[x] == '3')
				printf("�����Դϴ�.\n");
			else
				printf("�����Դϴ�.\n");
		}
		x++;
	}
	
	puts("<3��>");
	int grd = 0;
	printf("���� �Է�?");
	scanf_s("%d", &grd);

	switch (grd / 10) {
	case 10:
	case 9:
		printf("\'A����\'\n\n");
		break;
	case 8:
		printf("\'B����\'\n\n");
		break;
	case 7:
		printf("\'C����\'\n\n");
		break;
	default:
		printf("\'D����\'\n");
		break;
	}

	puts("<4��>");
	int n = 0,sum = 0;
	printf("������ �Է��ϼ���:");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i += 2)
	{
		sum += i;
	}

	printf("�ݺ����� ���� ��: %d\n", sum);
	printf("��ͷ� ���� ��: %d\n\n", total(n));

	puts("<5��>");
	puts("2���� �迭");
	char dict[4][20] = { "apple","pear","strawberry","orange" };
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", dict[i]);
	}
	printf("\n");
	puts("������ �迭");
	char* ptr[4];
	ptr[0] = "apple";
	ptr[1] = "pear";
	ptr[2] = "strawberry";
	ptr[3] = "orange";

	for (int k = 0; k < 4; k++)
		printf("%s\n", ptr[k]);
	printf("\n\n");
	//5 - c ��ǰ

	puts("<6��>");
	char prb[100] = "I am a boy. You are a girl!";

	puts("<���� ����>");
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
	printf("<���ĺ� ����>\n");

	printf("I = %d , a = %d, m = %d, b = %d, o = %d, y = %d, Y = %d, r = %d, e = %d, g = %d, i = %d, l = %d\n",
		sI, sa, sm, sb, so, sy, sY, sr, se, sg, si, sl);
	
	return 0;
}
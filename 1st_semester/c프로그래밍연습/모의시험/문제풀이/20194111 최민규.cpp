#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//1번 문제
typedef struct caffe {
	char name[20]; //음료 이름
	int price; //음료 가격
}caf;

int main(void)
{
	printf("20194111 최민규\n");
	printf("교수님, 문제 별로 주석 처리를 해 놓았으니, 2번 문제는주석을 풀고 실행해주세요.\n\n");
	caf pos[100];
	int in = 0;
	int idx = 0;

	while (1)
	{
		printf("1:음료 추가 2:음료 삭제 3:음료 검색 4:주문한 목록 5:결제 금액 6:종료? ");
		scanf_s("%d", &in);

		if (in == 1)
		{

			printf("추가할 음료의 이름과 가격을 입력하세요:");
			scanf_s("%s %d", &pos[idx].name,sizeof(pos[idx].name), &pos[idx].price);
			idx++;
		}

		else if (in == 2) //(삭제 메뉴는 미완성)
		{
			char del[20];
			printf("삭제할 음료의 이름을 입력하세요:");
			scanf_s("%s", del,sizeof(del));
			int check = 0;
			for (int i = 0; i < idx; i++)
			{
				if ((strcmp(pos[i].name, del))==0)
				{
					check = 1;
					for (int j = idx; j >i; j--)
					{
						strcpy_s(pos[j - 1].name, pos[j].name);
						pos[j - 1].price = pos[j].price;
					}
					printf("%s를 삭제했습니다.\n", del);
					break;
				}
			}

			if (check == 0)
			{
				printf("%s를 찾지 못했습니다. 음료의 이름을 다시 확인해주세요.\n",del);
			}
			
		}

		else if (in == 3)
		{
			char srch[20];
			printf("검색할 음료의 이름을 입력하세요:");
			scanf_s("%s",srch, sizeof(srch));

			printf("전체 이름으로 검색...\n");
			for (int i = 0; i < idx; i++)
			{
				if (strcmp(pos[i].name, srch) == 0)
				{
					printf("%s을(를) 찾았습니다.\n", pos[i].name);
				}
			}
			printf("\n→철자로 검색...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(pos[i].name, srch) != 0)
				{
					printf("%s을(를) 찾았습니다.\n", pos[i].name);
				}
			}
		}

		else if (in == 4)
		{
			printf("주문한 목록은 다음과 같습니다.\n");

			for (int i = 0; i < idx; i++)
			{
				printf("%s %d\n", pos[i].name, pos[i].price);
			}
			printf("\n");
		}

		else if (in == 5)
		{
			int total = 0;

			for (int i = 0; i < idx; i++)
			{
				total += pos[i].price;
			}

			printf("총 결제 금액은 %d 원입니다.\n",total);
		}

		else if (in == 6)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		else
		{
		printf("존재하지 않는 명령입니다. 입력을 다시 한 번 확인하세요.\n");
		}
	}

	return 0;
}


/*
//2번 문제
typedef struct student {
	char name[10];
	int num1;
	int num2;
	int num3;
	int num4;
	int total;
	double avr;
	char grade[5];
}st;

int main(void)
{
	printf("20194111 최민규\n");
	printf("교수님, 문제 별로 주석 처리를 해 놓았으니 1번 문제는 주석을 풀고 실행해주세요.\n\n");
	FILE* src;
	FILE* des;

	fopen_s(&src, "score_src_new.txt", "rt");
	fopen_s(&des, "score_grade.txt", "wt");

	if (src == NULL || des == NULL)
	{
		printf("파일 오픈 오류!\n");
		return -1;
	}

	int in = 0;
	char str[100];

	st grd[100];

	int i;
	i = 0;
	while (feof(src) == 0) {
		char num1[20];
		char num2[20];
		char num3[20];
		char num4[20];
		fscanf_s(src, "%s %s %s %s %s", grd[i].name, sizeof(grd[i].name),num1,sizeof(num1),num2,sizeof(num2),num3,sizeof(num3),num4,sizeof(num4));
		// 점수에 ,를 없애주는 작업
		for (int k = 0; k < 20; k++)
		{
			if (num1[k] == ',')
			{
				num1[k] = NULL;
			}

			if (num2[k] == ',')
			{
				num2[k] = NULL;
			}


			if (num3[k] == ',')
			{
				num3[k] = NULL;
			}


			if (num4[k] == ',')
			{
				num4[k] = NULL;
			}
		}

		grd[i].num1 = atoi(num1);
		grd[i].num2 = atoi(num2);
		grd[i].num3 = atoi(num3);
		grd[i].num4 = atoi(num4);
		i++;
	}
	i--;

	while (1)
	{

		printf("1:성적 출력 2:총점, 평균 계산 3:학점 부여 후 출력 4:파일 저장 5:프로그램 종료?");
		scanf_s("%d", &in);


		if (in == 1)
		{
			printf("<성적 출력>\n");
			for (int j = 0; j < i; j++)
			{
				printf("%s %d %d %d %d\n", grd[j].name, grd[j].num1, grd[j].num2, grd[j].num3, grd[j].num4);
			}
			printf("\n");
		}

		else if (in == 2)
		{
			int total = 0;
			double avr = 0;
			printf("<총점, 평균 계산>\n");

			for (int k = 0; k < i; k++)
			{
				total = 0;
				avr = 0;

				total += grd[k].num1 + grd[k].num2 + grd[k].num3 + grd[k].num4;
				grd[k].total = total;

				avr = total / 4;
				grd[k].avr = avr;
			}
		}

		else if (in == 3)
		{
			printf("<학점 부여 후 출력>\n"); //박택훈에서 왜 문제가 생기는지 해결 못함..

			for (int k = 0; k < i; k++)
			{
				if (grd[k].avr >= 95)
					strcpy_s(grd[k].grade, "A+");
				else if (grd[k].avr >= 90)
					strcpy_s(grd[k].grade, "A");
				else if (grd[k].avr >= 85)
					strcpy_s(grd[k].grade, "B+");
				else if (grd[k].avr >= 80)
					strcpy_s(grd[k].grade, "B");
				else if (grd[k].avr >= 75)
					strcpy_s(grd[k].grade, "C+");
				else if (grd[k].avr >= 70)
					strcpy_s(grd[k].grade, "C");
				else if (grd[k].avr >= 65)
					strcpy_s(grd[k].grade, "D+");
				else if (grd[k].avr >= 60)
					strcpy_s(grd[k].grade, "D");
				else if (grd[k].avr < 60)
					strcpy_s(grd[i].grade, "F");

				printf("%s %d %d %d %d %d %lf %s\n", grd[k].name, grd[k].num1, grd[k].num2, grd[k].num3, grd[k].num4,grd[k].total, grd[k].avr, grd[k].grade);
			}
		}

		else if (in == 4)
		{
			printf("<파일 저장>\n");
			for (int k = 0; k < i; k++)
			{
				fprintf(des,"% s% d% d% d% d% d% lf% s\n", grd[k].name, grd[k].num1, grd[k].num2, grd[k].num3, grd[k].num4,grd[k].total, grd[k].avr, grd[k].grade);
			}
			printf("파일 저장 완료\n");
		}


		else if (in == 5)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}
	}

	fclose(src);
	fclose(des);

	return 0;
}
*/
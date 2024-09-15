//20194111 최민규
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("20194111 최민규\n\n");
	/*
	//1번 문제
	FILE* fp;
	fopen_s(&fp, "text.txt", "rt");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		return -1;
	}

	char str[100];
	while (fgets(str,sizeof(str),fp)!=NULL)
	{
		puts(str);
	}

	fclose(fp);
	return 0;
	*/
	
	//2번 문제
	FILE * fp;
	fopen_s(&fp, "std.txt", "rt");

	FILE* fp1;
	fopen_s(&fp1, "out.txt", "wt");

	FILE* fp2;
	fopen_s(&fp2, "grouping.txt", "wt");

	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		return -1;
	}

	int num; //학번
	char name[10]; //이름
	char locate[5]; //지역
	char sex[5]; //성별
	int age; //나이
	char phone[20]; //전화번호
	double gpa; //학점
	char traffic[10]; //교통수단

	int ret,inp,men = 0, girl = 0;


	//학점 3~4인 친구들만 out.txt파일에 출력
	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
			break;
		}
		
		if (!strcmp(sex, "남"))
			men++;

		if (!strcmp(sex, "여"))
			girl++;

		if (3<=gpa && gpa <= 4)
		{
			fprintf(fp1,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
		}
	}
	fseek(fp, 0, SEEK_SET);

	fclose(fp1);

	fprintf(fp2,"남학생 %d명, 여학생 %d명\n",men,girl);
	fprintf(fp2,"<남학생>\n");

	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
			break;
		}

		else if (!strcmp(sex,"남"))
		{
			fprintf(fp2,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
		}
	}

	fseek(fp, 0, SEEK_SET);

	fprintf(fp2,"<여학생>\n");

	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
		}

		else if (!strcmp(sex,"여"))
		{
			fprintf(fp2,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
			break;
		}
	}

	fseek(fp, 0, SEEK_SET);

	fclose(fp2);

	while (1) {
		printf("원하는 검색을 입력하세요.(1: 이름), (2: 학번), (3: 종료) 숫자만 입력:");
		scanf_s("%d", &inp);

		if (inp == 1)
		{
			char src[10];
			printf("이름을 입력하세요:");
			scanf_s("%s", src, sizeof(src));

			while (1)
			{
				ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

				if (ret == EOF)
				{
					printf("검색하신 정보를 찾을 수 없습니다.\n");
					fseek(fp, 0, SEEK_SET);
					break;
				}

				else if (!strcmp(name, src))
				{
					printf("%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
					fseek(fp, 0, SEEK_SET);
					break;
				}
			}
		}

		else if (inp == 2)
		{
			int src;
			printf("학번을 입력하세요:");
			scanf_s("%d", &src);

			while (1)
			{
				ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name,sizeof(name), locate,sizeof(locate), sex,sizeof(sex), &age, phone,sizeof(phone), &gpa, traffic,sizeof(traffic));

				if (ret == EOF)
				{
					printf("검색하신 정보를 찾을 수 없습니다.\n");
					fseek(fp, 0, SEEK_SET);
					break;
				}

				else if (num == src)
				{
					printf("%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
					fseek(fp, 0, SEEK_SET);
					break;
				}
			}
		}

		else if (inp == 3)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		else
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
	}
	fclose(fp);

	return 0;
	
}
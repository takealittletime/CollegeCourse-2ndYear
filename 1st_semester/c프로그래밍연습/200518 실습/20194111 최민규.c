//2020.05.18 C프로그래밍 연습 예제
//20194111 최민규

#include <stdio.h>

int main(void)
{
	/*

	FILE* fp = fopen("simple.txt", "wt");
	if (fp == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}
	else
		puts("파일오픈 성공!");


	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp);
	fputs("Your name is Yoon \n", fp);
	fclose(fp);
	return 0;
	
	//수업 예제 2번
	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt");
	if (fp == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}
	ch = fgetc(fp);
	printf("%c\n", ch);
	ch = fgetc(fp);
	printf("%c\n", ch);
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fclose(fp);
	return 0;
	*/
	/*
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	int ch;
	if (src == NULL || des == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	while ((ch = fgetc(src)) != EOF)
		fputc(ch, des);
	if (feof(src) != 0)
		puts("파일 복사 완료!");
	else
		puts("파일 복사 실패!");
	fclose(src);
	fclose(des);
	return 0;
	//수업 예제 3번
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}
	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);

	if (feof(src) != 0)
		puts("파일복사 완료!");
	else
		puts("파일복사 실패!");

	fclose(src);
	fclose(des);

	return 0;*/

	FILE* src = fopen("src.bin", "rb");
	FILE* des = fopen("dst.bin", "wb");
	char buf[20];
	int readCnt;
	if (src == NULL || des == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	while (1)
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		if (readCnt < sizeof(buf))
		{
			if (feof(src) != 0)
			{
				fwrite((void*)buf, 1, readCnt, des);
				puts("파일 복사 완료");
				break;
			}
			else
				puts("파일 복사 실패");
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);
	return 0;
	
	
}
//2020.05.18 C���α׷��� ���� ����
//20194111 �ֹα�

#include <stdio.h>

int main(void)
{
	/*

	FILE* fp = fopen("simple.txt", "wt");
	if (fp == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	else
		puts("���Ͽ��� ����!");


	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp);
	fputs("Your name is Yoon \n", fp);
	fclose(fp);
	return 0;
	
	//���� ���� 2��
	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt");
	if (fp == NULL) {
		puts("���� ���� ����!");
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
		puts("���� ���� ����!");
		return -1;
	}

	while ((ch = fgetc(src)) != EOF)
		fputc(ch, des);
	if (feof(src) != 0)
		puts("���� ���� �Ϸ�!");
	else
		puts("���� ���� ����!");
	fclose(src);
	fclose(des);
	return 0;
	//���� ���� 3��
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);

	if (feof(src) != 0)
		puts("���Ϻ��� �Ϸ�!");
	else
		puts("���Ϻ��� ����!");

	fclose(src);
	fclose(des);

	return 0;*/

	FILE* src = fopen("src.bin", "rb");
	FILE* des = fopen("dst.bin", "wb");
	char buf[20];
	int readCnt;
	if (src == NULL || des == NULL) {
		puts("���� ���� ����!");
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
				puts("���� ���� �Ϸ�");
				break;
			}
			else
				puts("���� ���� ����");
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);
	return 0;
	
	
}
// 2020. 05. 19. ȭ
// 20194111 �ֹα�
#include <stdio.h>

int main(void)
{
	/*
	// ���� 1
	printf("20194111 �ֹα�\n");
	FILE* fp;
	fopen_s(&fp, "text.txt", "wt");
	fputs("123456789",fp);
		fclose(fp);
	fopen_s(&fp,"text.txt", "rt");
	fseek(fp, -2, SEEK_END);
	putchar(fgetc(fp));
	fseek(fp, 2, SEEK_SET);
	putchar(fgetc(fp));
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));
	fclose(fp);
	return 0;
	

	//���� 2
	long fpos;
	int i;

	FILE* fp;
	fopen_s(&fp, "text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);
	fopen_s(&fp,"text.txt", "rt");
	for (i = 0; i < 4; i++)
	{
		putchar(fgetc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);
	return 0; 
	*/

	
	//����3
	printf("20194111 �ֹα�\n");
	

	FILE* fp;
	fopen_s(&fp, "text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);
	fopen_s(&fp, "text.txt", "rt");
	fseek(fp, -2, SEEK_END);
	printf("\nù ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\nù ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	fseek(fp, 2, SEEK_SET);
	printf("\n�� ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\n�� ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	fseek(fp, 2, SEEK_CUR);
	printf("\n�� ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\n�� ��° ��� �� �ε��� ��ġ: %d\n", ftell(fp));
	fclose(fp);
	return 0;
}


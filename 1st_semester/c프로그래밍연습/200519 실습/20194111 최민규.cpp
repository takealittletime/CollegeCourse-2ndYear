// 2020. 05. 19. 화
// 20194111 최민규
#include <stdio.h>

int main(void)
{
	/*
	// 문제 1
	printf("20194111 최민규\n");
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
	

	//문제 2
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

	
	//문제3
	printf("20194111 최민규\n");
	

	FILE* fp;
	fopen_s(&fp, "text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);
	fopen_s(&fp, "text.txt", "rt");
	fseek(fp, -2, SEEK_END);
	printf("\n첫 번째 출력 전 인덱스 위치: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\n첫 번째 출력 후 인덱스 위치: %d\n", ftell(fp));
	fseek(fp, 2, SEEK_SET);
	printf("\n두 번째 출력 전 인덱스 위치: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\n두 번째 출력 후 인덱스 위치: %d\n", ftell(fp));
	fseek(fp, 2, SEEK_CUR);
	printf("\n세 번째 출력 전 인덱스 위치: %d\n", ftell(fp));
	putchar(fgetc(fp));
	printf("\n세 번째 출력 후 인덱스 위치: %d\n", ftell(fp));
	fclose(fp);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define A//A: 1번 문제, B: 2번 문제, C: 3번 문제, D: 4번 문제

/* <문제 1>
간단한 도서 관리용 프로그램을 작성해 보자.
[제목, 저자명, 페이지수]에 대한 정보를 저장할 수 있는 구조체를 정의하고,
구조체 배열을 선언해서 도서에 대한 정보를 저장하고 있는 구조로 작성해 보자.
main함수에서는 사용자로부터 3권의 도서에 대한 정보를 입력받고,
입력이 끝나면 도서에 대한 내용을 출력해 주도록하자.
*/
#ifdef A

#define MAX 20
typedef struct book {
	char title[MAX];
	char author[MAX];
	int page;
}book;

int main(void)
{
	book lib[3];

	printf("<20194111 최민규>\n교수님, 다른 문제를 실행하시려면 코드 맨 위의 매크로를 수정하세요.\n\n");
	printf("도서 정보 입력\n");
	for (int i = 0; i < 3; i++)
	{
		printf("저자: ");
		gets_s(lib[i].author, sizeof(lib[i].author));
		printf("제목: ");
		gets_s(lib[i].title, sizeof(lib[i].title));
		printf("페이지: ");
		scanf_s("%d", &lib[i].page);
		getchar(); //버퍼에 남아있는 엔터 처리
		printf("\n");
	}

	printf("\n\n도서 정보 출력\n");
	for (int k = 0;k < 3; k++)
	{
		printf("저자: %s\n", lib[k].author);
		printf("제목: %s\n", lib[k].title);
		printf("페이지: %d\n", lib[k].page);
		printf("\n");
	}

	return 0;
}
#endif

/* <문제2>
문제 1에서 구현한 프로그램에 변경을 조금 가하자.
구조체 배열을 선언하는 것이 아니라, 구조체 포인터 배열을 선언하고 
구조체 변수를 동적으로 할당하는 형태로 프로그램을 재 구현해보자.
*/
#ifdef B
#define MAX 20
typedef struct book {
	char title[MAX];
	char author[MAX];
	int page;
}book;

int main(void)
{
	book* lib[3];

	printf("<20194111 최민규>\n교수님, 다른 문제를 실행하시려면 코드 맨 위의 매크로를 수정하세요.\n\n");
	printf("도서 정보 입력\n");
	for (int i = 0; i < 3; i++)
	{
		lib[i] = (book*)malloc(sizeof(book));
		printf("저자: ");
		gets_s(lib[i]->author, sizeof(lib[i]->author));
		printf("제목: ");
		gets_s(lib[i]->title, sizeof(lib[i]->title));
		printf("페이지: ");
		scanf_s("%d", &lib[i]->page);
		getchar(); //버퍼에 남아있는 엔터 처리
		printf("\n");
	}

	printf("\n\n도서 정보 출력\n");
	for (int k = 0;k < 3; k++)
	{
		printf("저자: %s\n", lib[k]->author);
		printf("제목: %s\n", lib[k]->title);
		printf("페이지: %d\n", lib[k]->page);
		printf("\n");
		free(lib[k]); //동적 할당된 메모리 공간들 다시 반환
	}

	return 0;
}

#endif

/* <문제3>
문자열을 저장하고 있는 파일을 열어서 A와 P으로 시작하는 단어의 수를 세어서 출력하는 프로그램을 작성해 보자.
단 모든 단어는 공백문자(스페이스바, \t, \n)에 의해서 구분된다고 가정한다.
*/
#ifdef C

int main(void)
{
	printf("<20194111 최민규>\n교수님, 다른 문제를 실행하시려면 코드 맨 위의 매크로를 수정하세요.\n\n");
	FILE* fp =  NULL;
	fopen_s(&fp,"word.txt", "rt");

	if (fp == NULL)
	{
		printf("파일 오픈 오류\n");
		return -1;
	}

	char str[50];
	int acount = 0, bcount = 0;

	while (fgets(str, sizeof(str), fp) != NULL)
	{
		if (str[0] == 'a' || str[0] == 'A')
			acount++;

		else if (str[0] == 'p' || str[0] == 'P')
			bcount++;
	}

	printf("A(a)로 시작하는 단어 수: %d\n",acount);
	printf("P(p)로 시작하는 단어 수: %d\n",bcount);

	fclose(fp);
	return 0;
}

#endif

/* <문제 4>
두 개의 텍스트 파일이 같은지 다른지를 확인하는 프로그램을 작성해 보자.
단순히 공백문자 하나가 차이를 보여도 두 텍스트 파일은 다른 것으로 판별이 나야 한다.
*/
#ifdef D

int main(void)
{
	printf("<20194111 최민규>\n교수님, 다른 문제를 실행하시려면 코드 맨 위의 매크로를 수정하세요.\n\n");

	FILE* fp1 = NULL;
	FILE* fp2 = NULL;

	fopen_s(&fp1, "word.txt", "rt");

	fopen_s(&fp2, "word2.txt", "rt"); //이 줄을 실행시키면 일치
	//fopen_s(&fp2, "word3.txt", "rt"); //이 줄을 실행시키면 불일치

	if (fp1 == NULL || fp2 == NULL)
	{
		printf("파일 오픈 오류\n");
		return -1;
	}

	int check = 1;

	while (!feof(fp1) && !feof(fp2)) //한 쪽 파일이 끝날때까지 반복
	{
		if (fgetc(fp1) != fgetc(fp2))
		{
			check = 0;
			break;
		}
	}

	if (!feof(fp1)) //fp1의 파일이 아직 끝나지 않은 경우
		check = 0;

	else if (!feof(fp2)) //fp2의 파일이 아직 끝나지 않은 경우
		check = 0;

	if (check == 1) //파일 일치 시
		printf("두 파일은 완전히 일치합니다.\n");

	else //파일 불일치 시
		printf("두 파일은 다릅니다.\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
#endif

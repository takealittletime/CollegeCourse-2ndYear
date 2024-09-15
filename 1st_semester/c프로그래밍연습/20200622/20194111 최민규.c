#include <stdio.h>
#include <stdlib.h>

#define A//A: 1�� ����, B: 2�� ����, C: 3�� ����, D: 4�� ����

/* <���� 1>
������ ���� ������ ���α׷��� �ۼ��� ����.
[����, ���ڸ�, ��������]�� ���� ������ ������ �� �ִ� ����ü�� �����ϰ�,
����ü �迭�� �����ؼ� ������ ���� ������ �����ϰ� �ִ� ������ �ۼ��� ����.
main�Լ������� ����ڷκ��� 3���� ������ ���� ������ �Է¹ް�,
�Է��� ������ ������ ���� ������ ����� �ֵ�������.
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

	printf("<20194111 �ֹα�>\n������, �ٸ� ������ �����Ͻ÷��� �ڵ� �� ���� ��ũ�θ� �����ϼ���.\n\n");
	printf("���� ���� �Է�\n");
	for (int i = 0; i < 3; i++)
	{
		printf("����: ");
		gets_s(lib[i].author, sizeof(lib[i].author));
		printf("����: ");
		gets_s(lib[i].title, sizeof(lib[i].title));
		printf("������: ");
		scanf_s("%d", &lib[i].page);
		getchar(); //���ۿ� �����ִ� ���� ó��
		printf("\n");
	}

	printf("\n\n���� ���� ���\n");
	for (int k = 0;k < 3; k++)
	{
		printf("����: %s\n", lib[k].author);
		printf("����: %s\n", lib[k].title);
		printf("������: %d\n", lib[k].page);
		printf("\n");
	}

	return 0;
}
#endif

/* <����2>
���� 1���� ������ ���α׷��� ������ ���� ������.
����ü �迭�� �����ϴ� ���� �ƴ϶�, ����ü ������ �迭�� �����ϰ� 
����ü ������ �������� �Ҵ��ϴ� ���·� ���α׷��� �� �����غ���.
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

	printf("<20194111 �ֹα�>\n������, �ٸ� ������ �����Ͻ÷��� �ڵ� �� ���� ��ũ�θ� �����ϼ���.\n\n");
	printf("���� ���� �Է�\n");
	for (int i = 0; i < 3; i++)
	{
		lib[i] = (book*)malloc(sizeof(book));
		printf("����: ");
		gets_s(lib[i]->author, sizeof(lib[i]->author));
		printf("����: ");
		gets_s(lib[i]->title, sizeof(lib[i]->title));
		printf("������: ");
		scanf_s("%d", &lib[i]->page);
		getchar(); //���ۿ� �����ִ� ���� ó��
		printf("\n");
	}

	printf("\n\n���� ���� ���\n");
	for (int k = 0;k < 3; k++)
	{
		printf("����: %s\n", lib[k]->author);
		printf("����: %s\n", lib[k]->title);
		printf("������: %d\n", lib[k]->page);
		printf("\n");
		free(lib[k]); //���� �Ҵ�� �޸� ������ �ٽ� ��ȯ
	}

	return 0;
}

#endif

/* <����3>
���ڿ��� �����ϰ� �ִ� ������ ��� A�� P���� �����ϴ� �ܾ��� ���� ��� ����ϴ� ���α׷��� �ۼ��� ����.
�� ��� �ܾ�� ���鹮��(�����̽���, \t, \n)�� ���ؼ� ���еȴٰ� �����Ѵ�.
*/
#ifdef C

int main(void)
{
	printf("<20194111 �ֹα�>\n������, �ٸ� ������ �����Ͻ÷��� �ڵ� �� ���� ��ũ�θ� �����ϼ���.\n\n");
	FILE* fp =  NULL;
	fopen_s(&fp,"word.txt", "rt");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
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

	printf("A(a)�� �����ϴ� �ܾ� ��: %d\n",acount);
	printf("P(p)�� �����ϴ� �ܾ� ��: %d\n",bcount);

	fclose(fp);
	return 0;
}

#endif

/* <���� 4>
�� ���� �ؽ�Ʈ ������ ������ �ٸ����� Ȯ���ϴ� ���α׷��� �ۼ��� ����.
�ܼ��� ���鹮�� �ϳ��� ���̸� ������ �� �ؽ�Ʈ ������ �ٸ� ������ �Ǻ��� ���� �Ѵ�.
*/
#ifdef D

int main(void)
{
	printf("<20194111 �ֹα�>\n������, �ٸ� ������ �����Ͻ÷��� �ڵ� �� ���� ��ũ�θ� �����ϼ���.\n\n");

	FILE* fp1 = NULL;
	FILE* fp2 = NULL;

	fopen_s(&fp1, "word.txt", "rt");

	fopen_s(&fp2, "word2.txt", "rt"); //�� ���� �����Ű�� ��ġ
	//fopen_s(&fp2, "word3.txt", "rt"); //�� ���� �����Ű�� ����ġ

	if (fp1 == NULL || fp2 == NULL)
	{
		printf("���� ���� ����\n");
		return -1;
	}

	int check = 1;

	while (!feof(fp1) && !feof(fp2)) //�� �� ������ ���������� �ݺ�
	{
		if (fgetc(fp1) != fgetc(fp2))
		{
			check = 0;
			break;
		}
	}

	if (!feof(fp1)) //fp1�� ������ ���� ������ ���� ���
		check = 0;

	else if (!feof(fp2)) //fp2�� ������ ���� ������ ���� ���
		check = 0;

	if (check == 1) //���� ��ġ ��
		printf("�� ������ ������ ��ġ�մϴ�.\n");

	else //���� ����ġ ��
		printf("�� ������ �ٸ��ϴ�.\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
#endif

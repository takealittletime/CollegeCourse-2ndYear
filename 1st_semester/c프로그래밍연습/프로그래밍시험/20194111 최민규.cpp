#include <stdio.h>
#include <string.h>

//1�� ����
int main(void)
{
	printf("<20194111 �ֹα�> 1�� ����\n");
	printf("������, 2�� ������ ���� �ּ� ó���� �� ��������, �ּ��� Ǯ�� �����ϼ���.\n");
	
	int inp;
	int booky = 0;
	char library[10][50] = { 0 };
	int num = 0;

	while (1)
	{
		printf("\n1:���� �Է� 2:���� ���� 3:���� �˻� 4:���� ��� ��� 5: ���� ���� 6: ����:");
		scanf_s("%d", &inp);
		getchar();

		if (inp == 1)
		{
			if (booky >= 10)
				printf("\nå�� �� �̻� �߰��� �� �����ϴ�.\n");
			else
			{
				char add[50];
				printf("\n�߰��� ������ �̸��� �Է��ϼ���(�ִ� 10��): ");
				gets_s(add, sizeof(add));
				for (int i = 0; i < strlen(add); i++)
				{
					library[booky][i] = add[i];
				}
				printf("\n%s��(��) ������ �߰� �Ǿ����ϴ�.\n", library[booky]);
				booky++;
			}

		}

		else if (inp == 2)
		{
			char del[50];
			int check = 0;
			int idx = 0;
			printf("\n�����Ͻ� ������ �̸��� ��Ȯ�� �Է��ϼ���: ");
			gets_s(del, sizeof(del));
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(library[i], del) == 0)
				{
					idx = i;
					check = 1;
					break;
				}
			}

			if (check == 0)
				printf("\n�Է��Ͻ� ������ ã�� �� �����ϴ�.\n");

			else
			{
				for (int i = idx; i < 9; i++)
				{
					for (int j = 0; j < 50; j++)
					{
						library[i][j] = library[i + 1][j];
					}
				}
				booky--;

				printf("\n%s��(��) ���ŵǾ����ϴ�.\n", del);
			}
		}

		else if (inp == 3)
		{
			char srch[50];
			printf("\n�˻��Ͻ� ������ �̸��� �Է��ϼ���: ");
			gets_s(srch, sizeof(srch));
			printf("\n��ü �̸����� �˻�...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(library[i], srch) == 0)
				{
					printf("%s��(��) ã�ҽ��ϴ�.\n", library[i]);
				}
			}
			printf("\nö�ڷ� �˻�...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(library[i], srch) != 0)
				{
					printf("%s��(��) ã�ҽ��ϴ�.\n", library[i]);
				}
			}
		}

		else if (inp == 4)
		{
			printf("\n<���� ���>\n");
			for (int i = 0; i < booky; i++)
			{
				printf("%s\n", library[i]);
			}
		}

		else if (inp == 5)
		{
			FILE* fp;
			fopen_s(&fp, "library.txt", "wt");
			if (fp == NULL)
			{
				puts("���� ���� ����\n");
				return -1;
			}

			for (int i = 0; i < booky; i++)
			{
				fprintf(fp, "%s\n", library[i]);
			}
			fclose(fp);
			printf("���� ������ library.txt���Ͽ� �����մϴ�.\n");
		}

		else if (inp == 6)
		{
			printf("\n���α׷��� �����մϴ�.\n");
			break;
		}

		else
			printf("\n�߸��� �Է��Դϴ�.\n�ٽ� �õ����ּ���.\n");

	}

	return 0;
}


/*
//2�� ����
#define MAX 20
typedef struct student {
	int num; //�й�
	char name[MAX]; //�̸�
	int kor; //���� ����
	int eng; //���� ����
}st;

int main(void)
{
	printf("<20194111 �ֹα�> 2�� ����\n");
	printf("������, 1�� ������ �ּ� ó���� �Ͻ� �� �������ּ���.\n");
	st std[100];
	int inp = 0;
	int idx = 0;

	printf("\n********����ü********\n");
	while (1)
	{
		printf("\n���<1> �й��˻�<2> ��������<3> ��������<4> ��������<5> �������<6> �����Է�<7> ����<-1>:");
		scanf_s("%d", &inp);
		if (inp == 1)
		{
			while (1)
			{
				int stn = 0;
				printf("�й��� �Է��Ͻÿ�(����<-1>):");
				scanf_s("%d", &stn);

				if (stn == -1)
				{
					break;
				}

				else
				{
					std[idx].num = stn;
					printf("�̸� ����� ������� �Է��Ͻÿ�.\n");
					scanf_s("%s %d %d", std[idx].name, sizeof(std[idx].name), &std[idx].kor, &std[idx].eng);
					idx++;
				}
			}
		}

		else if (inp == 2)
		{
			int srch,check = 0;
			printf("�й� �Է�:");
			scanf_s("%d", &srch);

			for (int i = 0; i < idx; i++)
			{
				if (std[i].num == srch)
				{
					check = 1;
					printf("�й�: %d, �̸�: %s, ����: %d, ����: %d \n", std[i].num, std[i].name, std[i].kor, std[i].eng);
					break;
				}
			}

			if (check == 0)
			{
				printf("�ش� �й� �л��� ���� ������ ã�� ���߽��ϴ�.\n");
			}
		}

		else if (inp == 3)
		{
			int kavr = 0;
			for (int i = 0; i < idx; i++)
			{
				kavr += std[i].kor;
			}
			kavr /= idx;
			printf("���� ���: %d��\n", kavr);
		}
		
		else if (inp == 4)
		{
			int eavr = 0;
			for (int i = 0; i < idx; i++)
			{
				eavr += std[i].eng;
			}
			eavr /= idx;
			printf("���� ���: %d��\n", eavr);
		}

		else if (inp == 5)
		{
			int srch,check = 0, change;
			printf("������ �й���? ");
			scanf_s("%d", &srch);

			for (int i = 0; i < idx; i++)
			{
				if (srch == std[i].num)
				{
					check = 1;
					change = i;
					break;
				}
			}

			if (check == 1)
			{
				int kchange, echange;
				printf("���� ����?");
				scanf_s("%d", &kchange);
				printf("���� ����?");
				scanf_s("%d", &echange);
				std[change].kor = kchange;
				std[change].eng = echange;
				printf("�й�: %d, �̸�: %s, ����:%d, ����: %d\n", std[change].num, std[change].name, std[change].kor, std[change].eng);
				printf("���� �Ϸ�!\n");
			}

			else
			{
				printf("�ش� �й� �л��� ���� ������ ã�� �� �����ϴ�.\n");
			}
		}

		else if (inp == 6)
		{
			FILE* fp;
			fopen_s(&fp, "score_out.txt", "wt");

			if (fp == NULL)
			{
				puts("���� ���� ����\n");
				return -1;
			}
			
			for (int i = 0; i < idx; i++)
			{
				fprintf(fp, "%d %s %d %d\n", std[i].num, std[i].name, std[i].kor, std[i].eng);
			}
			fclose(fp);
			printf("score_out.txt���Ͽ� �����Ͽ����ϴ�.\n");
		}

		else if (inp == 7)
		{
			char fname[100];
			printf("�ҷ��� ������?");
			scanf_s("%s", fname, sizeof(fname));
			FILE* fp;
			fopen_s(&fp, fname, "rt");

			if (fp == NULL)
			{
				printf("���� ���� ����\n");
				return -1;
			}

			while (feof(fp) == 0)
			{
				fscanf_s(fp, "%d %s %d %d", &std[idx].num, std[idx].name,sizeof(std[idx].name), &std[idx].kor, &std[idx].eng);
				idx++;
			}
			fclose(fp);
			printf("%s���Ͽ��� ���� ������ �о�Խ��ϴ�.\n",fname);
		}

		else if (inp == -1)
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		else 
		{
			printf("�������� �ʴ� ����Դϴ�. �ٽ� Ȯ���ϼ���.\n");
		}	

	}

	return 0;
}
*/
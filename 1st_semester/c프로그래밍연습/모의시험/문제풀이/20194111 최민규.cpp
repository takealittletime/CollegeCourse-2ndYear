#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//1�� ����
typedef struct caffe {
	char name[20]; //���� �̸�
	int price; //���� ����
}caf;

int main(void)
{
	printf("20194111 �ֹα�\n");
	printf("������, ���� ���� �ּ� ó���� �� ��������, 2�� �������ּ��� Ǯ�� �������ּ���.\n\n");
	caf pos[100];
	int in = 0;
	int idx = 0;

	while (1)
	{
		printf("1:���� �߰� 2:���� ���� 3:���� �˻� 4:�ֹ��� ��� 5:���� �ݾ� 6:����? ");
		scanf_s("%d", &in);

		if (in == 1)
		{

			printf("�߰��� ������ �̸��� ������ �Է��ϼ���:");
			scanf_s("%s %d", &pos[idx].name,sizeof(pos[idx].name), &pos[idx].price);
			idx++;
		}

		else if (in == 2) //(���� �޴��� �̿ϼ�)
		{
			char del[20];
			printf("������ ������ �̸��� �Է��ϼ���:");
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
					printf("%s�� �����߽��ϴ�.\n", del);
					break;
				}
			}

			if (check == 0)
			{
				printf("%s�� ã�� ���߽��ϴ�. ������ �̸��� �ٽ� Ȯ�����ּ���.\n",del);
			}
			
		}

		else if (in == 3)
		{
			char srch[20];
			printf("�˻��� ������ �̸��� �Է��ϼ���:");
			scanf_s("%s",srch, sizeof(srch));

			printf("��ü �̸����� �˻�...\n");
			for (int i = 0; i < idx; i++)
			{
				if (strcmp(pos[i].name, srch) == 0)
				{
					printf("%s��(��) ã�ҽ��ϴ�.\n", pos[i].name);
				}
			}
			printf("\n��ö�ڷ� �˻�...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(pos[i].name, srch) != 0)
				{
					printf("%s��(��) ã�ҽ��ϴ�.\n", pos[i].name);
				}
			}
		}

		else if (in == 4)
		{
			printf("�ֹ��� ����� ������ �����ϴ�.\n");

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

			printf("�� ���� �ݾ��� %d ���Դϴ�.\n",total);
		}

		else if (in == 6)
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		else
		{
		printf("�������� �ʴ� ����Դϴ�. �Է��� �ٽ� �� �� Ȯ���ϼ���.\n");
		}
	}

	return 0;
}


/*
//2�� ����
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
	printf("20194111 �ֹα�\n");
	printf("������, ���� ���� �ּ� ó���� �� �������� 1�� ������ �ּ��� Ǯ�� �������ּ���.\n\n");
	FILE* src;
	FILE* des;

	fopen_s(&src, "score_src_new.txt", "rt");
	fopen_s(&des, "score_grade.txt", "wt");

	if (src == NULL || des == NULL)
	{
		printf("���� ���� ����!\n");
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
		// ������ ,�� �����ִ� �۾�
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

		printf("1:���� ��� 2:����, ��� ��� 3:���� �ο� �� ��� 4:���� ���� 5:���α׷� ����?");
		scanf_s("%d", &in);


		if (in == 1)
		{
			printf("<���� ���>\n");
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
			printf("<����, ��� ���>\n");

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
			printf("<���� �ο� �� ���>\n"); //�����ƿ��� �� ������ ������� �ذ� ����..

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
			printf("<���� ����>\n");
			for (int k = 0; k < i; k++)
			{
				fprintf(des,"% s% d% d% d% d% d% lf% s\n", grd[k].name, grd[k].num1, grd[k].num2, grd[k].num3, grd[k].num4,grd[k].total, grd[k].avr, grd[k].grade);
			}
			printf("���� ���� �Ϸ�\n");
		}


		else if (in == 5)
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
	}

	fclose(src);
	fclose(des);

	return 0;
}
*/
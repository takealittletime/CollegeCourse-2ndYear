//20194111 �ֹα�
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("20194111 �ֹα�\n\n");
	/*
	//1�� ����
	FILE* fp;
	fopen_s(&fp, "text.txt", "rt");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
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
	
	//2�� ����
	FILE * fp;
	fopen_s(&fp, "std.txt", "rt");

	FILE* fp1;
	fopen_s(&fp1, "out.txt", "wt");

	FILE* fp2;
	fopen_s(&fp2, "grouping.txt", "wt");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		return -1;
	}

	int num; //�й�
	char name[10]; //�̸�
	char locate[5]; //����
	char sex[5]; //����
	int age; //����
	char phone[20]; //��ȭ��ȣ
	double gpa; //����
	char traffic[10]; //�������

	int ret,inp,men = 0, girl = 0;


	//���� 3~4�� ģ���鸸 out.txt���Ͽ� ���
	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
			break;
		}
		
		if (!strcmp(sex, "��"))
			men++;

		if (!strcmp(sex, "��"))
			girl++;

		if (3<=gpa && gpa <= 4)
		{
			fprintf(fp1,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
		}
	}
	fseek(fp, 0, SEEK_SET);

	fclose(fp1);

	fprintf(fp2,"���л� %d��, ���л� %d��\n",men,girl);
	fprintf(fp2,"<���л�>\n");

	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
			break;
		}

		else if (!strcmp(sex,"��"))
		{
			fprintf(fp2,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
		}
	}

	fseek(fp, 0, SEEK_SET);

	fprintf(fp2,"<���л�>\n");

	while (1)
	{
		ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

		if (ret == EOF)
		{
		}

		else if (!strcmp(sex,"��"))
		{
			fprintf(fp2,"%d %s %s %s %d %s %lf %s\n", num, name, locate, sex, age, phone, gpa, traffic);
			break;
		}
	}

	fseek(fp, 0, SEEK_SET);

	fclose(fp2);

	while (1) {
		printf("���ϴ� �˻��� �Է��ϼ���.(1: �̸�), (2: �й�), (3: ����) ���ڸ� �Է�:");
		scanf_s("%d", &inp);

		if (inp == 1)
		{
			char src[10];
			printf("�̸��� �Է��ϼ���:");
			scanf_s("%s", src, sizeof(src));

			while (1)
			{
				ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name, sizeof(name), locate, sizeof(locate), sex, sizeof(sex), &age, phone, sizeof(phone), &gpa, traffic, sizeof(traffic));

				if (ret == EOF)
				{
					printf("�˻��Ͻ� ������ ã�� �� �����ϴ�.\n");
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
			printf("�й��� �Է��ϼ���:");
			scanf_s("%d", &src);

			while (1)
			{
				ret = fscanf_s(fp, "%d %s %s %s %d %s %lf %s", &num, name,sizeof(name), locate,sizeof(locate), sex,sizeof(sex), &age, phone,sizeof(phone), &gpa, traffic,sizeof(traffic));

				if (ret == EOF)
				{
					printf("�˻��Ͻ� ������ ã�� �� �����ϴ�.\n");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		else
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
	}
	fclose(fp);

	return 0;
	
}
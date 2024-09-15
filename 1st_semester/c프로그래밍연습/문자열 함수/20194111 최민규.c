#include <stdio.h>
#include <string.h>

void clearLine(void);

int main(void)
{
	printf("20194111 �ֹα�\n\n");
	//1-1
	printf("<1-1>\n");
	char str1[100], str2[10], str3[10], str4[10];
	strcpy(str1, "java");
	strcpy(str2, "android");
	strcpy(str3, "visual");
	strcpy(str4, "studio");
	strcat(str1, str2);
	strcat(str1, str3);
	strcat(str1, str4);
	printf("%s\n\n", str1);

	//1-2
	printf("\n<1-2>\n");
	char str5[50] = ("computer engineer");
	char* find1 = strchr(str5, 'r');
	char* find2 = strrchr(str5, 'r');
	printf("ù��° r�� ��ġ: %p\n�ι�° r�� ��ġ: %p\n", find1, find2);

	//1-3
	printf("\n<1-3>\n");
	char str6[50] = ("My name is alphago");
	char* find3 = strstr(str6, "alphago");

	if (find3 == '\0')
		printf("ã�� ���߽��ϴ�.\n");
	else
		printf("ã�ҽ��ϴ�.\n");

	//1-4-1
	printf("\n<1-4-1>\n");
	char str7[10] = ("AppLE");
	char str8[10] = ("apple");

	if (!strcmp(str7, str8))
		printf("�����ϴ�.\n");
	else
		printf("���� �ʽ��ϴ�.\n");

	//1-4-2
	printf("\n<1-4-2>\n");

	if (!_stricmp(str7, str8)) //stricmp�� ������ ���� _stricmp�� �̿���.
		printf("�����ϴ�.\n");
	else
		printf("���� �ʽ��ϴ�.\n");

	/* strcmp�� ���ڿ��� �տ������� ������� ���ϰ�, ������ ��,�ҹ��ڸ� �����Ѵ�.
	�� ���ڿ��� ������ 0, �������� ũ�� -1, ������ ũ�� 1�� ��ȯ�Ѵ�.
	stricmp�� ��ü������ strcmp�� �����ϳ�, ��� ���ڿ��� �ҹ��ڷ� �ٲ۵� ���Ѵ�.
	��, ������ ��,�ҹ��ڸ� ���������ʴ´�.*/

	//1-5
	printf("\n<1-5>\n");
	char voc[10] = "microsoft"; //9����
	char voc1[10] = "intel"; //5����
	char voc2[10] = "samsung"; //7����
	char voc3[10] = "a    b"; //6����

	int size[4] = {strlen(voc),strlen(voc1),strlen(voc2),strlen(voc3)};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3-i; j++)
		{
			if (size[j] < size[j + 1])
			{
				int tmp = size[j];
				size[j] = size[j + 1];
				size[j + 1] = tmp;
			}

		}
	}

	printf("�湮�ڿ��� ���̰� �� ������� ���\n");
	for (int k = 0; k < 4; k++)
	{
		if (strlen(voc) == size[k])
			printf("%d. %s\n", k+1,voc);
		
		else if (strlen(voc1) == size[k])
			printf("%d. %s\n", k + 1, voc1);
		
		else if (strlen(voc2) == size[k])
			printf("%d. %s\n", k + 1, voc2);
		
		else if (strlen(voc3) == size[k])
			printf("%d. %s\n", k + 1, voc3);
	}

	
	//2
	printf("\n<2>\n");
	char str9[100];
	printf("�濬���ϴ� ������ ������ ����ϴ� ����\n���ڿ��� �Է��ϼ���:");
	gets_s(str9, sizeof(str9));
	int result = 0;
	for (int i = 0; i < strlen(str9); i++)
	{
		if (str9[i] == str9[i + 1])
			result++;
	}
	printf("%s���� �����ϴ� ������ ������ %d�� �Դϴ�.\n", str9, result);

	//3
	printf("\n<3>");
	int inp;
	int booky = 0;
	char library[10][50] = { 0 };

	while (1)
	{
		printf("\n{1:���� �Է� 2:���� ���� 3:���� �˻� 4:���� ��� ��� 5: ����}\n");
		printf("\n����Ͻô� �Է��� ���ּ���: ");
		scanf("%d", &inp);
		clearLine();

		if (inp == 1)
		{
			if (booky >= 10)
				printf("\n��å�� �� �̻� �߰��� �� �����ϴ�.\n");
			else
			{
				char add[50];
				printf("\n���߰��� ������ �̸��� �Է��ϼ���: ");
				gets_s(add, sizeof(add));
				for (int i = 0; i < strlen(add); i++)
				{
					library[booky][i] = add[i];
				}
				printf("\n��%s��(��) ������ �߰� �Ǿ����ϴ�.\n", library[booky]);
				booky++;
			}
			
		}

		else if (inp == 2)
		{
			char del[50];
			int check = 0;
			int idx = 0;
			printf("\n�������Ͻ� ������ �̸��� ��Ȯ�� �Է��ϼ���: ");
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
				printf("\n���Է��Ͻ� ������ ã�� �� �����ϴ�.\n");

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

				printf("\n��%s��(��) ���ŵǾ����ϴ�.\n", del);
			}
		}

		else if (inp == 3)
		{
			char srch[50];
			printf("\n��˻��Ͻ� ������ �̸��� �Է��ϼ���: ");
			gets_s(srch, sizeof(srch));
			printf("\n����ü �̸����� �˻�...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(library[i], srch) == 0)
				{
					printf("��%s��(��) ã�ҽ��ϴ�.\n", library[i]);
				}
			}
			printf("\n��ö�ڷ� �˻�...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(library[i], srch) != 0)
				{
					printf("��%s��(��) ã�ҽ��ϴ�.\n", library[i]);
				}
			}
		}

		else if (inp == 4)
		{
			printf("\n��<���� ���>\n");
			for (int i = 0; i < 10; i++)
			{
				printf("%s\n", library[i]);
			}
		}

		else if (inp == 5)
		{
			printf("\n�����α׷��� �����մϴ�.\n\n");
			break;
		}

		else
			printf("\n���߸��� �Է��Դϴ�.\n�ٽ� �õ����ּ���.\n");

	}

	return 0;
}

void clearLine(void)
{
	while (getchar() != '\n');
}
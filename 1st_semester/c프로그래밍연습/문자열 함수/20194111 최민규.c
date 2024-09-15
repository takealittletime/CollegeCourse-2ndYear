#include <stdio.h>
#include <string.h>

void clearLine(void);

int main(void)
{
	printf("20194111 최민규\n\n");
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
	printf("첫번째 r의 위치: %p\n두번째 r의 위치: %p\n", find1, find2);

	//1-3
	printf("\n<1-3>\n");
	char str6[50] = ("My name is alphago");
	char* find3 = strstr(str6, "alphago");

	if (find3 == '\0')
		printf("찾지 못했습니다.\n");
	else
		printf("찾았습니다.\n");

	//1-4-1
	printf("\n<1-4-1>\n");
	char str7[10] = ("AppLE");
	char str8[10] = ("apple");

	if (!strcmp(str7, str8))
		printf("같습니다.\n");
	else
		printf("같지 않습니다.\n");

	//1-4-2
	printf("\n<1-4-2>\n");

	if (!_stricmp(str7, str8)) //stricmp는 오류가 나서 _stricmp를 이용함.
		printf("같습니다.\n");
	else
		printf("같지 않습니다.\n");

	/* strcmp는 문자열을 앞에서부터 순서대로 비교하고, 영문의 대,소문자를 구별한다.
	두 문자열이 같으면 0, 오른쪽이 크면 -1, 왼쪽이 크면 1을 반환한다.
	stricmp는 전체적으로 strcmp와 동일하나, 모든 문자열을 소문자로 바꾼뒤 비교한다.
	즉, 영문의 대,소문자를 구별하지않는다.*/

	//1-5
	printf("\n<1-5>\n");
	char voc[10] = "microsoft"; //9글자
	char voc1[10] = "intel"; //5글자
	char voc2[10] = "samsung"; //7글자
	char voc3[10] = "a    b"; //6글자

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

	printf("→문자열의 길이가 긴 순서대로 출력\n");
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
	printf("→연속하는 문자의 개수를 출력하는 문제\n문자열을 입력하세요:");
	gets_s(str9, sizeof(str9));
	int result = 0;
	for (int i = 0; i < strlen(str9); i++)
	{
		if (str9[i] == str9[i + 1])
			result++;
	}
	printf("%s에서 연속하는 문자의 개수는 %d개 입니다.\n", str9, result);

	//3
	printf("\n<3>");
	int inp;
	int booky = 0;
	char library[10][50] = { 0 };

	while (1)
	{
		printf("\n{1:도서 입력 2:도서 제거 3:도서 검색 4:도서 목록 출력 5: 종료}\n");
		printf("\n→원하시는 입력을 해주세요: ");
		scanf("%d", &inp);
		clearLine();

		if (inp == 1)
		{
			if (booky >= 10)
				printf("\n→책을 더 이상 추가할 수 없습니다.\n");
			else
			{
				char add[50];
				printf("\n→추가할 도서의 이름을 입력하세요: ");
				gets_s(add, sizeof(add));
				for (int i = 0; i < strlen(add); i++)
				{
					library[booky][i] = add[i];
				}
				printf("\n→%s이(가) 도서에 추가 되었습니다.\n", library[booky]);
				booky++;
			}
			
		}

		else if (inp == 2)
		{
			char del[50];
			int check = 0;
			int idx = 0;
			printf("\n→제거하실 도서의 이름을 정확히 입력하세요: ");
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
				printf("\n→입력하신 도서를 찾을 수 없습니다.\n");

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

				printf("\n→%s이(가) 제거되었습니다.\n", del);
			}
		}

		else if (inp == 3)
		{
			char srch[50];
			printf("\n→검색하실 도서의 이름을 입력하세요: ");
			gets_s(srch, sizeof(srch));
			printf("\n→전체 이름으로 검색...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(library[i], srch) == 0)
				{
					printf("→%s을(를) 찾았습니다.\n", library[i]);
				}
			}
			printf("\n→철자로 검색...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(library[i], srch) != 0)
				{
					printf("→%s을(를) 찾았습니다.\n", library[i]);
				}
			}
		}

		else if (inp == 4)
		{
			printf("\n→<도서 목록>\n");
			for (int i = 0; i < 10; i++)
			{
				printf("%s\n", library[i]);
			}
		}

		else if (inp == 5)
		{
			printf("\n→프로그램을 종료합니다.\n\n");
			break;
		}

		else
			printf("\n→잘못된 입력입니다.\n다시 시도해주세요.\n");

	}

	return 0;
}

void clearLine(void)
{
	while (getchar() != '\n');
}
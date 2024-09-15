#include <stdio.h>
#include <string.h>

//1번 문제
int main(void)
{
	printf("<20194111 최민규> 1번 문제\n");
	printf("교수님, 2번 문제는 따로 주석 처리를 해 놓았으니, 주석을 풀고 실행하세요.\n");
	
	int inp;
	int booky = 0;
	char library[10][50] = { 0 };
	int num = 0;

	while (1)
	{
		printf("\n1:도서 입력 2:도서 제거 3:도서 검색 4:도서 목록 출력 5: 파일 저장 6: 종료:");
		scanf_s("%d", &inp);
		getchar();

		if (inp == 1)
		{
			if (booky >= 10)
				printf("\n책을 더 이상 추가할 수 없습니다.\n");
			else
			{
				char add[50];
				printf("\n추가할 도서의 이름을 입력하세요(최대 10권): ");
				gets_s(add, sizeof(add));
				for (int i = 0; i < strlen(add); i++)
				{
					library[booky][i] = add[i];
				}
				printf("\n%s이(가) 도서에 추가 되었습니다.\n", library[booky]);
				booky++;
			}

		}

		else if (inp == 2)
		{
			char del[50];
			int check = 0;
			int idx = 0;
			printf("\n제거하실 도서의 이름을 정확히 입력하세요: ");
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
				printf("\n입력하신 도서를 찾을 수 없습니다.\n");

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

				printf("\n%s이(가) 제거되었습니다.\n", del);
			}
		}

		else if (inp == 3)
		{
			char srch[50];
			printf("\n검색하실 도서의 이름을 입력하세요: ");
			gets_s(srch, sizeof(srch));
			printf("\n전체 이름으로 검색...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(library[i], srch) == 0)
				{
					printf("%s을(를) 찾았습니다.\n", library[i]);
				}
			}
			printf("\n철자로 검색...\n");
			for (int i = 0; i < 10; i++)
			{
				if (strstr(library[i], srch) != 0)
				{
					printf("%s을(를) 찾았습니다.\n", library[i]);
				}
			}
		}

		else if (inp == 4)
		{
			printf("\n<도서 목록>\n");
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
				puts("파일 오픈 실패\n");
				return -1;
			}

			for (int i = 0; i < booky; i++)
			{
				fprintf(fp, "%s\n", library[i]);
			}
			fclose(fp);
			printf("도서 정보를 library.txt파일에 저장합니다.\n");
		}

		else if (inp == 6)
		{
			printf("\n프로그램을 종료합니다.\n");
			break;
		}

		else
			printf("\n잘못된 입력입니다.\n다시 시도해주세요.\n");

	}

	return 0;
}


/*
//2번 문제
#define MAX 20
typedef struct student {
	int num; //학번
	char name[MAX]; //이름
	int kor; //국어 점수
	int eng; //영어 점수
}st;

int main(void)
{
	printf("<20194111 최민규> 2번 문제\n");
	printf("교수님, 1번 문제는 주석 처리를 하신 뒤 실행해주세요.\n");
	st std[100];
	int inp = 0;
	int idx = 0;

	printf("\n********구조체********\n");
	while (1)
	{
		printf("\n등록<1> 학번검색<2> 국어성적평균<3> 영어성적평균<4> 성적수정<5> 파일출력<6> 파일입력<7> 종료<-1>:");
		scanf_s("%d", &inp);
		if (inp == 1)
		{
			while (1)
			{
				int stn = 0;
				printf("학번을 입력하시오(종료<-1>):");
				scanf_s("%d", &stn);

				if (stn == -1)
				{
					break;
				}

				else
				{
					std[idx].num = stn;
					printf("이름 국어성적 영어성적을 입력하시오.\n");
					scanf_s("%s %d %d", std[idx].name, sizeof(std[idx].name), &std[idx].kor, &std[idx].eng);
					idx++;
				}
			}
		}

		else if (inp == 2)
		{
			int srch,check = 0;
			printf("학번 입력:");
			scanf_s("%d", &srch);

			for (int i = 0; i < idx; i++)
			{
				if (std[i].num == srch)
				{
					check = 1;
					printf("학번: %d, 이름: %s, 국어: %d, 영어: %d \n", std[i].num, std[i].name, std[i].kor, std[i].eng);
					break;
				}
			}

			if (check == 0)
			{
				printf("해당 학번 학생에 대한 정보를 찾지 못했습니다.\n");
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
			printf("국어 평균: %d점\n", kavr);
		}
		
		else if (inp == 4)
		{
			int eavr = 0;
			for (int i = 0; i < idx; i++)
			{
				eavr += std[i].eng;
			}
			eavr /= idx;
			printf("영어 평균: %d점\n", eavr);
		}

		else if (inp == 5)
		{
			int srch,check = 0, change;
			printf("수정할 학번은? ");
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
				printf("국어 성적?");
				scanf_s("%d", &kchange);
				printf("영어 성적?");
				scanf_s("%d", &echange);
				std[change].kor = kchange;
				std[change].eng = echange;
				printf("학번: %d, 이름: %s, 국어:%d, 영어: %d\n", std[change].num, std[change].name, std[change].kor, std[change].eng);
				printf("수정 완료!\n");
			}

			else
			{
				printf("해당 학번 학생에 대한 정보를 찾을 수 없습니다.\n");
			}
		}

		else if (inp == 6)
		{
			FILE* fp;
			fopen_s(&fp, "score_out.txt", "wt");

			if (fp == NULL)
			{
				puts("파일 오픈 실패\n");
				return -1;
			}
			
			for (int i = 0; i < idx; i++)
			{
				fprintf(fp, "%d %s %d %d\n", std[i].num, std[i].name, std[i].kor, std[i].eng);
			}
			fclose(fp);
			printf("score_out.txt파일에 저장하였습니다.\n");
		}

		else if (inp == 7)
		{
			char fname[100];
			printf("불러올 파일은?");
			scanf_s("%s", fname, sizeof(fname));
			FILE* fp;
			fopen_s(&fp, fname, "rt");

			if (fp == NULL)
			{
				printf("파일 오픈 실패\n");
				return -1;
			}

			while (feof(fp) == 0)
			{
				fscanf_s(fp, "%d %s %d %d", &std[idx].num, std[idx].name,sizeof(std[idx].name), &std[idx].kor, &std[idx].eng);
				idx++;
			}
			fclose(fp);
			printf("%s파일에서 성적 정보를 읽어왔습니다.\n",fname);
		}

		else if (inp == -1)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		else 
		{
			printf("존재하지 않는 명령입니다. 다시 확인하세요.\n");
		}	

	}

	return 0;
}
*/
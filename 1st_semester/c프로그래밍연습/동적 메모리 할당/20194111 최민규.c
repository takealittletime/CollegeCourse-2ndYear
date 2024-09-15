//2020. 05. 27. 동적 메모리 할당.
//20194111 최민규
#include <stdio.h> //표준 입출력 헤더 파일 추가
#include <stdlib.h> //동적 메모리 할당을 위한 헤더 파일 추가


int main(void)
{
	//메뉴 출력
	printf("<2019411 최민규>\n");
	printf("=====================================\n\n");
	printf("1. 크키가 n인 동적 배열을 생성\n\n");
	printf("2. 배열을 난수로 채운다.\n\n");
	printf("3. 배열의 각 원소를 출력한다.\n\n");
	printf("4. 배열의 각 원소들의 합을 출력한다.\n\n");
	printf("5. 동적 할당 공간을 반납한다.\n\n");
	printf("6. 프로그램을 종료한다.\n\n");
	printf("=====================================\n\n");

	int inp,size = 1; //입력을 받을 변수 inp, 배열의 크기를 할당할 변수 size
	int* arr = (int*)malloc(sizeof(int) * size); //int형 크기 하나짜리 arr을 동적으로 생성

	while (1) //무한 반복
	{
		srand(time(NULL)); //난수 시드 초기화
		printf("\n메뉴를 선택하시오: "); //사용자 입력
		scanf_s("%d", &inp);

		if (inp == 1) //1번 메뉴
		{
			printf("\n생성하실 배열의 크기를 입력하세요:"); //배열 크기 입력
			scanf_s("%d", &size);
			arr = (int*)malloc(sizeof(int) * size); //배열 크기에 따라 arr동적 할당

			if (arr == NULL) //동적 할당 실패시 에러 메시지 출력
			{
				printf("\nerror: 배열을 생성하지 못했습니다.\n");
			}
			else //동적 할당 성공 시 완료 메시지 출력
			{
				printf("\n크기가 %d인 정수형 배열이 생성되었습니다.\n", size);
			}
		}

		else if (inp == 2) //2번 메뉴
		{
			for (int i = 0; i < size; i++) //배열 크기 만큼 반복
			{
				arr[i] = rand() % 100+1; //1 ~ 100사이 난수로 배열 요소 초기화
			}
			printf("\n배열의 요소들을 1~100 사이 난수로 채웁니다.\n"); //메시지 출력
		}

		else if (inp == 3) //3번 메뉴
		{
			printf("\n<배열의 요소는 다음과 같습니다.>\n");
			for (int j = 0; j < size; j++) //배열 크기 만큼 반복
			{
				printf("arr[%d] = %d\n", j, arr[j]); //배열 요소 출력
			}
			printf("\n"); //줄바꿈
		}
	
		else if (inp == 4) //4번 메뉴
		{
			int sum = 0; //배열 요소의 총합을 할당할 변수 sum 선언 및 0으로 초기화
			for (int k = 0; k < size; k++) //배열 크기만큼 반복
			{
				sum += arr[k]; //sum에 배열 요소 합산
			}

			printf("\n배열 요소의 총합은 %d 입니다.\n",sum); //sum값 출력
		}

		else if (inp == 5) //5번 메뉴
		{
			free(arr); //동적 할당 공간 반납
			printf("\n동적 할당된 공간을 메모리에 반납합니다.\n"); //메시지 출력
		}

		else if (inp == 6) //6번 메뉴
		{
			printf("\n프로그램을 종료합니다.\n"); //메시지 출력
			break; //while문 종료
		}

		else { //그 외 입력 시

			printf("\n프로그램에 존재하지 않는 명령입니다.\n입력을 다시 해주세요.\n"); //경고 메시지 출력
		}

	}

	return 0; //값 0 반환
}
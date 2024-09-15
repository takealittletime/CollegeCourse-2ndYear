//2020. 05. 26.
//20194111 최민규
#include <stdio.h>
#include <stdlib.h>

/*
//1번
char* ReadUserName(void)
{
	char* name = (char*)calloc(20,sizeof(char));
	printf("%p\n", name);
	printf("What's your name?");
	gets_s(name, sizeof(char) * 20);
	return name;
}

int main(void)
{
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1: %s \n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n", name2);
	printf("name1: %s \n", name1);
	printf("name2: %s \n", name2);
	free(name1);
	free(name2);

	return 0;
}*/

/*
//2번
char* ReadUserName(void)
{
	char* name = (char*)calloc( 20,sizeof(char));
	printf("%p\n", name);
	//name = realloc(name, sizeof(char) * 30);
	printf("%p\n", name);
	printf("What's your name?");
	gets_s(name, sizeof(char) * 30);
	return name;
}

int main(void)
{
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1: %s \n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n", name2);
	printf("name1: %s \n", name1);
	printf("name2: %s \n", name2);
	free(name1);
	free(name2);

	return 0;
}*/

//3번
int main(void)
{
	int num, i = 1,j=0;
	int* arr = (int*)malloc(sizeof(int));

	while (1)
	{
		printf("==정수를 입력하세요(종료하려면 음수 입력)==:");
		scanf_s("%d", &num);

		if (num < 0)
		{
			printf("==프로그램이 종료됩니다.==\n");
			break;
		}

		else
		{
			arr = realloc(arr, sizeof(int) * (++i));
			arr[j++] = num;
		}
	}
	arr[j] = NULL;

	printf("==저장된 값은 다음과 같습니다.==\n\n");
	
	for (int k = 0; k < j; k++)
	{
		printf("arr[%d] = %d\n", k,arr[k]);
	}

	return 0;

}
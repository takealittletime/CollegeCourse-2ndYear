//2020. 05. 26.
//20194111 �ֹα�
#include <stdio.h>
#include <stdlib.h>

/*
//1��
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
//2��
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

//3��
int main(void)
{
	int num, i = 1,j=0;
	int* arr = (int*)malloc(sizeof(int));

	while (1)
	{
		printf("==������ �Է��ϼ���(�����Ϸ��� ���� �Է�)==:");
		scanf_s("%d", &num);

		if (num < 0)
		{
			printf("==���α׷��� ����˴ϴ�.==\n");
			break;
		}

		else
		{
			arr = realloc(arr, sizeof(int) * (++i));
			arr[j++] = num;
		}
	}
	arr[j] = NULL;

	printf("==����� ���� ������ �����ϴ�.==\n\n");
	
	for (int k = 0; k < j; k++)
	{
		printf("arr[%d] = %d\n", k,arr[k]);
	}

	return 0;

}
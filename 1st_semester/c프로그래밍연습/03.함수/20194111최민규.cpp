#include <stdio.h>
#include <stdlib.h>

#define n 50

void delete(int a[], int n, int loc);

int  main(void)
{
	srand(time(NULL));

	int num[n] = { 0 };
	int loc = rand() % 50;

	for (int i = 0; i < n; i++)
	{
		num[i] = rand() % 100;
	}

	printf("원본 배열:");
	for (int k = 0; k < n; k++)
	{
		printf(" %d", num[k]);
	}

	printf("\n\nloc = %d\n\n", loc);

	printf("%d번째 수 삭제:");
	delete(num, loc);

	for (int j = 0; j < n - 1; j++)
	{
		printf("%d", num[j]);
	}

}

void delete(int a[],int loc)
{
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j] == NULL)
		{
			a[j - 1] = a[j];
			break;
		}

		if (j >= loc)
		{
			a[j - 1] = a[j];
		}
	}
}

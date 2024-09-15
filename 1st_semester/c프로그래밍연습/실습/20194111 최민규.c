#include <stdio.h>

struct point
{
	int xp;
	int yp;
};

struct employee
{
	char name[20];
	char num[20];
	int money;
};

struct connect
{
	int data;
	struct connect* next;
};

int main(void)
{
	/*예제 1번
	struct point p1 = { 1,2 };
	struct point p2 = { 100,200 };
	struct point* ptr = &p1;
	(*ptr).xp += 4;
	(*ptr).yp += 5;
	printf("[%d, %d] \n", ptr->xp, ptr->yp);
	ptr = &p2;
	ptr->xp += 1;
	ptr->yp += 2;
	printf("[%d, %d] \n", (*ptr).xp, (*ptr).yp);*/

	/*예제 2번
	struct employee per[50];
	struct employee per1;
	struct employee per2;
	struct employee per3;
	int num = 0;
	printf("직원정보 3명을 입력하세요.\n");
	scanf("%s %s %d", &per1.name, &per1.num, &per1.money);
	num++;
	scanf("%s %s %d", &per2.name, &per2.num, &per2.money);
	num++;
	scanf("%s %s %d", &per3.name, &per3.num, &per3.money);
	num++;

	printf("\n직원 정보는 다음과 같습니다.\n");
	printf("<구조체만 이용>\n");
	int tot1 = per1.money + per2.money + per3.money;
	printf("%s %s %d\n", per1.name, per1.num, per1.money);
	printf("%s %s %d\n", per2.name, per2.num, per2.money);
	printf("%s %s %d\n", per3.name, per3.num, per3.money);
	printf("\n직원은 총 %d 명, 급여는 총 %d 원입니다.\n", num, tot1);

	per[0] = per1; per[1] = per2; per[2] = per3;
	int tot2 = 0;

	printf("\n<구조체 배열 이용>\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s %s %d\n", per[i].name, per[i].num, per[i].money);
		tot2 += per[i].money;
	}
	printf("\n직원은 총 %d 명, 급여는 총 %d 원입니다.\n",num,tot2);*/

	/*예제 3번*/
	struct connect con4= { 1 };
	struct connect con3 = { 2, &con4 };
	struct connect con2 = { 10, &con3 };
	struct connect con1 = { 3, &con3 };

	printf("%d \n", con1.data + con2.data + con3.data + con4.data);

	return 0;
}
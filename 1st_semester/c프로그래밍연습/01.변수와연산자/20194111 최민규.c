#include <stdio.h>

int main(void)
{
	//1. 변수 3개(a, b, c)를 선언과 함께 초기화한다. (초기화 값은 a는 5, b는 3, c는 2이다.)
	int a = 5, b = 3, c = 2;


	//2. a / b, a % c를 printf를 통해 출력한다.
	printf("a/b = %d\n",a/b);
	printf("a%%c = %d\n",a%c);

	//3. a += 7 / b += 3, a += 7 % c += 3 를 printf를 통해 출력하여 값을 확인해본다. 
	//**문제 오류: a += 7 → a + 7, b += 3 → b + 3, c += 3 → c + 3으로 수정.

	printf("a / b = %d\n", ((a+7)/(b+3)));
	printf("a %% c =%d\n", ((a+7)%(c+3)));


	//4. (a++) / (b++))를 printf를 통해 출력하여 값을 확인해본다.
	printf("(a++)/(b++) = %d\n", a++/b++); // a=5, a=3, c= 2


	//5. (a++) % (c++)를 printf를 통해 출력하여 값을 확인해본다.
	printf("(a++) %% (c++) = %d\n", a++%c++); // a = 6, b= 4, c = 2


	//6. (++a) / (++b)를 printf를 통해 출력하여 값을 확인해본다.
	printf("(++a) / (++b) = %d\n", ((++a) / (++b))); // a= 8, b=5, c = 3


	//7. (++a) % (++c)를 printf를 통해 출력하여 값을 확인해본다.
	printf("(++a) %% (++c) = %d\n", ((++a) % (++c))); // a = 9, b = 5, c = 4

	return 0;
}
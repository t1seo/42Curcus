#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897

double get_radian(int num)
{
	return num * (PI / 180);
}

int main()
{
	double result1, result2, result3;

	double num = get_radian(60);

	result1 = sin(num);
	result2 = cos(num);
	result3 = tan(num);

	printf("sin60 : %lf\n", result1);
	printf("cos60 : %lf\n", result2);
	printf("tan60 : %lf\n", result3);

	return 0;
}

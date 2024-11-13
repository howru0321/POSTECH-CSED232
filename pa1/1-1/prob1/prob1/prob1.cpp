#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	FILE* ip = fopen("input.txt", "r");
	FILE* op = fopen("ouput.txt", "w");

	char oper;//연산자를 받아오는 변수
	float num1, num2;//피연산숫자 두개를 받아오는 변수

	while (fscanf(ip, "%c %f %f\n", &oper, &num1, &num2) == 3)//총 3개를 받아오면 3을 return한다. 마지막에는 받아오지 못하므로 0이 return 되고, while문이 종료된다
	{
		if (oper == '+')//연산자가 +일때
		{
			fprintf(op, "%.3f\n", num1 + num2);
		}
		if (oper == '-')//연산자가 -일때
		{
			fprintf(op, "%.3f\n", num1 - num2);
		}
		if (oper == '/')//연산자가 /일때
		{
			fprintf(op, "%.3f\n", num1 / num2);
		}
		if (oper == '*')//연산자가 *일때
		{
			fprintf(op, "%.3f\n", num1 * num2);
		}
	}
	fclose(ip);
	fclose(op);
}
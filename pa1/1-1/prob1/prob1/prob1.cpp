#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	FILE* ip = fopen("input.txt", "r");
	FILE* op = fopen("ouput.txt", "w");

	char oper;//�����ڸ� �޾ƿ��� ����
	float num1, num2;//�ǿ������ �ΰ��� �޾ƿ��� ����

	while (fscanf(ip, "%c %f %f\n", &oper, &num1, &num2) == 3)//�� 3���� �޾ƿ��� 3�� return�Ѵ�. ���������� �޾ƿ��� ���ϹǷ� 0�� return �ǰ�, while���� ����ȴ�
	{
		if (oper == '+')//�����ڰ� +�϶�
		{
			fprintf(op, "%.3f\n", num1 + num2);
		}
		if (oper == '-')//�����ڰ� -�϶�
		{
			fprintf(op, "%.3f\n", num1 - num2);
		}
		if (oper == '/')//�����ڰ� /�϶�
		{
			fprintf(op, "%.3f\n", num1 / num2);
		}
		if (oper == '*')//�����ڰ� *�϶�
		{
			fprintf(op, "%.3f\n", num1 * num2);
		}
	}
	fclose(ip);
	fclose(op);
}
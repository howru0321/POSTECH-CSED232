#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define FLUSH while (getchar() != '\n')

int main()
{
	FILE* ip = fopen("input.txt", "r");
	char pic[100][15];//�ִ� 100���� �����Ͽ���, �ܾ� ���� ���� (4+1+6)=11�̳� �������� �� �ܾ� �ڿ� ���ʿ��� ���Ⱑ �ִٴ°��� ������ ���̸� ���� �÷� 15�� ��Ҵ�

	int i = 0;
	while (fgets(pic[i], sizeof(pic[i]), ip) != NULL)//������ �޾ƿ��� �������� NULL���� ���´�	
	{
		pic[i][11] = '\0';//�ܾ� �ڿ� �ʿ���� ���� ������
		i++;
	}
	int j = 0, k = 0, cp = 0;
	for (j = 0; j < i; j++)//�ݺ����� ���� selection sort�� ������
	{
		cp = j;
		for (k = j; k < i; k++)
		{
			if (strcmp(pic[cp], pic[k]) > 0)
			{
				cp = k;
			}
		}
		char copy[15];
		strcpy(copy, pic[j]);
		strcpy(pic[j], pic[cp]);
		strcpy(pic[cp], copy);
	}

	FILE* op = fopen("ouput.txt", "w");
	
	int z;
	for (z = 0; z < i; z++)
	{
		fprintf(op, "%s\n", pic[z]);
	}
	fclose(ip);
	fclose(op);
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define FLUSH while (getchar() != '\n')

int main()
{
	FILE* ip = fopen("input.txt", "r");
	char pic[100][15];//최대 100개로 지정하였고, 단어 길이 역시 (4+1+6)=11이나 예시파일 중 단어 뒤에 불필요한 띄어쓰기가 있다는것을 감안해 길이를 조금 늘려 15로 잡았다

	int i = 0;
	while (fgets(pic[i], sizeof(pic[i]), ip) != NULL)//끝까지 받아오면 마지막엔 NULL값이 나온다	
	{
		pic[i][11] = '\0';//단어 뒤에 필요없는 띄어쓰기 제거함
		i++;
	}
	int j = 0, k = 0, cp = 0;
	for (j = 0; j < i; j++)//반복문을 통해 selection sort를 실행함
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
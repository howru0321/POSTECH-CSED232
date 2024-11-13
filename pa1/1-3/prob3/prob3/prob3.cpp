#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 100;

int strt(char map[][10], int spox, int spoy, int fpox, int fpoy, int dis, int l);

int main()
{
    FILE* ip = fopen("input.txt", "r");
    int i, j;
    char map[10][10];//input.txt 정보를 읽어오는 함수
    char temp;
    for (i = 0; i < 10; i++)//input.txt 정보를 읽기위한 반복분
    {
        fscanf(ip, "%c %c %c %c %c %c %c %c %c %c\n", &map[i][0], &map[i][1], &map[i][2], &map[i][3], &map[i][4], &map[i][5], &map[i][6], &map[i][7], &map[i][8], &map[i][9]);
    }

    int kpox, kpoy, epox, epoy;//열쇠와 출구의 위치를 나타내는 변수
    int k, l;
    for (k = 0; k < 10; k++)//열쇠와 출구의 위치를 for반복문을 통해 찾는다
    {
        for (l = 0; l < 10; l++)
        {
            if (map[k][l] == 'k')
            {
                kpoy = k;
                kpox = l;
            }
            if (map[k][l] == 'e')
            {
                epoy = k;
                epox = l;
            }
            
        }
    }
    map[kpoy][kpox] = '0';//최단거리를 찾는 알고리즘 상 배열에는 '0','1'밖에 없으므로 'k'와  'e'는 다 '0'으로 바꾸어주었다
    map[epoy][epox] = '0';
    int kdis;
    kdis = strt(map, 0, 0, kpox, kpoy, 100, 0);//출발점과 열쇠사이의 경로, 최대 경로가 100이므로 100으로 설정하였다
    int kedis;
    kedis = strt(map, kpox, kpoy, epox, epoy, 100, 0);//열쇠와 출구사이의 경로
    FILE* op = fopen("ouput.txt", "w");
    fprintf(op, "%d", kdis + kedis);

    fclose(ip);
    fclose(op);
}

int strt(char map[][10], int spox, int spoy, int fpox, int fpoy, int dis, int l)
{
    if (spox == fpox && spoy == fpoy)//끝점에 도착했을경우
    {
        if (dis > l)//이 경로가 그 전에 보았던 경로보다 짧을때
        {
            dis = l;
        }
        return dis;
    }
    

    map[spoy][spox] = '1';//전에 지났던 곳을 다시 가는것을 방지

    if (spoy > 0 && map[spoy - 1][spox] == '0')//위로
    {
        dis = strt(map, spox, spoy - 1, fpox, fpoy, dis, l + 1);
    }
    if (spox > 0 && map[spoy][spox - 1] == '0')//왼쪽으로
    {
        dis = strt(map, spox - 1, spoy, fpox, fpoy, dis, l + 1);
    }
    if (spoy < 9 && map[spoy + 1][spox] == '0')//아래로
    {
        dis = strt(map, spox, spoy + 1, fpox, fpoy, dis, l + 1);
    }
    if (spox < 9 && map[spoy][spox + 1] == '0')//오른쪽으로
    {
        dis = strt(map, spox + 1, spoy, fpox, fpoy, dis, l + 1);
    }
    else
    {
        map[spoy][spox] = '0';
        return dis;
    }

    map[spoy][spox] = '0';

    return dis;
}
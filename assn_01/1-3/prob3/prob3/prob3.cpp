#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX 100;

int strt(char map[][10], int spox, int spoy, int fpox, int fpoy, int dis, int l);

int main()
{
    FILE* ip = fopen("input.txt", "r");
    int i, j;
    char map[10][10];//input.txt ������ �о���� �Լ�
    char temp;
    for (i = 0; i < 10; i++)//input.txt ������ �б����� �ݺ���
    {
        fscanf(ip, "%c %c %c %c %c %c %c %c %c %c\n", &map[i][0], &map[i][1], &map[i][2], &map[i][3], &map[i][4], &map[i][5], &map[i][6], &map[i][7], &map[i][8], &map[i][9]);
    }

    int kpox, kpoy, epox, epoy;//����� �ⱸ�� ��ġ�� ��Ÿ���� ����
    int k, l;
    for (k = 0; k < 10; k++)//����� �ⱸ�� ��ġ�� for�ݺ����� ���� ã�´�
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
    map[kpoy][kpox] = '0';//�ִܰŸ��� ã�� �˰��� �� �迭���� '0','1'�ۿ� �����Ƿ� 'k'��  'e'�� �� '0'���� �ٲپ��־���
    map[epoy][epox] = '0';
    int kdis;
    kdis = strt(map, 0, 0, kpox, kpoy, 100, 0);//������� ��������� ���, �ִ� ��ΰ� 100�̹Ƿ� 100���� �����Ͽ���
    int kedis;
    kedis = strt(map, kpox, kpoy, epox, epoy, 100, 0);//����� �ⱸ������ ���
    FILE* op = fopen("ouput.txt", "w");
    fprintf(op, "%d", kdis + kedis);

    fclose(ip);
    fclose(op);
}

int strt(char map[][10], int spox, int spoy, int fpox, int fpoy, int dis, int l)
{
    if (spox == fpox && spoy == fpoy)//������ �����������
    {
        if (dis > l)//�� ��ΰ� �� ���� ���Ҵ� ��κ��� ª����
        {
            dis = l;
        }
        return dis;
    }
    

    map[spoy][spox] = '1';//���� ������ ���� �ٽ� ���°��� ����

    if (spoy > 0 && map[spoy - 1][spox] == '0')//����
    {
        dis = strt(map, spox, spoy - 1, fpox, fpoy, dis, l + 1);
    }
    if (spox > 0 && map[spoy][spox - 1] == '0')//��������
    {
        dis = strt(map, spox - 1, spoy, fpox, fpoy, dis, l + 1);
    }
    if (spoy < 9 && map[spoy + 1][spox] == '0')//�Ʒ���
    {
        dis = strt(map, spox, spoy + 1, fpox, fpoy, dis, l + 1);
    }
    if (spox < 9 && map[spoy][spox + 1] == '0')//����������
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
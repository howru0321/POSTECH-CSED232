#include "WhiteBoard.h"

WhiteBoard::WhiteBoard()//�⺻������. ���� ���ǿ��� char���� 'a'�� ġȯ�϶�� ������ �־� char board[15]15] ��� �迭�� 'a'�� �ʱ�ȭ �Ͽ���
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = 'a';
		}
	}
}

WhiteBoard::~WhiteBoard()
{

}

void WhiteBoard::fillPoint(int x, int y, char alphabet)// ������ x,y ��ǥ�� ���� alphabet ���� ĭ�� ä���. �� �Լ��� ���� ������ friend�� ���� �ʰ� WhiteBoard�� private�� board[][]�� ���� �����ϱ� ���ؼ� �̴�.
{
	board[y][x] = alphabet;
}

void WhiteBoard::reset()// ��� ĭ�� *�� �ʱ�ȭ�Ѵ�.
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = '*';
		}
	}
}

void WhiteBoard::display() const//whiteboard �� ����Ѵ�.
{
	std::cout << "[WhiteBoard]" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}
#pragma once
#include <iostream>

class WhiteBoard {
private:
	char board[15][15];

public:
	WhiteBoard();//�⺻������. ���� ���ǿ��� char���� 'a'�� ġȯ�϶�� ������ �־� char board[15]15] ��� �迭�� 'a'�� �ʱ�ȭ �Ͽ���
	~WhiteBoard();//�Ҹ���
	void fillPoint(int x, int y, char alphabet);// ������ x,y ��ǥ�� ���� alphabet ���� ĭ�� ä���. �� �Լ��� ���� ������ friend�� ���� �ʰ� WhiteBoard�� private�� board[][]�� ���� �����ϱ� ���ؼ� �̴�.
	void reset();// ��� ĭ�� *�� �ʱ�ȭ�Ѵ�.
	void display() const;//whiteboard �� ����Ѵ�.
};
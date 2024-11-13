#pragma once
#include <iostream>
#include "WhiteBoard.h"

class AShape {
protected:
	char alphabet;//������ �̷�� ���ĺ��̴�

public:
	AShape();//�⺻ ������
	virtual ~AShape();//�Ҹ���
	virtual void draw(WhiteBoard* board) const = 0;//whiteboard�� ������ �׸��� �Լ�. pure virtual function�̸�, protected�� �ִ� ������ alphabet���� ������ �׸���. ��ġ�� ��ӵ� class�� �����ڷ� �޴´�
	virtual void print() const = 0;//�׵��� �׷��� ������ ����Ʈ�� �����ִ� �Լ�. pure virtual function�̸�, ���� ������� ������ ���´�.�ش� ������ �����ϴ� ������ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ¾��ĺ�, ũ�⸦ ���� ����Ѵ�.���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�
	virtual int size() const = 0;//�ش� ������ ũ�⸦ ����ϴ� �Լ�. ������ ��ǥ�� �� ���� �ִ� ���ĺ�, ũ�⸦ ���� ����Ѵ�.���� ���� - ����Ʈ ��� �� ������ �����ϴ� ������ ���δ�
};

class APoint : public AShape {//��� class. �� ���� ������ ���� ����̴�.
private:
	int x;
	int y;

public:
	APoint();
	APoint(int x_, int y_, char alphabet_);
	~APoint();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AVerticalLine :public AShape {//��� class. �� ���� ������ ���� ����̴�.
private:
	int x;
	int y_start;
	int y_end;

public:
	AVerticalLine();
	AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
	~AVerticalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class AHorizontalLine :public AShape {//��� class. �� ���� ������ ���� ����̴�.
private:
	int y;
	int x_start;
	int x_end;

public:
	AHorizontalLine();
	AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
	~AHorizontalLine();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};

class ARectangle :public AShape {//��� class. �� ���� ������ �簢���� ����̴�.
private:
	int x_start;
	int x_end;
	int y_start;
	int y_end;

public:
	ARectangle();
	ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);
	~ARectangle();
	void draw(WhiteBoard* board) const;
	void print() const;
	int size() const;
};
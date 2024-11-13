#pragma once
#include <iostream>
#include "ashape.h"

struct AShapeNode {
	AShape* shape;
	AShapeNode* next;
};


class AShapeList {
private:
	AShapeNode* head;
	AShapeNode* tail;
	int size;

public:
	AShapeList();//�⺻ ������
	~AShapeList();//�Ҹ���
	void addNewAShape(AShape* new_shape);//���ο� ������ �߰��ϴ� �Լ�. linked list�� ���� �����Ѵ�
	void popNodeByldx(int idx);//linked list�� ���� ������ �迭���� ���ϴ� ����� �����Ѵ�
	const AShapeNode* getNodeByldx(int idx) const;//���ϴ� ����� �ּҸ� �����ϴ� �Լ�
	void displayAShapeList() const;//�������� ��� �������� ����ϴ� �Լ�.���� ���� �� ������ ������ �Ѳ����� ����� �� ���δ�.
	void drawAll(WhiteBoard* board) const;//��� ������ whiteboard�� �׸���
	int getSize() const;//���� ����Ʈ�� ������ �ִ� ������ ������ �����ϴ� �Լ�
};
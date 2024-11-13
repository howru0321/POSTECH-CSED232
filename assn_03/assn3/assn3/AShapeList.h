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
	AShapeList();//기본 생성자
	~AShapeList();//소멸자
	void addNewAShape(AShape* new_shape);//새로운 도형을 추가하는 함수. linked list를 통해 구현한다
	void popNodeByldx(int idx);//linked list를 통해 구현한 배열에서 원하는 노드을 삭제한다
	const AShapeNode* getNodeByldx(int idx) const;//원하는 노드의 주소를 리턴하는 함수
	void displayAShapeList() const;//관리중인 모든 도형들을 출력하는 함수.도형 삭제 시 도형의 정보를 한꺼번에 출력할 때 쓰인다.
	void drawAll(WhiteBoard* board) const;//모든 도형을 whiteboard에 그린다
	int getSize() const;//현재 리스트가 가지고 있는 도형의 개수를 리턴하는 함수
};
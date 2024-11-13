#pragma once
#include <iostream>
#include "WhiteBoard.h"
#include "AShapeList.h"

class Menu {
private:
	bool is_running;
	AShapeList* shape_list;
	WhiteBoard* board;

public:
	Menu(WhiteBoard* board, AShapeList* shape_list);//�⺻ ������. is_running �� �⺻������ ������ �Ǿ� �ϹǷ� true�� �ʱ�ȭ �Ͽ���.
	~Menu();//�Ҹ���
	void display() const;//�Ŵ��� ����ϴ� �Լ�
	bool getRunning() const;//���� ���α׷��� ���� �������� ���θ� turn, false�� �����Ѵ�
	void getUserInput();//������ �Է��� �޾� �޴��� ���� �ϰ�, ���� addAShape, deleteAShape ���� ȣ���Ѵ�.
	void addAShape() const;//������ ���ϴ� �Լ�.
	void deleteAShape() const;//������ �Է��� �޾� ���������� �����ϴ� �Լ�
};
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
	Menu(WhiteBoard* board, AShapeList* shape_list);//기본 생성자. is_running 은 기본적으로 실행이 되야 하므로 true로 초기화 하였다.
	~Menu();//소멸자
	void display() const;//매뉴를 출력하는 함수
	bool getRunning() const;//현재 프로그램이 실행 중인지의 여부를 turn, false로 리턴한다
	void getUserInput();//유저의 입력을 받아 메뉴를 고르게 하고, 이후 addAShape, deleteAShape 등을 호출한다.
	void addAShape() const;//도형을 더하는 함수.
	void deleteAShape() const;//유저의 입력을 받아 도형삭제를 진행하는 함수
};
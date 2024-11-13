#pragma once
#include <iostream>

class WhiteBoard {
private:
	char board[15][15];

public:
	WhiteBoard();//기본생성자. 문제 조건에서 char형은 'a'로 치환하라는 조건이 있어 char board[15]15] 모든 배열을 'a'로 초기화 하였다
	~WhiteBoard();//소멸자
	void fillPoint(int x, int y, char alphabet);// 지정된 x,y 좌표에 들어온 alphabet 으로 칸을 채운다. 이 함수를 만든 이유는 friend를 쓰지 않고 WhiteBoard의 private인 board[][]에 값을 대입하기 위해서 이다.
	void reset();// 모든 칸을 *로 초기화한다.
	void display() const;//whiteboard 를 출력한다.
};
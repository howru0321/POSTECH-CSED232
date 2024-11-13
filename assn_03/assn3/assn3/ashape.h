#pragma once
#include <iostream>
#include "WhiteBoard.h"

class AShape {
protected:
	char alphabet;//도형을 이루는 알파벳이다

public:
	AShape();//기본 생성자
	virtual ~AShape();//소멸자
	virtual void draw(WhiteBoard* board) const = 0;//whiteboard에 도형을 그리는 함수. pure virtual function이며, protected에 있는 변수인 alphabet으로 도형을 그린다. 위치는 상속된 class의 생성자로 받는다
	virtual void print() const = 0;//그동안 그려진 도형의 리스트를 보여주는 함수. pure virtual function이며, 넣은 순서대로 도형이 나온다.해당 도형을 설명하는 내용을 출력하는 함수. 도형의 좌표값 및 갖고 있는알파벳, 크기를 전부 출력한다.도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다
	virtual int size() const = 0;//해당 도형의 크기를 출력하는 함수. 도형의 좌표값 및 갖고 있는 알파벳, 크기를 전부 출력한다.도형 삭제 - 리스트 출력 시 도형을 설명하는 데에서 쓰인다
};

class APoint : public AShape {//상속 class. 이 경우는 도형이 점인 경우이다.
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

class AVerticalLine :public AShape {//상속 class. 이 경우는 도형이 선인 경우이다.
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

class AHorizontalLine :public AShape {//상속 class. 이 경우는 도형이 선인 경우이다.
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

class ARectangle :public AShape {//상속 class. 이 경우는 도형이 사각형인 경우이다.
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
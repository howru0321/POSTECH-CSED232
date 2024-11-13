#pragma once
#include <iostream>
#include "geometry.h"
#include <vector>

using namespace std;

class canvas2d : public vector<geometry*> {//STL vector를 상속 받아 구현되며 보유한 객체를 stdout으로 그려내는 class
public:
	canvas2d(int width, int height, char c_empty) : width(width), height(height), c_empty(c_empty) {
		for (int i = 0; i < height; i++) {
			vector<char>element1(width);
			vector<int>element2(width);
			for (int j = 0; j < width; j++)
				element1[j] = c_empty;
			for (int j = 0; j < width; j++)
				element2[j] = 0;
			board1.push_back(element1);
			board2.push_back(element2);
		}
	}
	void draw2stdout() {// 보유한 객체를 stdout으로 출력
		for (int i = 0; i < (int)this->size(); i++) {
			(* (this->begin() + i))->draw2canvas(board2);
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board2[i][j] == 0)
					cout << board1[i][j];
				else
					cout << board2[i][j];
			}
			cout << endl;
		}
	}
	
	/*void push_back(geometry* geo) {
		vector<geometry*>::push_back(geo);
	}*/
	
private:
	int width;//width: canvas의 폭
	int height;//height: canvas의 높이
	char c_empty;// 빈 공간을 표현할 글자(char)
	vector<vector<char>> board1;//size는 기존 canvas의 width랑 height가 같고 c_empty로 차 있는 2차원 배열. vector class로 만들었으며, board2의 원소가 0일때 출력되는 용도이다.
	vector<vector<int>> board2;//canvas 정보를 담고 있는 2차원 배열. 처음엔 0으로 차 있고 조건에 따라 숫자가 더해진다. 0이 아닌 숫자들은 출력이 된다.
	friend class geometry;
};
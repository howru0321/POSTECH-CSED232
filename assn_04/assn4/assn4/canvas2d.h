#pragma once
#include <iostream>
#include "geometry.h"
#include <vector>

using namespace std;

class canvas2d : public vector<geometry*> {//STL vector�� ��� �޾� �����Ǹ� ������ ��ü�� stdout���� �׷����� class
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
	void draw2stdout() {// ������ ��ü�� stdout���� ���
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
	int width;//width: canvas�� ��
	int height;//height: canvas�� ����
	char c_empty;// �� ������ ǥ���� ����(char)
	vector<vector<char>> board1;//size�� ���� canvas�� width�� height�� ���� c_empty�� �� �ִ� 2���� �迭. vector class�� ���������, board2�� ���Ұ� 0�϶� ��µǴ� �뵵�̴�.
	vector<vector<int>> board2;//canvas ������ ��� �ִ� 2���� �迭. ó���� 0���� �� �ְ� ���ǿ� ���� ���ڰ� ��������. 0�� �ƴ� ���ڵ��� ����� �ȴ�.
	friend class geometry;
};
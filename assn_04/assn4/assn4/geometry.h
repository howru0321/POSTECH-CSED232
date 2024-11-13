#pragma once
#include <algorithm>
#include <vector>
#include "parser.h"

using namespace std;

class geometry {// 모든 geometry 구성 요소들의 abstract class
public:
	virtual void draw2canvas(vector<vector<int>> &board) = 0;//canvas의 instance가 geometry를 그릴 때 사용된다.
};

template <typename T>
class rectangle :public geometry {//2차원 평면을 가정한 사각형 class
public:
	rectangle(T x1, T y1, T x2, T y2) : x_1(x1), y_1(y1), x_2(x2), y_2(y2) {
		if (x1 == x2 || y1 == y2)
			throw;
	};

	void draw2canvas(vector<vector<int>>& board) {
		int max_x_temp = (int)max(this->x_1, this->x_2);
		int max_y_temp = (int)max(this->y_1, this->y_2);
		int min_x_temp = (int)min(this->x_1, this->x_2);
		int min_y_temp = (int)min(this->y_1, this->y_2);

		int max_x = min(max_x_temp, (int)board[0].size()-1);
		int max_y = min(max_y_temp, (int)board.size()-1);
		int min_x = max(min_x_temp, 0);
		int min_y = max(min_y_temp, 0);

		for (int j = min_x; j <= max_x; j++) {
			for (int i = min_y; i <= max_y; i++) {
				board[i][j] += 1;
			}
		}
	}

	bool is_equal(const rectangle<T>& other) {//멤버함수를 호출하는 instance와 other이 정확히 4개의 point를 공유하는 경우 true, 그렇지 않은 경우 false

		T this_max_x = (T)max(this->x_1, this->x_2);
		T this_max_y = (T)max(this->y_1, this->y_2);
		T this_min_x = (T)min(this->x_1, this->x_2);
		T this_min_y = (T)min(this->y_1, this->y_2);

		T other_max_x = (T)max(other.x_1, other.x_2);
		T other_max_y = (T)max(other.y_1, other.y_2);
		T other_min_x = (T)min(other.x_1, other.x_2);
		T other_min_y = (T)min(other.y_1, other.y_2);

		if (this_max_x == other_max_x && this_max_y == other_max_y && this_min_x == other_min_x && this_min_y == other_min_y)
			return true;
		else
			return false;
	}
	bool is_intersect(const rectangle<T>& other) {//멤버함수를 호출하는 instance와 other이 equal이 아니면서 영역이 겹치는 경우 true, 그렇지 않은 경우 false (아래 예시)

		T this_max_x = (T)max(this->x_1, this->x_2);
		T this_max_y = (T)max(this->y_1, this->y_2);
		T this_min_x = (T)min(this->x_1, this->x_2);
		T this_min_y = (T)min(this->y_1, this->y_2);

		T other_max_x = (T)max(other.x_1, other.x_2);
		T other_max_y = (T)max(other.y_1, other.y_2);
		T other_min_x = (T)min(other.x_1, other.x_2);
		T other_min_y = (T)min(other.y_1, other.y_2);

		if (this_max_x == other_max_x && this_max_y == other_max_y && this_min_x == other_min_x && this_min_y == other_min_y)
			return false;
		else if (this_max_x == other_min_x && this_min_y == other_max_y)
			return false;
		else if (this_max_x == other_min_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_min_y == other_max_y)
			return false;
		else if (this_max_x == other_min_x)
			return false;
		else if (this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x)
			return false;
		else if (this_min_y == other_max_y)
			return false;

		else if (this->x_1 >= other_min_x && this->x_1 <=other_max_x && this->y_1>=other_min_y && this->y_1 <= other_max_y)
			return true;
		else if (this->x_1 >= other_min_x && this->x_1 <=other_max_x && this->y_2>=other_min_y && this->y_2 <= other_max_y)
			return true;
		else if (this->x_2 >= other_min_x && this->x_2 <=other_max_x && this->y_1>=other_min_y && this->y_1 <= other_max_y)
			return true;
		else if (this->x_2 >= other_min_x && this->x_2 <=other_max_x && this->y_2>=other_min_y && this->y_2 <= other_max_y)
			return true;

		else
			return false;
	}
	bool is_line_overlap(const rectangle<T>& other) {//멤버함수를 호출하는 instance와 other이 equal 및 intersect가 아니면서 한 변을 공유하는 경우 true, 그렇지 않은 경우 false

		T this_max_x = (T)max(this->x_1, this->x_2);
		T this_max_y = (T)max(this->y_1, this->y_2);
		T this_min_x = (T)min(this->x_1, this->x_2);
		T this_min_y = (T)min(this->y_1, this->y_2);

		T other_max_x = (T)max(other.x_1, other.x_2);
		T other_max_y = (T)max(other.y_1, other.y_2);
		T other_min_x = (T)min(other.x_1, other.x_2);
		T other_min_y = (T)min(other.y_1, other.y_2);

		if (this_max_x == other_max_x && this_max_y == other_max_y && this_min_x == other_min_x && this_min_y == other_min_y)
			return false;
		else if (this_max_x == other_min_x && this_min_y == other_max_y)
			return false;
		else if (this_max_x == other_min_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_min_y == other_max_y)
			return false;

		else if (this_max_x == other_min_x)
			return true;
		else if (this_max_y == other_min_y)
			return true;
		else if (this_min_x == other_max_x)
			return true;
		else if (this_min_y == other_max_y)
			return true;

		else
			return false;
	}
	bool is_point_match(const rectangle<T>& other) {//멤버함수를 호출하는 instance와 other이 intersect가 아니면서 오직 한 점을 공유하는 경우 true, 그렇지 않은 경우 false
		T this_max_x = (T)max(this->x_1, this->x_2);
		T this_max_y = (T)max(this->y_1, this->y_2);
		T this_min_x = (T)min(this->x_1, this->x_2);
		T this_min_y = (T)min(this->y_1, this->y_2);

		T other_max_x = (T)max(other.x_1, other.x_2);
		T other_max_y = (T)max(other.y_1, other.y_2);
		T other_min_x = (T)min(other.x_1, other.x_2);
		T other_min_y = (T)min(other.y_1, other.y_2);

		if (this_max_x == other_max_x && this_max_y == other_max_y && this_min_x == other_min_x && this_min_y == other_min_y)
			return false;

		else if (this_max_x == other_min_x && this_min_y == other_max_y)
			return true;
		else if (this_max_x == other_min_x && this_max_y == other_min_y)
			return true;
		else if (this_min_x == other_max_x && this_max_y == other_min_y)
			return true;
		else if (this_min_x == other_max_x && this_min_y == other_max_y)
			return true;

		else
			return false;
	}
	bool is_disjoint(const rectangle<T>& other) {//멤버함수를 호출하는 instance와 other이 만나지 않는 경우 true, 그렇지 않은 경우 false
		T this_max_x = (T)max(this->x_1, this->x_2);
		T this_max_y = (T)max(this->y_1, this->y_2);
		T this_min_x = (T)min(this->x_1, this->x_2);
		T this_min_y = (T)min(this->y_1, this->y_2);

		T other_max_x = (T)max(other.x_1, other.x_2);
		T other_max_y = (T)max(other.y_1, other.y_2);
		T other_min_x = (T)min(other.x_1, other.x_2);
		T other_min_y = (T)min(other.y_1, other.y_2);

		if (this_max_x == other_max_x && this_max_y == other_max_y && this_min_x == other_min_x && this_min_y == other_min_y)
			return false;
		else if (this_max_x == other_min_x && this_min_y == other_max_y)
			return false;
		else if (this_max_x == other_min_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x && this_min_y == other_max_y)
			return false;
		else if (this_max_x == other_min_x)
			return false;
		else if (this_max_y == other_min_y)
			return false;
		else if (this_min_x == other_max_x)
			return false;
		else if (this_min_y == other_max_y)
			return false;
		else if (this->x_1 >= other_min_x && this->x_1 <= other_max_x && this->y_1 >= other_min_y && this->y_1 <= other_max_y)
			return false;
		else if (this->x_1 >= other_min_x && this->x_1 <= other_max_x && this->y_2 >= other_min_y && this->y_2 <= other_max_y)
			return false;
		else if (this->x_2 >= other_min_x && this->x_2 <= other_max_x && this->y_1 >= other_min_y && this->y_1 <= other_max_y)
			return false;
		else if (this->x_2 >= other_min_x && this->x_2 <= other_max_x && this->y_2 >= other_min_y && this->y_2 <= other_max_y)
			return false;

		else
			return true;
	}
private:
	T x_1;//rectangle의 x좌표중 가장 큰값이나 가장 작은값 중 하나
	T y_1;//rectangle의 y좌표중 가장 큰값이나 가장 작은값 중 하나
	T x_2;//rectangle의 x좌표중 가장 큰값이나 가장 작은값 중 하나
	T y_2;//rectangle의 y좌표중 가장 큰값이나 가장 작은값 중 하나
};
template <typename T, int N>
class point :public geometry {//포인트 class로 T는 사용될 numeric type, N은 coordinate dimension을 의미한다

public:
	point(const T* number) {//point class의 생성자이며 N개의 T값으로 초기화 된다.
		codi = N;
		num = *number;
	}
	void get_pos(T _x, T _y) {//point의 위치를 설정해 주는 함수. 위치좌표가 private이므로 public함수를 통해 구현해 주었다.
		x = _x;
		y = _y;
	}

	void draw2canvas(vector<vector<int>>& board) {
		if ((float)x > (float)((int)board[0].size() - 1) || (float)y > (float)((int)board.size() - 1))
			return;

		int pos_x = (int)x;
		int pos_y = (int)y;
		board[pos_y][pos_x] += (int)num;
	}

private:
	int codi;//차원. 본 알고리즘에서는 사용하지 못했다.

	T num;//point의 값을 저장하는 변수

	T x;//point의 x좌표
	T y;//point의 y좌표
};
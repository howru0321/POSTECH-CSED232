#pragma once
#include <algorithm>
#include <vector>
#include "parser.h"

using namespace std;

class geometry {// ��� geometry ���� ��ҵ��� abstract class
public:
	virtual void draw2canvas(vector<vector<int>> &board) = 0;//canvas�� instance�� geometry�� �׸� �� ���ȴ�.
};

template <typename T>
class rectangle :public geometry {//2���� ����� ������ �簢�� class
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

	bool is_equal(const rectangle<T>& other) {//����Լ��� ȣ���ϴ� instance�� other�� ��Ȯ�� 4���� point�� �����ϴ� ��� true, �׷��� ���� ��� false

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
	bool is_intersect(const rectangle<T>& other) {//����Լ��� ȣ���ϴ� instance�� other�� equal�� �ƴϸ鼭 ������ ��ġ�� ��� true, �׷��� ���� ��� false (�Ʒ� ����)

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
	bool is_line_overlap(const rectangle<T>& other) {//����Լ��� ȣ���ϴ� instance�� other�� equal �� intersect�� �ƴϸ鼭 �� ���� �����ϴ� ��� true, �׷��� ���� ��� false

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
	bool is_point_match(const rectangle<T>& other) {//����Լ��� ȣ���ϴ� instance�� other�� intersect�� �ƴϸ鼭 ���� �� ���� �����ϴ� ��� true, �׷��� ���� ��� false
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
	bool is_disjoint(const rectangle<T>& other) {//����Լ��� ȣ���ϴ� instance�� other�� ������ �ʴ� ��� true, �׷��� ���� ��� false
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
	T x_1;//rectangle�� x��ǥ�� ���� ū���̳� ���� ������ �� �ϳ�
	T y_1;//rectangle�� y��ǥ�� ���� ū���̳� ���� ������ �� �ϳ�
	T x_2;//rectangle�� x��ǥ�� ���� ū���̳� ���� ������ �� �ϳ�
	T y_2;//rectangle�� y��ǥ�� ���� ū���̳� ���� ������ �� �ϳ�
};
template <typename T, int N>
class point :public geometry {//����Ʈ class�� T�� ���� numeric type, N�� coordinate dimension�� �ǹ��Ѵ�

public:
	point(const T* number) {//point class�� �������̸� N���� T������ �ʱ�ȭ �ȴ�.
		codi = N;
		num = *number;
	}
	void get_pos(T _x, T _y) {//point�� ��ġ�� ������ �ִ� �Լ�. ��ġ��ǥ�� private�̹Ƿ� public�Լ��� ���� ������ �־���.
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
	int codi;//����. �� �˰��򿡼��� ������� ���ߴ�.

	T num;//point�� ���� �����ϴ� ����

	T x;//point�� x��ǥ
	T y;//point�� y��ǥ
};
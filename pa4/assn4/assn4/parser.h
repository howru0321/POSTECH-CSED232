#pragma once
#include <string>
#include "geometry.h"
#include "canvas2d.h"

class parser {// string을 받아 객체의 instance를 생성하는 기능을 제공하는 class
public:
	canvas2d parse_canvas(const std::string& line) {
		int first;
		int second;
		for (first = 0; line[first] != ','; first++);
		for (second = first + 1; line[second] != ','; second++);

		canvas2d c(stoi(line.substr(0, first)), stoi(line.substr(first + 1, second - first - 1)), line[second + 1]);
		return c;
	}
	geometry* parse_geometry(const std::string& line) {
		int cnt = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == ',')
				cnt++;
		}
		
		int first;
		int second;
		int third;
		int fourth;
		int fifth;
		int sixth;

		for (first = 0; line[first] != ','; first++);
		for (second = first + 1; line[second] != ','; second++);
		if (cnt >= 3)
			for (third = second + 1; line[third] != ','; third++);
		if (cnt >= 4)
			for (fourth = third + 1; line[fourth] != ','; fourth++);
		if (cnt >= 5)
			for (fifth = fourth + 1; line[fifth] != ','; fifth++);
		if (cnt == 6)
			for (sixth = fifth + 1; line[sixth] != ','; sixth++);

		if (line.substr(0, first) == "rectangle") {
			if (line.substr(first + 1, second - first - 1) == "int") {
				rectangle<int>*r=new rectangle<int> (stoi(line.substr(second + 1, third - second - 1)), stoi(line.substr(third + 1, fourth - third - 1)), stoi(line.substr(fourth + 1, fifth - fourth - 1)), stoi(line.substr(fifth + 1)));
				return r;
			}
			else if (line.substr(first + 1, second - first - 1) == "float") {
				rectangle<float>*r=new rectangle<float> (stof(line.substr(second + 1, third - second - 1)), stof(line.substr(third + 1, fourth - third - 1)), stof(line.substr(fourth + 1, fifth - fourth - 1)), stof(line.substr(fifth + 1)));
				return r;
			}
		}
		else if (line.substr(0, first) == "point") {
			if (cnt == 3) {
				if (line.substr(first + 1, second - first - 1) == "int") {
					const int a = 1;
					point<int,2>* p = new point<int, 2>(&a);
					p->get_pos(stoi(line.substr(second + 1, third - second - 1)), stoi(line.substr(third + 1)));
					return p;
				}
				else if (line.substr(first + 1, second - first - 1) == "float") {
					const float a = 1;
					point<float, 2>* p = new point<float, 2>(&a);
					p->get_pos(stof(line.substr(second + 1, third - second - 1)), stof(line.substr(third + 1)));
					return p;
				}
			}
			if (cnt == 4) {
				if (line.substr(first + 1, second - first - 1) == "int") {
					const int a = stoi(line.substr(fourth + 1));
					point<int, 3>* p = new point<int, 3>(&a);
					p->get_pos(stoi(line.substr(second + 1, third - second - 1)), stoi(line.substr(third + 1, fourth - third - 1)));;
					return p;
				}
				else if (line.substr(first + 1, second - first - 1) == "float") {
					const float a = stof(line.substr(fourth + 1));
					point<float, 3>* p = new point<float, 3>(&a);
					p->get_pos(stof(line.substr(second + 1, third - second - 1)), stof(line.substr(third + 1, fourth - third - 1)));
					return p;
				}
			}
			if (cnt == 5) {
				if (line.substr(first + 1, second - first - 1) == "int") {
					const int a = stoi(line.substr(fourth + 1, fifth - fourth - 1)) + stoi(line.substr(fifth + 1));
					point<int, 4>* p = new point<int, 4>(&a);
					p->get_pos(stoi(line.substr(second + 1, third - second - 1)), stoi(line.substr(third + 1, fourth - third - 1)));
					return p;
				}
				else if (line.substr(first + 1, second - first - 1) == "float") {
					const float a = stof(line.substr(fourth + 1, fifth - fourth - 1)) + stof(line.substr(fifth + 1));
					point<float, 4>* p = new point<float, 4>(&a);
					p->get_pos(stof(line.substr(second + 1, third - second - 1)), stof(line.substr(third + 1, fourth - third - 1)));
					return p;
				}
			}
			if (cnt == 6) {
				if (line.substr(first + 1, second - first - 1) == "int") {
					const int a = stoi(line.substr(fourth + 1, fifth - fourth - 1)) + stoi(line.substr(fifth + 1, sixth - fifth - 1)) + stoi(line.substr(sixth + 1));
					point<int, 5>* p = new point<int, 5>(&a);
					p->get_pos(stoi(line.substr(second + 1, third - second - 1)), stoi(line.substr(third + 1, fourth - third - 1)));
					return p;
				}
				else if (line.substr(first + 1, second - first - 1) == "float") {
					const float a = stof(line.substr(fourth + 1, fifth - fourth - 1)) + stof(line.substr(fifth + 1, sixth - fifth - 1)) + stof(line.substr(sixth + 1));
					point<float, 5>* p = new point<float, 5>(&a);
					p->get_pos(stof(line.substr(second + 1, third - second - 1)), stof(line.substr(third + 1, fourth - third - 1)));
					return p;
				}
			}
		}
	}
};
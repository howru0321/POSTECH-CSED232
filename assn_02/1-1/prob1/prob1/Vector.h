#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Vector
{
private:
	float* arr;//배열
	int len;//데이터 개수
	int msize;//할당된 메모리 사이즈
public:
	typedef float* iterator;//float*를 iterator 형으로 선언.
	typedef const float* const_iterator;//const float*를 const_iterator 형으로 선언.

	Vector();//기본 생성자. 모든 멤버 변수를 0 혹은 NULL 로 초기화한다.
	Vector(int size);//데이터 크기와 메모리 할당량은 size 로 초기화. size 개수만큼 0 으로 초기화된 데이터 저장.
	Vector(int size, const float& init);//float init 으로 초기화된 데이터를 저장. 데이터 크기와 메모리 할당량은 size 로 초기화.
	Vector(int size, const float* init);//float 배열 init 으로 초기화된 데이터 저장. 데이터 크기와 메모리 할당량은 size 로 초기화.
	Vector(const Vector& v);//복사 생성자.
	~Vector();//소멸자. 할당된 메모리를 삭제한다.
	
	int capacity() const;//데이터에 할당된 메모리 사이즈를 리턴한다.
	int size() const;//데이터 개수를 리턴한다.

	iterator begin();//데이터의 맨 처음 주소를 리턴한다.
	const_iterator begin() const;//데이터의 맨 처음 주소를 리턴한다. (const 버전)
	iterator end();//데이터의 맨 마지막 주소를 리턴한다.
	const_iterator end() const;//데이터의 맨 마지막 주소를 리턴한다. (const 버전)
	float& front();//데이터의 맨 처음 데이터를 리턴한다.
	const float& front() const;//데이터의 맨 처음 데이터를 리턴한다. (const 버전)
	float& back();//데이터의 맨 마지막 데이터를 리턴한다.
	const float& back() const;//데이터의 맨 마지막 데이터를 리턴한다. (const 버전)

	void allocate(int capacity);//데이터에 할당된 메모리를 capacity 만큼 동적 할당한다.
	void resize(int size);//size 만큼 데이터에 할당된 메모리를 동적 할당하며, 데이터 개수는 size 만큼 갖는다.
	void push_back(const float& value);//데이터의 맨 뒤에 새로운 데이터 value 를 추가한다. 2.문제 세부 조건 규칙에 따라 메모리를 동적 할당한다.
	void pop_back();//맨 마지막 데이터를 삭제한다. 이때 메모리 할당은 유지한다.
	void insert(iterator position, const float& value);//데이터의 특정 위치(position)에 value 를 삽입한다. 2.문제 세부 조건 규칙에 따라 메모리를 동적 할당한다.
	void insert(iterator position, const float* first, const float* last);//: 데이터에서 특정 위치(position)에 float array 를 삽입한다. 이때 first, last 는 각각 float array 의 맨 처음 주소, 맨 마지막 주소이다. 2.문제 세부 조건 규칙에 따라 메모리를 동적 할당한다.
	void erase(iterator position);//데이터에서 특정 위치(position)의 값을 삭제한다. 이때 메모리 할당은 유지한다.
	void clear();//할당된 메모리 사이즈, 데이터 개수를 0 으로 설정하며, 데이터를 NULL 로 설정한다.
	float& operator[](int index);//연산자 ‘[]’를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다.
	const float& operator[](int index) const;//연산자 ‘[]’를 오버로딩한다. 데이터에서 index 위치에 해당하는 값을 리턴한다. (const 버전)
	Vector& operator=(const Vector& v);//연산자 ‘=’를 오버로딩한다. 현재 멤버변수를 입력 Vector 의 멤버변수로 치환한다.
};
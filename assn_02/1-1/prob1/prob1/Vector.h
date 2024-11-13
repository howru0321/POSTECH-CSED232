#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Vector
{
private:
	float* arr;//�迭
	int len;//������ ����
	int msize;//�Ҵ�� �޸� ������
public:
	typedef float* iterator;//float*�� iterator ������ ����.
	typedef const float* const_iterator;//const float*�� const_iterator ������ ����.

	Vector();//�⺻ ������. ��� ��� ������ 0 Ȥ�� NULL �� �ʱ�ȭ�Ѵ�.
	Vector(int size);//������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ. size ������ŭ 0 ���� �ʱ�ȭ�� ������ ����.
	Vector(int size, const float& init);//float init ���� �ʱ�ȭ�� �����͸� ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ.
	Vector(int size, const float* init);//float �迭 init ���� �ʱ�ȭ�� ������ ����. ������ ũ��� �޸� �Ҵ緮�� size �� �ʱ�ȭ.
	Vector(const Vector& v);//���� ������.
	~Vector();//�Ҹ���. �Ҵ�� �޸𸮸� �����Ѵ�.
	
	int capacity() const;//�����Ϳ� �Ҵ�� �޸� ����� �����Ѵ�.
	int size() const;//������ ������ �����Ѵ�.

	iterator begin();//�������� �� ó�� �ּҸ� �����Ѵ�.
	const_iterator begin() const;//�������� �� ó�� �ּҸ� �����Ѵ�. (const ����)
	iterator end();//�������� �� ������ �ּҸ� �����Ѵ�.
	const_iterator end() const;//�������� �� ������ �ּҸ� �����Ѵ�. (const ����)
	float& front();//�������� �� ó�� �����͸� �����Ѵ�.
	const float& front() const;//�������� �� ó�� �����͸� �����Ѵ�. (const ����)
	float& back();//�������� �� ������ �����͸� �����Ѵ�.
	const float& back() const;//�������� �� ������ �����͸� �����Ѵ�. (const ����)

	void allocate(int capacity);//�����Ϳ� �Ҵ�� �޸𸮸� capacity ��ŭ ���� �Ҵ��Ѵ�.
	void resize(int size);//size ��ŭ �����Ϳ� �Ҵ�� �޸𸮸� ���� �Ҵ��ϸ�, ������ ������ size ��ŭ ���´�.
	void push_back(const float& value);//�������� �� �ڿ� ���ο� ������ value �� �߰��Ѵ�. 2.���� ���� ���� ��Ģ�� ���� �޸𸮸� ���� �Ҵ��Ѵ�.
	void pop_back();//�� ������ �����͸� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
	void insert(iterator position, const float& value);//�������� Ư�� ��ġ(position)�� value �� �����Ѵ�. 2.���� ���� ���� ��Ģ�� ���� �޸𸮸� ���� �Ҵ��Ѵ�.
	void insert(iterator position, const float* first, const float* last);//: �����Ϳ��� Ư�� ��ġ(position)�� float array �� �����Ѵ�. �̶� first, last �� ���� float array �� �� ó�� �ּ�, �� ������ �ּ��̴�. 2.���� ���� ���� ��Ģ�� ���� �޸𸮸� ���� �Ҵ��Ѵ�.
	void erase(iterator position);//�����Ϳ��� Ư�� ��ġ(position)�� ���� �����Ѵ�. �̶� �޸� �Ҵ��� �����Ѵ�.
	void clear();//�Ҵ�� �޸� ������, ������ ������ 0 ���� �����ϸ�, �����͸� NULL �� �����Ѵ�.
	float& operator[](int index);//������ ��[]���� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�.
	const float& operator[](int index) const;//������ ��[]���� �����ε��Ѵ�. �����Ϳ��� index ��ġ�� �ش��ϴ� ���� �����Ѵ�. (const ����)
	Vector& operator=(const Vector& v);//������ ��=���� �����ε��Ѵ�. ���� ��������� �Է� Vector �� ��������� ġȯ�Ѵ�.
};
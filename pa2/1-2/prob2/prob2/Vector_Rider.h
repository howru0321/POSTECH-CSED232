#pragma once
#include "Rider.h"
using namespace std;

class Vector_Rider
{
private:
	int msize;
	int len;
	Rider* arr;

	friend class Pizza;//Pizza에서는 고객수를 알아야하므로 friend처리를 해 주었다

public:
	typedef  Rider* iterator;
	typedef const Rider* const_iterator;

	Vector_Rider();
	Vector_Rider(int size);
	Vector_Rider(int size, const Rider& init);
	Vector_Rider(int size, const Rider* init);
	Vector_Rider(const Vector_Rider& v);
	~Vector_Rider();

	int capacity() const;
	int size() const;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	Rider& front();
	const Rider& front() const;
	Rider& back();
	const Rider& back() const;

	void allocate(int capacity);
	void resize(int size);

	void push_back(const Rider& value);
	void pop_back();
	void insert(iterator position, const Rider& value);
	void insert(iterator position, const Rider* first, const Rider* last);

	void erase(iterator position);
	void clear();

	Rider& operator[](int index);
	const Rider& operator[](int index) const;
	Vector_Rider& operator=(const Vector_Rider& v);
};
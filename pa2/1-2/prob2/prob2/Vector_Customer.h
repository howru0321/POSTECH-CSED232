#pragma once
#include "Customer.h"
using namespace std;

class Vector_Customer
{
private:
	int msize;
	int len;
	Customer* arr;

	friend class Pizza;//Pizza에서는 고객수를 알아야하므로 friend처리를 해 주었다

public:
	typedef  Customer * iterator;
	typedef const Customer * const_iterator;

	Vector_Customer();
	Vector_Customer(int size);
	Vector_Customer(int size, const Customer & init);
	Vector_Customer(int size, const Customer * init);
	Vector_Customer(const Vector_Customer & v);
	~Vector_Customer();

	int capacity() const;
	int size() const;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	Customer& front();
	const Customer& front() const;
	Customer & back();
	const Customer & back() const;

	void allocate(int capacity);
	void resize(int size);

	void push_back(const Customer & value);
	void pop_back();
	void insert(iterator position, const Customer & value);
	void insert(iterator position, const Customer * first, const Customer * last);

	void erase(iterator position);
	void clear();

	Customer & operator[](int index);
	const Customer & operator[](int index) const;
	Vector_Customer & operator=(const Vector_Customer & v);
};
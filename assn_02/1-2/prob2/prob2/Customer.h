#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Customer
{
private:
	float money;// ���� ���� ���� ��
	float paidMoney;// ���� ������ ���� �� �ջ�
	float time;// ���� ���� ��� �޴µ� �ɸ� �� �ð�

	friend class Pizza;

public:
	Customer();// �⺻ ������.money, paidMoney, time ���� 1000, 0, 0 ���� �ʱ�ȭ�Ѵ�.
	Customer(float money, float paidMoney, float time);// ��� ���� money, paidMoney, time �� �Է� ������ �����Ѵ�.
	Customer(const Customer& customer);// ���� ������.
	~Customer();// �Ҹ���.

	float reportMoney() const;// ���� ������� ������ ���� �� ���� �����ϴ� �Լ�.
	float reportTime() const;// ���� ������� ���ڸ� ��� �޴µ� �ɸ� �� �ð��� �����ϴ� �Լ�.
	void pay(float price, float time);// ���� ���Կ� ������ ���� ���ݸ�ŭ ���� �����ϸ�, ������ ��� �ð���ŭ �� ��� �ð��� �����ִ� �Լ�.
	friend ostream& operator <<(ostream& os, const Customer& x)//<< �����ε�
	{
		os << "(money, paidMoney, time) : (" << x.money << ", " << x.paidMoney << ", " << x.time << x.time << ")";

		return os;
	}
};
#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Rider
{
private:
	float money;// ��� ��簡 ���� ��
	float earnMoney;// ��� ��簡 �� ���� �� �ջ�
	float time;// ���� ����ϴµ� �ɸ� �� �ð�

	friend class Pizza;

public:
	Rider();// �⺻ ������.money, earnMoney, time ��� 0 ���� �ʱ�ȭ�Ѵ�.
	Rider(float money, float earnMoney, float time);// ��� ���� money, earnMomey, time �� �Է� ������ �����Ѵ�.
	Rider(const Rider& rider);// ���� ������.
	~Rider();// �Ҹ���.�Լ� ���� ���ٸ� ������ �ʿ� �����ϴ�.
	float reportMoney() const;// ��� ��簡 ������� �� ���� �� �ջ��� �����Ѵ�.
	float reportTime() const;// ��� ��簡 ������� ���ڸ� ����ϴµ� �ɸ� �� �ð��� �����Ѵ�.
	void deliver(float price, float time);// ������ ���� ���ݸ�ŭ ���� ������, ������ ��� �ð���ŭ �� ��� �ð��� �����ش�.
	friend ostream& operator <<(ostream& os, const Rider& x)//<< �����ε�
	{
		os << "(money, earnMoney, time) : (" << x.money << ", " << x.earnMoney << ", " << x.time << ")";

		return os;
	}
};
#include "Vector_Customer.h"
using namespace std;

Customer::Customer()//�⺻ ������
{
	money = 1000;
	paidMoney = 0;
	time = 0;
}

Customer::Customer(float money, float paidMoney, float time)//���ϴ� ������ �ʱ�ȭ �ϴ� ������
{
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
}

Customer::Customer(const Customer& customer)//���� ������
{
	money = customer.money;
	paidMoney = customer.paidMoney;
	time = customer.time;
}

Customer::~Customer()
{
}

float Customer::reportMoney() const
{
	return paidMoney;
}

float Customer::reportTime() const
{
	return time;
}

void Customer::pay(float price, float time)
{
	money -= price;
	paidMoney += price;
	this->time += time;
}
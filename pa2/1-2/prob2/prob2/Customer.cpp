#include "Vector_Customer.h"
using namespace std;

Customer::Customer()//기본 생성자
{
	money = 1000;
	paidMoney = 0;
	time = 0;
}

Customer::Customer(float money, float paidMoney, float time)//원하는 값으로 초기화 하는 생성자
{
	this->money = money;
	this->paidMoney = paidMoney;
	this->time = time;
}

Customer::Customer(const Customer& customer)//복사 생성자
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
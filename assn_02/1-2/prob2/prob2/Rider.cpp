#include "Vector_Rider.h"
using namespace std;

Rider::Rider()//�⺻������
{
	money = 0;
	earnMoney = 0;
	time = 0;
}

Rider::Rider(float money, float earnMoney, float time)//���ϴ� ������ �ʱ�ȭ �ϴ� ������
{
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;
}

Rider::Rider(const Rider& rider)//���������
{
	money = rider.money;
	earnMoney = rider.earnMoney;
	time = rider.time;
}

Rider::~Rider()
{
}

float Rider::reportMoney() const
{
	return earnMoney;
}

float Rider::reportTime() const
{
	return time;
}

void Rider::deliver(float price, float time)
{
	money += price;
	earnMoney += price;
	this->time += time;
}
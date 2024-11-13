#include "Vector_Rider.h"
using namespace std;

Rider::Rider()//기본생성자
{
	money = 0;
	earnMoney = 0;
	time = 0;
}

Rider::Rider(float money, float earnMoney, float time)//원하는 값으로 초기화 하는 생성자
{
	this->money = money;
	this->earnMoney = earnMoney;
	this->time = time;
}

Rider::Rider(const Rider& rider)//복사생성자
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
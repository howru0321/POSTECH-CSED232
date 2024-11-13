#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Customer
{
private:
	float money;// 고객이 현재 가진 돈
	float paidMoney;// 고객이 지불한 돈의 총 합산
	float time;// 고객이 피자 배달 받는데 걸린 총 시간

	friend class Pizza;

public:
	Customer();// 기본 생성자.money, paidMoney, time 각각 1000, 0, 0 으로 초기화한다.
	Customer(float money, float paidMoney, float time);// 멤버 변수 money, paidMoney, time 을 입력 값으로 설정한다.
	Customer(const Customer& customer);// 복사 생성자.
	~Customer();// 소멸자.

	float reportMoney() const;// 고객이 현재까지 지불한 돈의 총 합을 리턴하는 함수.
	float reportTime() const;// 고객이 현재까지 피자를 배달 받는데 걸린 총 시간을 리턴하는 함수.
	void pay(float price, float time);// 피자 가게에 정해진 피자 가격만큼 돈을 지불하며, 정해진 배달 시간만큼 총 배달 시간에 더해주는 함수.
	friend ostream& operator <<(ostream& os, const Customer& x)//<< 오버로딩
	{
		os << "(money, paidMoney, time) : (" << x.money << ", " << x.paidMoney << ", " << x.time << x.time << ")";

		return os;
	}
};
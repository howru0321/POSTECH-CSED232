#pragma once
#include "Vector_Customer.h"
#include "Vector_Rider.h"
using namespace std;

class Pizza
{
private:
	float money;//가게의 돈
	float priceA;// A 구역의 피자 가격
	float priceB;// B 구역의 피자 가격
	float feeA;// A 구역 배달 수수료
	float feeB;// B 구역 배달 수수료
	float timeA;// A 구역 배달 소요 시간
	float timeB;// B 구역 배달 소요 시간
	Vector_Customer A;// A 구역 고객들.Vector_float class 사용.
	Vector_Customer B;// B 구역 고객들.Vector_float class 사용.
	Vector_Rider R;// 배달 기사.Vector_Rider class 사용.

public:
	Pizza();//기본 생성자
	Pizza(float money);//멤버 변수 money 를 입력으로 받아 설정하며, 나머지는 기본 생성자와 동일하다.
	Pizza(const Pizza& pizza);//복사 생성자. 모든 멤버 변수를 입력의 멤버 변수로 대체한다.
	~Pizza();//소멸자.

	void setPrice();//A, B 구역의 피자 가격과 배달 수수료를 책정하는 함수.
	void setPrice(float a, float b);//a, b 가 주어졌을 때 A, B 구역의 피자 가격과 배달 수수료를 책정하는 함수.
	void hire(const Rider& rider);//배달 기사 채용 기능을 구현하는 함수.
	void hire(const Rider* riders, int size);//배달 기사 여러 명을 한 번에 채용하는 기능을 구현하는 함수.
	void enroll(const Customer& customer, bool a);//특정 지역의 고객을 추가하는 함수.
	void enroll(const Customer* customers, int size, bool a);//특정 지역의 다수 고객들을 추가하는 기능을 구현하는 함수.

	float reportMoney() const;//피자 가게가 현재 가지고 있는 돈을 리턴하는 함수.
	int numRiders() const;//배달 기사의 현재 인원을 리턴한다.
	int numCustomers(bool a) const;//고객수를 리턴하는 함수. Bool a 가 true 일 경우, A 지역 고객 수를 리턴한다. Bool a 가 false 일 경우, B 지역 고객수를 리턴한다.
	float meanFee() const;//현재 고용 중인 라이더가 배달을 통해 번 돈의 평균을 리턴하는 함수.
	float meanTimeRiders() const;//현재 고용 중인 라이더가 배달하는데 걸린 시간의 평균을 리턴하는 함수.
	float meanMoneyCustomers() const;//현재 관리 중인 고객들이 피자를 구매하는데 든 비용의 평균을 리턴하는 함수.
	float meanTimeCustomers() const;//현재 관리 중인 고객들이 배달 받는데 걸린 시간의 평균을 리턴하는 함수.

	void deliver();//각 구역의 고객들에게 일괄적으로 피자를 배달하는 함수.
	friend ostream& operator <<(ostream& os, const Pizza& x)//피자가가게가 보유한 돈, 구역별 고객 수, 피자 가격, 배달 수수료, 배달기사수를 콘솔에 출력하는 함수.
	{
		os << "1) Money : " << x.money << endl << "2) (Customer, Price, Fee)" << endl << " - A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl << " - B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl << "3) Riders: " << x.R.size();
		
		return os;
	}
};
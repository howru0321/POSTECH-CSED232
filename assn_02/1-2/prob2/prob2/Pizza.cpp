#include "Pizza.h"
using namespace std;

Pizza::Pizza()
{
	/*맴버 변수 초기화*/
	money = 10000;
	timeA = 10;
	timeB = 20;

	A.allocate(5);
	B.allocate(5);
	R.allocate(5);

	setPrice();//초기 가격 책정
}

Pizza::Pizza(float money)//기본생성자
{
	/*맴버 변수 초기화*/
	this->money = money;
	timeA = 10;
	timeB = 20;

	A.allocate(5);
	B.allocate(5);
	R.allocate(5);

	setPrice();//초기 가격 책정
}

Pizza::Pizza(const Pizza& pizza)
{
	//맴버 변수를 모두 복사한다.
	money = pizza.money;
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeB;
	timeA = pizza.timeA;
	timeB = pizza.timeB;

	A = pizza.A;
	B = pizza.B;
	R = pizza.R;
}

Pizza::~Pizza()//소멸자
{
}

void Pizza::setPrice()
{
	priceA = (100 - 3 * float(A.len));
	priceB = (100 - 6 * float(B.len));
	feeA = (10 - float(A.len));
	feeB = (10 - float(B.len));
}

void Pizza::setPrice(float a, float b)//가격책정
{
	priceA = (100 - a * float(A.len));//데이터 손실을 막기위해 형변환한다
	priceB = (100 - b * float(B.len));
	feeA = (10 - float(A.len));
	feeB = (10 - float(B.len));
}

void Pizza::hire(const Rider& rider)//가장 먼저 고용한 배달원은 해고하고 한명 고용한다.
{
	R.erase(R.begin());
	R.push_back(rider);
}

void Pizza::hire(const Rider* riders, int size)//다수의 배달원을 고용할때 사용하는 함수
{
	for (int i = 0; i < size; i++)
	{
		R.erase(R.begin());
	}
	R.insert(R.begin(), riders, riders + size);
}

void Pizza::enroll(const Customer& customer, bool a)//A B고객을 관리하는 함수. 0명이하 10명 이상이 되면 안되고, 고객수 합은 항상 10명이다
{
	
	if (a == true)
	{
		if (B.len == 1)//0명 이하가 되는 경우는 함수를 종료시킨다.
		{
			return;
		}
		A.push_back(customer);//뒤에 한명 넣는다
		B.erase(B.begin());//앞에 한명 뺀다
	}
	else
	{
		if (A.len == 1)//0명 이하가 되는 경우는 함수를 종료시킨다.
		{
			return;
		}
		B.push_back(customer);//뒤에 한명 넣는다
		A.erase(A.begin());//앞에 한명 뺀다
	}
	setPrice();
}

void Pizza::enroll(const Customer* customers, int size, bool a)//다수의 고객을 관리할때 쓰는 함수
{
	if (a == true)
	{
		if (B.len == size)
		{
			return;
		}
		A.insert(A.end(), customers, customers + size);
		for (int i = 0; i < size; i++)
		{
			B.erase(B.begin());
		}
	}
	else
	{
		if (A.len == size)
		{
			return;
		}
		B.insert(B.end(), customers, customers + size);
		for (int i = 0; i < size; i++)
		{
			A.erase(A.begin());
		}
	}
	setPrice();
}

float Pizza::reportMoney() const//가게 돈을 리턴
{
	return money;
}

int Pizza::numRiders() const//라이더 수를 리턴
{
	return R.len;
}

int Pizza::numCustomers(bool a) const
{
	if (a == true)
	{
		return A.len;
	}
	else
	{
		return B.len;
	}
}

float Pizza::meanFee() const
{
	float totem = 0;//배달원이 배달을 통해 벌어들인 돈의 총합
	
	for (int i = 0; i < R.len; i++)//총합 계산
	{
		totem += R[i].earnMoney;
	}

	return (totem / R.len);//평균 리턴
}

float Pizza::meanTimeRiders() const
{
	float totime = 0;//배달 시간의의 총합

	for (int i = 0; i < R.len; i++)//총합 계산
	{
		totime += R[i].time;
	}

	return (totime / R.len);//평균 리턴
}

float Pizza::meanMoneyCustomers() const
{
	float totpm = 0;//낸돈의 총합

	for (int i = 0; i < A.len; i++)//총합 계산
	{
		totpm += A[i].paidMoney;
	}
	for (int i = 0; i < B.len; i++)//총합 계산
	{
		totpm += B[i].paidMoney;
	}

	return (totpm / 10);//평균 리턴
}

float Pizza::meanTimeCustomers() const
{
	float totime = 0;//배달받는데 걸린 시간의의 총합

	for (int i = 0; i < A.len; i++)//총합 계산
	{
		totime += A[i].time;
	}
	for (int i = 0; i < B.len; i++)//총합 계산
	{
		totime += B[i].time;
	}

	return (totime / 10);//평균 리턴
}

void Pizza::deliver()//배달 알고리즘
{
	int rid = 0;//rider배열 위치

	for (int i = 0; i < A.len; i++)//A구역 배달 알고리즘
	{
		money += priceA;//가게가 번 돈

		A[i].pay(priceA, timeA);//배달 후 손님의 돈, 시간등을 바꾸는 함수

		R[rid].deliver(feeA, timeA);//배달 후 배달원의 돈, 시간등을 바꾸는 함수
		
		money -= feeA;//가게가 지불한 수수료

		rid++;
		rid %= 5;//5명이 한 바퀴씩 돌면 다시 첫 배달원으로 돌아가야한다
	}

	for (int i = 0; i < B.len; i++)//A구역 배달 알고리즘
	{
		money += priceB;//가게가 번 돈

		B[i].pay(priceB, timeB);//배달 후 손님의 돈, 시간등을 바꾸는 함수

		R[rid].deliver(feeB, timeB);//배달 후 배달원의 돈, 시간등을 바꾸는 함수

		money -= feeB;//가게가 지불한 수수료

		rid++;
		rid %= 5;//5명이 한 바퀴씩 돌면 다시 첫 배달원으로 돌아가야한다
	}
}
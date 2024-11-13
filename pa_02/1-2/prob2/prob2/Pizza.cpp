#include "Pizza.h"
using namespace std;

Pizza::Pizza()
{
	/*�ɹ� ���� �ʱ�ȭ*/
	money = 10000;
	timeA = 10;
	timeB = 20;

	A.allocate(5);
	B.allocate(5);
	R.allocate(5);

	setPrice();//�ʱ� ���� å��
}

Pizza::Pizza(float money)//�⺻������
{
	/*�ɹ� ���� �ʱ�ȭ*/
	this->money = money;
	timeA = 10;
	timeB = 20;

	A.allocate(5);
	B.allocate(5);
	R.allocate(5);

	setPrice();//�ʱ� ���� å��
}

Pizza::Pizza(const Pizza& pizza)
{
	//�ɹ� ������ ��� �����Ѵ�.
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

Pizza::~Pizza()//�Ҹ���
{
}

void Pizza::setPrice()
{
	priceA = (100 - 3 * float(A.len));
	priceB = (100 - 6 * float(B.len));
	feeA = (10 - float(A.len));
	feeB = (10 - float(B.len));
}

void Pizza::setPrice(float a, float b)//����å��
{
	priceA = (100 - a * float(A.len));//������ �ս��� �������� ����ȯ�Ѵ�
	priceB = (100 - b * float(B.len));
	feeA = (10 - float(A.len));
	feeB = (10 - float(B.len));
}

void Pizza::hire(const Rider& rider)//���� ���� ����� ��޿��� �ذ��ϰ� �Ѹ� ����Ѵ�.
{
	R.erase(R.begin());
	R.push_back(rider);
}

void Pizza::hire(const Rider* riders, int size)//�ټ��� ��޿��� ����Ҷ� ����ϴ� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		R.erase(R.begin());
	}
	R.insert(R.begin(), riders, riders + size);
}

void Pizza::enroll(const Customer& customer, bool a)//A B���� �����ϴ� �Լ�. 0������ 10�� �̻��� �Ǹ� �ȵǰ�, ���� ���� �׻� 10���̴�
{
	
	if (a == true)
	{
		if (B.len == 1)//0�� ���ϰ� �Ǵ� ���� �Լ��� �����Ų��.
		{
			return;
		}
		A.push_back(customer);//�ڿ� �Ѹ� �ִ´�
		B.erase(B.begin());//�տ� �Ѹ� ����
	}
	else
	{
		if (A.len == 1)//0�� ���ϰ� �Ǵ� ���� �Լ��� �����Ų��.
		{
			return;
		}
		B.push_back(customer);//�ڿ� �Ѹ� �ִ´�
		A.erase(A.begin());//�տ� �Ѹ� ����
	}
	setPrice();
}

void Pizza::enroll(const Customer* customers, int size, bool a)//�ټ��� ���� �����Ҷ� ���� �Լ�
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

float Pizza::reportMoney() const//���� ���� ����
{
	return money;
}

int Pizza::numRiders() const//���̴� ���� ����
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
	float totem = 0;//��޿��� ����� ���� ������� ���� ����
	
	for (int i = 0; i < R.len; i++)//���� ���
	{
		totem += R[i].earnMoney;
	}

	return (totem / R.len);//��� ����
}

float Pizza::meanTimeRiders() const
{
	float totime = 0;//��� �ð����� ����

	for (int i = 0; i < R.len; i++)//���� ���
	{
		totime += R[i].time;
	}

	return (totime / R.len);//��� ����
}

float Pizza::meanMoneyCustomers() const
{
	float totpm = 0;//������ ����

	for (int i = 0; i < A.len; i++)//���� ���
	{
		totpm += A[i].paidMoney;
	}
	for (int i = 0; i < B.len; i++)//���� ���
	{
		totpm += B[i].paidMoney;
	}

	return (totpm / 10);//��� ����
}

float Pizza::meanTimeCustomers() const
{
	float totime = 0;//��޹޴µ� �ɸ� �ð����� ����

	for (int i = 0; i < A.len; i++)//���� ���
	{
		totime += A[i].time;
	}
	for (int i = 0; i < B.len; i++)//���� ���
	{
		totime += B[i].time;
	}

	return (totime / 10);//��� ����
}

void Pizza::deliver()//��� �˰���
{
	int rid = 0;//rider�迭 ��ġ

	for (int i = 0; i < A.len; i++)//A���� ��� �˰���
	{
		money += priceA;//���԰� �� ��

		A[i].pay(priceA, timeA);//��� �� �մ��� ��, �ð����� �ٲٴ� �Լ�

		R[rid].deliver(feeA, timeA);//��� �� ��޿��� ��, �ð����� �ٲٴ� �Լ�
		
		money -= feeA;//���԰� ������ ������

		rid++;
		rid %= 5;//5���� �� ������ ���� �ٽ� ù ��޿����� ���ư����Ѵ�
	}

	for (int i = 0; i < B.len; i++)//A���� ��� �˰���
	{
		money += priceB;//���԰� �� ��

		B[i].pay(priceB, timeB);//��� �� �մ��� ��, �ð����� �ٲٴ� �Լ�

		R[rid].deliver(feeB, timeB);//��� �� ��޿��� ��, �ð����� �ٲٴ� �Լ�

		money -= feeB;//���԰� ������ ������

		rid++;
		rid %= 5;//5���� �� ������ ���� �ٽ� ù ��޿����� ���ư����Ѵ�
	}
}
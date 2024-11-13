#pragma once
#include "Vector_Customer.h"
#include "Vector_Rider.h"
using namespace std;

class Pizza
{
private:
	float money;//������ ��
	float priceA;// A ������ ���� ����
	float priceB;// B ������ ���� ����
	float feeA;// A ���� ��� ������
	float feeB;// B ���� ��� ������
	float timeA;// A ���� ��� �ҿ� �ð�
	float timeB;// B ���� ��� �ҿ� �ð�
	Vector_Customer A;// A ���� ����.Vector_float class ���.
	Vector_Customer B;// B ���� ����.Vector_float class ���.
	Vector_Rider R;// ��� ���.Vector_Rider class ���.

public:
	Pizza();//�⺻ ������
	Pizza(float money);//��� ���� money �� �Է����� �޾� �����ϸ�, �������� �⺻ �����ڿ� �����ϴ�.
	Pizza(const Pizza& pizza);//���� ������. ��� ��� ������ �Է��� ��� ������ ��ü�Ѵ�.
	~Pizza();//�Ҹ���.

	void setPrice();//A, B ������ ���� ���ݰ� ��� �����Ḧ å���ϴ� �Լ�.
	void setPrice(float a, float b);//a, b �� �־����� �� A, B ������ ���� ���ݰ� ��� �����Ḧ å���ϴ� �Լ�.
	void hire(const Rider& rider);//��� ��� ä�� ����� �����ϴ� �Լ�.
	void hire(const Rider* riders, int size);//��� ��� ���� ���� �� ���� ä���ϴ� ����� �����ϴ� �Լ�.
	void enroll(const Customer& customer, bool a);//Ư�� ������ ���� �߰��ϴ� �Լ�.
	void enroll(const Customer* customers, int size, bool a);//Ư�� ������ �ټ� ������ �߰��ϴ� ����� �����ϴ� �Լ�.

	float reportMoney() const;//���� ���԰� ���� ������ �ִ� ���� �����ϴ� �Լ�.
	int numRiders() const;//��� ����� ���� �ο��� �����Ѵ�.
	int numCustomers(bool a) const;//������ �����ϴ� �Լ�. Bool a �� true �� ���, A ���� �� ���� �����Ѵ�. Bool a �� false �� ���, B ���� ������ �����Ѵ�.
	float meanFee() const;//���� ��� ���� ���̴��� ����� ���� �� ���� ����� �����ϴ� �Լ�.
	float meanTimeRiders() const;//���� ��� ���� ���̴��� ����ϴµ� �ɸ� �ð��� ����� �����ϴ� �Լ�.
	float meanMoneyCustomers() const;//���� ���� ���� ������ ���ڸ� �����ϴµ� �� ����� ����� �����ϴ� �Լ�.
	float meanTimeCustomers() const;//���� ���� ���� ������ ��� �޴µ� �ɸ� �ð��� ����� �����ϴ� �Լ�.

	void deliver();//�� ������ ���鿡�� �ϰ������� ���ڸ� ����ϴ� �Լ�.
	friend ostream& operator <<(ostream& os, const Pizza& x)//���ڰ����԰� ������ ��, ������ �� ��, ���� ����, ��� ������, ��ޱ����� �ֿܼ� ����ϴ� �Լ�.
	{
		os << "1) Money : " << x.money << endl << "2) (Customer, Price, Fee)" << endl << " - A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl << " - B : (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl << "3) Riders: " << x.R.size();
		
		return os;
	}
};
#include "Vector_Customer.h"
using namespace std;

Vector_Customer::Vector_Customer()
{
    msize = 0;
    len = 0;
}

Vector_Customer::Vector_Customer(int size)//size��ŭ �迭�� 0���� �ʱ�ȭ
{
    msize = size;//�ִ� �޸� �Ҵ緮
    len = size;//������ ����
    arr = new Customer[msize] {};//0���� �ʱ�ȭ
}

Vector_Customer::Vector_Customer(int size, const Customer& init)//0�� �ƴ� ���ڷ� �ʱ�ȭ
{
    msize = size;
    len = size;
    arr = new Customer[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init;
    }
}

Vector_Customer::Vector_Customer(int size, const Customer* init)//���ϴ� �迭 copy
{
    msize = size;
    len = size;
    arr = new Customer[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init[i];
    }
}

Vector_Customer::Vector_Customer(const Vector_Customer& v)//������ ����� ���� class�� �迭�� ����
{
    msize = v.msize;
    len = v.len;
    arr = new Customer[msize] {};
    for (int i = 0; i < msize; i++)
    {
        arr[i] = v.arr[i];
    }
}

Vector_Customer::~Vector_Customer()//�Ҹ���
{
    delete[] arr;
}


int Vector_Customer::capacity() const//�޸� ������ ����
{
    return msize;
}

int Vector_Customer::size() const//������ ���� ����
{
    return len;
}


Vector_Customer::iterator Vector_Customer::begin()//������ ù �ּ� ����
{
    return arr;
}

Vector_Customer::const_iterator Vector_Customer::begin() const//const ����
{
    return arr;
}

Vector_Customer::iterator Vector_Customer::end()//������ ������ �ּ� ����
{
    return &arr[len];
}

Vector_Customer::const_iterator Vector_Customer::end() const
{
    return &arr[len];
}

Customer& Vector_Customer::front()//������ ù �� ����
{
    return arr[0];
}

const Customer& Vector_Customer::front() const
{
    return arr[0];
}

Customer& Vector_Customer::back()//������ ������ �� ����
{
    return arr[len];
}

const Customer& Vector_Customer::back() const
{
    return arr[len];
}


void Vector_Customer::allocate(int capacity)//�迭 ũ�� �Ҵ�
{
    arr = new Customer[capacity] {};
    msize = capacity;
    len = capacity;//���⼭�� �ǹ��ִ� �����Ͱ� ���ٰ� ���°� �´�
}

void Vector_Customer::resize(int size)//�迭 ũ�� ���Ҵ�
{
    Customer* t_arr = new Customer[size] {};//0���� �ʱ�ȭ

    if (size < len)
    {
        len = size;
    }

    msize = size;//�޸� ������ ����

    if (len != 0)//�����Ͱ� ���� ��쿡�� ������ �����Ͱ� ���� ��찡 ������ �����Ƿ� ��츦 ������
    {
        for (int i = 0; i < len; i++)//�ӽú���
        {
            t_arr[i] = arr[i];
        }
    }
    delete[] arr;
    arr = new Customer[size] {};//�ٽ� size��ŭ ���Ҵ�

    for (int i = 0; i < len; i++)//�����ص� �迭 �ٽ� arr�� ����
    {
        arr[i] = t_arr[i];
    }
    delete[] t_arr;
    len = size;//������ ������ size��ŭ ������

}

void Vector_Customer::push_back(const Customer& value)//�� �ڿ� ������ �߰�
{
    if (len + 1 < 5)
    {
        if (len + 1 > msize)
        {
            int temp = len;
            resize(len + 1);
            len = temp;
            len++;//���� ���������� �ֱ� �ٷ� ������ len�� ���� 1 �߰��� ��� resize�� ���� �۵��Ѵ�
            arr[len - 1] = value;//������
        }
        else
        {
            len++;
            arr[len - 1] = value;//������
        }
    }
    else
    {
        if (len + 1 >= msize)
        {
            int temp = len;
            resize((len + 1) * 2);
            len = temp;
            len++;
            arr[len - 1] = value;//������
        }
        else
        {
            len++;
            arr[len - 1] = value;//������
        }
    }
}

void Vector_Customer::pop_back()//�� �ڿ� ������ ����
{
    //arr[len - 1] = 0;//������ �̿��� ���� �� 0���� �ʱ�ȭ �Ѵ�
    len -= 1;//������ ���� 1 ����
}

inline void spcr(Customer* apos, Customer* aend, int space)//�߰��� ���� ���� â��
{
    for (Customer* temp = aend; temp != (apos - 1); temp--)
    {
        *(temp + space) = *temp;
    }
    //*apos = 0;//�� ���� 0���� �ʱ�ȭ
}

void Vector_Customer::insert(iterator position, const Customer& value)
{
    int apos = 0;//position�� ��ġ�� ��Ÿ���� ���
    for (iterator temp = begin(); temp != position; temp++)
    {
        apos++;
    }

    if (len + 1 < 5)
    {
        if (len + 1 > msize)
        {
            msize = len + 1;
            int temp1 = len;
            resize(msize);
            len = temp1;
            Customer* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, 1);
            len++;
            *(begin() + apos) = value;//������
        }
        else
        {
            len++;
            *(begin() + apos) = value;//������
        }
    }
    else
    {
        if (len + 1 >= msize)
        {
            msize = (len + 1) * 2;
            int temp1 = len;
            resize(msize);
            len = temp1;
            Customer* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, 1);
            len++;
            *(begin() + apos) = value;//������
        }
        else
        {
            len++;
            *(begin() + apos) = value;//������
        }
    }
}

void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last)
{
    int cnt = 0;//�������� �迭�� ������ ����
    int i = 0;
    for (const Customer* temp = first; (temp + i) != last; i++)
    {
        cnt++;
    }

    int apos = 0;//position�� ��ġ�� ��Ÿ���� ���
    for (iterator temp = begin(); temp != position; temp++)
    {
        apos++;
    }
    Customer* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
    if (len + cnt < 5)
    {
        if (len + cnt > msize)
        {
            int temp1 = len;
            resize(len + cnt);
            len = temp1;
            Customer* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            Customer* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Customer* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
    }
    else
    {
        if (len + cnt >= msize)
        {
            int temp1 = len;
            resize((len + cnt) * 2);
            len = temp1;
            Customer* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            Customer* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Customer* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
    }
}

void Vector_Customer::erase(iterator position)
{
    for (iterator temp = position; temp != end(); temp++)
    {
        *(temp) = *(temp + 1);
    }
    //*(end() - 1) = 0;//������ �� �κ� 0���� �ʱ�ȭ
    len--;//������ ���� 1����
}

void Vector_Customer::clear()
{
    /*for (iterator temp = begin(); temp != (end() + 1); temp++)
    {
        *(temp) = '\0';//��� �����͸� NULL�� �ʱ�ȭ
    }*/
    msize = 0;
    len = 0;
}

Customer& Vector_Customer::operator[](int index)//[]������ �����ε�
{
    return arr[index];
}

const Customer& Vector_Customer::operator[](int index) const
{
    return arr[index];
}

Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v)//=������ �����ε�
{
    msize = v.msize;
    len = v.len;
    arr = new Customer[msize] {};
    for (int i = 0; i < len; i++)
    {
        arr[i] = v.arr[i];
    }
    return *this;
}
#include <cstdio>
#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;

Vector::Vector()
{
    msize = 0;
    len = 0;
}

Vector::Vector(int size)//size��ŭ �迭�� 0���� �ʱ�ȭ
{
    msize = size;//�ִ� �޸� �Ҵ緮
    len = size;//������ ����
    arr = new float[msize] {};//0���� �ʱ�ȭ
}

Vector::Vector(int size, const float& init)//0�� �ƴ� ���ڷ� �ʱ�ȭ
{
    msize = size;
    len = size;
    arr = new float[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init;
    }
}

Vector::Vector(int size, const float* init)//���ϴ� �迭 copy
{
    msize = size;
    len = size;
    arr = new float[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init[i];
    }
}

Vector::Vector(const Vector& v)//������ ����� ���� class�� �迭�� ����
{
    msize = v.msize;
    len = v.len;
    arr = new float[msize] {};
    for (int i = 0; i < msize; i++)
    {
        arr[i] = v.arr[i];
    }
}

Vector::~Vector()//�Ҹ���
{
    delete[] arr;
}


int Vector::capacity() const//�޸� ������ ����
{
    return msize;
}

int Vector::size() const//������ ���� ����
{
    return len;
}


Vector::iterator Vector::begin()//������ ù �ּ� ����
{
    return arr;
}

Vector::const_iterator Vector::begin() const//const ����
{
    return arr;
}

Vector::iterator Vector::end()//������ ������ �ּ� ����
{
    return &arr[len];
}

Vector::const_iterator Vector::end() const
{
    return &arr[len];
}

float& Vector::front()//������ ù �� ����
{
    return arr[0];
}

const float& Vector::front() const
{
    return arr[0];
}

float& Vector::back()//������ ������ �� ����
{
    return arr[len];
}

const float& Vector::back() const
{
    return arr[len];
}


void Vector::allocate(int capacity)//�迭 ũ�� �Ҵ�
{
    arr = new float[capacity] {};
    msize = capacity;
    len = 0;
}

void Vector::resize(int size)//�迭 ũ�� ���Ҵ�
{
    float* t_arr = new float[size] {};//0���� �ʱ�ȭ

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
    arr = new float[size] {};//�ٽ� size��ŭ ���Ҵ�

    for (int i = 0; i < len; i++)//�����ص� �迭 �ٽ� arr�� ����
    {
        arr[i] = t_arr[i];
    }
    delete[] t_arr;
    len = size;//������ ������ size��ŭ ������

}

void Vector::push_back(const float& value)//�� �ڿ� ������ �߰�
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

void Vector::pop_back()//�� �ڿ� ������ ����
{
    arr[len - 1] = 0;//������ �̿��� ���� �� 0���� �ʱ�ȭ �Ѵ�
    len -= 1;//������ ���� 1 ����
}

inline void spcr(float* apos, float* aend, int space)//�߰��� ���� ���� â��
{
    for (float* temp = aend; temp != (apos - 1); temp--)
    {
        *(temp + space) = *temp;
    }
    *apos = 0;//�� ���� 0���� �ʱ�ȭ
}

void Vector::insert(iterator position, const float& value)
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
            float* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
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
            float* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
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

void Vector::insert(iterator position, const float* first, const float* last)
{
    int cnt = 0;//�������� �迭�� ������ ����
    int i = 0;
    for (const float* temp = first; (temp + i) != last; i++)
    {
        cnt++;
    }

    int apos = 0;//position�� ��ġ�� ��Ÿ���� ���
    for (iterator temp = begin(); temp != position; temp++)
    {
        apos++;
    }
    float* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
    if (len + cnt < 5)
    {
        if (len + cnt > msize)
        {
            int temp1 = len;
            resize(len + cnt);
            len = temp1;
            float* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            float* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            float* tempp = begin() + apos;//position �ּ�
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
            float* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            float* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            float* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
    }
}

void Vector::erase(iterator position)
{
    for (iterator temp = position; temp != end(); temp++)
    {
        *(temp) = *(temp + 1);
    }
    *(end() - 1) = 0;//������ �� �κ� 0���� �ʱ�ȭ
    len--;//������ ���� 1����
}

void Vector::clear()
{
    for (iterator temp = begin(); temp != (end() + 1); temp++)
    {
        *(temp) = '\0';//��� �����͸� NULL�� �ʱ�ȭ
    }
    msize = 0;
    len = 0;
}

float& Vector::operator[](int index)//[]������ �����ε�
{
    return arr[index];
}

const float& Vector::operator[](int index) const
{
    return arr[index];
}

Vector& Vector::operator=(const Vector& v)//=������ �����ε�
{
    msize = v.msize;
    len = v.len;
    arr = new float[msize] {};
    for (int i = 0; i < len; i++)
    {
        arr[i] = v.arr[i];
    }
    return *this;
}
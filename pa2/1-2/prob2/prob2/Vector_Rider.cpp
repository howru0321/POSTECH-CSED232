#include "Vector_Rider.h"
using namespace std;

Vector_Rider::Vector_Rider()
{
    msize = 0;
    len = 0;
}

Vector_Rider::Vector_Rider(int size)//size��ŭ �迭�� 0���� �ʱ�ȭ
{
    msize = size;//�ִ� �޸� �Ҵ緮
    len = size;//������ ����
    arr = new Rider[msize] {};//0���� �ʱ�ȭ
}

Vector_Rider::Vector_Rider(int size, const Rider& init)//0�� �ƴ� ���ڷ� �ʱ�ȭ
{
    msize = size;
    len = size;
    arr = new Rider[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init;
    }
}

Vector_Rider::Vector_Rider(int size, const Rider* init)//���ϴ� �迭 copy
{
    msize = size;
    len = size;
    arr = new Rider[msize] {};//0���� �ʱ�ȭ
    for (int i = 0; i < len; i++)
    {
        arr[i] = init[i];
    }
}

Vector_Rider::Vector_Rider(const Vector_Rider& v)//������ ����� ���� class�� �迭�� ����
{
    msize = v.msize;
    len = v.len;
    arr = new Rider[msize] {};
    for (int i = 0; i < msize; i++)
    {
        arr[i] = v.arr[i];
    }
}

Vector_Rider::~Vector_Rider()//�Ҹ���
{
    delete[] arr;
}


int Vector_Rider::capacity() const//�޸� ������ ����
{
    return msize;
}

int Vector_Rider::size() const//������ ���� ����
{
    return len;
}


Vector_Rider::iterator Vector_Rider::begin()//������ ù �ּ� ����
{
    return arr;
}

Vector_Rider::const_iterator Vector_Rider::begin() const//const ����
{
    return arr;
}

Vector_Rider::iterator Vector_Rider::end()//������ ������ �ּ� ����
{
    return &arr[len];
}

Vector_Rider::const_iterator Vector_Rider::end() const
{
    return &arr[len];
}

Rider& Vector_Rider::front()//������ ù �� ����
{
    return arr[0];
}

const Rider& Vector_Rider::front() const
{
    return arr[0];
}

Rider& Vector_Rider::back()//������ ������ �� ����
{
    return arr[len];
}

const Rider& Vector_Rider::back() const
{
    return arr[len];
}


void Vector_Rider::allocate(int capacity)//�迭 ũ�� �Ҵ�
{
    arr = new Rider[capacity] {};
    msize = capacity;
    len = capacity;//���⼭�� �ǹ��ִ� �����Ͱ� ���ٰ� ���°� �´�
}

void Vector_Rider::resize(int size)//�迭 ũ�� ���Ҵ�
{
    Rider* t_arr = new Rider[size] {};//0���� �ʱ�ȭ

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
    arr = new Rider[size] {};//�ٽ� size��ŭ ���Ҵ�

    for (int i = 0; i < len; i++)//�����ص� �迭 �ٽ� arr�� ����
    {
        arr[i] = t_arr[i];
    }
    delete[] t_arr;
    len = size;//������ ������ size��ŭ ������

}

void Vector_Rider::push_back(const Rider& value)//�� �ڿ� ������ �߰�
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

void Vector_Rider::pop_back()//�� �ڿ� ������ ����
{
    //arr[len - 1] = 0;//������ �̿��� ���� �� 0���� �ʱ�ȭ �Ѵ�
    len -= 1;//������ ���� 1 ����
}

inline void spcr(Rider* apos, Rider* aend, int space)//�߰��� ���� ���� â��
{
    for (Rider* temp = aend; temp != (apos - 1); temp--)
    {
        *(temp + space) = *temp;
    }
    //*apos = 0;//�� ���� 0���� �ʱ�ȭ
}

void Vector_Rider::insert(iterator position, const Rider& value)
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
            Rider* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
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
            Rider* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
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

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last)
{
    int cnt = 0;//�������� �迭�� ������ ����
    int i = 0;
    for (const Rider* temp = first; (temp + i) != last; i++)
    {
        cnt++;
    }

    int apos = 0;//position�� ��ġ�� ��Ÿ���� ���
    for (iterator temp = begin(); temp != position; temp++)
    {
        apos++;
    }
    Rider* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
    if (len + cnt < 5)
    {
        if (len + cnt > msize)
        {
            int temp1 = len;
            resize(len + cnt);
            len = temp1;
            Rider* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            Rider* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Rider* tempp = begin() + apos;//position �ּ�
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
            Rider* temp = &arr[len - 1];//������ ������ �κ��� �ּ�
            spcr(begin() + apos, temp, cnt);
            Rider* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Rider* tempp = begin() + apos;//position �ּ�
            len += cnt;
            for (int i = 0; i < cnt; i++)//�� ����
            {
                *(tempp + i) = *(first + i);
            }
        }
    }
}

void Vector_Rider::erase(iterator position)
{
    for (iterator temp = position; temp != end(); temp++)
    {
        *(temp) = *(temp + 1);
    }
    //*(end() - 1) = 0;//������ �� �κ� 0���� �ʱ�ȭ
    len--;//������ ���� 1����
}

void Vector_Rider::clear()
{
    /*for (iterator temp = begin(); temp != (end() + 1); temp++)
    {
        *(temp) = '\0';//��� �����͸� NULL�� �ʱ�ȭ
    }*/
    msize = 0;
    len = 0;
}

Rider& Vector_Rider::operator[](int index)//[]������ �����ε�
{
    return arr[index];
}

const Rider& Vector_Rider::operator[](int index) const
{
    return arr[index];
}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v)//=������ �����ε�
{
    msize = v.msize;
    len = v.len;
    arr = new Rider[msize] {};
    for (int i = 0; i < len; i++)
    {
        arr[i] = v.arr[i];
    }
    return *this;
}
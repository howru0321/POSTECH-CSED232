#include "Vector_Customer.h"
using namespace std;

Vector_Customer::Vector_Customer()
{
    msize = 0;
    len = 0;
}

Vector_Customer::Vector_Customer(int size)//size만큼 배열을 0으로 초기화
{
    msize = size;//최대 메모리 할당량
    len = size;//데이터 개수
    arr = new Customer[msize] {};//0으로 초기화
}

Vector_Customer::Vector_Customer(int size, const Customer& init)//0이 아닌 숫자로 초기화
{
    msize = size;
    len = size;
    arr = new Customer[msize] {};//0으로 초기화
    for (int i = 0; i < len; i++)
    {
        arr[i] = init;
    }
}

Vector_Customer::Vector_Customer(int size, const Customer* init)//원하는 배열 copy
{
    msize = size;
    len = size;
    arr = new Customer[msize] {};//0으로 초기화
    for (int i = 0; i < len; i++)
    {
        arr[i] = init[i];
    }
}

Vector_Customer::Vector_Customer(const Vector_Customer& v)//이전에 만들어 놓은 class의 배열을 복사
{
    msize = v.msize;
    len = v.len;
    arr = new Customer[msize] {};
    for (int i = 0; i < msize; i++)
    {
        arr[i] = v.arr[i];
    }
}

Vector_Customer::~Vector_Customer()//소멸자
{
    delete[] arr;
}


int Vector_Customer::capacity() const//메모리 사이즈 리턴
{
    return msize;
}

int Vector_Customer::size() const//데이터 개수 리턴
{
    return len;
}


Vector_Customer::iterator Vector_Customer::begin()//데이터 첫 주소 리턴
{
    return arr;
}

Vector_Customer::const_iterator Vector_Customer::begin() const//const 버전
{
    return arr;
}

Vector_Customer::iterator Vector_Customer::end()//데이터 마지막 주소 리턴
{
    return &arr[len];
}

Vector_Customer::const_iterator Vector_Customer::end() const
{
    return &arr[len];
}

Customer& Vector_Customer::front()//데이터 첫 값 리턴
{
    return arr[0];
}

const Customer& Vector_Customer::front() const
{
    return arr[0];
}

Customer& Vector_Customer::back()//데이터 마지막 값 리턴
{
    return arr[len];
}

const Customer& Vector_Customer::back() const
{
    return arr[len];
}


void Vector_Customer::allocate(int capacity)//배열 크기 할당
{
    arr = new Customer[capacity] {};
    msize = capacity;
    len = capacity;//여기서는 의미있는 데이터가 들어갔다고 보는게 맞다
}

void Vector_Customer::resize(int size)//배열 크기 재할당
{
    Customer* t_arr = new Customer[size] {};//0으로 초기화

    if (size < len)
    {
        len = size;
    }

    msize = size;//메모리 사이즈 변경

    if (len != 0)//데이터가 없는 경우에는 복사할 데이터가 없는 경우가 있을수 있으므로 경우를 나눈다
    {
        for (int i = 0; i < len; i++)//임시복사
        {
            t_arr[i] = arr[i];
        }
    }
    delete[] arr;
    arr = new Customer[size] {};//다시 size만큼 재할당

    for (int i = 0; i < len; i++)//복사해둔 배열 다시 arr에 복사
    {
        arr[i] = t_arr[i];
    }
    delete[] t_arr;
    len = size;//데이터 개수는 size만큼 가진다

}

void Vector_Customer::push_back(const Customer& value)//맨 뒤에 데이터 추가
{
    if (len + 1 < 5)
    {
        if (len + 1 > msize)
        {
            int temp = len;
            resize(len + 1);
            len = temp;
            len++;//값을 최종적으로 넣기 바로 직전에 len의 값을 1 추가해 줘야 resize가 재대로 작동한다
            arr[len - 1] = value;//값대입
        }
        else
        {
            len++;
            arr[len - 1] = value;//값대입
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
            arr[len - 1] = value;//값대입
        }
        else
        {
            len++;
            arr[len - 1] = value;//값대입
        }
    }
}

void Vector_Customer::pop_back()//맨 뒤에 데이터 삭제
{
    //arr[len - 1] = 0;//데이터 이외의 값은 다 0으로 초기화 한다
    len -= 1;//데이터 개수 1 감소
}

inline void spcr(Customer* apos, Customer* aend, int space)//중간에 넣을 공간 창출
{
    for (Customer* temp = aend; temp != (apos - 1); temp--)
    {
        *(temp + space) = *temp;
    }
    //*apos = 0;//빈 공간 0으로 초기화
}

void Vector_Customer::insert(iterator position, const Customer& value)
{
    int apos = 0;//position의 위치를 나타내는 상수
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
            Customer* temp = &arr[len - 1];//데이터 마지막 부분의 주소
            spcr(begin() + apos, temp, 1);
            len++;
            *(begin() + apos) = value;//값대입
        }
        else
        {
            len++;
            *(begin() + apos) = value;//값대입
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
            Customer* temp = &arr[len - 1];//데이터 마지막 부분의 주소
            spcr(begin() + apos, temp, 1);
            len++;
            *(begin() + apos) = value;//값대입
        }
        else
        {
            len++;
            *(begin() + apos) = value;//값대입
        }
    }
}

void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last)
{
    int cnt = 0;//넣으려는 배열의 데이터 개수
    int i = 0;
    for (const Customer* temp = first; (temp + i) != last; i++)
    {
        cnt++;
    }

    int apos = 0;//position의 위치를 나타내는 상수
    for (iterator temp = begin(); temp != position; temp++)
    {
        apos++;
    }
    Customer* temp = &arr[len - 1];//데이터 마지막 부분의 주소
    if (len + cnt < 5)
    {
        if (len + cnt > msize)
        {
            int temp1 = len;
            resize(len + cnt);
            len = temp1;
            Customer* temp = &arr[len - 1];//데이터 마지막 부분의 주소
            spcr(begin() + apos, temp, cnt);
            Customer* tempp = begin() + apos;//position 주소
            len += cnt;
            for (int i = 0; i < cnt; i++)//값 대입
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Customer* tempp = begin() + apos;//position 주소
            len += cnt;
            for (int i = 0; i < cnt; i++)//값 대입
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
            Customer* temp = &arr[len - 1];//데이터 마지막 부분의 주소
            spcr(begin() + apos, temp, cnt);
            Customer* tempp = begin() + apos;//position 주소
            len += cnt;
            for (int i = 0; i < cnt; i++)//값 대입
            {
                *(tempp + i) = *(first + i);
            }
        }
        else
        {
            Customer* tempp = begin() + apos;//position 주소
            len += cnt;
            for (int i = 0; i < cnt; i++)//값 대입
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
    //*(end() - 1) = 0;//마지막 빈 부분 0으로 초기화
    len--;//데이터 개수 1감소
}

void Vector_Customer::clear()
{
    /*for (iterator temp = begin(); temp != (end() + 1); temp++)
    {
        *(temp) = '\0';//모든 데이터를 NULL로 초기화
    }*/
    msize = 0;
    len = 0;
}

Customer& Vector_Customer::operator[](int index)//[]연산자 오버로딩
{
    return arr[index];
}

const Customer& Vector_Customer::operator[](int index) const
{
    return arr[index];
}

Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v)//=연산자 오버로딩
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
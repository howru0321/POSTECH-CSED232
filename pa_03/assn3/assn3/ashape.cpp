#include "ashape.h"

AShape::AShape()
{
	alphabet = 'a';
}

AShape::~AShape()
{

}

APoint::APoint()
{
	x = 0;
	y = 0;
}

APoint::APoint(int x_, int y_, char alphabet_)
{
	x = x_;
	y = y_;
	alphabet = alphabet_;
}

APoint::~APoint()
{

}

void APoint::draw(WhiteBoard* board) const
{
	board->fillPoint(x, y, alphabet);
}

void APoint::print() const
{
	using namespace std;

	cout << "APoint with [alphabet: " << alphabet << "] and [x:" << x << "][y:" << y << "]";
}

int APoint::size() const
{
	return 1;
}

AVerticalLine::AVerticalLine()
{
	x = 0;
	y_start = 0;
	y_end = 0;
}

AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_)
{
	x = x_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}

AVerticalLine::~AVerticalLine()
{

}

void AVerticalLine::draw(WhiteBoard* board) const
{
	for (int i = y_start; i <= y_end; i++)
	{
		board->fillPoint(x, i, alphabet);
	}
}

void AVerticalLine::print() const
{
	using namespace std;

	cout << "AVerticalLine with [alphabet: " << alphabet << "] and [x:" << x << "][y_start:" << y_start << "] [y_end:" << y_end << "]";
}

int AVerticalLine::size() const
{
	return (y_end - y_start + 1);
}

AHorizontalLine::AHorizontalLine()
{
	y = 0;
	x_start = 0;
	x_end = 0;
}

AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_)
{
	y = y_;
	x_start = x_start_;
	x_end = x_end_;
	alphabet = alphabet_;
}

AHorizontalLine::~AHorizontalLine()
{

}

void AHorizontalLine::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++)
	{
		board->fillPoint(i, y, alphabet);
	}
}

void AHorizontalLine::print() const
{
	using namespace std;

	cout << "AHorizontalLine with [alphabet: " << alphabet << "] and [y:" << y << "][x_start:" << x_start << "] [x_end:" << x_end << "]";
}

int AHorizontalLine::size() const
{
	return (x_end - x_start + 1);
}

ARectangle::ARectangle()
{
	x_start = 0;
	x_end = 0;
	y_start = 0;
	y_end = 0;
}

ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_)
{
	x_start = x_start_;
	x_end = x_end_;
	y_start = y_start_;
	y_end = y_end_;
	alphabet = alphabet_;
}

ARectangle::~ARectangle()
{

}

void ARectangle::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++)
	{
		for (int j = y_start; j <= y_end; j++)
		{
			board->fillPoint(i, j, alphabet);//이렇게 fillPoint 함수를 사용하면 friend 없이도 WhiteBoard의 private인 board[][]에 alphabet를 대입할 수 있다.
		}
	}
}

void ARectangle::print() const
{
	using namespace std;

	cout << "ARectangle with [alphabet: " << alphabet << "] and [x_start:" << x_start << "][x_end:" << x_end << "] [y_start:" << y_start << "]" << "] [y_end:" << y_end << "]";
}

int ARectangle::size() const
{
	return (x_end - x_start + 1) * (y_end - y_start + 1);
}
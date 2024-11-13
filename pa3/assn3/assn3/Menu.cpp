#include "Menu.h"

Menu::Menu(WhiteBoard* board, AShapeList* shape_list)//�⺻ ������. is_running �� �⺻������ ������ �Ǿ� �ϹǷ� true�� �ʱ�ȭ �Ͽ���.
{
	is_running = true;
	this->shape_list = shape_list;
	this->board = board;
}

Menu::~Menu()//�Ҹ���
{

}

void Menu::display() const//�Ŵ��� ����ϴ� �Լ�
{
	using namespace std;

	cout << "[===========]" << endl;
	cout << "[Select Menu]" << endl;
	cout << "[===========]" << endl;
	cout << "1. add new shape" << endl;
	cout << "2. delete existing shape" << endl;
	cout << "3. exit" << endl;
	cout << ">>";
}

bool Menu::getRunning() const//���� ���α׷��� ���� �������� ���θ� turn, false�� �����Ѵ�
{
	return is_running;
}

void Menu::getUserInput()//������ �Է��� �޾� �޴��� ���� �ϰ�, ���� addAShape, deleteAShape ���� ȣ���Ѵ�.
{
	using namespace std;

	int temp;
	cin >> temp;

	if (temp == 1) addAShape();
	else if (temp == 2)
	{
		if (shape_list->getSize() == 0)
		{
			cout << "AShapeList is empty." << endl;
		}
		else
		{
			deleteAShape();
		}
	}
	else if (temp == 3) is_running = false;
	else cout << "Error:Invalid input. Type again" << endl;
}

void Menu::addAShape() const
{
	int x_start, x_end, y_start, y_end;
	char alphabet;

	using namespace std;
	cout << "[Add New AShape]" << endl;

	cout << "Enter Alphabet >>";
	cin >> alphabet;

	cout << "x_start >>";
	cin >> x_start;

	cout << "x_end >>";
	cin >> x_end;

	cout << "y_start >>";
	cin >> y_start;

	cout << "y_end >>";
	cin >> y_end;

	AShape* newnode;

	if (x_start > x_end || y_start > y_end)
	{
		cout << "Error:x_start exceed x_end or y_start exceed y_end" << endl;
	}
	else if (x_start < 0 || x_end < 0 || y_start < 0 || y_end < 0)
	{
		cout << "Error:coordinate cannot be nagative value" << endl;
	}
	else if (x_start > 14 || x_end > 14 || y_start > 14 || y_end > 14)
	{
		cout << "Error:you input exceed whiteboard size" << endl;
	}
	else
	{
		if (x_start == x_end && y_start == y_end)
		{
			newnode = new APoint(x_start, y_start, alphabet);
			cout << "New APoint added with size: " << newnode->size() << endl;
		}
		else if (x_start == x_end)
		{
			newnode = new AVerticalLine(x_start, y_start, y_end, alphabet);
			cout << "New AVerticalLine added with size: " << newnode->size() << endl;
		}
		else if (y_start == y_end)
		{
			newnode = new AHorizontalLine(y_start, x_start, x_end, alphabet);
			cout << "New AHorizontalLine added with size: " << newnode->size() << endl;
		}
		else
		{
			newnode = new ARectangle(x_start, x_end, y_start, y_end, alphabet);
			cout << "New ARectangle added with size: " << newnode->size() << endl;
		}
		shape_list->addNewAShape(newnode);
	}
}

void Menu::deleteAShape() const
{
	int pos;
	
	shape_list->displayAShapeList();
	std::cout << ">>";
	std::cin >> pos;

	if (pos >= shape_list->getSize())
	{
		std::cout << "Error: Index exceed size of AShapeList" << std::endl;
	}
	else
	{
		shape_list->popNodeByldx(pos);
	}
}
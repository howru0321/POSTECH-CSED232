#include "AShapeList.h"

AShapeList::AShapeList()//�⺻ ������
{
	head = NULL;
	tail = NULL;
	size = 0;
}

AShapeList::~AShapeList()//�Ҹ���
{
	/*AShapeNode* temp1 = head;
	AShapeNode* temp2;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}*/
	int temp = size;
	for (int i = 0; i < temp; i++)
	{
		popNodeByldx(0);//�տ��� ���� ������ �ϴϱ�, 0�� �����ϸ� �ȴ�
	}
}

void AShapeList::addNewAShape(AShape* new_shape)
{
	struct AShapeNode* newnode = new struct AShapeNode;
	newnode->next = NULL;
	newnode->shape = new_shape;
	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
	size++;
}

void AShapeList::popNodeByldx(int idx)
{
	AShapeNode* temp = head;
	if (head == tail)//head==tail==NULL�� ���� �� �Լ��� ���� ���ϵ��� ���谡 �Ǿ� �����Ƿ�, �� �Լ� ������ head==tail�� ���� node�� �Ѱ��� ����̴�.
	{
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else if (idx == 0)//idx�� 0�̸� head �ּҸ� �Űܾ� �Ѵ�
	{
		head = temp->next;
		delete temp;
	}
	else
	{
		for (int i = 0; i < idx - 1; i++)//������ ����� �� ����� �ּҸ� ã�´�
		{
			temp = temp->next;
		}
		AShapeNode* temp1 = temp->next;
		temp->next = temp1->next;
		if (temp1 == tail)
		{
			tail = temp;
		}
		delete temp1;
	}
	size--;
}

const AShapeNode* AShapeList::getNodeByldx(int idx) const
{
	AShapeNode* temp = head;
	for (int i = 0; i < idx; i++)//ã�� ����� �ּҸ� ã�´�.
	{
		temp = temp->next;
	}
	return temp;
}

void AShapeList::displayAShapeList() const
{
	AShapeNode* temp = head;

	using namespace std;
	cout << "Choose index of AShape that you want to remove" << endl;
	cout << "[========List of AShape========]" << endl;
	cout << "Current Size: " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ") ";
		temp->shape->print();
		cout << endl;
		temp = temp->next;
	}
}

void AShapeList::drawAll(WhiteBoard* board) const
{
	AShapeNode* temp = head;
	for (int i = 0; i < size; i++)
	{
		temp->shape->draw(board);
		temp = temp->next;
	}
}

int AShapeList::getSize() const
{
	return size;
}
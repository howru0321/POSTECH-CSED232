#include "AShapeList.h"

AShapeList::AShapeList()//기본 생성자
{
	head = NULL;
	tail = NULL;
	size = 0;
}

AShapeList::~AShapeList()//소멸자
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
		popNodeByldx(0);//앞에서 부터 삭제를 하니까, 0만 삭제하면 된다
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
	if (head == tail)//head==tail==NULL인 경우는 이 함수를 돌지 못하도록 설계가 되어 있으므로, 이 함수 내에서 head==tail인 경우는 node가 한개인 경우이다.
	{
		head = NULL;
		tail = NULL;
		delete temp;
	}
	else if (idx == 0)//idx가 0이면 head 주소를 옮겨야 한다
	{
		head = temp->next;
		delete temp;
	}
	else
	{
		for (int i = 0; i < idx - 1; i++)//삭제할 노드의 전 노드의 주소를 찾는다
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
	for (int i = 0; i < idx; i++)//찾을 노드의 주소를 찾는다.
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
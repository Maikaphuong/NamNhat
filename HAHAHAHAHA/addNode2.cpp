#include<iostream>
using namespace std;
//Them x vao vi tri trong danh sach
struct Node
{
	int data;
	Node* previous;
	Node* next;
};
struct List
{
	Node* pHead;
	Node* pEnd;
};
void createList(List& roll)
{
	roll.pHead = NULL;
	roll.pEnd = NULL;
}
Node* createNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	temp->previous = NULL;
	return temp;
}
void addLast(List& roll, Node* p)
{
	if (roll.pHead == NULL)
	{
		roll.pHead = roll.pEnd = p;
	}
	else
	{
		p->previous = roll.pEnd;
		roll.pEnd->next = p;
		roll.pEnd = p;//reset
	}
}
void output(List roll)
{
	cout << endl << ">> Xuat phan tu trong list: " << endl;
	int count = 1;
	for (Node* temp = roll.pHead; temp != NULL; temp = temp->next)
	{
		cout << "+ Vi tri " << count << " : " << temp->data << endl;
		count++;
	}
	cout << endl;
}
int main()
{
	List roll;
	createList(roll);
	int num;
	cout << ">> Nhap num: ";
	cin >> num;
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		cout << ">> Gia tri " << i + 1 << " : ";
		int value;
		cin >> value;
		Node* temp = createNode(value);
		addLast(roll,temp);
	}
	output(roll);
	cout << endl << " >>> NHAP VALUE DE THEM : ";
	int them;
	cin >> them;
	cout << endl << ">> Nhap gia tri x: ";
	int x;
	cin >> x;
	for (Node* p = roll.pHead; p != NULL; p = p->next)
	{
		if (p->data == x)
		{
			/*Node* after = p->next;
			Node* add = new Node;
			add->data = them;
			add->next = after;
			after->previous = add;
			add->previous = p;qua
			p->next = add;*/
			Node* k = new Node;
			k->data = them;
			k->next = p->next;
			p->next = k;
			k->previous = p;
			p->previous = k->previous;
		}
	}
	cout << endl << ">> Xuat sau khi them " << endl;
	output(roll);
	int xoa;
	cout << endl << ">> Nhap gia tri xoa: ";
	cin >> xoa;
	Node* a = NULL;
	for (Node* b = roll.pHead; b != NULL; b = b->next)
	{
		if (b->data == xoa)
		{
			Node* c = b->next;
			delete b;
			a->next = c;
			c->previous = a->next;
			b = c;
			delete c;
			c = NULL;
			break;
		}
		a = b;
	}
	delete a;
	a = NULL;
	cout << endl << "//////" << endl;
	output(roll);
	Node* p = roll.pHead;
	while (p != NULL)
	{
		Node* deleteP = p->next;
		delete p;
		p = deleteP;
	}
	roll.pHead = NULL;
	roll.pEnd = NULL;
	system("pause");
	return 0;
}
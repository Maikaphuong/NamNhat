#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
struct Node
{
	int data;
	Node* pre;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};
void createList(List& a)
{
	a.head = NULL;
	a.tail = NULL;
}
Node* createNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->pre = NULL;
	temp->next = NULL;
	return temp;
}
void addFirst(List& a, Node* p)
{
	if (a.head == NULL)
	{
		a.head = a.tail = p;
	}
	else
	{
		p->next = a.head;
		a.head->pre = p;
		a.head = p;
	}
	cout << endl << ">> Them thanh cong !!" << endl;
}
void addLast(List& a, Node*p)
{
	if (a.head == NULL)
	{
		a.head = a.tail = p;
	}
	else
	{
		p->pre = a.tail;
		a.tail->next = p;
		a.tail = p;
	}
	cout << endl << ">> Them thanh cong !!" << endl;
}
void addAfter_X(List& a, int x, int value)
{
	if (value == a.tail->data)
	{
		addLast(a, createNode(value));
	}
	else
	{
		Node* p = a.head;
		while (p != NULL && p->data != x)
		{
			p = p->next;
		}
		//b1 : luc nay da tim duoc vi tri x tuc la p->data
		Node* y = p->next;//b2: da tim tim vi tri y
		//b3: chen value giua x va y
		Node* data = createNode(value);
		p->next = data;
		data->pre = p;
		data->next = y;
		y->pre = data;
		cout << endl << ">> Them thanh cong !!" << endl;
	}
}
void output(List a)
{
	cout << ">> XUAT node trong List" << endl;
	for (Node* p = a.head; p != NULL; p = p->next)
	{
		cout << p->data << endl;
	}
}
void delFirst(List& a)
{
	if(a.head == NULL)
	{
		cout << ">> Danh sach da rong" << endl;
	}
	else if(a.head == a.tail)
	{
		Node* p = a.head;
		a.head = NULL;
		a.tail = NULL;
		delete p;
		p = NULL;
	}
	else
	{
		Node* p = a.head;
		Node* temp = p->next;
		temp->pre = NULL;
		a.head = temp;
		delete p;
		p = NULL;
		cout << ">> Xoa thanh cong << " << endl;
	}
}
void delEnd(List& a)
{
	if (a.head == NULL)
	{
		cout << ">> Danh sach rong <<" << endl;
	}
	else if (a.head == a.tail)
	{
		Node* p = a.head;
		a.head = NULL;
		a.tail = NULL;
		delete p;
		p = NULL;
		cout << ">> Xoa thanh cong !!" << endl;
	}
	else
	{
		Node* p = a.tail;//sao chep node xoa
		Node* temp = p->pre;//tro den node phia truoc node xoa
		temp->next = NULL;
		a.tail = temp;
		delete p;
		p = NULL;
		cout << ">> Xoa thanh cong !!" << endl;
	}
}

void delX(List& a, int vl) {
////TH 1: NULL - (data) - NULL
////TH 2: NULL - x - (data) - NULL
////TH 3: NULL - x - (data) - z - NULL( nhiều phần tử trở lên)
//	if (a.head != NULL)
//	{
//		Node* value = a.head;
//		while (value != NULL)
//		{
//			Node* x = value->pre;
//			Node* y = value->next;
//			if (value->data == vl)
//			{
//				//TH: 1 phan tu duy nhat
//				if (x == NULL && y == NULL)
//				{
//					a.head = NULL;
//					a.tail = NULL;
//					delete value;
//					value = NULL;
//					return;//thoat vong lap while
//				}
//				//TH 2: NULL - x - (data) - NULL
//				else if (y == NULL)
//				{
//					x->next = NULL;
//					a.tail = x;
//					delete value;
//					value = NULL;
//					return;
//				}
//				//TH 3:( nhiều phần tử trở lên)
//				else
//				{
//					// NULL - (data) - y - NULL
//				   // NULL - x - (data) - z - NULL
//					if (x == NULL)
//					{
//						y->pre = x;
//						a.head = y;
//						delete value;
//					}
//					else
//					{
//						x->next = y;
//						y->pre = x;
//						delete value;
//					}
//					value = y;
//				}
//			}
//			else
//			{
//				value = y;
//			}
//		}
//	}
//	else
//	{
//		cout << "!! Danh sach rong khong the xoa" << endl;
//	}
	while (a.head != NULL && a.head->data == vl)
	{
		Node* temp = a.head;
		a.head = a.head->next;
		delete temp;
		temp = NULL;
	}
	if (a.head == NULL)
	{
		a.tail = NULL;
		return;
	}
	//Truong hop tren da xu ly x khac value
	Node* y = a.head;
	while (y != NULL)
	{
		if (y->data == vl)
		{
				Node* pre = y->pre;
				pre->next = y->next;
				Node* temp = y;
				if (a.tail == y)
				{
					a.tail = pre;
				}
				y = y->next;
				delete temp;
				temp = NULL;
		}
		else
		{
			y = y->next;
		}
	}
}
int main()
{
	List a;
	createList(a);
	char choice;
	do
	{
		system("cls");
		cout << "        Menu" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Nhap add First" << endl;
		cout << " 2. Nhap add Last" << endl;
		cout << " 3. Xuat " << endl;
		cout << " 4. xoa dau" << endl;
		cout << " 5. xoa cuoi" << endl;
		cout << " 6. xoa x //chua check dieu kien" << endl;
		cout << " 7. Them Value sau x // chua check dieu kien" << endl;
		cout << "--------------------------" << endl;
		cout << "> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << " 1. Nhap add First" << endl;
			int num;
			cout << ">>Nhap so luong: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				int value;
				cin >> value;
				cin.ignore();
				addFirst(a, createNode(value));
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Nhap add Last" << endl;
			int num;
			cout << ">>Nhap so luong: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				int value = rand() % 100 + 1;
				addLast(a, createNode(value));
			}
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. Xuat" << endl;
			output(a);
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. xoa dau" << endl;
			delFirst(a);
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. xoa cuoi" << endl;
			delEnd(a);
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 6. xoa x" << endl;
			output(a);
			int x;
			cout << endl << "------------------------------------" << endl;
			cout << ">> Nhap x: ";
			cin >> x;
			cout << endl;
			delX(a, x);
			system("pause");
			break;
		}
		case '7':
		{
			cout << " 7. Them Value sau x // chua check dieu kien" << endl;
			output(a);
			int x;
			cout << endl << "------------------------------------" << endl;
			cout << ">> Nhap x: ";
			cin >> x;
			cout << endl;
			cout << ">> Nhap value: ";
			int value;
			cin >> value;
			addAfter_X(a, x, value);
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	Node* p = a.head;
	while (p != NULL)
	{
		Node* delNode = p;
		p = p->next;
		delete delNode;
		delNode = NULL;
	}
	a.head = NULL;
	a.tail = NULL;
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
/*
Bài 7: Quản lý một danh sách liên kết vòng.
*/
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct List
{
	Node* head;
	Node* end;
};
void createList(List& roll)
{
	roll.head = NULL;
	roll.end = NULL;
}
Node* createNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}
void addLast(List& roll, Node* p)
{
	if (roll.head == NULL)
	{
		roll.head = roll.end = p;
		roll.end->next = roll.head;
	}
	else
	{
		roll.end->next = p;
		roll.end = p;
		p->next = roll.head;
	}
}
void output(List roll)
{
	Node* p = roll.head;
	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p!= roll.head);
}
void addFirst(List& roll, Node* p)
{
	if (roll.head == NULL)
	{
		roll.head = roll.end = p;
		roll.end->next = roll.head;
	}
	else
	{
		roll.end->next = p;
		p->next = roll.head;
		roll.head = p;
	}
}
void deleteFirst(List& roll)
{
	if (roll.head == roll.end)
	{
		Node* temp = roll.head;
		roll.head = NULL;
		roll.end = NULL;
		delete temp;
		temp = NULL;
	}
	else
	{
		Node* xoa = roll.head;
		roll.head = roll.head->next;
		roll.end->next = roll.head;
		delete xoa; 
		xoa = NULL;
	}
	cout << ">> Xoa thanh cong" << endl;
}
void deleteLast(List& roll)
{
	if (roll.head == roll.end)
	{
		Node* temp = roll.head;
		roll.head = NULL;
		roll.end = NULL;
		delete temp;
		temp = NULL;
	}
	else
	{
		Node* p = roll.head;//copy vi tri truoc Node xoa
		Node* xoa = p->next;//copy vi tri xoa
		while (xoa != roll.end)
		{
			p = p->next;
			xoa = p->next;
		}
		p->next = roll.head;
		roll.end = p;
		delete xoa;
		xoa = NULL;
	}

		cout << ">> Xoa thanh cong" << endl;
}
void deleteX(List& roll, int x)
{
	//xoa cac vitri trung nhau o head, hay 1 Node duy nhat 
	while (roll.head != roll.end && roll.head->data == x)
	{
		Node* xoa = roll.head;
		roll.head = roll.head->next;
		delete xoa;
		xoa = NULL;
	}
	if (roll.head == roll.end && roll.head->data == x)
	{
		deleteFirst(roll);
		return;
	}
	Node* pre = roll.head;
	Node* curr = roll.head->next;
	while (curr !=	NULL)
	{

		if (curr->data == x)
		{
			Node* temp = curr;
			pre->next = curr->next;
			if (curr == roll.end)
				roll.end = pre;
			curr = curr->next;
			cout << ">> phan tu xoa " << temp->data << endl;
			delete temp;
			temp = NULL;
			cout << " >> curr tiep theo: " << curr->data << endl;
			cout << " >> pre : " << pre->data << endl;
		}
		else
		{
			pre = curr;
			curr = curr->next;
		}
	}
	cout << ">> Xoa thanh cong" << endl;
}
int main()
{
	List roll;
	createList(roll);
	char choice;
	do
	{
		system("cls");
		cout << "  MENU" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Nhap" << endl;
		cout << " 2. Xuat" << endl;
		cout << " 3. Them vao dau" << endl;
		cout << " 4. Xoa dau" << endl;
		cout << " 5. xoa cuoi" << endl;
		cout << " 6. Tim danh sach roi xoa" << endl;
		cout << " -----------------------------------" << endl;
		cout << ">> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << " 1. Nhap" << endl;
			int num;
			cout << ">> Nhap so luong: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				int value = rand() % 100 + 1;
				addLast(roll, createNode(value));
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat" << endl;
			if (roll.head == NULL)
				cout << "-> Danh=sach rong !!" << endl;
			else
				output(roll);
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. Them vao dau" << endl;
			int num;
			cout << ">> Nhap so luong: ";
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				int value;
				cout << ">> Nhap: ";
				cin >> value;
				cout << endl;
				addFirst(roll, createNode(value));
			}
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. Xoa dau" << endl;
			if (roll.head == NULL)
				cout << "-> Danh=sach rong !!" << endl;
			else
				deleteFirst(roll);
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. Xoa cuoi" << endl;
			if (roll.head == NULL)
				cout << "-> Danh=sach rong !!" << endl;
			else
				deleteLast(roll);
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 6. Tim danh sach roi xoa" << endl;
			if (roll.head == NULL)
				cout << "-> Danh=sach rong !!" << endl;
			else
			{
				int x;
				cout << ">> Nhap x: ";
				cin >> x;
				cout << endl;
				deleteX(roll, x);
			}
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	system("pause");
	return 0;
}
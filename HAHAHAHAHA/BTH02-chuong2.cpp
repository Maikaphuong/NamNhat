#include<iostream>
#include<ctime>
#include<string>
#include<cmath>
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
Node* createNode(int p)
{
	Node* temp = new Node;
	temp->data = p; 
	temp->next = NULL;
	return temp;
}
void output(List roll)
{
	for (Node* p = roll.head; p != NULL; p = p->next)
	{
		cout << p->data << " "; 
	}
}
void addNode(List& roll, Node* p)
{
	if (roll.head == NULL)
	{
		roll.head = roll.end = p;
	}
	else
	{
		roll.end->next = p;
		roll.end = p;
	}
}
void case1(List& roll)
{
	int num;
	do
	{
		cout << ">> Nhap num: ";
		cin >> num;
		cout << endl;
	} while (num < 1);
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int value = rand() % 100 + 1;
		addNode(roll, createNode(value));
	}
}
void intersectionSort(List& roll)
{
	for (Node* a = roll.head->next; a != NULL; a = a->next)
	{
		for (Node* b = roll.head; b != a; b = b->next)
		{
			if (a->data < b->data)
			{
				int temp = a->data;
				a->data = b->data;
				b->data = temp;
			}
		}
	}
}
void selectionSort(List& roll)
{
	for (Node* a = roll.head; a != roll.end; a = a->next)
	{
		Node* min = a;
		for (Node* b = a->next; b != NULL; b = b->next)
		{
			if (min->data > b->data)
				min = b;
		}
		if (min->data != a->data)
		{
			int temp = min->data;
			a->data = min->data;
			min->data = temp;
		}
	}
}
void interchangeSort(List& roll)
{
	for (Node* a = roll.head; a != roll.end; a = a->next)
	{
		for (Node* b = a->next; b != NULL; b = b->next)
		{
			if (a->data > b->data)
			{
				int temp = a->data;
				a->data = b->data;
				b->data = temp;
			}
		}
	}
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
		cout << " 1. Nhap danh sach" << endl;
		cout << " 2. Xuat danh sach" << endl;
		cout << " 3. Intersection Sort" << endl;
		cout << " 4. Selection Sort" << endl;
		cout << " 5. Interchange Sort" << endl;
		cout << " =================================" << endl;
		cout << ">> Nhap : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << " 1. Nhap danh sach" << endl;
			case1(roll);
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat danh sach" << endl;
			if (roll.head != NULL)
			{
				output(roll);
			}
			else
				cout << " !! Khong co du lieu xuat " << endl;
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. Intersection Sort" << endl;
			if (roll.head != NULL)
			{
				intersectionSort(roll);
			}
			else
				cout << " !! Khong co du lieu de sap xep !! " << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. Selection Sort" << endl;
			if (roll.head != NULL)
			{
				selectionSort(roll);
			}
			else
				cout << " !! Khong co du lieu de sap xep !! " << endl;
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. Interchange Sort" << endl;
			if (roll.head != NULL)
			{
				interchangeSort(roll);
			}
			else
				cout << " !! Khong co du lieu de sap xep !! " << endl;
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	// xoa Node
	Node* p = roll.head;
	while (p != NULL)
	{
		Node* xoa = p;
		p = p->next;
		delete xoa;
		xoa = NULL;
	}
	roll.head = roll.end = NULL;
	system("pause");
	return 0;
}
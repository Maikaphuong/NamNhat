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
	Node* first;
	Node* end;
};
void createList(List& roll)
{
	roll.first = NULL;
	roll.end = NULL;
}
Node* createNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->pre = NULL;
	temp->next = NULL;
	return temp;
}
void addNode(List& roll, Node* p)
{
	if (roll.first == NULL)
		roll.first = roll.end = p;
	else
	{
		roll.end->next = p;
		p->pre = roll.end;
		roll.end = p;
	}
}
void output(List roll)
{
	for (Node* p = roll.first; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
}
void interchangeSort(List& roll)
{
	for (Node* a = roll.first; a != roll.end; a = a->next)
	{
		for (Node* b = a->next; b != NULL; b = b->next)
		{
			if (b->data < a->data)
			{
				int temp = b->data;
				b->data = a->data;
				a->data = temp;
			}
		}
	}
}
void selectionSort(List& roll)
{
	for (Node* a = roll.first; a != roll.end; a = a->next) {
		Node* index = a;
		for (Node* b = a->next; b != NULL; b = b->next) {
			if (index->data > b->data) {
				index = b;
			}
		}
		if (index != a) {
			int temp = index->data;
			index->data = a->data;
			a->data = temp;
		}
	}
}
void insersectionSort(List& roll)
{
	for (Node* a = roll.first->next;a != NULL; a = a->next)
	{
		Node* temp = a;
		for (Node* b = roll.first; b != a; b = b->next)
		{
			if (b->data > temp->data)
			{
				int swap = b->data;
				b->data = temp->data;
				temp->data = swap;
			}
		}
	}
}
void bubleSort(List& roll)
{
	for (Node* a = roll.end; a != roll.first; a = a->pre)
	{
		for (Node* b = roll.first; b != a; b = b->next)
		{
			if (b->data > b->next->data)
			{
				int swap = b->data;
				 b->data = b->next->data;
				 b->next->data = swap;
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
		cout << "        Menu" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Nhap " << endl;
		cout << " 2. Xuat" << endl;
		cout << " 3. selectionSort" << endl;
		cout << " 4. Intersection Sort" << endl;
		cout << " 5. Interchange sort" << endl;
		cout << " 6. Bubble sort" << endl;
		cout << "--------------------------" << endl;
		cout << "> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			int num;
			cout << ">> Nhap so luong: ";
			cin >> num;
			srand(time(NULL));
			for (int i = 0; i < num; i++)
			{
				int value = rand() % 100 + 1;
				addNode(roll, createNode(value));
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat" << endl;
			output(roll);
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. SelectionSort" << endl;
			selectionSort(roll);
			cout << ">> Sap xep thanh cong" << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. Intersection Sort" << endl;
			insersectionSort(roll);
			cout << ">> Sap xep thanh cong" << endl;
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. Interchange Sort" << endl;
			interchangeSort(roll);
			cout << ">> Sap xep thanh cong" << endl;
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 5. Buble Sort" << endl;
			bubleSort(roll);
			cout << ">> Sap xep thanh cong" << endl;
			system("pause");
			break;
		}
		}
	} while (choice != '0');

	//delete Node
	Node* p = roll.first;
	while (p != NULL)
	{
		Node* xoa = p;
		p = p->next;
		delete xoa;
		xoa = NULL;
	}
	roll.first = NULL;
	roll.end = NULL;
	system("pause");
	return 0;
}
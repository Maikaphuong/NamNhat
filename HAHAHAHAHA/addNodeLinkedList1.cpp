#include<iostream>
using namespace std;
//Them x vao vi tri trong danh sach
struct Node
{
	int data;
	Node* next;
};
struct List
{
	Node* headList;
	Node* endList;
};
Node* createNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}
void createList(List& roll)
{
	roll.headList = NULL;
	roll.endList = NULL;
}
void addLast(List& roll, Node *add)
{
	if (roll.headList == NULL)
	{
		roll.headList = roll.endList = add;
	}
	else
	{
		roll.endList->next = add;
		roll.endList = add;
	}
}
void addFirst(List& roll, Node *add)
{
	if (roll.headList == NULL)
	{
		roll.headList = roll.endList = add;
	}
	else
	{
		add->next = roll.headList;
		roll.headList = add;
	}
}
void output(List roll)
{
	int dem = 0;
	for (Node* k = roll.headList; k != NULL; k = k->next)
	{
		cout << "- Vitri " << dem + 1 << " : " << k->data << endl;
		dem++;
	}
}
int sizeList(List roll)
{
	int count = 0;
	for (Node* p = roll.headList; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}
void addAtAfter(List& roll,int value, int vitri)
{
	Node* p = roll.headList;
	for (int i = 0; i < vitri-1; i++)
	{
		p = p->next;
	}
	Node* temp = new Node;
	temp->data = value;
	temp->next = p->next;
	p->next = temp;
}
void addAtBefor(List& roll, int value, int vitri)
{
	if (vitri == 1)
	{
		Node* temp = createNode(value);
		addFirst(roll, temp);
	}
	else
	{
		Node* p = roll.headList;
		for (int i = 0; i < vitri - 2; i++)
		{
			p = p->next;
		}
		Node* temp = new Node;
		temp->data = value;
		temp->next = p->next;
		p->next = temp;
	}
}
void addValueAfter(List& roll, int value, int p)
{
	Node* pointer = createNode(p);
	for (Node* i = roll.headList; i != NULL; i = i->next)
	{
		if (i->data == pointer->data)
		{
			Node* temp = new Node;
			temp->data = value;
			temp->next = i->next;
			i->next = temp;
		}
	}
}
void addValueBefor(List& roll, int value, int p)
{
	Node* copy = NULL;
	int size = 0;
	for (Node* i = roll.headList; i != NULL; i = i->next)
	{
		if(size == 0 && i->data == p)
		{
			addFirst(roll, createNode(value));
		}
		else if (i->data == p)
		{
			Node* temp = createNode(value);
			temp->next = i;//B1: liên kết temp với node (node có giá trị là p ) cần đứng trước nó
			copy->next = temp;//B2: liên kết node (copy) đứng trước node (có giá trị p) liên kết với temp 
		}
		copy = i;//sao chep node truoc do;
		size++;
	}
}
int checkValue(List roll, int check)
{
	int flag = 0;
	for (Node* i = roll.headList; i != NULL; i = i->next)
	{
		if (i->data == check)
		{
			flag = 1;
		}
	}
	return flag;
}
int main()
{
	List roll;
	createList(roll);
	char choice;
	do
	{
		system("cls");
		cout << "  .. Menu .." << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Them NODE vao danh sach" << endl;
		cout << " 2. Xuat danh sach" << endl;
		cout << " 3. Them vao vi tri A 'sau' vitri X trong danh sach" << endl;
		cout << " 4. Them vao vi tri A 'truoc' vitri X trong danh sach" << endl;
		cout << " 5. Them vao gia tri A vao 'sau' gia tri X trong danh sach" << endl;
		cout << " 6. Them vao gia tri A vao 'truoc' gia tri X trong danh sach" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << ">> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '0':
		{
			cout << ">> Ban da thoat chuong trinh" << endl;
			break;
		}
		case '1':
		{
			cout << " 1. Them NODE vao danh sach" << endl;
			int num;
			do
			{
				cout << "- Nhap so luong phan tu: ";
				cin >> num;
			} while (num < 1);
			for (int i = 0; i < num; i++)
			{
				int value;
				cout << "- Nhap gia tri thu " << i + 1 << " : ";
				cin >> value;
				Node *temp = createNode(value);
				addLast(roll, temp);
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat danh sach" << endl;
			if (roll.headList == NULL)
			{
				cout << ">> Khong co du lieu" << endl;
			}
			else
			{
				output(roll);
			}
			cout << endl;
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. Them vao vi tri A sau vitri X trong danh sach" << endl;
			if (roll.headList == NULL)
			{
				cout << ">> Chua co du lieu trong danh sach" << endl;
			}
			else
			{
				cout << ">> Danh sach: " << endl;
				output(roll);
				int value, vitri;
				cout << ">> Nhap gia tri : ";
				cin >> value;
				do
				{
					cout << endl << ">> Nhap vi tri:";
					cin >> vitri;
				} while (vitri < 1 || vitri > sizeList(roll));
				addAtAfter(roll, value, vitri);
			}
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. Them vao vi tri A truoc vitri X trong danh sach" << endl;
			if (roll.headList == NULL)
			{
				cout << ">> Chua co du lieu trong danh sach" << endl;
			}
			else
			{
				cout << ">> Danh sach: " << endl;
				output(roll);
				int value, vitri;
				cout << ">> Nhap gia tri: ";
				cin >> value;
				do
				{
					cout << endl << ">> Nhap vi tri: ";
					cin >> vitri;
				} while (vitri < 1 || vitri > sizeList(roll));
				addAtBefor(roll, value, vitri);
			}
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. Them vao gia tri A vao sau gia tri X trong danh sach" << endl;
			if (roll.headList == NULL)
			{
				cout << ">> Chua co du lieu trong danh sach" << endl;
			}
			else
			{
				cout << ">> Danh sach: " << endl;
				output(roll);
				int value, p;
				cout << ">> Nhap gia tri A: ";
				cin >> value;
				do
				{
					cout << endl << ">> Nhap gia tri X de cho A dung sau X: ";
					cin >> p;
				} while (checkValue(roll, p) == 0);
				addValueAfter(roll, value, p);
			}
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 6. Them vao gia tri A vao 'truoc' gia tri X trong danh sach" << endl;
			if (roll.headList == NULL)
			{
				cout << ">> Chua co du lieu trong danh sach" << endl;
			}
			else
			{
				cout << ">> Danh sach: " << endl;
				output(roll);
				int value, p;
				cout << ">> Nhap gia tri A: ";
				cin >> value;
				do
				{
					cout << endl << ">> Nhap gia tri X de cho A dung sau X: ";
					cin >> p;
				} while (checkValue(roll, p) == 0);
				addValueBefor(roll, value, p);
			}
			system("pause");
			break;
		}
		}
	}while(choice != '0');
	system("pause");
	return 0;
}
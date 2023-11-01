/*
Bài 8: Quản lý một stack có tối đa 100 phần tử, mỗi phần tử trong stack có kiểu int.
a. Khai báo cấu trúc stack
b. Viết thủ tục khỏi tạo stack rỗng
c. Viết thủ tục xét stack rỗng
d. Viết thủ tục xét stack đầy
e. Viết thủ tục thêm một phần tử vào stack
f. Viết thủ tục xoá một phần tử trong stack
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Node
{
	string data;
	Node* next;
};
struct Stack
{
	Node* head;
};
void createStack(Stack& st)
{
	st.head = NULL;
};
Node* createNode(string x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}
bool isEmpty(Stack st)
{
	if (st.head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(Stack& st, Node* p)//them Node
{
	if (st.head == NULL)
	{
		st.head = p;
	}
	else
	{
		p->next = st.head;
		st.head = p;
	}
}
string pop(Stack& st)// xoa phan tu dau tien
{
	if (st.head == NULL)
	{
		cout << ">> Danh sach rong!!" << endl;
		return 0;
	}
	else
	{
		string value;
		Node* xoa = st.head;
		st.head = st.head->next;
		value = xoa->data;
		delete xoa;
		xoa = NULL;
		return value;
	}
}
void output(Stack st)
{
	Node* p = st.head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
void dec_To_X(int value, int x, Stack& decimal)
{
	if (x != 16)
	{
		while (value != 0)
		{
			int temp = value % x;

			push(decimal, createNode(to_string(temp)));
			value = value / x;
		}
	}
	else
	{
		string hex;
		while (value != 0)
		{
			int temp = value % 16;
			if (temp > 9)
			{
				switch (temp)
				{
				case 10:
				{
					hex = 'A';
					break;
				}
				case 11 :
				{
					hex = 'B';
					break;
				}
				case 12:
				{
					hex = 'C';
					break;
				}
				case 13:
				{
					hex = 'D';
					break;
				}
				case 14:
				{
					hex = 'E';
					break;
				}
				case 15:
				{
					hex = 'F';
					break;
				}
				}
			}
			else
			{
				hex = to_string(temp);
			}
			push(decimal, createNode(hex));
			value = value / 16;
		}
	}
}
int main()
{
	Stack st;
	createStack(st);
	char choice;
	do
	{
		system("cls");
		cout << " Menu" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1> Them node vao stack " << endl;
		cout << " 2> Xuat danh sach stack" << endl;
		cout << " 3> Kiem stack rong" << endl;
		cout << " 4> đổi một số hệ thập phân sang hệ bất kỳ" << endl;
		cout << " 5> Them vao stack" << endl;
		cout << " 6> Xoa 1 stack" << endl;
		cout << " --------------------------" << endl;
		cout << " >> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << " 1> Khai bao cau truc stack" << endl;
			int num;
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				string value;
				cout << ">> Nhap value " << i + 1 << " : ";
				cin >> value;
				push(st, createNode(value));
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2> Xuat danh sach stack" << endl;
			output(st);
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 2> Kiem stack rong" << endl;
			if (isEmpty(st) == true)
				cout << ">> Danh dach hien dang rong" << endl;
			else
				cout << ">> Danh sach khong rong " << endl;
			system("pause");
			break;
		}
		case '4':
		{
			Stack decimal;
			createStack(decimal);
			cout << " 4> đổi một số hệ thập phân sang hệ bất kỳ" << endl;
			bool flag = false;
			output(st);
			int value;
			cout << "----------------------------------------" << endl;
			cout << ">> Nhap vualue can chuyen doi: ";
			cin >> value;
			for (Node* p = st.head; p != NULL; p = p->next)
			{
				if (p->data == to_string(value))
				{
					flag = true;
				}
			}
			if (flag == true)
			{
				int x;
				do
				{
					cout << ">> Nhap he so can chuyen doi: ";
					cin >> x;
					cout << endl;
				} while (x != 2 && x != 16 && x != 10);
				dec_To_X(value, x, decimal);
				for (Node* p = decimal.head; p != NULL; p = p->next)
				{
					cout << p->data;
				}
				while (decimal.head != NULL)
				{
					Node* xoa = decimal.head;
					decimal.head = decimal.head->next;
					delete xoa;
					xoa = NULL;
				}
			}
			else
			{
				cout << ">> Khong tim thay value trong stack can chuyen doi " << endl;
			}

			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5> Them vao stack" << endl;
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	// Giai phong node
	while (st.head != NULL)
	{
		Node* xoa = st.head;
		st.head = st.head->next;
		delete xoa;
		xoa = NULL;
	}
	cout << endl << ">> Giai phong bo nho thanh cong !!" << endl;
	system("pause");
	return 0;
}
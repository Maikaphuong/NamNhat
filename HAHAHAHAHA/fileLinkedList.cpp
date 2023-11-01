#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
BT1: Xây dựng 1 chương trình quản lý phần tử bằng danh sách liên kết đơn chứa các số
nguyên dương. Thực hiện các yêu cầu sau:
- Khai báo cấu trúc danh sách liên kết đơn.
- Tạo file gồm các số với tên input.txt
- Hàm đọc dữ liệu các phần tử file input.txt
+ Dòng đầu tiên: số phần tử
+ Dãy tiếp theo chứa dãy số nguyên thêm vào. Ví dụ: 10, 2, 5, 6, 8, 9
- Hàm xuất các giá trị đang có trong danh sách ra màn hình
- Hàm thêm phần tử vào cuối danh sách từ tập tin input.txt
- Hàm sắp xếp danh sách liên kết đơn tăng dần.
- Hàm sắp xếp danh sách liên kết đơn giảm dần.
- Hàm main để kiểm chứng toàn bộ chương trình dưới dạng menu lựa chọn.
*/
struct Node
{
	char data;
	Node* link;
};
struct List
{
	Node* head;
	Node* end;
};
void createList(List& roll)
{
	roll.head = roll.end = NULL;
}
Node* createNode(char x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->link = NULL;
	return temp;
}
void addNode(List& roll, Node* p)
{
	if (roll.head == NULL)
	{
		roll.head = roll.end = p;
	}
	else
	{
		roll.end->link = p;
		roll.end = p;
	}
}
void deleteNode(List& roll)
{
	Node* p = roll.head;
	while (p != NULL)
	{
		Node* xoa = p;
		p = p->link;
		delete xoa;
		xoa = NULL;
	}
	roll.head = NULL;
	roll.end = NULL;
}
void docFile(List& roll, int &size)
{
	ifstream file;
	file.open("BTH01.txt");
	if (file.is_open())
	{
		file >> size;
		char data;
		while (file >> data)
		{
			file.ignore(2);
			addNode(roll, createNode(data));
		}
		file.close();
	}
	else
	{
		cout << " !! Khong the doc file !!" << endl;
	}
}
void output(List roll)
{
	for (Node* p = roll.head; p != NULL; p = p->link)
	{
		cout << p->data << ", ";
	}
}
void addNodeFile(List& roll, int&size)
{
	char data;
	cout << ">> Nhap du lieu can them vao cuoi: ";
	cin >> data;
	size++;
	addNode(roll, createNode(data));
	ofstream file;
	file.open("BTH01.txt", ios::trunc);
	if (file.is_open())
	{
		file << size << endl;
		for (Node* p = roll.head; p != NULL; p = p->link)
		{
			file << p->data << ", ";
		}
		file.close();
	}
	else
	{
		cout << ">> Khong the mo file << " << endl;
	}
}
void increaseData(List& roll)
{
	for (Node* a = roll.head; a != roll.end; a = a->link)
	{
		for (Node* b = a->link; b != NULL; b = b->link)
		{
			if (a->data > b->data)
			{
				char temp = a->data;
				a->data = b->data;
				b->data = temp;
			}
		}
	}
	cout << ">> Xap xep thanh cong << " << endl;
}
void decreaseData(List& roll)
{
	for (Node* a = roll.head; a != roll.end; a = a->link)
	{
		for (Node* b = a->link; b != NULL; b = b->link)
		{
			if (a->data < b->data)
			{
				char temp = a->data;
				a->data = b->data;
				b->data = temp;
			}
		}
	}
	cout << ">> Xap xep thanh cong << " << endl;
}
int main()
{
	int size;
	List roll;
	createList(roll);
	docFile(roll, size);
	char choice;
	do
	{
		system("cls");
		cout << "... Menu ..." << endl;
		cout << " 0.Thoat" << endl;
		cout << " 1.Add node " << endl;
		cout << " 2.Xuat file" << endl;
		cout << " 3.Xap xep file tang dan" << endl;
		cout << " 4.Xap xep file giam dan" << endl;
		cout << "--------------------------" << endl;
		cout << ">> Nhap : ";
		cin >> choice;
		switch (choice)
		{
		case '0': 
		{
			deleteNode(roll);
			cout << endl << ">> Da giai phong bo nho << " << endl;
			cout << ">> Ban da thoat << " << endl;
			system("pause");
			break;
		}
		case'1':
		{
			cout << " 1.Add node " << endl;
			addNodeFile(roll, size);
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat file" << endl;
			output(roll);
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3.Xap xep file tang dan" << endl;
			increaseData(roll);
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4.Xap xep file giam dan" << endl;
			decreaseData(roll);
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	return 0;
}

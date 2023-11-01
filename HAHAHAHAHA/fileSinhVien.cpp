
/*
Bài 19 (*): Dùng cấu trúc dữ liệu phù hợp để viết các thủ tục và kiểm chứng kết quả cho việc quản
lý danh sách sinh viên bao gồm các thao tác:
- Nhập danh sách sinh viên từ bàn phím
- Nhập danh sách sinh viên từ tập tin txt
- Xuất danh sách sinh viên
- Lọc danh sách theo từng thành phần dữ liệu của sinh viên
- Thêm 1 sinh viên vào vị trí bất kỳ trong danh sách
- Xóa 1 sinh viên bất kỳ trong danh sách
- Sắp xếp danh sách sinh viên theo từng dữ liệu thành phần
- Ghi danh sách sinh viên thỏa điều kiện ra tập tin txt
Cấu trúc 1 sinh viên gồm:
struct SinhVien
{
string maSV;
string hoTen;
int namSinh;
string diaChi;
bool gioiTinh; //nam là true, nữ là false
double diemTB;
};
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
struct Student
{
	string code;
	string name;
	int year;
	string address;
	bool gender;
	double score;
};
struct Node
{
	Student data;
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
Node* createNode(Student pupil)
{
	Node* temp = new Node;
	temp->data = pupil;
	temp->next = NULL;
	return temp;
}
void randomCode(Student& temp)
{
	srand(time(NULL));
	const string alpha = "0123456789abcdefghijklmnopqrstuvwhyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int len = alpha.size();
	string newCode;
	for (int i = 0; i < 5; i++)
	{
		int index = rand() % len;
		newCode += alpha[index];
	}
	temp.code = newCode;
}
void output(List roll)
{
	int i = 0;
	for (Node* p = roll.head; p != NULL; p = p->next)
	{
		cout << ">> Sinh vien " << i + 1 << " : " << endl;
		i++;
		Student temp = p->data;
		cout << "- Code: " << temp.code << endl;
		cout << "- Name: " << temp.name << endl;
		cout << "- Year: " << temp.year << endl;
		cout << "- Address: " << temp.address << endl;
		if (temp.gender == true)
		{
			cout << "- Gender: man " << endl;
		}
		else
		{
			cout << "- Gender: female" << endl;
			cout << "- Marks: " << temp.score << endl << endl;
			cout << "-----------------------------------------" << endl;
		}
	}
}
void inputStudent(Student& temp)
{
	cin.ignore();
	randomCode(temp);
	cout << "- Code: " << temp.code;
	cout << endl << "- Name: ";
	getline(cin, temp.name);
	cout << endl << "- Year: ";
	cin >> temp.year;
	cin.ignore();
	cout << endl << "- Address: ";
	getline(cin, temp.address);
	char flag = 0;
	do
	{
		cout << endl << "Hay chon gioi tinh" << endl;
		cout << " 0. Nam" << endl;
		cout << " 1. Nu" << endl;
		cout << "-------------------------" << endl;
		cout << " >> Chon :  ";
		cin >> flag;
		if (flag == '0')
		{
			temp.gender = true;
			cout << "- Gender: Man" << endl;
			break;
		}
		else if (flag == '1')
		{
			temp.gender = false;
			cout << "- Gender: female " << endl;
			break;
		}

	} while (flag != '0' && flag != '1');
	cin.ignore();
	cout << endl << "- Marks: ";
	cin >> temp.score;
	cout << endl << "-----------------------------------------" << endl;
}
void addNode(List& roll, Node* temp)
{
	if (roll.head == NULL)
		roll.head = roll.end = temp;
	else
	{
		roll.end->next = temp;
		roll.end = temp;
	}
}
void deleteNode(List& roll)
{
	Node* p = roll.head;
	while (p != NULL)
	{
		Node* xoa = p;
		p = p->next;
		delete xoa;
		xoa = NULL;
	}
	roll.head = NULL;
	roll.end = NULL;
}
int countList()
{
	int count = 0;
	ifstream file;
	file.open("student.txt");
	if (file.is_open())
	{
		string data;
		while (!file.eof())
		{
			getline(file, data);
			if (data == "")
				break;
			count++;
		}
		file.close();
	}
	else
		cout << "!! Khong the mo file" << endl;
	return count;
}
void ghiFile(List& roll, int dem)
{
	ofstream file;
	if (dem == 0)
		file.open("student.txt", ios::out);
	else
		file.open("student.txt", ios::app);
	if (file.is_open())
	{
		for (Node* p = roll.head; p != NULL; p = p->next)
		{
			string gen;
			if (p->data.gender == true)
				gen = "Male";
			else
				gen = "Female";
			file << p->data.code << "#" << p->data.name << "#" << p->data.year << "#" << p->data.address << "#" << gen << "#" << p->data.score << endl;
		}
		file.close();
		cout << ">> Luu file thanh cong << " << endl;
	}
	else cout << "!! Khong the doc file !!" << endl;
	deleteNode(roll);
}
void inputNode(List& roll)
{
	int num;
	do
	{
		cout << ">> Nhap so luong muon sinh vien them vao: ";
		cin >> num;
		cout << endl;
	} while (num < 1);
	for (int i = 0; i < num; i++)
	{

		system("cls");
		cout << "-- Nhap sinh vien thu " << i + 1 << " : " << endl;
		Student pupil;
		randomCode(pupil);
		inputStudent(pupil);
		Node* temp = createNode(pupil);
		addNode(roll, temp);
		system("pause");
	}
	ghiFile(roll, countList());
}
void addAnyWhere(List& roll, Node* add, string placeCode)//them vao sau vi tri placeCode
{
	if (placeCode == roll.head->data.code)
	{
		if (roll.head == NULL)
			roll.head = roll.end = add;
		else
		{
			add->next = roll.head;
			roll.head = add;
		}
	}
	else if (placeCode == roll.end->data.code)//vi tri cuoi
	{
		addNode(roll, add);
	}
	else//vi tri bat ky
	{
		Node* pre = roll.head;
		Node* curr = new Node;
		while (pre->data.code != placeCode)
		{
			curr = pre->next;// sau chep vi tri phi sau placeCode
			pre = pre->next;
		}
		pre->next = add;
		pre = add;
		add->next = curr;
		add = curr;
	}
}
void docFile(List& roll)
{
	if (roll.head == NULL && countList() > 0)
	{
		ifstream file;
		file.open("student.txt");
		if (file.is_open())
		{
			string data;
			while (!file.eof())
			{
				getline(file, data);
				if (data != "")
				{

					char* kytu = strtok(&data[0], "#");
					Student pupil;
					pupil.code = kytu;
					kytu = strtok(NULL, "#");
					pupil.name = kytu;
					kytu = strtok(NULL, "#");
					pupil.year = atoi(kytu);
					kytu = strtok(NULL, "#");
					pupil.address = kytu;
					kytu = strtok(NULL, "#");
					if (strcmp(kytu, "Male") == 0)
						pupil.gender = true;
					else
						pupil.gender = false;
					kytu = strtok(NULL, "#");
					pupil.score = atof(kytu);
					kytu = nullptr;
					addNode(roll, createNode(pupil));
				}
			}
			file.close();
		}
		else
			cout << ">> Khong the mo file" << endl;
	}
	else
	{
		cout << ">> Danh sach dang rong <<" << endl;
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
		cout << "   Menu" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Nhap" << endl;
		cout << " 2. Xuat" << endl;
		cout << " 3. Them" << endl;
		cout << " 4. Xoa" << endl;
		cout << " -----------------------" << endl;
		cout << ">> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			cout << " 1. Nhap" << endl;
			inputNode(roll);
			system("pause");
			break;
		}
		case'2':
		{
			cout << " 2. Xuat" << endl;
			docFile(roll);
			output(roll);
			system("pause");
			break;
		}
		case'3':
		{

			system("pause");
			break;
		}
		case'4':
		{

			system("pause");
			break;
		}
		}
	} while (choice != '0');
	deleteNode(roll);
	cout << ">> Ban da giai phong bo nho" << endl;
	system("pause");
	return 0;
}
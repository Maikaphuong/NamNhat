#define _CRT_SECURE_NO_WARNINGS
/*
5 đ (70') + 5' đọc đề
-  Giám khảo: Bảo và Mai
- Thí sinh: Phương
Hệ thống bán hàng gồm 2 loại sản phẩm
- Điện thoại gồm 2 model:
+ iphone : 18tr
+ xiaomi : 13 tr
-Laptop gồm 2 model:
+ Asus : 20 tr
+ Macbook : 30.5tr
viết chương trình có các chức năng như sau:
- nhập xuất và xóa sản phẩm
- chỉnh sửa sản phẩm
- xuất hóa đơn thành tiền
- Moi chiec deu co ma random khac nhau
*/
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;

struct LIST
{
	string name;
	string model;
	int amount;
	string code;
	string price;
};
int countList()//gia tri that
{
	int count = 0;
	ifstream file;
	file.open("BTH10file.txt");
	if (file.is_open())
	{
		string data;
		while (!file.eof())
		{
			getline(file, data);
			if (data == "")
			{
				break;
			}
			count++;
		}
		file.close();
	}
	else
	{
		cout << "!!! Khong mo duoc file " << endl;
	}
	return count;
}
string product(char choice)
{
	switch (choice)
	{
	case '1':
	{
		return "Smartphone";
		break;
	}
	case '2':
	{
		return "Laptop";
		break;
	}
	}
}
string model_Phone(char choice)
{
	switch (choice)
	{
	case '1':
	{
		return "Iphone";
		break;
	}
	case '2':
	{
		return "Xiaomi";
		break;
	}
	}
}
string model_Laptop(char choice)
{
	switch (choice)
	{
	case '1':
	{
		return "Asus";
		break;
	}
	case '2':
	{
		return "Macbook";
		break;
	}
	}
}
string price_Phone(char choice)
{
	switch (choice)
	{
	case '1':
	{
		return "18";
	}
	case '2':
	{
		return "13";
	}
	}
}
string price_Laptop(char choice)
{
	switch (choice)
	{
	case '1':
	{
		return "20";
	}
	case '2':
	{
		return "30.5";
	}
	}
}
//-----------------------case 1-------------------------------------
void ghi_1File(LIST p, int soluong)
{
	ofstream file;
	if (soluong == 0)
	{
		file.open("BTH10file.txt",ios::out);
	}
	else
	{
		file.open("BTH10file.txt", ios::app);
	}
	if (file.is_open())
	{
		file << p.name << "#" << p.model << "#" << p.price << "#" << p.amount<< "#" << p.code << endl;
		file.close();
	}
	else
	{
		cout << "!! Khong mo duoc file" << endl;
	}
}
void randomID(LIST& p)
{
	srand(time(NULL));
	const char* alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const int size = 5;
	int len = strlen(alpha);
	string id;
	for (int i = 0; i < size; i++)
	{
		int index = rand() % len;
		id += alpha[index];
	}
	cout << ">> ID: " << id << endl;
	p.code = id;
	cout << ">> p.code: " << p.code << endl;
}
void input(int soluong)
{
	int num;
	do
	{
		cout << ">> Nhap so luong danh sach can them vao kho: ";
		cin >> num;
	} while (num < 1 || num > 200);
	LIST* p = new LIST[num];
	for (int i = 0; i < num;i++)
	{
		cout << ">> STT " << i + 1 << " << " << endl;
		char choiceName;
		do
		{
			system("cls");
			cout << ">> STT " << i + 1 << " << " << endl;
			cout << "Chon 1 san pham duoi day:" << endl;
			cout << "1. Smartphone" << endl;
			cout << "2. Laptop" << endl;
			cout << "-------------------------" << endl;
			cout << ">> Nhap: ";
			cin >> choiceName;
			if (choiceName == '1' || choiceName == '2')
			{
				p[i].name = product(choiceName);
				break;
			}
		} while (choiceName != '1' && choiceName != '2');

		//--------------------------------------------------------------------
		if (choiceName == '1')
		{
			char choiceModel;
			do
			{
				cout << "Chon 1 model duoi day: " << endl;
				cout << "1. Iphone" << endl;
				cout << "2. Xiaomi" << endl;
				cout << "-------------------------" << endl;
				cout << ">> Nhap: ";
				cin >> choiceModel;
				if (choiceModel == '1' || choiceModel == '2')
				{
					p[i].model = model_Phone(choiceModel);
					int number;
					do
					{
						cout << ">> Nhap so luong san pham: ";
						cin >> number;
					} while (number < 1);
					p[i].amount = number;
					int giaTien = number * stoi(price_Phone(choiceModel));
					cout << "Gia tien: " << giaTien << endl;
					p[i].price = to_string(giaTien);
					break;
				}
				else
				{
					cout << ">> Nhap sai yeu cau" << endl;
				}
			} while (choiceModel != '1' && choiceModel != '2');
			randomID(p[i]);
		}
		else if(choiceName == '2')//laptop
		{
			char choiceModel;
			do
			{
				cout << "Chon 1 model duoi day: " << endl;
				cout << "1. Asus" << endl;
				cout << "2. Macbook" << endl;
				cout << "-------------------------" << endl;
				cout << ">> Nhap: ";
				cin >> choiceModel;
				if (choiceModel == '1' || choiceModel == '2')
				{
					p[i].model = model_Laptop(choiceModel);
					int number;
					do
					{
						cout << ">> Nhap so luong san pham: ";
						cin >> number;
					} while (number < 1);
					p[i].amount = number;
					int giaTien = number * stoi(price_Laptop(choiceModel));
					cout << "Gia tien: " << giaTien << endl;
					p[i].price = to_string(giaTien);
					break;
				}
				else
				{
					cout << ">> Nhap sai yeu cau" << endl;
				}
			} while (choiceModel != '1' && choiceModel != '2');
			randomID(p[i]);
		}
		cout << "-----------------------------------------" << endl;
	}
	for (int i = 0; i < num; i++)
	{
		ghi_1File(p[i], soluong);
	}
	cout << endl << ">> Thanh cong << " << endl;
	//delete
	delete[]p;
	p = nullptr;
}
//---------------------- case 2 ------------------------------------
void docFile(LIST& p, int vitri)
{
	ifstream file;
	file.open("BTH10file.txt");
	if (file.is_open())
	{
		int dem = 0;
		string data;
		while (!file.eof())
		{
			getline(file, data);
			if (data != "" && dem == vitri)
			{
				char* kytu = strtok(&data[0], "#");
				p.name = kytu;
				kytu = strtok(NULL, "#");
				p.model = kytu;
				kytu = strtok(NULL, "#");
				p.price = kytu;
				kytu = strtok(NULL, "#");
				p.amount = atoi(kytu);
				kytu = strtok(NULL, "#");
				p.code = kytu;
				kytu = nullptr;
			}
			dem++;
		}
		file.close();
	}
	else
	{
		cout << ">> Khong the mo file" << endl;
	}
}
void xuat_1List(LIST p)
{
	cout << "- Ten: " << p.name << endl;
	cout << "- Model: " << p.model << endl;
	cout << "- ID: " << p.code << endl;
	cout << "- So luong: " << p.amount << endl;
	cout << "- Gia tien: " << p.price << endl;
	cout << "--------------------------------------" << endl;
}
void case2(int soluong)
{
	LIST* p = new LIST[soluong];
	for (int i = 0; i < soluong; i++)
	{
		docFile(p[i], i);
	}
	for (int i = 0; i < soluong; i++)
	{
		cout << ">> STT " << i + 1 << " : << " << endl;
		xuat_1List(p[i]);
	}
	//delete
	delete[]p;
	p = nullptr;
}
//------------------------ case 3 ------------------------------------
void deleteList(int vitri, int soluong)
{
	LIST* p = new LIST[soluong];
	for (int i = 0; i < soluong; i++)
	{
		docFile(p[i], i);
	}
	LIST* copy = new LIST[soluong - 1];
	for (int i = 0; i < vitri; i++)
	{
		copy[i] = p[i];
	}
	for (int i = vitri + 1; i < soluong;i++)
	{
		copy[i - 1] = p[i];
	}
	//delete p
	delete[]p;
	p = nullptr;
	ofstream file;
	file.open("BTH10file.txt");
	if (file.is_open())
	{
		for (int i = 0; i < soluong - 1; i++)
		{
			file << copy[i].name << "#" << copy[i].model << "#" << copy[i].price << "#" << copy[i].amount << "#" << copy[i].code << endl;
		}
		file.close();
	}
	else
	{
		cout << "!! Khong mo duoc file" << endl;
	}
	//delete
	delete[]copy;
	copy = nullptr;
}
void case3(int soluong)
{
	cin.ignore();
	string id;
	do
	{
		cout << ">> Nhap ma id: ";
		getline(cin, id);
	} while (id == "");
	ifstream file;
	file.open("BTH10file.txt");
	int flag = 0;
	int vitri = 0;
	cout << "///// id " << id << endl;
	string code;
	if (file.is_open())
	{
		int dem = 0;
		string data;
		while (!file.eof())
		{
			getline(file, data);
			if (data != "")
			{
				char* kytu = strtok(&data[0], "#");
				kytu = strtok(NULL, "#");
				kytu = strtok(NULL, "#");
				kytu = strtok(NULL, "#");
				kytu = strtok(NULL, "#");
				code = kytu;
				cout << ">> Code: " << code << endl;
				cout << ">> id: " << id << endl;
				if (code == id)
				{
					vitri = dem;
					flag = 1;
				}
				kytu = nullptr;
			}
			dem++;
		}
		file.close();
	}
	else
	{
		cout << ">> Khong mo duoc fiile" << endl;
	}
	//delete
	if (flag == 1)
	{
		deleteList(vitri, soluong);
		cout << ">> Xoa thanh cong << " << endl;
	}
	else
	{
		cout << "!! Khong tim thay thong tin danh sach can xoa" << endl;
	}
}
//----------------------- case 4 ------------------------------------
void case4(int soluong)
{
	string id;
	do
	{
		cout << ">> Nhap 'ma san pham': ";
		getline(cin, id);
	} while (id == "");
	LIST* p = new LIST[soluong];
	for (int i = 0; i < soluong; i++)
	{
		docFile(p[i], i);
	}
	int flag = 0;
	for (int i = 0; i < soluong; i++)
	{
		if (id == p[i].code)
		{
			cout << endl << ">> Thong tin ban can tim << " << endl;
			flag = 1;
			xuat_1List(p[i]);
			break;
		}
	}
	//delete
	delete[]p;
	p = nullptr;
	if (flag == 0)
	{
		cout << ">> Khong tim thay danh sach cua ban !!" << endl;
	}
}
int main()
{
	char choice;
	do
	{
		cout << "Count list : " << countList() << endl;
		cout << "    Menu" << endl;
		cout << "0. Thoat" << endl;
		cout << "1. Nhap san pham" << endl;
		cout << "2. Xuat san pham" << endl;
		cout << "3. Xoa san pham" << endl;
		cout << "4. Tim san pham" << endl;
		cout << "5. Xuat hoa don" << endl;
		cout << "6. " << endl;
		cout << ">> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '0':
		{
			cout << endl << "Tam biet" << endl;
			break;
		}
		case '1':
		{
			cout << "1. Nhap san pham" << endl;
			input(countList());
			break;
		}
		case '2':
		{
			cout << "2. Xuat san pham" << endl;
			if (countList() == 0)
			{
				cout << "!! Khong co du lieu !!" << endl;
			}
			else
			{
				case2(countList());
			}
			break;
		}
		case '3':
		{
			cout << "3. Xoa san pham" << endl;
			if (countList() == 0)
			{
				cout << "!! Khong co du lieu !!" << endl;

			}
			else
			{
				case3(countList());
			}
			break;
		}
		case '4':
		{
			cout << "4. Tim san pham" << endl;
			if (countList() == 0)
			{
				cout << "!! Khong co du lieu !!" << endl;

			}
			else
			{
				cin.ignore();
				case4(countList());
			}
			break;
		}
		case '5':
		{
			cout << "5. Xuat hoa don" << endl;
			if (countList() == 0)
			{
				cout << "!! Khong co du lieu !!" << endl;

			}
			else
			{

			}
			break;
		}
		}
	} while (choice != '0');
	system("pause");
	return 0;
}
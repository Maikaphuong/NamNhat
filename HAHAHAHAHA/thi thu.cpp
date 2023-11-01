#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
typedef Node NODE;
typedef Node* TREE;
void createTree(TREE& tree)
{
	tree = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void addNode(TREE& tree, Node* p)
{
	if (tree == NULL)
	{
		tree = p;
	}
	else
	{
		if (tree->data > p->data)
			addNode(tree->left, p);
		else if (tree->data < p->data)
			addNode(tree->right, p);
		else
		{
			delete p;
			p = NULL;
		}
	}
}
void output(TREE tree)
{
	if (tree != NULL)
	{
		cout << tree->data << " ";
		output(tree->left);
		output(tree->right);
	}
}
void deleteTree(TREE& tree)
{
	if (tree == NULL)
		return;
	else
	{
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
		tree = NULL;
	}
}
void docFile(TREE& tree)
{
	bool flag = true;
	ifstream file;
	file.open("BTH01.txt");
	if (file.is_open())
	{
		int value,size;
		if (file >> size) // Check if the file is not empty
		{
			while (file >> value)
			{
				addNode(tree, createNode(value));
				file.ignore(2);
			}
		}
		else
		{
			flag = false;
		}
		file.close(); // Close the file after reading or handling an empty file
	}
	else
		cout << ">> Khong mo duoc file << " << endl;
	//file rong thi add 0
	if (flag == false)
	{
		ofstream data;
		data.open("BTH01.txt");
		if (data.is_open())
		{
			int size = 0;
			data << size;
			data.close();
		}
		else
		{
			cout << ">> Khong mo duoc file" << endl;
		}
	}
}
void ghi(TREE tree, ofstream& file)
{
	if (tree != NULL)
	{
		file << tree->data << ", ";
		ghi(tree->left, file);
		ghi(tree->right, file);
	}
}
int countNode(TREE tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + countNode(tree->left) + countNode(tree->right);
	}
}
void ghiFile(TREE tree)
{
	int size = countNode(tree);
	ofstream file;
	file.open("BTH01.txt", ios::trunc);
	if (file.is_open())
	{
		file << size << endl;
		ghi(tree, file);
		file.close();
	}
	else
		cout << "<< Khong the mo file" << endl;
}
void case1(TREE &tree)
{
	int num;
	do
	{
		cout <<endl << ">> Nhap so luong number: ";
		cin >> num;

	} while (num < 1);
	for (int i = 0; i < num; i++)
	{
		int value;
		cout << endl << "- Nhap so thu " << i + 1 << ": ";
		cin >> value;
		addNode(tree, createNode(value));
	}
	ghiFile(tree);
}
int main()
{
	char choice;
	TREE tree;
	createTree(tree);
	do
	{
		system("cls");
		deleteTree(tree);
		docFile(tree);
		cout << "... Menu ..." << endl;
		cout << "0. Thoat " << endl;
		cout << "1. Them node" << endl;
		cout << "2. Xuat file" << endl;
		cout << "3. " << endl;
		cout << "..........................." << endl;
		cout << ">> Nhap: ";
		cin >> choice;
		switch (choice)
		{
		case '0':
		{
			cout << ">> Ban da thoat " << endl;
			deleteTree(tree);
			break;
		}
		case '1':
		{
			cout << "1. Them node" << endl;
			case1(tree);
			system("pause");
			break;
		}
		case '2':
		{
			cout << "2. Xuat file" << endl;
			output(tree);
			system("pause");
			break;
		}
		}
	} while (choice != '0');
	system("pause");
	return 0;
}
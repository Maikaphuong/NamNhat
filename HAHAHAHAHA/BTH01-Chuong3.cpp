#include<iostream>
using namespace std;
/*
Khai báo cấu trúc cây nhị phân tìm kiếm.
1.2. Viết thủ tục khởi tạo cây rỗng.
1.3. Viết thủ tục thêm một phần tử vào cây (dùng đệ quy).
1.4. Viết thủ tục tìm một phần tử trong cây (dùng đệ quy).
1.5. Viết thủ tục xóa một nut trong cây (dùng đệ quy).
1.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng đệ quy)
1.9 Viết thủ tục đếm số phần tử trong cây.
1.10 Viết thủ tục tính trung bình cộng các phần tử trong cây.
1.11 Viết thủ tục tìm giá trị lớn nhất trong cây.
1.12 Viết thủ tục đếm số phần tử là số nguyên tố trong cây.
*/
struct Node
{
	int data;
	Node* left;
	Node* right;
};
typedef struct Node NODE;
typedef NODE* TREE;
void createTree(TREE& tree)
{
	tree = NULL;
}
void addNode(TREE& tree, int value)
{
	if (tree == NULL)
	{
		Node* p = new Node;
		p->data = value;
		p->left = NULL;
		p->right = NULL;
		tree = p;
	}
	else
	{
		if (tree->data > value)
		{
			return addNode(tree->left, value);
		}
		else if (tree->data < value)
			return addNode(tree->right, value);
	}
}
bool findNode(TREE tree, int x)
{
	if (tree == NULL)
		return false;
	else
	{
		if (tree->data > x)
			return findNode(tree->left, x);
		else if (tree->data < x)
			return findNode(tree->right, x);
		else
			return true;
	}
}
void outputNLR(TREE  tree)
{
	if (tree != NULL)
	{
		cout << tree->data << " ";
		outputNLR(tree->left);
		outputNLR(tree->right);
	}
}
void deleteTree(TREE& tree)
{
	if (tree != NULL)
	{
		if (tree->left)
			return deleteTree(tree->left);
		if (tree->right)
			return deleteTree(tree -> right);
		delete (tree);
		tree = NULL;
	}
}
void nodeTheMang(TREE& x, TREE& y)
{
	if (y->left != NULL)
		nodeTheMang(x, y->left);
	else
	{
		x->data = y->data;
		x = y;
		y = y->right;
	}
}
void deleteNode(TREE& tree, int x)
{
	if (tree == NULL)
		return;
	else
	{
		Node* xoa = tree;
		if (tree->data > x)
			return deleteNode(tree->left, x);
		else if (tree->data < x)
			return deleteNode(tree->right, x);
		else
		{
			if (tree->left == NULL)
				tree = tree->right;
			else  if (tree->right == NULL)
				tree = tree->left;
			else
			{
				nodeTheMang(xoa, tree->right);
			}
		}
		delete xoa;
		xoa = NULL;
	}
}
int countNode(TREE tree)
{
	if (tree == NULL)
		return 0;
	else
		return 1 + countNode(tree->left) + countNode(tree->right);
}
int maxValue(TREE tree)
{
	if (tree->right == NULL)
		return tree->data;
	else
		maxValue(tree->right);
}
bool SNT(int data)
{
	bool flag = true;
	if (data > 1)
	{
		for (int i = 2; i < data; i++)
		{
			if (data % i == 0)
			{
				flag = false;
			}
		}
	}
	return flag;
}
int countSNT(TREE tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		if (SNT(tree->data) == true)
			return 1 + countSNT(tree->left) + countSNT(tree->right);
		else
			return countSNT(tree->left) + countSNT(tree->right);
	}
}
int main()
{
	TREE tree;
	createTree(tree);
	char choice;
	do
	{
		system("cls");
		cout << " Menu" << endl;
		cout << " 0. Thoat" << endl;
		cout << " 1. Them " << endl;
		cout << " 2. Xuat (NLR)" << endl;
		cout << " 3. Tim kiem node" << endl;
		cout << " 4. Xoa 1 node tren cay" << endl;
		cout << " 5. Dem so phan tu trong cay " << endl;
		cout << " 6. Tim gia tri lon nhat " << endl;
		cout << " 7. Dem so node la so nguyen to " << endl;
		cout << "________________________" << endl;
		cout << ">> Nhap : ";
		cin >> choice;
		switch (choice)
		{
		case '0':
		{
			deleteTree(tree);
			cout << ">> Da giai phong bo nho " << endl;
			break;
		}
		case '1':
		{
			cout << " 1. Them " << endl;
			int num;
			do
			{
				cout << ">> Nhap number: ";
				cin >> num;
				cout << endl;
			} while (num < 1);
			for (int i = 0; i < num; i++)
			{
				int value;
				cout << endl << "- Nhap phan tu thu " << i + 1 << " : ";
				cin >> value;
				addNode(tree, value);
			}
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat (NLR)" << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
				outputNLR(tree);
			system("pause");
			break;
		}
		case '3':
		{
			cout << " 3. Tim kiem node" << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
			{
				int number;
				cout << ">> Nhap number tim kiem: ";
				cin >> number;
				bool flag = findNode(tree, number);
				if (flag == true)
					cout << ">> Co gia tri " << number << " trong binary tree" << endl;
				else
					cout << ">> Khong co gia tri " << number << " trong binary tree" << endl;
			}
			system("pause");
			break;
		}
		case '4':
		{
			cout << " 4. Xoa 1 node tren cay" << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
			{
				int number;
				cout << ">> Nhap number: ";
				cin >> number;
				bool flag = findNode(tree, number);
				if (flag == true)
				{
					deleteNode(tree, number);
					cout << "<< Da xoa thanh cong >> " << endl;
				}

				else
					cout << ">> Khong co gia tri " << number << " trong binary tree" << endl;
			}
			system("pause");
			break;
		}
		case '5':
		{
			cout << " 5. Dem so phan tu trong cay " << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
			{
				cout << ">> So luong node trong cay nhi phan la: " << countNode(tree) << endl;
			}
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 6. Tim gia tri lon nhat " << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
			{
				cout << ">> So luong node trong cay nhi phan la: " << maxValue(tree) << endl;
			}
			system("pause");
			break;
		}
		case '7':
		{
			cout << " 7. Dem so node la so nguyen to " << endl;
			if (tree == NULL)
			{
				cout << ">> Binary tree is empty <<" << endl;
			}
			else
			{
				cout << ">> So luong SNT trong cay nhi phan la: " << countSNT(tree) << endl;
			}
			system("pause");
			break;
		}
		}
	} while (choice != '0');

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
/*
2.1. Khai báo cấu trúc cây nhị phân tìm kiếm.
2.2. Viết thủ tục khởi tạo cây rỗng.
2.3. Viết thủ tục thêm một phần tử vào cây (không dùng đệ quy).
2.4. Viết thủ tục tìm một phần tử trong cây (không dùng đệ quy).
2.5. Viết thủ tục xóa một nút trong cây (dùng đệ quy).
2.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng stack)
2.7. Viết thủ tục duyệt cây theo thứ tự LNR (dùng stack)
2.8. Viết thủ tục duyệt cây theo thứ tự LRN (dùng queue)
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
void deleteTree(TREE& tree)
{
	if (tree != NULL)
	{
		if (tree->left)
			return deleteTree(tree->left);
		if (tree->right)
			return deleteTree(tree->right);
		delete (tree);
		tree = NULL;
	}
}
void addNode(TREE& tree, int x)
{
	Node* p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	if (tree == NULL)
		tree = p;
	else
	{
		Node* root = tree;
		while (root != NULL)
		{
			if (root->data < x)
			{
				if (root->right == NULL)
				{
					root->right = p;
					return;
				}
				else
					root = root->right;
			}
			else if (root->data > x)
			{
				if (root->left == NULL)
				{
					root->left = p;
					return;
				}
				else
					root = root->left;
			}
			else
			{
				delete p;
				p = NULL;
				break;
			}
		}

	}
}
bool findNode(TREE tree, int x)
{
	bool flag = false;
	Node* temp = tree;
	while (temp != NULL)
	{
		if (temp->data > x)
			temp = temp->left;
		else if (temp->data < x)
			temp = temp->right;
		else
		{
			flag = true;
			break;
		}
	}
	return flag;
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
//dung stack
struct NodeS
{
	int info;
	NodeS* link;
};
struct stack
{
	NodeS*head;
};
void createStack(stack &st)
{
	st.head = NULL;
}
int isEmpty(stack st)
{
	if (st.head == NULL)
	{
		return true;
	}
	return false;
}
void push(stack &st, int x)
{
	NodeS* temp = new NodeS;
	temp->info = x;
	temp->link = NULL;
	if (st.head == NULL)
	{
		st.head = temp;
	}
	else
	{
		temp->link = st.head;
		st.head = temp;
	}
}
void pop(stack& st)
{
	if (isEmpty(st) == true)
	{
		cout << " >> Danh sach rong !! << " << endl;
	}
	else
	{
		NodeS* xoa = st.head;
		st.head = st.head->link;
		delete xoa;
		xoa = NULL;
	}
}
void LNR_Stack(TREE tree)
{
	stack STACK;
	createStack(STACK);

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
		cout << " 5. Duyet cay NLR (stack) " << endl;
		cout << " 6. Duyet cay LNR (stack) " << endl;
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
		}
	} while (choice != '0');



	return 0;
}

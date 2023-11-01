#include<iostream>
#include<ctime>
#include<string>
#include<cmath>
using namespace std;
const int MAX = 100;
struct List
{
	int array[MAX];
	int size = 0;
};
void input(List& roll)
{
	int num;
	do
	{
		cout << ">> Nhap so luong phan tu muon them vao danh sach: ";
		cin >> num;
	} while (num < 1);
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		roll.array[roll.size++] = rand() % 100 + 1;
	}
}
void output(List roll)
{
	for (int i = 0; i < roll.size; i++)
	{
		cout << roll.array[i] << " ";
	}
}
void sort(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
void intersectionSort(List& roll)
{
	for (int i = 1; i < roll.size; i++)
	{
		for (int j = 0; j != i; j++)
		{
			if (roll.array[i] < roll.array[j])
			{
				sort(roll.array[i], roll.array[j]);
			}
		}
	}
	cout << "!! Sort sucessfully !! " << endl;
}
void selectionSort(List& roll)//min uu tien
{
	for (int i = 0; i < roll.size - 1; i++)
	{
		int indexMin = i;
		for (int j = i + 1; j < roll.size; j++)
		{
			if ( roll.array[indexMin] > roll.array[j])
			{
				indexMin = j;//tim value min
			}
		}
		if (indexMin != i)
			sort(roll.array[indexMin], roll.array[i]);
	}
}
void interchangeSort(List& roll)
{
	for (int i = 0; i < roll.size - 1; i++)
	{
		for (int j = i + 1; j < roll.size; j++)
		{
			if (roll.array[i] > roll.array[j])
				sort(roll.array[i], roll.array[j]);
		}
	}
}
void bubbleSort(List& roll)
{
	for (int i = roll.size - 1; i >= 1; i--)
	{
		for (int j = 0; j != i; j++)
		{
			if (roll.array[j] > roll.array[j + 1])
				sort(roll.array[j], roll.array[j + 1]);
		}
	}
}
void linearSearch(List roll,int x)
{
	int flag = false;
	int index;
	for (int i = 0; i < roll.size; i++)
	{
		if (roll.array[i] == x)
		{
			flag = true;
			index = i + 1;
		}
	}
	if (flag == true)
	{
		cout << ">>	Tim thay gia tri x tai vi tri thu: " << index << endl;
	}
	else
		cout << "!! Khong tim thay gia tri x !! " << endl;
}
bool  binarySearch(int value, int array[], int min, int max)//da xap xep
{
	if (min <= max)
	{
		int middle = (min + max) / 2;
		if (value == max)
			return true;
		else if (value > array[middle])
			return binarySearch(value, array, middle + 1, max);
		else if (value < array[middle])
			return binarySearch(value, array, min, middle - 1);
	}
}
int main()
{
	List roll;
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
		cout << " 6. Bubble sort" << endl;
		cout << " 7. Tim kiem tuan tu" << endl;
		cout << " 8. Tim kiem nhi phan" << endl;
		cout << " =================================" << endl;
		cout << ">> Nhap : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << " 1. Nhap danh sach" << endl;
			input(roll);
			system("pause");
			break;
		}
		case '2':
		{
			cout << " 2. Xuat danh sach" << endl;
			if (roll.size != 0)
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
			if (roll.size != 0)
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
			if (roll.size != 0)
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
			if (roll.size != 0)
			{
				interchangeSort(roll);
			}
			else
				cout << " !! Khong co du lieu de sap xep !! " << endl;
			system("pause");
			break;
		}
		case '6':
		{
			cout << " 6. Bubble sort" << endl;
			if (roll.size != 0)
			{
				bubbleSort(roll);
			}
			else
				cout << " !! Khong co du lieu de sap xep !! " << endl;
			system("pause");
			break;
		}
		case '7':
		{
			cout << " 7. Tim kiem tuan tu" << endl;
			if (roll.size != 0)
			{
				int x;
				cout << ">> Nhap gia tri X de tim kiem: ";
				cin >> x;
				linearSearch(roll, x);
			}
			else
				cout << " !! Khong co du lieu de tim kiem!! " << endl;
			system("pause");
			break;
		}
		case '8':
		{
			cout << " 8. Tim kiem nhi phan" << endl;
			if (roll.size != 0)
			{
				selectionSort(roll);
				int x;
				cout << ">> Nhap gia tri X de tim kiem: ";
				cin >> x;
				bool check = binarySearch(x, roll.array, 0, roll.size - 1);
				if (check == true)
					cout << ">> Co x trong du lieu " << endl;
				else
					cout << " !! Khong tim thay du lieu X " << endl;
			}
			else
				cout << " !! Khong co du lieu de tim kiem!! " << endl;
			system("pause");
			break;
		}
		}
	} while (choice != '0');

	system("pause");
	return 0;
}

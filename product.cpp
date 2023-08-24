#include<iostream>
#include<cmath>
#include<ctime>
#define maxsize 50
using namespace std;
bool validate(int x, int y, int t)
{
	if (t<x || t>y) return true;
	else return false;
}
void inputDSdac(int& n, int arr[])
{
	do
	{ 
		cout << "Nhap so luong phan tu cua mang: ";
		cin >> n;
	} while (validate(1, maxsize, n));
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	cout << "Set up mang da xong!\n";
	system("pause");
}
void addElement(int &x, int arr[], int &n, int &t)
{
	if (n == 50) {
		cout << "Mang da day khong chen them duoc!\n";
		system("pause");
		return;
	} else{
		cout << "Nhap gia tri can them: "; /////2 4 6 8 9 5 8 _
		cin >> x;
		do {
			cout << "Nhap thu tu chen x vao mang: ";
			cin >> t;
		} while (validate(1, n+1, t));
		for (int i = n; i > t - 1; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[t-1] = x;
		n++;
		cout << "Them thanh cong!\n";
	}
}
bool searchFor(int arr[],int &n, int &x)
{
	cout << "Nhap gia tri can tim: ";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (x == arr[i])
		{
			return true;
			break;
		}
	} return false;
}
void outputDSdac(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << " Gia tri "<<i+1<<" : " << arr[i] << "\n";
	}
}
void deleteElement( int arr[], int& n, int& t)
{
		cout << "Nhap thu tu gia tri can xoa: "; /////2 4 6 8 9 5 8 _
		cin >> t;
		if (t > n || t < 1) 
		{
			cout << "Xoa khong hop le!\n";
			system("pause");
			return;
		}
		else 
		{
		   for (int i = t-1; i < n; i++)
			   arr[i] = arr[i + 1];
		    n--;
			cout << "Xoa thanh cong!\n";
	    }
}
void displayDSdac(int& choice) 
{
		cout << "================= DANH SACH DAC ===============\n"
			<< "1. Nhap danh sach.\n"
			<< "2. Xuat danh sach.\n"
			<< "3. Them phan tu vao vi tri thu i danh sach.\n"
			<< "4. Tim kiem phan tu trong danh sach.\n"
			<< "5. Xoa phan tu o vi tri thu i danh sach.\n"
			<< "6. Thoat.\n"
			<< "Chon chuc nang >>> ";
		cin >> choice;
}
void displayMenu(int &choice) 
{
	cout << "================= MENU ===============\n"
			<< "1. Danh sach dac.\n"
			<< "2. Danh sach lien ket.\n"
			<< "3. Stack.\n"
			<< "4. Queue.\n"
			<< "5. Cay nhi phan tim kiem.\n"
			<< "6. Do thi.\n"
			<< "7. Cay bao trum.\n"
			<< "8. Thoat.\n"
			<< "Chon chuc nang >>> ";
	cin >> choice;
}
int main() 
{
	bool input = false;
	int x, t;
	int choice;
	int n;
	int arr[maxsize];
	while(1) 
	{
		system("cls");
		displayMenu(choice);
		switch (choice) 
		{
			case 1:
				do
				{
					system("cls");
					displayDSdac(choice);
					switch (choice) 
					{
						case 1:
							inputDSdac(n, arr);
							input = true;
						  break;
						case 2:
							if (input)
								outputDSdac(n, arr);
							else cout << "Chua nhap du lieu!\n";
							system("pause");
						  break;
						case 3:
							if (input)
								addElement(x, arr, n, t);
							else cout << "Chua nhap du lieu!\n";
							system("pause");
							break;
						case 4:
							if(input){
								if (searchFor(arr,n,x)) 
									cout << "X co trong mang!\n";
								else cout << "X khong co trong mang!\n";
								system("pause");
							}
							break;
						case 5:
							if (input)
								deleteElement(arr, n, t);
							else cout << "Chua nhap du lieu!\n";
							system("pause");
							break;
						case 6:
							break;
						default:
							cout << "Gai tri khong hop le!\n";
							system("pause");
				    }
				} while (choice!=6);
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5: 
			break;
		case 6:
			break;
		case 7: 
			break;
		case 8: 
			return 0;
			break;
		default:
			cout << "Nhap khong hop le!\n";
			system("pause");
		}
	}
	return 0;
}
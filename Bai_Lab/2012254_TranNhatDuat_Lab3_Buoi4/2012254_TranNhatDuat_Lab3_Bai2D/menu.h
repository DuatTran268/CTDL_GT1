#pragma once

void XuatMenu();
int ChonMenu();
void XuLyMenu(int menu, int[MAX], int& n);


void XuatMenu()
{
	cout << "\n============================ He thong chuc nang ==========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu tu file .txt";
	cout << "\n2. Xem du lieu";
	cout << "\n3. QuickSort";
	cout << "\n4. HeapSort";
	cout << "\n5. MergSort";
	cout << "\n==========================================================================\n";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nMoi ban chon chuc nang >> ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}


void XuLyMenu(int stt, sinhvien a[MAX], int& n)
{
	char filename[MAX];
	int kq;
	system("cls");
	switch (stt)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nPress one key to continue!";
		return;
	case 1:
		cout << "\n1. Nhap du lieu tu file .txt";
		cout << "\n1. Tao danh sach sinh vien";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);

		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		break;
	case 3:
		cout << "\n3. QuickSort";
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep bang thuat toan QuickSort";
		QuickSort(a, n);
		Output_Arr(a, n);
		break;
	case 4:
		cout << "\n4. HeapSort";
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep bang thuat toan HeapSort";
		HeapSort(a, n);
		Output_Arr(a, n);
		break;
	case 5:
		cout << "\n5. MergSort";
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep bang thuat toan MergSort";
		MergeSort(a, n);
		Output_Arr(a, n);
		break;
	}
	cout << "\nPress one key to continue!";
}
#pragma once
#include "BSTree.h"
void XuatMenu();
int ChonMenu(int soMenu);


void XuatMenu()
{
	cout << "\n=========================MENU==========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay BST";
	cout << "\n2. Xuat cay BST ";
	cout << "\n3. Xuat so nut cua cay (so luong hoc vien trong danh sach) ";
	cout << "\n4. Xuat so nut la cua cay va thong tin tuong ung cua cac nut";
	cout << "\n5. Chieu cao cua cay ";
	cout << "\n6. Muc cua nut ";
	cout << "\n7. Tim kiem theo ma hoc vien ";
	cout << "\n8. Xoa hoc vien co ma HV cho truoc ";
	cout << "\n========================THE END========================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << soMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BSTree& root)
{
	char* filename;
	int kq;
	KeyType maHV;
	char ten[8];
	BSNode* p;
	KeyType x;
	//=========================
	switch (menu)
	{

	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuonbg trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay BT";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = File_BT(root, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao  BSTree thanh cong.";
		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat BSTree  ";
		cout << "\n\nCay BT hien hanh, xuat theo thu tu truoc (NLR) :\n";
		TieuDe();
		PreOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << endl;
		system("PAUSE");

		cout << "\n\nCay BT hien hanh, xuat theo thu tu giua (LNR) :\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << endl;
		system("PAUSE");


		cout << "\n\nCay BT hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";

		cout << "\n\nDanh sach hoc vien co " << DemSoNut(root) << " hoc vien ";

		break;

	case 3:
		system("CLS");
		cout << "\n3. Xuat so nut cua cay (so luong hoc vien trong danh sach) ";

		cout << "\nCay nhi phan co " << DemSoNut(root) << " nut ";

		cout << "\n\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";

		break;

	case 4:
		system("CLS");
		cout << "\n4. Xuat so nut la cua cay va thong tin tuong ung cua cac nut";

		cout << endl;
		TieuDe();
		kq = DemNutLa(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nCay nhi phan co " << kq << " nut la";

		cout << "\n\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";

		break;

	case 5:
		system("CLS");
		cout << "\n5. Chieu cao cua cay ";

		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nCay nhi phan co " << DemSoNut(root) << " nut ";
		cout << "\nChieu cao cua cay : " << TinhChieuCao(root);

		break;

	case 6:
		system("CLS");
		cout << "\n6. Muc cua nut ";

		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nCay nhi phan co " << DemSoNut(root) << " nut ";
		cout << "\nNhap khoa x (ma hoc vien) : x =  ";
		cin >> x;
		cout << "\nMuc cua nut co khoa : " << x << " : " << TimMuc_x(root, x);

		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo ma hoc vien ";

		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";

		cout << "\nNhap ma HV can tim : maHV = ";
		cin >> maHV;
		p = TimKiem_maHV(root, maHV);

		if (p == NULL)
			cout << "\nTrong DS, khong co hoc vien nao co maHV = " << maHV;
		else
		{
			TieuDe();
			Xuat_HV(p->info);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";
		}
		break;

	case 8:
		system("CLS");
		cout << "\n8. Xoa hoc vien co ma HV cho truoc ";
		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDS hoc vien co " << DemSoNut(root) << " nguoi";
		cout << "\nNhap ma hoc vien : maHV = ";
		cin >> maHV;
		Delete_Khoa(root, maHV);
		break;
	}
}


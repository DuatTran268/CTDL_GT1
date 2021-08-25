#pragma once

void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, BSTree& root);

void XuatMenu()
{
	cout << "\n\t\t============ HE THONG MENU =================";
	cout << "\n\t 0. Thoat khoi chuong trinh";
	cout << "\n\t 1. Tao bang luong nhan vien ";
	cout << "\n\t 2. Xem bang luong nhan vien theo thu tu giua (LNR)";
	cout << "\n\t 3. Tinh so nut cua cay ";
	cout << "\n\t 4. Xuat thong tin nhan vien co ma nhan vien LD19022";
	cout << "\n\t 5. Sua thong tin nhan vien LD18041 thanh 1990";
	cout << "\n\t\t================ THE END ===================";
}

int ChonMenu(int soMenu)
{
	int tuyChon;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n\n\t\t Nhap vao so Menu ( 0 -> " << soMenu << "): ";
		cin >> tuyChon;
		if (0 <= tuyChon && tuyChon <= soMenu)
			break;

	}
	return tuyChon;
}

void XuLyMenu(int tuyChon, BSTree& root)
{
	char* filename;
	int kq;
	//


	system("CLS");
	switch (tuyChon)
	{
	case 0:
		cout << "\Chuong trinh da thoat!!!\n";
		return;
	case 1:
		filename = new char[50];
		do
		{
			cout << "\nNhap vao filename: ";
			cin >> filename;
			kq = ReadFile(root, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao cay BST thanh cong.";
		delete[]filename;
		break;

	case 2:
		cout << "\n 2. Xuat cay BST theo thu tu";
		cout << "\n\n Cay BST xuat theo thu tu giua (LNR) \n";
		TieuDe();
		InOrder(root);
		break;
	case 3:
	{
		cout << "\n 3. Tinh so nut cua cay ";
		
		int kq = Count(root);
		cout << "\n\nTong so nut cua cay la : " << kq << endl;
		break;
	}
	case 4:
	{
		cout << "\n 4. Xuat thong tin nhan vien co ma nhan vien LD19022\n";
		cout << endl << "\tDANH SACH BANG LUONG NHAN VIEN\n";
		TieuDe();
		InOrder(root);
		KeyType x = "LD19022";
		cout << endl << "Thong tin nhan vien co ma LD19022";
		TieuDe();
		XuatThongTinNhanVienTheoMaNhanVien(root, x);
		break;
	}
	case 5:
	{
		cout << "\n5. Sua thong tin nam sinh nhan vien LD18041 thanh 1990\n";
		cout << endl << "\t\t\nDANH SACH BANG LUONG NHAN VIEN\n";
		TieuDe();
		InOrder(root);
		KeyType y = "LD18041";
		int namSinh = 1990;
		SuaThongTinNhanVien(root, y, namSinh);
		cout << endl << "\t\t\\nDANH SACH BANG LUONG NHAN VIEN\n";
		TieuDe();
		InOrder(root);
		break;
	}
	default:
		break;
	}
	cout << endl;
	system("PAUSE");
}
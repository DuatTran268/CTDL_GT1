#pragma once


void XuatMenu()
{
	cout << "\n=================================================== MENU =======================================================";
	cout << "\n0. Thoat chuong trinh!";
	cout << "\n1. Tao danh sach hoc vien";
	cout << "\n2. Xem danh sach hoc vien";
	cout << "\n3. Sap xep danh sach hoc vien tang dan theo ma hoc vien bang thuat giai chon truc tiep";
	cout << "\n4. Sap xep danh sach hoc vien tang dan theo ma hoc vien bang thuat giai QuickSort ";
	cout << "\n5. Sap xep danh sach hoc vien tang theo ten, ten trung nhau tang theo ho, ten va ho trung nhau tang theo ten lot ";
	cout << "\n=================================================== END ========================================================";
}
int ChonMenu(int soMuc)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\n>>>CHON CHUC NANG: ", cin >> stt;
		if (stt >= 0 && stt <= soMuc)
			break;
	}
	return stt;
}
void XuLyMenu(int stt, HocVien HV[MAX], int& n)
{
	bool ktra = false;
	char filename[MAX];

	switch (stt)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh!";
		return;
	case 1:
	{
		cout << "\n1. Tao bang diem mon hoc\n";
		cout << "\nNhap ten file: ", cin >> filename;
		ktra = Nhap_DuLieu(HV, n, filename);
		if (!ktra)
		{
			cout << "\nLoi mo file!";
		}
		else
		{
			cout << "\nNhap du lieu thanh cong!";
			cout << "\nDu lieu vua nhap la:\n";
			Xuat_DanhSachHocVien(HV, n);
		}
		break;
	}

	case 2:
	{
		cout << "\n2. Xem bang diem mon hoc\n";
		Xuat_DanhSachHocVien(HV, n);
		break;
	}
	case 3:
	{
		system("cls");
		cout << "\n3. Sap xep danh sach hoc vien tang dan theo ma hoc vien bang thuat giai chon truc tiep";
		SapTangTheoMaHocVien_SelectionSort(HV, n);
		cout << "\nDanh sach sau khi sap xep:\n";
		Xuat_DanhSachHocVien(HV, n);
		break;

	}
	case 4:
	{
		cout << "\n4. Sap xep danh sach hoc vien tang dan theo ma hoc vien bang thuat giai QuickSort ";
		SapTangTheoMaHocVien_QuickSort(HV, n);
		cout << "\nDanh sach sau khi sap xep:\n";
		Xuat_DanhSachHocVien(HV, n);
		break;
	}
	case 5:
	{
		cout << "\n5. Sap xep danh sach hoc vien tang theo ten, ten trung nhau tang theo ho, ten va ho trung nhau tang theo ten lot ";
		SapTangTheoYeuCau(HV, n);
		cout << "\nDanh sach sau khi sap xep:\n";
		Xuat_DanhSachHocVien(HV, n);
		break;
	}
	}
	cout << "\nEnter any key to back Menu  ";
	_getch();
	
}
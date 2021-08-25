#pragma once

void XuatMenu()
{
	cout << "\n================== MENU ==================";
	cout << "\n0. Thoat chuong trinh!";
	cout << "\n1. Tao danh sach hoc vien";
	cout << "\n2. Xem danh sach hoc vien";
	cout << "\n3. Tim kiem theo lop va so tin chi";
	cout << "\n4. Tim kiem theo ten";  // Hoa trước
	cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
	cout << "\n================== END ===================";
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
			Xuat_DanhSachBangDiem(HV, n);
		}
		break;
	}
	case 2:
	{
		cout << "\n2. Xem bang diem mon hoc\n";
		Xuat_DanhSachBangDiem(HV, n);
		break;
	}
	case 3:
	{
		cout << "\n3. Tim kiem theo lop va so tin chi\n";
		char lop[MAX];
		cout << "Nhap lop: ", cin >> lop;
		int stc;
		cout << "Nhap so tin chi : ", cin >> stc;
		TimKiemTheoLopVaSoTinChi(HV, n, lop, stc);
		break;
	}
	case 4:
	{
		cout << "\n4. Tim kiem theo ten\n";
		char ten[MAX];
		cout << "Nhap ten: ", cin >> ten;
		TimKiemTheoTen(HV, n, ten);
		break;
	}
	case 5:
	{
		cout << "\n5. Tim kiem theo nam sinh va diem trung binh\n";
		unsigned short int namSinh;
		cout << "Nhap nam sinh: ", cin >> namSinh;
		double dtb;
		cout << "Nhap diem trung binh: ", cin >> dtb;
		XuatHocVienTheoNamSinhVaDTB(HV, n, namSinh, dtb);
		break;
	}
	}
	cout << "\nEnter any key to back Menu";
	_getch();
}
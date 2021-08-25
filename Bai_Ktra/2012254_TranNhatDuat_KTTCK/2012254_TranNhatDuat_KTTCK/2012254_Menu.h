#pragma once
void XuatMenu()
{
	cout << "\n=============================== MENU ===============================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach sinh vien";
	cout << "\n2. Xem DS sinh vien";
	cout << "\n3. Sua so tin chi tich luy cua hoc vien co ma hoc vien DL23452 thanh 35";
	cout << "\n4. Xoa hoc vien co ma hoc vien DL42032 ra khoi danh sach hoc vien";
	cout << "\n5. Xuat danh sach hoc vien lop CTK36";
	cout << "\n====================================================================\n";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << " Chon 1 chuc nang trong MENU>>>  ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST& l)
{
	char* filename;
	int kq;
	char ma[10] = "DL23452";
	int soTinNew = 35;
	char maHV[8] = "DL42032";
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\0. Thoat khoi chuonbg trinh\n";
		return;
	case 1:
		cout << "\n1. Tao danh sach sinh vien (Nhap du lieu tu tap tin cho truoc vao BTS )\n";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = TapTin_List(filename, l);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao  BTS thanh cong.";
		delete[] filename;
		break;
	case 2:
		cout << "\n2. Xem DS sinh vien\n";
		cout << "\n\t\tDANH SACH SINH VIEN: \n";
		Xuat_DS_SV(l);
		break;
	case 3:
		cout << "\n3. Sua so tin chi tich luy cua hoc vien co ma hoc vien DL23452 thanh 35\n";
		cout << "\nDanh sach sinh vien hien hanh: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sau khi sua doi tin chi: \n";
		SuaSoTinChi(l, ma, soTinNew);
		Xuat_DS_SV(l);
		break;

	case 4:
		cout << "\n5. Xoa hoc vien co ma hoc vien DL42032 ra khoi danh sach hoc vien\n";
		cout << "\nDanh sach sinh vien hien hanh: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sinh vien sau khi xoa: \n";
		Remove_MaHV(l, maHV);
		Xuat_DS_SV(l);
		break;
	case 5:
		cout << "\n4. Xuat danh sach hoc vien lop CTK36\n";
		cout << "\nDanh sach sinh vien hien hanh: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sinh vien lop CTK36: \n";
		Xuat_DS_SV_Lop_CTK36(l);
		break;
	}
	cout << "\nPress any key to coutinue . . .";
	_getch();
}
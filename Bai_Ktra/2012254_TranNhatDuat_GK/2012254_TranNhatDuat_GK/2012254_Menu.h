#pragma once
void XuatMenu()
{
	cout << "\n*******************************MENU***********************************";
	cout << "\n0. Thoat khoi chuong trinh ";
	cout << "\n1. Tao danh sach hoc vien ";
	cout << "\n2. Xem danh sach hoc vien ";
	cout << "\n3. Su so tin chi tich luy cua hoc vien co ma hoc vien DL23452 thanh 35 ";
	cout << "\n4. Xuat danh sach hoc vien lop CTK36 ";
	cout << "\n5. Xoa cac hoc vien co nam sinh 1995 ra khoi danh sach hoc vien ";
	cout << "\n**********************************END*********************************";

}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Chon chuc 1 nang trong MENU...  ";
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
	int soTinNew;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\0. Thoat khoi chuonbg trinh\n";
		return;
	case 1:
		cout << "\n1. Tao danh sach sinh vien (Chuyen du lieu tu tap tin cho truoc vao DSLKD)\n";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = TapTin_List(filename, l);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao  DSLKD thanh cong.";
		delete[] filename;
		break;
	case 2:
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\n\t\tDANH SACH SINH VIEN: \n";
		Xuat_DS_SV(l);
		break;
	case 3:
		cout << "\n3. Sua so tin chi tich luy cua hoc vien co ma hoc vien DL23452 thanh 35\n";
		cout << "\nDanh sach sinh vien goc: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sau khi sua doi tin chi: \n";
		soTinNew = 35;
		SuaSoTinChi(l, ma, soTinNew);
		Xuat_DS_SV(l);
		break;
	case 4:
		cout << "\n4. Xuat danh sach hoc vien lop CTK36\n";
		cout << "\nDanh sach sinh vien goc: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sinh vien lop CTK36: \n";
		Xuat_DS_SV_Lop_CTK36(l);
		break;
	case 5:
		cout << "\n5. Xoa tat cac hoc vien co nam sinh 1995 ra khoi danh sach hoc vien\n";
		cout << "\nDanh sach sinh vien goc: \n";
		Xuat_DS_SV(l);
		cout << "\n\nDanh sach sinh vien sau khi xoa: \n";
		Remove_NamSinh(l, 1995);
		Xuat_DS_SV(l);
		break;
	}
	cout << "\nPress one key to coutinue . . .";
	_getch();
}


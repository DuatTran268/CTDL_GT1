void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int stt, int n);


void XuatMenu()
{
	cout << "\n--------------------MENU---------------------------";
	cout << "\n0. Thoat chuong trinh ";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
		//Tim kiem
	cout << "\n3. Tim x - Co / Khong";
	cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
		//Chen
	cout << "\n7. Chen x vao dau danh sach";
	cout << "\n8. Chen x vao cuoi danh sach";
	cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
	cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
		//Huy
	cout << "\n11. Huy nut dau danh sach";
	cout << "\n12. Huy nut cuoi danh sach";
	cout << "\n13. Huy nut dau tien co x";
	cout << "\n14. Huy nut cuoi cung co x";
	cout << "\n15. Huy tat ca cac nut co x";
	cout << "\n16. Huy toan bo danh sach";
		//Sap xep
	cout << "\n17. Sap tang - Chon truc tiep(hoan doi du lieu)";
	cout << "\n18. Sap tang - Chon truc tiep(hoan doi lien ket)";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Chon mot chuc nang MENU  ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int stt, LIST & l)
{
	system("CLS");
	char filename[MAX];
	dulieu x, y;
	NODE* p;
	int kq;
	LIST l1;
	switch (stt)
	{
	case 0:
		system("cls");
		cout << "\n0.Thoat khoi chuong trinh";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = File_List(filename, l);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << "\nDanh sach nhap co " << SoNut(l) << " phan tu : \n\n";
		XuatDS(l);
		cout << endl;
		break;
		
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu";
		cout << "\nDanh sach l co " << SoNut(l) << " phan tu : \n";
		XuatDS(l);
		cout << endl;
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim x - Co / Khong";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		p = Search_First(l, x);
		if (p != NULL)
			cout << endl << x << " co khong danh sach";
		else
			cout << endl << x << " khong co khong danh sach";
		cout << endl;
		break;

	case 4:
		system("cls");
		cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Node_x_First(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien dau tien trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Node_x_End(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien cuoi cung trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 6:
		system("cls");
		cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		Search_Node_x(l, x);
		cout << endl;
		break;
		//................Chen.......................

	case 7:
		system("cls");
		cout << "\n7. Chen x vao dau danh sach";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x : ";
		cin >> x;
		InsertHead(l, x);
		cout << "\nDanh sach da chen " << x << " vao dau danh sach:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;

	case 8:
		system("cls");
		cout << "\n8. Chen x vao cuoi danh sach";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x : ";
		cin >> x;
		InsertTail(l, x);
		cout << "\nDanh sach da chen " << x << " vao cuoi danh sach:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;

	case 9:
		system("cls");
		cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nNhap y can tim kiem : ";
		cin >> y;
		Insert_x_After_first_y(l, y, x);
		cout << "\nDanh sach da chen " << x << " vao danh sach sau vi tri dau tien " << y << " xuat hien:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 10:
		system("cls");
		cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nNhap y can tim kiem : ";
		cin >> y;
		Insert_x_After_End_y(l, y, x);
		cout << "\nDanh sach da chen " << x << " vao DS sau vi tri dau tien " << y << " xuat hien:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;

	case 11:
		system("cls");
		cout << "\n11. Huy nut dau danh sach";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveHead(l);
		cout << "\nDanh sach sau khi huy nut dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;

	case 12:
		system("cls");
		cout << "\n12. Huy nut cuoi danh sach";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveTail(l);
		cout << "\nDanh sach sau khi huy nut cuoi :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;

	case 13:
		system("cls");
		cout << "\n13. Huy nut dau tien co x";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		kq = RemoveNode_First(l, x);
		if (!kq)
			cout << endl << x << " khong co trong danh sach\n";
		else
		{
			cout << "\nDanh sach sau khi huy nut dau tien co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;

	case 14:
		system("cls");
		cout << "\n14. Huy nut cuoi cung co x";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		kq = RemoveNode_End(l, x);
		if (!kq)
			cout << endl << x << " khong co trong danh sach\n";
		else
		{
			cout << "\nDanh sach sau khi huy nut dau tien co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
		;

	case 15:
		system("cls");
		cout << "\n15. Huy tat ca cac nut co x";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		if (!RemoveNode_First(l, x))
		{
			cout << "\nKhong co " << x << " trong danh sach, danh sach khong doi\n";
		}
		else
		{
			Remove_x(l, x);
			cout << "\nDanh sach sau khi huy cac nut co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
	case 16:
		system("cls");
		cout << "\n16. Huy toan bo danh sach";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveList(l);
		cout << endl << "Danh sach sau khi huy tat ca cac phan tu:\n";
		XuatDS(l);
		cout << "\nPhuc hoi lai danh sach nhu truoc khi huy";
		Copy(l, l1);
		cout << "\nDanh sach da phuc hoi :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		break;
	case 17:
		system("cls");	
		cout << "\n17. Sap tang - Chon truc tiep(hoan doi du lieu)";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l1);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l1) << " phan tu.\n";
		List_Selection_Sort1(l1);
		cout << endl << "Danh sach sau khi sap tang:\n";
		XuatDS(l1);
		cout << endl;
		break;

	case 18:
		system("cls");
		cout << "\n18. Sap tang - Chon truc tiep(hoan doi lien ket)";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l1);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l1) << " phan tu.\n";
		system("PAUSE");
		List_Selection_Sort2(l1);
		cout << endl << "Danh sach sau khi sap tang:\n";
		XuatDS(l1);
		cout << endl;
		break;

	}
	cout << "\nPress one key to continue!";
}
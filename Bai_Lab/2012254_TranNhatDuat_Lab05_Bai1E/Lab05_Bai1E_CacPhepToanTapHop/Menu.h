
void XuatMenu()
{
	cout << "\n----------------- Menu ------------------\n";
	cout << "\n0. de thoat chuong trinh!";
	cout << "\n1. de nhap du lieu tu file";
	cout << "\n2. de xem du lieu";
	cout << "\n3. de giao 2 tap hop";
	cout << "\n4. de hop 2 tap hop";
	cout << "\n5. de hieu 2 tap hop";
	cout << "\n6. de hieu doi xung 2 tap hop";
	cout << "\n7. de tich Descartes 2 tap hop";
	cout << "\n8. de kiem tra phan tu co thuoc vao tap hop";
	cout << "\n9. de kiem tra quan he bao ham giua 2 tap";
	cout << "\n10. de tinh luc luong tap hop";
	cout << "\n-------------------END--------------------";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\n Chon chuc nang MENU >> ";
		cin >> stt;
		if (stt >= 0 && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int stt, LIST& a, LIST& b)
{
	LIST ketQua;
	CreatList(ketQua);
	int x;

	char filenameA[10] = "A.txt";
	char filenaemB[10] = "B.txt";

	system("cls");
	switch (stt)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Nhap du lieu tu tap tin\n";
		FileReader(filenameA, a);
		FileReader(filenaemB, b);
		cout << "\nDu lieu A - B hien hanh...\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		break;
	case 2:
		cout << "\n2. Xem du lieu tap hop\n";
		cout << "\nDu lieu A - B hien hanh...\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		break;
	case 3:
		cout << "\n3. Giao 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA n B = ";
		ketQua = Giao2TapHop(a, b);
		Output(ketQua);
		break;
	case 4:
		cout << "\n4. Hop 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA u B = ";
		ketQua = Hop2TapHop(a, b);
		Output(ketQua);
		break;
	case 5:
		cout << "\n5. Hieu 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA \\ B = ";
		ketQua = Hieu2TapHop(a, b);
		Output(ketQua);
		break;
	case 6:
		cout << "\n6. Hieu doi xung 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA /\\ B = ";
		ketQua = HieuDanhSach2TapHop(a, b);
		Output(ketQua);
		break;
	case 7:
		cout << "\n7. Tich Descartes 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nA x B = \n";
		TichDescrates(a, b);
		break;
	case 8:
		cout << "\n8. Kiem tra phan tu co thuoc vao tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nNhap phan tu x = ";
		cin >> x;
		if (CheckDependent(a, x) && CheckDependent(b, x))
			cout << "\nPhan tu x thuoc 2 tap hop A va B";
		else if (CheckDependent(a, x))
			cout << "\nPhan tu x thuoc tap hop A";
		else if (CheckDependent(b, x))
			cout << "\nPhan tu x thuoc tap hop B";
		else if (!(CheckDependent(a, x) && CheckDependent(b, x)))
			cout << "\nPhan tu x khong thuoc 2 tap hop A va B";
		break;
	case 9:
		cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		if (RelationshipTest(a, b) && RelationshipTest(b, a))
			cout << "\nTap hop a bang tap hop b";
		else if (RelationshipTest(a, b))
			cout << "\nTap hop a bao ham trong tap hop b";
		else if (RelationshipTest(b, a))
			cout << "\nTap hop b bao ham trong tap hop a";
		else cout << "\nHai tap hop khong bao ham lan nhau";;
		break;
	case 10:
		cout << "\n10. Tinh luc luong tap hop\n";
		cout << "\nTap hop A = ";
		Output(a);
		cout << "\nTap hop B = ";
		Output(b);
		cout << "\nLuc luong cua tap hop a : " << LucLuongTapHop(a);
		cout << "\nLuc luong cua tap hop b : " << LucLuongTapHop(b);
		break;
	}
	cout << "\nPress one key to coutinue . . .";
	_getch();
}
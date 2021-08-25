#pragma once
void XuatMenu()
{
	cout << "\n================He thong menu==================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay BST";
	cout << "\n2. Xuat cay BST theo thu tu truoc, giua, cuoi";
	cout << "\n3. Xuat cay theo chieu sau";
	cout << "\n4. Xuat cay theo chieu rong";
	cout << "\n5. Xuat cay theo tung muc";
	cout << "\n=====================END=======================";
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
void XuLyMenu(int menu, BSTree& root)
{
	char* filename;
	int kq;
	KeyType x, y;
	BSTree p;
	switch (menu)
	{

	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay BST";
		filename = new char[50];
		cout << "\nTen tap tin : filename = ";
		_flushall();
		cin >> filename;
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen du lieu file " << filename << " vao cay BST";
		else
			cout << "\nKhong thanh cong!!!";

		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat cay BST theo thu tu truoc, giua, cuoi";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n";
		PreOrder(root);
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		PosOrder(root);
		break;
	case 3:
		system("CLS");
		cout << "\n\nXuat BST theo chieu sau :\n";
		DFS(root);
		break;
	case 4:
		system("CLS");
		cout << "\n\nXuat BST theo chieu rong :\n";
		BFS(root);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Xuat cay theo tung muc";
		BFS_TheoMuc(root);
		break;

	}
}


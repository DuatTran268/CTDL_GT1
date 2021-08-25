#pragma once
//============================================

//khai bao nguyen mau
int DemSoNut(BSTree root);
int DemNutLa(BSTree root);
int TinhMax(int a, int b);
int TinhChieuCao(BSTree root);

BSTree TimKiem_maHV(BSTree root, KeyType x);
int TimMuc_x(BSTree root, KeyType x);

hocvien DeleteMin(BSTree& root);
int DeleteNode(hocvien  x, BSTree& root);
void Delete_Khoa(BSTree& root, KeyType x);
//============================================
//Dem so nut : So luong hoc vien trong danh sach
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);

}
//============================================
//Dem so nut la
int DemNutLa(BSTree root)
{
	int soNutLa;
	if (root == NULL)
		soNutLa = 0;
	else
		if (root->left == NULL && root->right == NULL)
		{
			Xuat_HV(root->info);
			soNutLa = 1;
		}
		else
			soNutLa = DemNutLa(root->left) + DemNutLa(root->right);

	return soNutLa;
}
//----------------------------------
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

//Chieu cao cua cay
int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else
		if (root->left == NULL && root->right == NULL)
			h = 0;
		else
			h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
}

//Tim kiem hoc vien theo maHV :
BSTree TimKiem_maHV(BSTree root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maHV, x) == 0) //Tim thay x 
			return root;
		else
			if (strcmp(root->info.maHV, x) < 0)
				return TimKiem_maHV(root->right, x); //tim x trong cay con phai
			else
				return TimKiem_maHV(root->left, x); //tim x trong cay con trai
	}
	return NULL; //khong co
}


//Tim muc cua x : hoc vien xac dinh boi khoa x
int TimMuc_x(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (strcmp(T->info.maHV, x) == 0)
			return muc;
		else
		{
			muc++;
			if (strcmp(T->info.maHV, x) > 0)
				T = T->left;
			else
				T = T->right;
		}
	}
	return -1;//T rong, hoac khong co nut chua x
}
//==================================
//Huy nut co gia tri nho nhat cua cay con phai cua root
//Input root
//Output : root (da xoa duoc nut co gia tri nho nhat cua cay con phai root
//          x; khoa cua nut bi xoa

hocvien DeleteMin(BSTree& root)
{
	hocvien k;
	if (root->left == NULL)
	{
		k = root->info;
		root = root->right;
		return k;
	}
	else
		return DeleteMin(root->left);
}


//Huy mot nut co khoa cho truoc ra khoi cay : nut the mang la phan tu nho nhat cua cay cay con phai
//Input : x, root
//Output :  1, root (cay BST ket qua root) neu thanh cong
//			0; khong thanh cong

int DeleteNode(hocvien  x, BSTree& root)
{
	if (root != NULL)
	{
		if (strcmp(x.maHV, root->info.maHV) < 0)
			return DeleteNode(x, root->left);
		else
			if (strcmp(x.maHV, root->info.maHV) > 0)
				return DeleteNode(x, root->right);
			else //x  == root->key
				if ((root->left == NULL) && (root->right == NULL)) //khong co con trai, khong co con phai
					root = NULL;
				else
					if (root->left == NULL) //co 1 con : con phai, khong co con trai
						root = root->right;
					else
						if (root->right == NULL) //co 1 con : con trai, khong co con phai
							root = root->left;
						else //co ca 2 con trai, phai
							root->info = DeleteMin(root->right); //Huy nut co gia tri nho nhat cua cay con phai x
		return 1; //Thanh cong
	}
	return 0;//khong thanh cong
}

//Huy nut co khoa cho truoc
void Delete_Khoa(BSTree& root, KeyType x)
{
	BSTree p;
	p = TimKiem_maHV(root, x);
	if (p == NULL)
	{
		cout << "\nKhong co hoc vien nao co ma hoc vien la " << x;
		cout << endl;
		system("PAUSSE");
		return;
	}

	if (DeleteNode(p->info, root) == 0)
		cout << "\nHuy nut khong thanh cong";
	else
	{
		cout << "\nDa huy nut co khoa " << x;
		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n|";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << "|";
		cout << "\nDS hoc vien con lai co " << DemSoNut(root) << " nguoi";
	}
}

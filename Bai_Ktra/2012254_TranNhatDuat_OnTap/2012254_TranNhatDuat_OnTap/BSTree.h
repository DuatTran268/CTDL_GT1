#pragma once
//Thu vien dinh nghia BST, cac thao tac he thong, nhap, xuat
#define MAXCOT 73
//DN kieu truong khoa cua du lieu (thanh phan di lieu cua nut)
typedef char KeyType[8];
//Dinh nghia kieu thanh phan du lieu cua nut
struct hocvien
{
	KeyType maHV; //key
	char hoHV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int	tichLuy;
};

//Kieu cac nut
struct BSNode
{
	hocvien info;
	BSNode* left;
	BSNode* right;
};

//Kieu BSTree
typedef BSNode* BSTree;
//----------------------------------

BSNode* CreateNode(hocvien x);
void CreateBST(BSTree& root);
int InsertNode(BSTree& root, hocvien x);


int File_BT(BSTree& root, char* filename);
void TieuDe();
void Xuat_HV(hocvien p);


//============================================
//Cai dat cac ham he thong

//Tao nut moi voi x cho truoc
BSNode* CreateNode(hocvien x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//----------------------------------

//Khoi tao cay BSTree rong
void CreateBST(BSTree& root)
{
	root = NULL;
}

//----------------------------------
//Them x vao cay BST

int InsertNode(BSTree& root, hocvien x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (_strcmpi(root->info.maHV, x.maHV) == 0)
			return 0; // x da co san
		if ((_strcmpi(root->info.maHV, x.maHV) > 0))
			return  InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}//root == NULL

	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1; //thanh cong
}
//============================================
//Cai dat cac ham nhap, xuat

//Tao BSTree tu file - cai dat danh sach hoc vien bang cay nhi phan tim kiem
int File_BT(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;

	int kq;
	CreateBST(root);
	hocvien x;

	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.dtb;
		in >> x.tichLuy;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
//----------------------------------

//Xuat tieu de
void TieuDe()
{
	int i;
	cout << endl;
	cout << "|";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << "|";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << '|'
		<< setw(8) << "maHV"
		<< '|'
		<< setw(10) << "Ho"
		<< setw(10) << "Tenlot"
		<< setw(10) << "Ten"
		<< '|'
		<< setw(8) << "Lop"
		<< '|'
		<< setw(6) << "NS"
		<< '|'
		<< setw(6) << "DTB"
		<< '|'
		<< setw(10) << "TichLuy"
		<< '|';
	cout << "\n";

	cout << "|";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << "|";
}
//----------------------------------
//Xuat 1 hoc vien
void Xuat_HV(hocvien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(8) << p.maHV
		<< '|'
		<< setw(10) << p.hoHV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< '|'
		<< setw(8) << p.lop
		<< '|'
		<< setw(6) << p.namSinh
		<< '|'
		<< setw(6) << setprecision(2) << p.dtb << ':'
		<< setw(10) << p.tichLuy
		<< '|';
}

//============================================
//Cai dat cac ham duyet cay

//Duyet va Xuat cay theo thu tu truoc : NLR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_HV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//----------------------------------

//Duyet va Xuat cay theo thu tu giua : LNR
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_HV(root->info);
		InOrder(root->right);
	}
}
//----------------------------------

//Duyet va Xuat cay theo thu tu sau : LRN
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_HV(root->info);
	}
}
//----------------------------------



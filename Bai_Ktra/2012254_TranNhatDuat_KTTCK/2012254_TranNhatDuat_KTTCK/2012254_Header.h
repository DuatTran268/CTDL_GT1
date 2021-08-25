#pragma once
#define MAXCOT 73

typedef char KeyType[8];

struct hocvien
{
	KeyType maHV;
	char ho[10];
	char tenLot[10];
	char ten[10];
	char lop[5];
	int namSinh;
	double diemTB;
	int soTin;
};

struct BSNode
{
	hocvien info;
	BSNode* left;
	BSNode* right;
};

typedef BSNode* BSTree;

void KeNgang(char kt);

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

void CreateBST(BSTree& root)
{
	root = NULL;
}

int InsertNode(BSTree& root, hocvien x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (strcmp(root->info.maHV, x.maHV) == 0)
			return 0; // x da co san
		if ((strcmp(root->info.maHV, x.maHV) > 0))
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}//root == NULL 
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1; //thanh cong
}

int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maHV;
	int kq;
	CreateBST(root);
	hocvien x;
	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.diemTB;
		in >> x.soTin;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

//Xuat tieu de
void TieuDe()
{
	KeNgang('=');
	cout << "|\n";
	cout << setiosflags(ios::left);
	cout << '|'
		<< setw(8) << "Ma SV"
		<< '|'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten lot"
		<< setw(10) << "Ten"
		<< '|'
		<< setw(8) << "Lop"
		<< '|'
		<< setw(6) << "NS"
		<< '|'
		<< setw(6) << "DTB"
		<< '|'
		<< setw(10) << "Tin Chi"
		<< '|';
	KeNgang('=');
	cout << "|";
}
//Xuat 1 hoc vien
void Xuat_HV(hocvien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(8) << p.maHV
		<< '|'
		<< setw(10) << p.ho
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< '|'
		<< setw(8) << p.lop
		<< '|'
		<< setw(6) << p.namSinh
		<< '|'
		<< setw(6) << setprecision(2) << p.diemTB
		<< '|'
		<< setw(10) << p.soTin
		<< '|';
}
//Xuat cay theo thu tu truoc : NLR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_HV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//Xuat cay theo thu tu giua : LNR
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_HV(root->info);
		InOrder(root->right);
	}
}
//Xuat cay theo thu tu sau : LRN
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_HV(root->info);
	}
}
void KeNgang(char kt)
{
	cout << "\n|";
	for (int i = 1; i <= MAXCOT; i++)
		cout << kt;
}
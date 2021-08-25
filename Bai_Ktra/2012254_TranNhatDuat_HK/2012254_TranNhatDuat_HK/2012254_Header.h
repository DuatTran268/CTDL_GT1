#pragma once
#define	MAX_COT 58

typedef char KeyType[8];
// Cấu trúc dữ liệu học viên
struct NhanVien
{
	KeyType maNhanVien;
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	long luong;
};

struct BSNode
{
	NhanVien info;
	BSNode* pLeft;
	BSNode* pRight;
};

typedef BSNode* BSTree;

// Khởi tạo node
BSNode* CreateNode(NhanVien x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->pLeft = p->pRight = NULL;
	}
	return p;
}

// Thêm node vào cây
int InsertNode(BSTree& root, NhanVien x)
{
	// Trường hợp cây đã tồn tại phần tử
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNhanVien, x.maNhanVien) == 0)
			return 0;
		if (_strcmpi(root->info.maNhanVien, x.maNhanVien) < 0)
			return InsertNode(root->pRight, x);
		else
			return InsertNode(root->pLeft, x);
	}
	// Trường hợp cây rỗng
	root = CreateNode(x); // Khởi tạo Node cho cây
	if (root == NULL) return -1;
	return 1;
}

// Đọc dữ liệu từ file
int ReadFile(BSTree& root, char* file)
{
	ifstream in(file);
	if (!in) return 0;
	root = NULL;
	int kq;
	NhanVien x;
	while (!in.eof())
	{
		in >> x.maNhanVien;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.namSinh;
		in >> x.luong;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1) return 0;
	}
	in.close();
	return 1;
}

void KeNgang(char kt)
{
	cout << '|';
	for (int i = 1; i <= MAX_COT; i++)
		cout << kt;
	cout << '|';
}
void TieuDe()
{
	cout << endl;
	KeNgang('=');
	cout << setiosflags(ios::left) << endl
		<< '|'
		<< setw(8) << "Ma NV"
		<< '|'
		<< setw(8) << "Ho"
		<< '|'
		<< setw(8) << "Ten lot"
		<< '|'
		<< setw(8) << "Ten"
		<< '|'
		<< setw(8) << "Nam sinh"
		<< '|'
		<< setw(13) << "Luong"
		<< '|' << endl;
	KeNgang('=');
}
void XuatNV(NhanVien p)
{
	cout << setiosflags(ios::left) << endl
		<< '|'
		<< setw(8) << p.maNhanVien
		<< '|'
		<< setw(8) << p.ho
		<< '|'
		<< setw(8) << p.tenLot
		<< '|'
		<< setw(8) << p.ten
		<< '|'
		<< setw(8) << p.namSinh
		<< '|'
		<< setw(13) << setprecision(2) << setiosflags(ios::fixed) << p.luong
		<< '|' << endl;
	KeNgang('-');
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->pLeft);
		XuatNV(root->info);
		InOrder(root->pRight);
	}
}
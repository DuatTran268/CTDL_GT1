#pragma once
#define MAXCOT 73
struct SinhVien
{
	char maSV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char lop[5];
	int namSinh;
	double diemTB;
	int soTin;
};

struct tagNode
{
	SinhVien info;
	tagNode* pNext;
};
typedef struct tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(SinhVien x)
{
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreateList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}

void InsertHead(LIST& l, SinhVien x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (l.pHead == NULL) //DS rong
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead; //chen vao dau DS
		l.pHead = new_ele;
	}
}

void InsertTail(LIST& l, SinhVien x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("CLS");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

// Nhap tap tin -> list
int TapTin_List(char* filename, LIST& l)
{
	SinhVien x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreateList(l);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.diemTB;
		in >> x.soTin;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}
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
	cout << "\n";

	cout << "|";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << "|";
}

//Xuat 1 hoc vien
void Xuat_SV(SinhVien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< '|'
		<< setw(8) << p.maSV
		<< '|'
		<< setw(10) << p.ho
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< '|'
		<< setw(8) << p.lop
		<< '|'
		<< setw(6) << p.namSinh
		<< '|'
		<< setw(6) << setprecision(2) << p.diemTB << '|'
		<< setw(10) << p.soTin
		<< '|';
}


void Xuat_DS_SV(LIST l)
{
	NODE* p = l.pHead;
	if (IsEmpty(l))
	{
		cout << "\nDanh sach rong!";
		return;
	}

	TieuDe();
	while (p != NULL)
	{
		Xuat_SV(p->info);
		p = p->pNext;
	}
}
void SuaSoTinChi(LIST l, char maSV[10], int soTinChi)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (_strcmpi(maSV, p->info.maSV) == 0)
			p->info.soTin = soTinChi;
		p = p->pNext;
	}
}
void Xuat_DS_SV_Lop_CTK36(LIST l)
{
	NODE* p = l.pHead;
	if (IsEmpty(l))
	{
		cout << "\nDanh sach rong!";
		return;
	}
	TieuDe();
	while (p != NULL)
	{
		if (_strcmpi(p->info.lop, "CTK36") == 0)
		{
			Xuat_SV(p->info);
		}
		p = p->pNext;
	}
}
int RemoveNode_First(LIST& l, int namSinh)
{
	NODE* p = l.pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->info.namSinh == namSinh)
			break;
		q = p; p = p->pNext;
	}
	if (p == NULL)
		return 0;
	//xoa nut sau q
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q; //xoa nut cuoi
		q->pNext = p->pNext;
	}
	else //xoa nut dau
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
void Remove_NamSinh(LIST& l, int namSinh)
{
	while (RemoveNode_First(l, namSinh));
}
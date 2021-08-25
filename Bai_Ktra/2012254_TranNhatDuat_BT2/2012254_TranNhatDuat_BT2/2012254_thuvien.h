#pragma once


// Khai bao hang
#define MAX 100
#define DONGKE 67

struct HocVien
{
	char maHV[8];
	char hoHV[8];
	char tenLotHV[8];
	char tenHV[8];
	char lop[6];
	unsigned short int namSinh;
	double dtb;
	int soTinChiTichLuy;
};
// Prototype
bool Nhap_DuLieu(HocVien HV[MAX], int& n, char* filename);
void Xuat_KeNgang(char kytu);
void Xuat_TieuDe();
void Xuat_ThongBao(int tong);
void Xuat_HocVien(HocVien hv);
void Xuat_DanhSachHocVien(HocVien HV[MAX], int n);
void SapTangTheoYeuCau(HocVien HV[MAX], int n);
void SapTangTheoMaHocVien_SelectionSort(HocVien HV[MAX], int n);
void Partion(HocVien HV[MAX], int left, int right);
void SapTangTheoMaHocVien_QuickSort(HocVien HV[MAX], int n);


// Function
bool Nhap_DuLieu(HocVien HV[MAX], int& n, char* filename)
{
	ifstream Nhap(filename);

	if (!Nhap)
		return false;
	else
	{
		n = 0;
		while (!Nhap.eof())
		{
			Nhap >> HV[n].maHV;
			Nhap >> HV[n].hoHV;
			Nhap >> HV[n].tenLotHV;
			Nhap >> HV[n].tenHV;
			Nhap >> HV[n].lop;
			Nhap >> HV[n].namSinh;
			Nhap >> HV[n].dtb;
			Nhap >> HV[n].soTinChiTichLuy;
			n++;
		}
		Nhap.close();
		return true;
	}
}
void Xuat_KeNgang(char kytu)
{
	cout << setiosflags(ios::left) << '|';
	for (int i = 0; i < DONGKE; i++)
	{
		cout << kytu;
	}
	cout << '|';
}
void Xuat_TieuDe()
{
	Xuat_KeNgang('*');
	cout << "\n" << setiosflags(ios::left) << '|'
		<< setw(8) << "MaHV" << '|'
		<< setw(8) << "Ho" << '|'
		<< setw(8) << "Ten lot" << '|'
		<< setw(8) << "Ten" << '|'
		<< setw(6) << "Lop" << '|'
		<< setw(12) << "Nam sinh" << '|'
		<< setw(5) << "DTB" << '|'
		<< setw(5) << "STC" << '|' << "\n";
	Xuat_KeNgang('-');
}
void Xuat_ThongBao(int tong)
{
	cout << "\n" << setiosflags(ios::left) << '|'
		<< setw(40) << "Tong Hoc Vien trong danh sanh tren:"
		<< setw(27) << tong << '|' << "\n";
	Xuat_KeNgang('*');
}
void Xuat_BangDiem(HocVien hv)
{
	cout << "\n" << setiosflags(ios::left) << '|'
		<< setw(8) << hv.maHV << '|'
		<< setw(8) << hv.hoHV << '|'
		<< setw(8) << hv.tenLotHV << '|'
		<< setw(8) << hv.tenHV << '|'
		<< setw(6) << hv.lop << '|'
		<< setw(12) << hv.namSinh << '|'
		<< setw(5) << hv.dtb << '|'
		<< setw(5) << hv.soTinChiTichLuy << '|' << "\n";
	Xuat_KeNgang('-');
}
void Xuat_DanhSachHocVien(HocVien HV[MAX], int n)
{
	Xuat_TieuDe();
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		Xuat_BangDiem(HV[i]);
		dem++;
	}
	Xuat_ThongBao(dem);
}
void SapTangTheoYeuCau(HocVien HV[MAX], int n)
{
	// Tang theo ten
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(HV[i].tenHV, HV[j].tenHV) > 0)
				swap(HV[i], HV[j]);
	// Tang theo ho
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(HV[i].tenHV, HV[j].tenHV) == 0 &&
				_strcmpi(HV[i].hoHV, HV[j].hoHV) > 0)
				swap(HV[i], HV[j]);
	// Tang theo ten lot
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(HV[i].tenHV, HV[j].tenHV) == 0 &&
				_strcmpi(HV[i].hoHV, HV[j].hoHV) == 0 &&
				_strcmpi(HV[i].tenLotHV, HV[j].tenLotHV) > 0)
				swap(HV[i], HV[j]);
}
void SapTangTheoMaHocVien_SelectionSort(HocVien HV[MAX], int n)
{
	int indexMin;
	for (int i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(HV[j].tenHV, HV[indexMin].tenHV) < 0)
				indexMin = j;
		swap(HV[i], HV[indexMin]);
	}
}
void SapTangTheoMaHocVien_QuickSort(HocVien HV[MAX], int n)
{
	Partion(HV, 0, n - 1);
}
void Partion(HocVien HV[MAX], int left, int right)
{
	int i, j;
	HocVien hv;
	hv = HV[(left + right) / 2];
	i = left; j = right;
	do
	{
		while (_strcmpi(HV[i].tenHV, hv.tenHV) < 0)
			i++;
		while (_strcmpi(HV[j].tenHV, hv.tenHV) > 0)
			j--;
		if (i <= j)
		{
			swap(HV[i], HV[j]);
			i++; j--;
		}
	} while (i <= j);
	if (left < j)
		Partion(HV, left, j);
	if (i < right)
		Partion(HV, i, right);
}

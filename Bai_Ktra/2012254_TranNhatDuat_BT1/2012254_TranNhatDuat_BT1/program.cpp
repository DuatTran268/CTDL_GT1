// thư viện hàm
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

#include "2012254_thuvien.h"
#include "2012254_menu.h"

// Prototype
void ChayChuongTrinh();

// Function
void ChayChuongTrinh()
{
	int stt,
		n,
		soMuc = 5;
	HocVien HV[MAX];

	do
	{
		stt = ChonMenu(soMuc);
		XuLyMenu(stt, HV, n);
	} while (stt > 0);
}
int main()
{
	ChayChuongTrinh();
	return 0;
}

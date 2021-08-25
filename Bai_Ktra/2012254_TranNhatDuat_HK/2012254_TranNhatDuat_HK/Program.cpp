#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>


using namespace std;

#include "2012254_Header.h"
#include "2012254_ThuVien.h"
#include "2012254_Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	BSTree root = NULL;
	int tuyChon, soMenu = 5;
	do
	{
		tuyChon = ChonMenu(soMenu);
		XuLyMenu(tuyChon, root);
	} while (tuyChon > 0);
}
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

#include "2012254_Thuvien.h"
#include "2012254_Menu.h"


void ChayChuongTrinh()
{
	LIST l;
	int menu, soMenu = 5;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu > 0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}
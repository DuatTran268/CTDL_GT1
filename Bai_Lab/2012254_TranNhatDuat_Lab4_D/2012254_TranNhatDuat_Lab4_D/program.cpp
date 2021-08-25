#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<iomanip>

using namespace std;

#include"thuvien.h"
#include"menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	
	return 0;
}
void ChayChuongTrinh()
{
	system("cls");
	int soMenu = 18, menu;
	LIST l;
	do
	{
		system("CLS");
		
		menu = ChonMenu(soMenu);
		XuLyMenu(menu,  l);
		system("pause");
	} while (menu > 0);
}




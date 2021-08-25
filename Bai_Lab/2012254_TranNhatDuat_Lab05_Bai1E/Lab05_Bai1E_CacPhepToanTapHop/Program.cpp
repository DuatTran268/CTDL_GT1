#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}
void ChayChuongTrinh()
{
	int stt, soMenu = 10;
	LIST A, B;
	do
	{
		stt = ChonMenu(soMenu);
		XuLyMenu(stt, A, B);
	} while (stt > 0);
}
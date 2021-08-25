#pragma once

#pragma once
int Count(BSTree root)
{
	if (root == NULL)return 0;
	return 1 + Count(root->pLeft) + Count(root->pRight);
}

void XuatThongTinNhanVienTheoMaNhanVien(BSTree root, KeyType maNV)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNhanVien, maNV) == 0)
			XuatNV(root->info);
		XuatThongTinNhanVienTheoMaNhanVien(root->pLeft, maNV);
		XuatThongTinNhanVienTheoMaNhanVien(root->pRight, maNV);
	}
}
void SuaThongTinNhanVien(BSTree& root, KeyType maNV, int namSinh)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNhanVien, maNV) == 0)
			root->info.namSinh = namSinh;
		if (_strcmpi(root->info.maNhanVien, maNV) > 0)
			SuaThongTinNhanVien(root->pLeft, maNV, namSinh);
		else
			SuaThongTinNhanVien(root->pRight, maNV, namSinh);
	}
}
#pragma once
typedef int KeyType; 
struct BSNode
{
	KeyType key;
	BSNode* left; // dia chi trai
	BSNode* right; // dia chi phai
};
typedef BSNode* BSTree;
void CreateBST(BSTree& root); 
BSNode* CreateNode(KeyType x);

int InsertNode(BSTree& root, KeyType x); 
int File_BST(BSTree& root, char* filename);  // Tao tu  file
void PreOrder(BSTree root);//NLR
void InOrder(BSTree root); //LNR
void PosOrder(BSTree root); //LRN


BSNode* CreateNode(KeyType x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
//----------------------------------
//Khoi tao cay BST rong
void CreateBST(BSTree& root)
{
	root = NULL;
}
int InsertNode(BSTree& root, KeyType x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (root->key == x)
			return 0; // x da co san
		if (root->key > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}//root == NULL
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
//Tao cay BST tu file
int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	int kq;
	CreateBST(root);
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
//Xuat cay theo thu tu truoc : NLR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->key << '\t';
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
		cout << root->key << '\t';
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << '\t';
	}
}
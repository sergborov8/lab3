// binar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "locale.h"
#include <iostream>

using namespace std;

class BinTree
{
public:
	static int a, b;
	int m;
	BinTree *left;
	BinTree *right;
	BinTree(int n)
	{
		if (n == 1)
		{
			left = 0;
			right = 0;
		}
		else
		{
			left = new BinTree(n - 1);
			right = new BinTree(n - 1);
		}
		m = rand() % 100;
		if (a > 1)
		{
			cout << m << " ";
			a--;
		}
		else
		{
			cout << m << endl;
			a = a + b - 1;
			b *= 2;
		}
	}
};

void preorder(BinTree *node)
{
	if (node != 0)
	{
		cout << node->m << " ";
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(BinTree *node)
{
	if (node != 0)
	{	inorder(node->left);
		cout << node->m << " ";
		inorder(node->right);
	}
}


void postorder(BinTree *node)
{
	if (node != 0)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->m << " ";
	}
}

int BinTree::a;
int BinTree::b;

void main()
{
	int n;
	setlocale(LC_ALL, "rus");
	cout << "Введите количество уровней бинарного дерева: ";
	cin >> n;
	BinTree::a = 1;
	BinTree::b = 2;
	BinTree *tree = new BinTree(n);
	BinTree *tree1 = new BinTree(n - 1);
	cout << endl << "Обратный обход: ";
	preorder(tree);
	preorder(tree1);
	cout << endl << "Симметричный обход: ";
	inorder(tree);
	inorder(tree1);
	cout << endl << "Прямой обход: ";
	postorder(tree);
	postorder(tree1);
	delete tree;
	delete tree1;
	cout << endl;
	system("pause");
}



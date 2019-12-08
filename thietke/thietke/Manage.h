#include "News.h"
#include<fstream>
using namespace std;

class Manage :
	public News
{
public:
	struct Node
	{
		News data;
		Node* pNext;
	};
	struct List
	{
		Node* pHead;
		Node* pTail;
	};
	List l;
public:
	void init(List&);
	Node* makeNode(News);
	void addHead(List&, Node*);
	void addTail(List&, Node*);
	void readNews(List&);
	void cach(int, ofstream&);
	void ghiVaoFileIn(List);
	void ghivaoFileOut(Node*, ofstream&);
	void displayNews(List);
	void themVaoDau(List&);
	void themVaoCuoi(List&);
	void themVaoViTriBatKy(List&, int);
	void xoaBao(List&, int);
	void suaBao(List&, int, int);
	void timKiem(List& l, int choice);
	void sapXep(List& l, int n);
	void dongTacGia(Node*, ofstream&, string, int&);
	void Menu();
};
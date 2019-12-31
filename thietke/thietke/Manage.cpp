#include "Manage.h"
#include<iostream>
#include<string>
using namespace std;

void Manage::init(List& l)
{
	l.pHead = l.pTail = NULL;
}


Manage::Node* Manage::makeNode(News x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Cap phat that bai!!" << endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void Manage::addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
	
}

void Manage::addTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Manage::readNews(List& l)
{
	ifstream fileIn;
	fileIn.open("../dulieu.txt");
	while (!fileIn.eof()) {
		News bao;
		getline(fileIn, bao.codenews, ','); // doc den dau phay thi dung
		getline(fileIn, bao.namenews, ',');
		getline(fileIn, bao.namemaga, ',');
		getline(fileIn, bao.category, ',');
		getline(fileIn, bao.edition, ',');
		getline(fileIn, bao.publishing, ',');
		getline(fileIn, bao.publishingcom, ',');
		getline(fileIn, bao.mainau, ',');
		getline(fileIn, bao.sameau, ',');
		fileIn >> bao.publishingyear;
		// doc ki tu xuong dong
		string enter;
		getline(fileIn, enter);
		// neu 1 trong cac gia tri cua bao rong thi khong tao node
		if (bao.codenews.length() != 0 && bao.namenews.length() != 0 && bao.namemaga.length() != 0 && bao.category.length() != 0 && bao.edition.length() != 0 && bao.publishing.length() != 0 && bao.publishingcom.length() != 0 && bao.mainau.length() != 0 && bao.publishingyear != 0) {
			Node* p = makeNode(bao);
			addTail(l, p);
		}
	}
	fileIn.close();
}

void Manage::cach(int cach, ofstream& fileOut)
{
	for (int i = 0; i < cach; i++)
	{
		fileOut << " ";
	}
}

void Manage::ghiVaoFileIn(List l)
{
	ofstream fileIn;
	fileIn.open("../dulieu.txt");
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		fileIn << k->data.codenews << ",";
		fileIn << k->data.namenews << ",";
		fileIn << k->data.namemaga << ",";
		fileIn << k->data.category << ",";
		fileIn << k->data.edition << ",";
		fileIn << k->data.publishing << ",";
		fileIn << k->data.publishingcom << ",";
		fileIn << k->data.mainau << ",";
		fileIn << k->data.sameau << ",";
		fileIn << k->data.publishingyear << "\n";
	}
	fileIn.close();
}

void Manage::ghivaoFileOut(Node* k, ofstream& fileOut)
{
	fileOut << "||" << k->data.codenews;
	cach(10 - k->data.codenews.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.namenews;
	cach(28 - k->data.namenews.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.namemaga;
	cach(15 - k->data.namemaga.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.category;
	cach(12 - k->data.category.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.edition;
	cach(11 - k->data.edition.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.publishing;
	cach(12 - k->data.publishing.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.publishingyear << "        ||";
	fileOut << k->data.publishingcom;
	cach(12 - k->data.publishingcom.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.mainau;
	cach(13 - k->data.mainau.length(), fileOut);
	fileOut << "||";
	fileOut << k->data.sameau;
	cach(22 - k->data.sameau.length(), fileOut);
	fileOut << "||" << endl;
	fileOut << "||=====================================================================================================================================================================||" << endl;
}

void Manage::displayNews(List l)
{
	init(l);
	readNews(l);
	ofstream fileOut;
	fileOut.open("../output.txt");
	fileOut << "=========================================================================================================================================================================" << endl;
	fileOut << "||Ma bai bao||         Ten bai bao        ||  Ten tap chi  ||Loai tap chi||So xuat ban||Tap xuat ban||Nam xuat ban||Nha xuat ban||Tac gia chinh||     Dong tac gia     ||" << endl;
	fileOut << "||=====================================================================================================================================================================||" << endl;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
		ghivaoFileOut(k, fileOut);
	fileOut.close();
	cout << "Thanh cong!\n";
}

void Manage::themVaoDau(List& l)
{
	init(l);
	readNews(l);
	News themBao;
	// nhap bao
	News::inputData(themBao);
	// tao node
	Node* p = makeNode(themBao);
	addHead(l, p);
	// luu hay khong luu
	cout << "Ban co muon luu bai bao khong?(0: luu/1: khong luu): ";
	int temp;
	do {
		cin >> temp;
	} while (temp > 1 || temp < 0);
	if (temp == 0)
	{
		ghiVaoFileIn(l);
	}
	system("cls");
}

void Manage::themVaoCuoi(List& l)
{
	init(l);
	readNews(l);
	News themBao;
	// nhap bao
	News::inputData(themBao);
	// tao node
	Node* p = makeNode(themBao);
	addTail(l, p);
	// luu hay khong luu
	cout << "Ban co muon luu bai bao khong?(0: luu/1: khong luu): ";
	int temp;
	do {
		cin >> temp;
	} while (temp > 1 || temp < 0);
	if (temp == 0)
	{
		ghiVaoFileIn(l);
	}
	system("cls");
}

void Manage::themVaoViTriBatKy(List& l, int vt)
{
	init(l);
	readNews(l);
	News themBao;
	News::inputData(themBao);
	int dem = 0;
	Node* h = new Node;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		dem++;
		if (dem == vt)
		{
			Node* p = makeNode(themBao);
			p->pNext = k;
			h->pNext = p;
			break;
		}
		h = k;
	}
	// luu hay khong luu
	cout << "Ban co muon luu bai bao khong?(0: luu/1: khong luu): ";
	int temp;
	do {
		cin >> temp;
	} while (temp > 1 || temp < 0);
	if (temp == 0)
	{
		ghiVaoFileIn(l);
	}
	system("cls");
}

void Manage::xoaBao(List& l, int vt)
{
	init(l);
	readNews(l);
	int dem = 0;
	Node* h = new Node;
	if (vt == 1)
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	else {
		for (Node* k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			if (dem == vt)
			{
				h->pNext = k->pNext;
			}
			h = k;
		}
	}
	// luu hay khong luu
	cout << "Ban co muon luu bai bao khong?(0: luu/1: khong luu): ";
	int temp;
	do {
		cin >> temp;
	} while (temp > 1 || temp < 0);
	if (temp == 0)
	{
		ghiVaoFileIn(l);
	}
	system("cls");
}

void Manage::suaBao(List& l, int vt, int choiceEdit)
{
	init(l);
	readNews(l);
	int dem = 0;
	string codenews, namenews, namemaga, category, edition, publishing, publishingcom, mainau, sameau;
	int publishingyear;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		dem++;
		if (dem == vt)
		{
			switch (choiceEdit)
			{
			case 1:
				fflush(stdin);
				cout << "Nhap ma bai bao can sua: ";
				getline(cin, codenews);
				k->data.codenews = codenews;
				break;
			case 2:
				fflush(stdin);
				cout << "Nhap ten bai bao can sua: ";
				getline(cin, namenews);
				k->data.namenews = namenews;
				break;
			case 3:
				fflush(stdin);
				cout << "Nhap ten tap chi can sua: ";
				getline(cin, namemaga);
				k->data.namemaga = namemaga;
				break;
			case 4:
				fflush(stdin);
				cout << "Nhap loai tap chi can sua: ";
				getline(cin, category);
				k->data.category = category;
				break;
			case 5:
				fflush(stdin);
				cout << "Nhap so xuat ban can sua: ";
				getline(cin, edition);
				k->data.edition = edition;
				break;
			case 6:
				fflush(stdin);
				cout << "Nhap tap xuat ban can sua: ";
				getline(cin, publishing);
				k->data.publishing = publishing;
				break;
			case 7:
				fflush(stdin);
				cout << "Nhap nam xuat ban can sua: ";
				cin >> publishingyear;
				k->data.publishingyear = publishingyear;
				break;
			case 8:
				fflush(stdin);
				cout << "Nhap nha xuat ban can sua: ";
				getline(cin, publishing);
				k->data.publishingcom = publishingcom;
				break;
			case 9:
				fflush(stdin);
				cout << "Nhap tac gia chinh can sua: ";
				getline(cin, mainau);
				k->data.mainau = publishing;
				break;
			case 10:
				fflush(stdin);
				cout << "Nhap dong tac gia can sua: ";
				getline(cin, sameau);
				k->data.sameau = sameau;
				break;
			default:
				break;
			}
		}
	}
	// luu hay khong luu
	cout << "Ban co muon luu bai bao khong?(0: luu/1: khong luu): ";
	int temp;
	do {
		cin >> temp;
	} while (temp > 1 || temp < 0);
	if (temp == 0)
	{
		ghiVaoFileIn(l);
	}
	system("cls");
}
void Manage::dongTacGia(Node* k, ofstream& fileOut, string TGCT, int& dem)
{
	string tacgia;
	int dodai = k->data.sameau.length();
	for (int i = 0; i < dodai; i++)
	{
		if (k->data.sameau[i] == '-')
		{
			if (tacgia == TGCT)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			else
			{
				tacgia = "";
			}
		}
		else
		{
			tacgia += k->data.sameau[i];
			if (i == dodai - 1)
			{
				if (tacgia == TGCT)
				{
					dem++;
					ghivaoFileOut(k, fileOut);
				}
			}
		}
		
	}
}
void Manage::timKiem(List& l, int choice)
{

	string tenBao, tacGiaChinh, DTG, tenTapChi, loaiTapChi;
	int dem = 0, year;
	switch (choice)
	{
	case 1:
		cin.ignore();
		cout << "Moi ban nhap ten bai bao: ";
		getline(cin, tenBao);
		break;
	case 2:
		cin.ignore();
		cout << "Moi ban nhap tac gia chinh: ";
		getline(cin, tacGiaChinh);
		break;
	case 3:
		cin.ignore();
		cout << "Moi ban nhap dong tac gia: ";
		getline(cin, DTG);
		break;
	case 4:
		cin.ignore();
		cout << "Moi ban nhap ten tap chi: ";
		getline(cin, tenTapChi);
		break;
	case 5:
		cin.ignore();
		cout << "Moi ban nhap loai tap chi: ";
		getline(cin, loaiTapChi);
		break;
	case 6:
		cout << "Moi ban nhap nam xuat ban: ";
		cin >> year;
		break;
	default:
		break;
	}
	init(l);
	readNews(l);
	ofstream fileOut;
	fileOut.open("../output.txt");
	fileOut << "=========================================================================================================================================================================" << endl;
	fileOut << "||Ma bai bao||         Ten bai bao        ||  Ten tap chi  ||Loai tap chi||So xuat ban||Tap xuat ban||Nam xuat ban||Nha xuat ban||Tac gia chinh||     Dong tac gia     ||" << endl;
	fileOut << "||=====================================================================================================================================================================||" << endl;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		switch (choice)
		{
		case 1:
			if (k->data.namenews == tenBao)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			break;
		case 2:
			if (k->data.mainau == tacGiaChinh)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			break;
		case 3:
			dongTacGia(k, fileOut, DTG, dem);
			break;
		case 4:
			if (k->data.namemaga == tenTapChi)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			break;
		case 5:
			if (k->data.category == loaiTapChi)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			break;
		case 6:
			if (k->data.publishingyear == year)
			{
				dem++;
				ghivaoFileOut(k, fileOut);
			}
			break;
		default:
			break;
		}
	}
	if (dem == 0) cout << "Khong co bai bao ma ban tim kiem!" << endl;
	else cout << "Da tim thay " << dem << " bai bao ban can!" << endl;
	fileOut.close();
	system("cls");
}

void Manage::sapXep(List& l, int n)
{
	int choice, dem;
	List copyL;
	init(l);
	init(copyL);
	readNews(l);
	copyL = l;
	if (n == 1)
	{
		cout << "1. Tang dan" << endl;
		cout << "2. Giam dan" << endl;
		cout << "Moi ban lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (Node* q = copyL.pHead; q != NULL; q = q->pNext)
			{
				for (Node* p = q->pNext; p != NULL; p = p->pNext)
				{
					if (q->data.namenews.length() >= p->data.namenews.length())  dem = p->data.namenews.length();
					else dem = q->data.namenews.length();
					for (int i = 0; i <= dem - 1; i++)
					{
						if (q->data.namenews[i] > p->data.namenews[i])
							swap(q->data, p->data);
					}
				}
			}
			break;
		case 2:
			for (Node* q = copyL.pHead; q != NULL; q = q->pNext)
			{
				for (Node* p = q->pNext; p != NULL; p = p->pNext)
				{
					if (q->data.namenews.length() >= p->data.namenews.length())  dem = p->data.namenews.length();
					else dem = q->data.namenews.length();
					for (int i = 0; i <= dem - 1; i++)
					{
						if (q->data.namenews[i] < p->data.namenews[i])
							swap(q->data, p->data);
					}
				}
			}
			break;
		default:
			break;
		}
		cout << "Thanh cong!" << endl;
	}
	if (n == 2)
	{
		cout << "1. Tang dan" << endl;
		cout << "2. Giam dan" << endl;
		cout << "Moi ban lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (Node* q = copyL.pHead; q != NULL; q = q->pNext)
			{
				for (Node* p = q->pNext; p != NULL; p = p->pNext)
				{
					if (q->data.publishingyear > p->data.publishingyear)
						swap(q->data, p->data);
				}
			}
			break;
		case 2:
			for (Node* q = copyL.pHead; q != NULL; q = q->pNext)
			{
				for (Node* p = q->pNext; p != NULL; p = p->pNext)
				{
					if (q->data.publishingyear < p->data.publishingyear)
						swap(q->data, p->data);
				}
			}
			break;
		default:
			break;
		}
	}
	ofstream fileOut;
	fileOut.open("../output.txt");
	fileOut << "=========================================================================================================================================================================" << endl;
	fileOut << "||Ma bai bao||         Ten bai bao        ||  Ten tap chi  ||Loai tap chi||So xuat ban||Tap xuat ban||Nam xuat ban||Nha xuat ban||Tac gia chinh||     Dong tac gia     ||" << endl;
	fileOut << "||=====================================================================================================================================================================||" << endl;
	for (Node* k = copyL.pHead; k != NULL; k = k->pNext)
	{
		ghivaoFileOut(k, fileOut);
	}
	fileOut.close();
	system("cls");
}

void Manage::Menu()
{
	init(l);
	int choice, m, pos, posDel, posEdit, choiceAll;
	do
	{
		cout << "=======================================" << endl;
		cout << "||      Phan mem quan ly bao         ||" << endl;
		cout << "||===================================||" << endl;
		cout << "|| 0 ||          Thoat               ||" << endl;
		cout << "|| 1 || Hien thi du lieu cac bai bao ||" << endl;
		cout << "|| 2 ||      Them, sua, xoa          ||" << endl;
		cout << "|| 3 ||  Tim kiem theo ten bai bao   ||" << endl;
		cout << "|| 4 ||          Filter              ||" << endl;
		cout << "|| 5 ||          Sap xep             ||" << endl;
		cout << "=======================================" << endl;
		cout << "What do you want? Pls choose one: ";
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			displayNews(l);
			break;
		case 2:
			system("cls");
			cout << "====================================" << endl;
			cout << "||      Phan mem quan ly bao      ||" << endl;
			cout << "||================================||" << endl;
			cout << "|| 1 ||       Them bai bao        ||" << endl;
			cout << "|| 2 ||       Sua bai bao         ||" << endl;
			cout << "|| 3 ||       Xoa bai bao         ||" << endl;
			cout << "====================================" << endl;
			cout << "What do you want? Pls choose one: ";
			cin >> choiceAll;
			switch (choiceAll) {
			case 1:
				system("cls");
				cout << "====================================" << endl;
				cout << "||      Phan mem quan ly bao      ||" << endl;
				cout << "||================================||" << endl;
				cout << "|| 1 ||      Them vao dau         ||" << endl;
				cout << "|| 2 ||      Them vao cuoi        ||" << endl;
				cout << "|| 3 ||  Them vao vi tri bat ky   ||" << endl;
				cout << "====================================" << endl;
				cout << "What do you want? Pls choose one: ";
				cin >> m;
				switch (m) {
				case 1:
					system("cls");
					themVaoDau(l);
					break;
				case 2:
					system("cls");
					themVaoCuoi(l);
					break;
				case 3:
					system("cls");
					cout << "nhap vi tri can them: " << endl;
					cin >> pos;
					themVaoViTriBatKy(l, pos);
					break;
				default:
					system("cls");
					break;
				}
				break;
			case 2:
				system("cls");
				cout << "Nhap vi tri can sua: ";
				cin >> posEdit;
				cout << "====================================" << endl;
				cout << "||      Phan mem quan ly bao      ||" << endl;
				cout << "||================================||" << endl;
				cout << "|| 1 ||       Ma bai bao          ||" << endl;
				cout << "|| 2 ||       Ten bai bao         ||" << endl;
				cout << "|| 3 ||       Ten tap chi         ||" << endl;
				cout << "|| 4 ||       Loai tap chi        ||" << endl;
				cout << "|| 5 ||       So xuat ban         ||" << endl;
				cout << "|| 6 ||       Tap xuat ban        ||" << endl;
				cout << "|| 7 ||       Nam xuat ban        ||" << endl;
				cout << "|| 8 ||       Nha xuat ban        ||" << endl;
				cout << "|| 9 ||       Tac gia chinh       ||" << endl;
				cout << "||10 ||       Dong tac gia        ||" << endl;
				cout << "====================================" << endl;
				cout << "Nhap muc can chinh sua: ";
				cin >> m;
				switch (m)
				{
				case 1:
					system("cls");
					suaBao(l, posEdit, 1);
					break;
				case 2:
					system("cls");
					suaBao(l, posEdit, 2);
					break;
				case 3:
					system("cls");
					suaBao(l, posEdit, 3);
					break;
				case 4:
					system("cls");
					suaBao(l, posEdit, 4);
					break;
				case 5:
					system("cls");
					suaBao(l, posEdit, 5);
					break;
				case 6:
					system("cls");
					suaBao(l, posEdit, 6);
					break;
				case 7:
					system("cls");
					suaBao(l, posEdit, 7);
					break;
				case 8:
					system("cls");
					suaBao(l, posEdit, 8);
					break;
				case 9:
					system("cls");
					suaBao(l, posEdit, 9);
					break;
				case 10:
					system("cls");
					suaBao(l, posEdit, 10);
					break;
				default:
					cout << "You have entered it incorrectly, please try again!!" << endl;
					break;
				}
				break;
			case 3:
				system("cls");
				cout << "Nhap vi tri can xoa: ";
				cin >> posDel;
				xoaBao(l, posDel);
				break;
			default:
				cout << "You have entered it incorrectly, please try again!!" << endl;
				break;
			}
			break;
		case 3:
			system("cls");
			timKiem(l, 1);
			break;
		case 4:
			system("cls");
			cout << "====================================" << endl;
			cout << "||      Phan mem quan ly bao      ||" << endl;
			cout << "||================================||" << endl;
			cout << "|| 1 ||  Loc theo nam xuat ban    ||" << endl;
			cout << "|| 2 ||  Loc theo tac gia chinh   ||" << endl;
			cout << "|| 3 ||  Loc theo dong tac gia    ||" << endl;
			cout << "|| 4 ||  Loc theo ten tap chi     ||" << endl;
			cout << "|| 5 ||  Loc theo loai tap chi    ||" << endl;
			cout << "====================================" << endl;
			cout << "Moi ban lua chon: ";
			cin >> m;
			switch (m)
			{
			case 1:
				system("cls");
				timKiem(l, 6);
				break;
			case 2:
				system("cls");
				timKiem(l, 2);
				break;
			case 3:
				system("cls");
				timKiem(l, 3);
				break;
			case 4:
				system("cls");
				timKiem(l, 4);
				break;
			case 5:
				system("cls");
				timKiem(l, 5);
				break;
			default:
				break;
			}
			break;
		case 5:
			system("cls");
			cout << "====================================" << endl;
			cout << "||      Phan mem quan ly bao      ||" << endl;
			cout << "||================================||" << endl;
			cout << "|| 1 ||    Theo ten bai bao       ||" << endl;
			cout << "|| 2 ||       Theo nam            ||" << endl;
			cout << "====================================" << endl;
			cout << "Choose this one: ";
			cin >> m;
			switch (m)
			{
			case 1:
				system("cls");
				sapXep(l, 1);
				break;
			case 2:
				system("cls");
				sapXep(l, 2);
				break;
			default:
				break;
			}
			break;
		default:
			cout << "You have entered it incorrectly, please try again!!";
			break;
		}
	} while (choice);

}
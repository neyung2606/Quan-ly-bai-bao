#include "News.h"
#include<iostream>
#include<string>
using namespace std;

News::News()
{
	this->codenews = "A";
	this->namenews = "A";
	this->namemaga = "A";
	this->category = "A";
	this->edition = "A";
	this->publishing = "A";
	this->publishingcom = "A";
	this->mainau = "A";
	this->sameau = "A";
	this->publishingyear = 1999;
}

News::News(string MBB, string TBB, string TTC, string TL, string TB, string NXB, string CTXB, string TGC, string DTG, int Year) :
	codenews(MBB), namenews(TBB), namemaga(TTC), category(TL), edition(TB), publishing(NXB), publishingcom(CTXB), mainau(TGC), sameau(DTG), publishingyear(Year)
{
}


News::~News()
{
}
void validate(News x)
{
	if (x.codenews.length() == 0)
		throw string("Ma bai bao khong duoc de trong!!");
	if (x.codenews.length() > 10)
		throw string("Ma bai bao khong duoc qua 10 ki tu!!");
	if (x.namenews.length() == 0)
		throw string("Ten bai bao khong duoc de trong!!");
	if (x.namenews.length() > 28)
		throw string("Ten bai bao khong duoc qua 28 ki tu!!");
	if (x.namemaga.length() == 0)
		throw string("Ten tap chi khong duoc de trong!!");
	if (x.namemaga.length() > 15)
		throw string("Ten tap chi khong duoc qua 15 ki tu!!");
	if (x.category.length() == 0)
		throw string("Loai tap chi khong duoc de trong!!");
	if (x.category.length() > 12)
		throw string("Loai tap chi khong duoc qua 12 ki tu!!");
	if (x.edition.length() == 0)
		throw string("So xuat ban khong duoc de trong!!");
	if (x.edition.length() > 11)
		throw string("So xuat ban khong duoc qua 11 ki tu!!");
	if (x.publishing.length() == 0)
		throw string("Tap xuat ban khong duoc de trong!!");
	if (x.publishing.length() > 12)
		throw string("Tap xuat ban khong duoc qua 12 ki tu!!");
	if (x.publishingyear < 1000 && x.publishingyear > 9999)
		throw string("Nam xuat ban gom 4 chu so!!");
	if (x.publishingcom.length() == 0)
		throw string("So xuat ban khong duoc de trong!!");
	if (x.publishingcom.length() > 12)
		throw string("So xuat ban khong duoc qua 12 ki tu!!");
	if (x.mainau.length() == 0)
		throw string("So xuat ban khong duoc de trong!!");
	if (x.mainau.length() > 13)
		throw string("So xuat ban khong duoc qua 13 ki tu!!");
	if (x.sameau.length() == 0)
		throw string("So xuat ban khong duoc de trong!!");
	if (x.sameau.length() > 22)
		throw string("So xuat ban khong duoc qua 22 ki tu!!");
}
void News::inputData(News& bao)
{
	bool check;
	cin.ignore();
	do
	{
		check = true;
		cout << "Nhap ma bai bao: ";
		getline(cin, bao.codenews);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);

	do
	{
		check = true;
		cout << "Nhap ten bai bao: ";
		getline(cin, bao.namenews);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap ten tap chi: ";
		getline(cin, bao.namemaga);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap loai tap chi: ";
		getline(cin, bao.category);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap so xuat ban: ";
		getline(cin, bao.edition);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap tap xuat ban: ";
		getline(cin, bao.publishing);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap nam xuat ban: ";
		cin >> bao.publishingyear;
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap nha xuat ban: ";
		getline(cin, bao.publishingcom);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap tac gia chinh: ";
		getline(cin, bao.mainau);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
	do
	{
		check = true;
		cout << "Nhap ten dong tac gia: ";
		getline(cin, bao.sameau);
		try
		{
			validate(bao);
		}
		catch (string& s)
		{
			cout << s << endl;
			check = false;
		}
	} while (check == false);
}

void News::swap(News& a, News& b)
{
	News c = a;
	a = b;
	b = c;
}

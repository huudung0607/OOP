#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class sinhvien {
private:
	string msv, ten, lop, email;
public:
	sinhvien() {}
	sinhvien(string msv, string ten, string lop, string email) {
		this->msv = msv;
		this->ten = ten;
		this->lop = lop;
		this->email = email;
	}
	string getLop()
	{
		string res = "";
		for (int i = 0; i < 4; i++)
		{
			if (isalpha(lop[i]))
			{
				res += lop[i];
			}
		}
		return res;
	}
	void chuanhoaTen()
	{
		stringstream ss(ten);
		string res, tmp;
		while (ss >> tmp)
		{
			res += toupper(tmp[0]);
			for (int i = 1; i < tmp.size(); i++)
			{
				res += tolower(tmp[i]);
			}
			res += " ";
		}
		res.pop_back();
		ten = res;
	}
	void in()
	{
		cout << msv << " " << ten << " " << lop << " " << email << endl;
	}
};
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<sinhvien> v;
	for (int i = 0; i < n; i++)
	{
		string msv, ten, lop, email;
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, lop);
		getline(cin, email);
		sinhvien sv(msv,ten, lop, email);
		sv.chuanhoaTen();
		v.push_back(sv);
	}
	int q;
	cin >> q;
	while (q--)
	{
		string lp;
		cin >> lp;
		if (lp == "CNTT")
		{
			cout << "DANH SACH SINH VIEN NGANH CONG NGHE THONG TIN :" << endl;
			for (auto x : v)
			{
				if (x.getLop() == lp)
				{
					x.in();
				}
			}
		}
		if (lp == "DTVT")
		{
			cout << "DANH SACH SINH VIEN NGANH DIEN TU VIEN THONG :" << endl;
			for (auto x : v)
			{
				if (x.getLop() == lp)
				{
					x.in();
				}
			}
		}
		if (lp == "KT")
		{
			cout << "DANH SACH SINH VIEN NGANH KE TOAN : " << endl;
			for (auto x : v)
			{
				if (x.getLop() == lp)
				{
					x.in();
				}
			}
		}
		if (lp == "MKT")
		{
			cout << "DANH SACH SINH VIEN NGANH MARKETING : " << endl;
			for (auto x : v)
			{
				if (x.getLop() == lp)
				{
					x.in();
				}
			}
		}
	}
}

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
		return lop;
	}
	string getKhoa()
	{
		string res = "";
		for (int i = 0; i < 4; i++)
		{
			res += msv[i];
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
		cout << "DANH SACH SINH VIEN KHOA " << lp << " :" << endl;
		for (auto x : v)
		{
			if (x.getKhoa() == lp)
			{
				x.in();
			}
		}
	}
}

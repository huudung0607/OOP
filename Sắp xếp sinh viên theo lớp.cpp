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
	string getMa()
	{
		return msv;
	}
	void in()
	{
		cout << msv << " " << ten << " " << lop << " " << email << endl;
	}
};
bool cmp(sinhvien a, sinhvien b)
{
	if (a.getLop() == b.getLop())
	{
		return a.getMa() < b.getMa();
	}
	return a.getLop() < b.getLop();
}
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
		sinhvien sv(msv, ten, lop, email);
		v.push_back(sv);
	}
	sort(v.begin(), v.end(),cmp);
	for (auto x : v)
	{
		x.in();
	}
}

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
	friend istream& operator >> (istream& in, sinhvien& x)
	{
		getline(in, x.msv);
		getline(in, x.ten);
		getline(in, x.lop);
		getline(in, x.email);
		return in;
	}
	void in()
	{
		cout << msv << " " << ten << " " << lop << " " << email << endl;
	}
};
bool cmp(sinhvien a, sinhvien b)
{
	return a.getMa() < b.getMa();
}
int main()
{
	vector<sinhvien> v;
	sinhvien a;
	while (cin >> a)
	{
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		x.in();
	}
}

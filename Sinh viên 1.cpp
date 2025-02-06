#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
class sinhvien
{
private:
	int ma;
	string ten, ns, lop;
	double gpa;
public:
	sinhvien() {}
	sinhvien(int ma, string ten, string lop, string ns, double gpa)
	{
		this->ma = ma;
		this->ten = ten;
		this->lop = lop;
		this->ns = ns;
		this-> gpa = gpa;
	}
	void chuanhoaNS()
	{
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
	}
	void in()
	{
		cout << "SV" << setw(3) << setfill('0') << ma << " " << ten
			<< " " << lop << " " << ns << " " << fixed << setprecision(2) << gpa << endl;
	}
	
};
int main()
{
	int n;
	cin >> n;
	vector<sinhvien> v;
	for (int i = 1; i <= n; i++)
	{
		cin.ignore();
		string ten, ns, lop;
		double gpa;
		getline(cin, ten);
		getline(cin, lop);
		getline(cin, ns);
		cin >> gpa;
		sinhvien a(i, ten, lop, ns, gpa);
		a.chuanhoaNS();
		v.push_back(a);
	}
	for (auto x : v)
	{
		x.in();
	}
}

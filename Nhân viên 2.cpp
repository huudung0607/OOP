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
class nhanvien
{
private:
	int ma;
	string hoten, gt, ns, dc, mst, ngayhd;
public:
	nhanvien() {}
	nhanvien(int ma, string hoten, string gt, string ns, string dc, string mst, string ngayhd)
	{
		this->ma = ma;
		this->hoten = hoten;
		this->gt = gt;
		this->ns = ns;
		this->dc = dc;
		this->mst = mst;
		this->ngayhd = ngayhd;
	}
	void chuanhoaNS() {
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
	}
	void chuanhoaHD()
	{
		if (ngayhd[1] == '/')
		{
			ngayhd = "0" + ngayhd;
		}
		if (ngayhd[4] == '/')
		{
			ngayhd.insert(3, "0");
		}
	}
	void chuanhoaTen()
	{
		stringstream ss(hoten);
		string temp, res = "";
		while (ss >> temp)
		{
			res += toupper(temp[0]);
			for (int i = 1; i < temp.size(); i++)
			{
				res += tolower(temp[i]);
			}
			res += " ";
		}
		res.pop_back();
		hoten = res;
	}
	int getMA()
	{
		return ma;
	}
	string getNS()
	{
		stringstream ss(ns);
		string nam, thang, ngay;
		getline(ss, ngay, '/');
		getline(ss, thang, '/');
		getline(ss, nam, '/');
		return nam + thang + ngay;
	}
	friend ostream& operator << (ostream& out, nhanvien x)
	{
		out << setw(5) << setfill('0') << x.ma << " " << x.hoten << " " << x.gt << " "
		<< x.ns << " " << x.dc << " " << x.mst << " " << x.ngayhd << endl;
		return out;
	}
};
bool cmp(nhanvien a, nhanvien b)
{
	string s1 = a.getNS();
	string s2 = b.getNS();
	if (s1 != s2)
	{
		return s1 < s2;
	}
	return a.getMA() < b.getMA();
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<nhanvien> v;
	for (int i = 1; i <= n; i++)
	{
		string hoten, gt, ns, dc, mst, ngayhd;
		getline(cin, hoten);
		getline(cin, gt);
		getline(cin, ns);
		getline(cin, dc);
		getline(cin, mst);
		getline(cin, ngayhd);
		nhanvien nv(i, hoten, gt, ns, dc, mst, ngayhd);
		nv.chuanhoaNS();
		nv.chuanhoaHD();
		v.push_back(nv);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		cout << x;
	}
	
}

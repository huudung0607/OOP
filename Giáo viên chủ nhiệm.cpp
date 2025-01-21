#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
class person {
private:
	string ten, ns, diachi;
public:
	person() {}
	person(string ten, string ns, string diachi)
	{
		this->ten = ten;
		this->ns = ns;
		this->diachi = diachi;
	}
	void chuanhoaTen()
	{
		stringstream ss(ten);
		string temp, res = "";
		while (ss>>temp)
		{
			res += toupper(temp[0]);
			for (int i = 1; i < temp.size(); i++)
			{
				res += tolower(temp[i]);
			}
			res += " ";
		}
		res.pop_back();
		ten = res;
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
	string getTen()
	{
		return ten;
	}
	string getNS()
	{
		return ns;
	}
	string getDC()
	{
		return diachi;
	}
};
class student : public person {
private:
	string ma, lop;
	double gpa;
public:
	student() {}
	student(string ma, string ten, string ns, string diachi, string lop, double gpa) : person(ten, ns, diachi) {
		this->ma = ma;
		this->lop = lop;
		this->gpa = gpa;
	}
	string getLop()
	{
		return lop;
	}
	void in()
	{
		cout << ma << " " << getTen() << " " << getNS() << " " << getDC() << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
	}
};
class teacher : public person {
private:
	string ma, khoa, lop;
	int luong;
public:
	teacher() {}
	teacher(string ma, string ten, string ns, string diachi, string khoa, int luong, string lop) : person(ten, ns, diachi)
	{
		this->ma = ma;
		this->khoa = khoa;
		this->lop = lop;
		this->luong = luong;
	}
	string getLop()
	{
		return lop;
	}
	void in()
	{
		cout << ma << " " << getTen() << " " << getNS() << " " << getDC() << " " << khoa << " " << luong << " " << lop << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<student> hs;
	vector<teacher> gv;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		string ma, ten, ns, diachi, lop, khoa;
		int luong; double gpa;
		getline(cin, ma);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, diachi);
		if (ma[0] == 'G')
		{
			getline(cin, khoa);
			cin >> luong;
			cin >> lop;
			teacher giaovien(ma, ten, ns, diachi, khoa, luong, lop);
			giaovien.chuanhoaNS();
			giaovien.chuanhoaTen();
			gv.push_back(giaovien);
		}
		else
		{
			getline(cin, lop);
			cin >> gpa;
			student hocsinh(ma, ten, ns, diachi, lop, gpa);
			hocsinh.chuanhoaNS();
			hocsinh.chuanhoaTen();
			hs.push_back(hocsinh);
		}
	}
	cin.ignore();
	string lop;
	getline(cin, lop);
	cout << "DANH SACH GIAO VIEN PHU TRACH LOP " << lop << " : " << endl;
	for (auto x : gv)
	{
		if (x.getLop() == lop)
		{
			x.in();
		}
	}
	cout << "DANH SACH SINH VIEN LOP " << lop << " : " << endl;
	for (auto x : hs)
	{
		if (x.getLop() == lop)
		{
			x.in();
		}
	}
}

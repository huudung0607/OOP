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
using namespace std;
class student
{
public:
	student() {

	}
	student(string msv, string ten, string ns, string lop, double gpa)
	{
		this->msv = msv;
		this->ten = ten;
		this->ns = ns;
		this->lop = lop;
		this->gpa = gpa;
	}
	void nhap()
	{
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, lop);
		cin >> gpa;
	}
	void chuanhoaten() {
		stringstream ss(ten);
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
	void in()
	{
		if (lop == "CNTT1")
		{
			cout << msv << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
		}
		
	}

private:
	string msv, ten, ns, lop;
	double gpa;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	vector<student> danhsach;
	for (int i = 0; i < n; i++)
	{
		string msv, ten, ns, lop;
		double gpa;
		getline(cin, msv);
		getline(cin, ten);
		getline(cin, ns);
		getline(cin, lop);
		cin >> gpa;
		cin.ignore();
		student sv(msv, ten, ns, lop, gpa);
		sv.chuanhoaNS();
		sv.chuanhoaten();
		danhsach.emplace_back(sv);
	}
	for (auto x : danhsach)
	{
		x.in();
	}
}

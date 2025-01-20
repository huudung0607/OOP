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
	bool checkDob(string s)
	{
		if (s[1] == '/')
		{
			s = "0" + s;
		}
		if (s[4] == '/')
		{
			s.insert(3, "0");
		}
		if (ns[1] == '/')
		{
			ns = "0" + ns;
		}
		if (ns[4] == '/')
		{
			ns.insert(3, "0");
		}
		stringstream ss(s), ss2(ns);
		string temp, temp2;
		vector<string> v, v2;
		while (getline(ss, temp, '/'))
		{
			v2.push_back(temp);
		}
		while (getline(ss2, temp2, '/'))
		{
			v.push_back(temp2);
		}
		if (v[2] == v2[2])
		{
			if (v[1] == v2[1])
			{
				if (v[0] == v2[0])
				{
					return false;
				}
				else if (v[0] < v2[0])
				{
					return true;
				}
				else if (v[0] > v2[0])
				{
					return false;
				}
			}
			else if (v[1] < v2[1])
			{
				return true;
			}
			else if(v[1] > v2[1])
			{
				return false;
			}
		}
		else if (v[2] < v2[2])
		{
			return true;
		}
		else if (v[2] > v2[2])
		{
			return false;
		}
	}
	void in()
	{
		cout << msv << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
	}

private:
	string msv, ten, ns, lop;
	double gpa;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "30/07/2002";
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
		if (x.checkDob(s))
		{
			x.in();
		}
	}
}
